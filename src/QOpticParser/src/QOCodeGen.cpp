#include "QOCodeGen.h"
#include <fstream>

#include "QOIndexVisitor.h"
#include "StringTools.h"

// std::string qoptic::_generateOperatorContainer(QOIndexVisitor &visitor) {
//   std::string container = "struct OperatorContainer\n";
//   for (auto operatorName : visitor.getOperators()) {
//     container += "\t" + stripCurlyBraces(operatorName) + "\n";
//   }
//   for (auto operatorName : visitor.getIndexedOperators()) {
//     container += "\t" + stripCurlyBraces(operatorName) + "\n";
//   }
//   container += "end\n\n";
//   return container;
// }

std::string qoptic::_generateBasis() {
  return std::string("\tindices = _generate_indices(parameters = parameters)\n"
    "\tindexDict = Dict(key => val for (val, key) in enumerate(indices))\n\n"
    "\tbasis = reduce( ⊗, repeat( [SpinBasis(1//2)], length(indices) ) )\n\n");
}

int qoptic::generateCode(std::string filename, QOParser &parser) {
  std::ofstream file;
  file.open(filename);

  file << "# using QuantumOptics\n\n";

  // file << _generateOperatorContainer(visitor);

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

  std::string basisCode = _generateBasis();
  // for (auto tree : trees) {
  //   file << tree->generateDefinition(checkParameters, basisCode);
  // }

  file.close();
  return 0;
}