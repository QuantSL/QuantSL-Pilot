#include "QOCodeGen.h"
#include <fstream>

#include "QOIndexVisitor.h"
#include "QODefinitionVisitor.h"
#include "StringTools.h"

int qoptic::generateCode(std::string filename, QOParser &parser) {
  std::ofstream file;
  file.open(filename);

  file << "# using QuantumOptics\n\n";

  // Generate code to sample indices from each definition
  parser.reset();
  QOIndexVisitor indexVisitor;
  try {
    indexVisitor.visitMain(parser.main());
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
    return -1;
  }
  file << indexVisitor.getIndexSampler();

  file << "function _generate_indices(; parameters::Dict)\n";
  file << "\tresults = ()\n";
  for (auto simpleOperator : indexVisitor.getSimpleOperators()) {
    file << "\tresults = results..., (" << stripCurlyBraces(simpleOperator) << "(parameters = parameters)...)\n";
  }
  file << "\treturn unique(results)\nend\n\n";

  parser.reset();
  QODefinitionVisitor definitionVisitor;
  try {
    definitionVisitor.visitMain(parser.main());
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
    return -1;
  }
  file << definitionVisitor.getDefinitions();
  file << definitionVisitor.generateOperatorContainer();
  file << definitionVisitor.generateSystem();

  file.close();
  return 0;
}