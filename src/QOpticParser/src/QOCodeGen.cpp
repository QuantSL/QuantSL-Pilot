#include "QOCodeGen.h"
#include <fstream>

#include "DefinitionTree.h"
#include "StringTools.h"

void qoptic::generateCode(std::string filename, QOVisitor &visitor) {
  std::ofstream file;
  file.open(filename);

  file << "# using QuantumOptics\n\n";

  // Pamrameter Check definition
  std::string checkParameters;
  checkParameters += "\tfor parameter in [" +
    separateByComma(toSymbol(stripCurlyBraces(visitor.getParameters()))) +
    "]\n";
  checkParameters += "\t\t!haskey(parameters, parameter) && error(\"Parameter $parameter not defined\")\n";
  checkParameters += "\tend\n\n";

  // Generate code to sample indices from each definition
  std::vector<qoptic::DefinitionTree*> trees = visitor.getDefinitions();
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