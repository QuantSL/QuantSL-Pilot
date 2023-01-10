#include "ITensorCodeGen.h"
#include <fstream>

#include "ITensorDefinitionVisitor.h"

#include "../../shared/IndexVisitor.h"
#include "../../shared/StringTools.h"

int qdsl::generateCode(std::string filename, QDSLParser &parser) {
  std::ofstream file;
  file.open(filename);

  file << "using ITensor\n\n";

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