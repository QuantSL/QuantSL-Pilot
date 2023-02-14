#include "ITensorCodeGen.h"
#include <fstream>

#include "ITensorDefinitionVisitor.h"

#include "../../shared/IndexVisitor.h"
#include "../../shared/StringTools.h"

int qdsl::generateCode(std::string filename, QDSLParser &parser) {
  std::ofstream file;
  file.open(filename);

  file << "using ITensors\n\n"
    "# Define useful arithmetic to combine products of sums\n"
    "function ×(lhs::Sum{A}, rhs::Sum{A}) where {A}\n"
    "\tresult = OpSum()\n"
    "\tfor argL ∈ lhs.args[1], argR ∈ rhs.args[1]\n"
    "\t\tresult += argL * argR\n"
    "\tend\n"
    "\tresult\n"
    "end\n\n"
    "×(lhs::Op, rhs::Op) = lhs * rhs\n"
    "×(lhs::A,  rhs::Op) where {A} = lhs * rhs\n"
    "×(lhs::Op, rhs::A)  where {A} = lhs * rhs\n"
    "×(lhs::A,      rhs::Sum{B}) where {A, B} = lhs * rhs\n"
    "×(lhs::Sum{A}, rhs::B)      where {A, B} = lhs * rhs\n"
    "×(lhs::Sum{A}, rhs::Op)     where {A} = lhs * rhs\n"
    "×(lhs::Op,     rhs::Sum{A}) where {A} = lhs * rhs\n";

  // Generate code to sample indices from each definition
  parser.reset();
  IndexVisitor indexVisitor;
  indexVisitor.visitMain(parser.main());
  file << indexVisitor.getIndexSampler();

  file << "function _generate_indices(; parameters::Dict)\n";
  file << "\tresults = ()\n";
  for (auto simpleOperator : indexVisitor.getSimpleOperators()) {
    file << "\tresults = results..., (" << stripCurlyBraces(simpleOperator) << "(parameters = parameters)...)\n";
  }
  file << "\treturn unique(results)\nend\n\n";

  // Generate code to define each quantum object
  parser.reset();
  ITensorDefinitionVisitor definitionVisitor;
  definitionVisitor.visitMain(parser.main());
  file << definitionVisitor.getUserDefinitions();
  file << definitionVisitor.getDefinitions();
  file << definitionVisitor.generateOperatorContainer();
  file << definitionVisitor.generateSystem();

  file.close();
  return 0;
}