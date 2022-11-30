#include "DefinitionTree.h"
#include "StringTools.h"

std::string qoptic::SummationTree::generateIndexSampler(std::string indentation) {
  std::string results = "";
  // Sum open
  for (int i = 0; i < indices.size(); i++) {
    results += indentation + "for " + indices[i] + " in [" + lowerBounds[i] + ":";
    if(isNumber(upperBounds[i])) results += upperBounds[i] + ";]\n";
    else results += "parameters[:" + upperBounds[i] + "];]\n";
    indentation += "\t";
  }

  // Sum body
  for (auto childIndices : _childrensIndices) {
    if (childIndices.size() == 1) {
      results += indentation + "results = results..., " + childIndices[0] + "\n";
    }
    else results += indentation + "results = results..., (" + separateByComma(childIndices) + ")\n";
  }
  for (int i = 0; i < _childrenOperators.size(); i++) {
    results += indentation + "results = results..., (_generate_indices_from_" +
      stripCurlyBraces(_childrenOperators[i]) + "(" +separateByComma(_childrenOperatorsIndices[i]) +
      ", parameters = parameters))...\n";
  }
  for (auto childTree : _childrenTrees) {
    results += childTree->generateIndexSampler(indentation);
  }

  // Sum close
  for (int i = 0; i < indices.size(); i++) {
    indentation = indentation.substr(1);
    results += indentation + "end\n";
  }

  return results;
}

std::string qoptic::DefinitionTree::generateIndexSampler(std::string parameterCheck) {
  std::string results = "function _generate_indices_from_" + stripCurlyBraces(name) +
    "(" + separateByComma(indices) + "; parameters::Dict)\n";
  results += parameterCheck;
  results += "\tresults = ()\n";

  for (auto childIndices : _childrensIndices) {
    if (childIndices.size() == 1) {
      results += "\tresults = results..., " + childIndices[0] + "\n";
    }
    else results += "\tresults = results..., (" + separateByComma(childIndices) + ")\n";
  }
  for (int i = 0; i < _childrenOperators.size(); i++) {
    results +=  "\tresults = results..., (_generate_indices_from_" +
      stripCurlyBraces(_childrenOperators[i]) + "(" + separateByComma(_childrenOperatorsIndices[i]) +
      ", parameters = parameters))...\n";
  }
  results += "\n";
  for (auto childTree : _childrenTrees) {
    results += childTree->generateIndexSampler("\t");
  }
  results += "\treturn results\nend\n\n";
  return results;
}