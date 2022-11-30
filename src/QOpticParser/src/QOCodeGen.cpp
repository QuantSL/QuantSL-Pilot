#include "QOCodeGen.h"
#include <fstream>

#include "DefinitionTree.h"
#include "StringTools.h"

std::string qoptic::_generateParameterCheck(qoptic::QOVisitor &visitor) {
  std::string checkParameters = "\tfor parameter in [" +
    separateByComma(toSymbol(stripCurlyBraces(visitor.getParameters()))) +
    "]# Check if all parameters are defined\n";
  checkParameters += "\t\t!haskey(parameters, parameter) && error(\"Parameter $parameter not defined\")\n";
  checkParameters += "\tend\n\n";
  return checkParameters;
}

std::string qoptic::_generateOperatorContainer(QOVisitor &visitor) {
  std::string results = "struct OperatorContainer\n";
  for (auto operatorName : visitor.getOperators()) {
    results += "\t" + stripCurlyBraces(operatorName) + "\n";
  }
  for (auto operatorName : visitor.getIndexedOperators()) {
    results += "\t" + stripCurlyBraces(operatorName) + "\n";
  }
  results += "end\n\n";
  return results;
}

std::string qoptic::_generateBasis() {
  return std::string("\tindices = _generate_indices(parameters = parameters)\n"
    "\tindexDict = Dict(key => val for (val, key) in enumerate(indices))\n\n"
    "\tbasis = reduce( ⊗, repeat( [SpinBasis(1//2)], length(indices) ) )\n");
}

void qoptic::generateCode(std::string filename, QOVisitor &visitor) {
  std::ofstream file;
  file.open(filename);

  file << "# using QuantumOptics\n\n";

  file << _generateOperatorContainer(visitor);

  // Generate code to sample indices from each definition
  std::vector<qoptic::DefinitionTree*> trees = visitor.getDefinitions();
  std::string checkParameters = _generateParameterCheck(visitor);
  for (auto tree : trees) {
    file << tree->generateIndexSampler(checkParameters);
  }

  file << "function _generate_indices(; parameters::Dict)\n";
  file << checkParameters;
  file << "\tresults = ()\n";
  for (auto op : visitor.getOperators()) {
    file << "\tresults = results..., (_generate_indices_from_" <<
      stripCurlyBraces(op) << "(parameters = parameters))...\n";
  }
  file << "\treturn unique(results)\nend\n\n";



  file.close();
}