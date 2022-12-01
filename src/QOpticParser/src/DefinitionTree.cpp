#include "DefinitionTree.h"
#include "StringTools.h"

// --------------------------------------------------------------------------------
// Summation Tree

qoptic::SummationTree::SummationTree(std::string expressionIn, std::vector<std::string> indicesIn,
                                     std::vector<std::string> lowerBoundsIn,
                                     std::vector<std::string> upperBoundsIn) :
  expression(expressionIn), indices(indicesIn), lowerBounds(lowerBoundsIn), upperBounds(upperBoundsIn) {
  insertSpaces(expression); stripCurlyBracesInPlace(expression); tokenizeSummations(expression);
};

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

std::string qoptic::SummationTree::generateDefinition(std::string indentation) {
  std::string results = "";
  // Sum open
  for (int i = 0; i < indices.size(); i++) {
    indentation += "\t";
    results += "sum(" + indices[i] + " ->\n" + indentation;
  }

  // Sum body
  std::string processedExpression = expression;
  for (int i = 0; i < _childrenTrees.size(); ++i) {
    std::string search = "#" + std::to_string(i);
    processedExpression.replace(
      processedExpression.find(search), search.size(), _childrenTrees[i]->generateDefinition(indentation)
    );
  }
  results += "\t" + processedExpression;

  // Sum close
  for (int i = indices.size() - 1; i >= 0; --i) {
    results += ", [" + lowerBounds[i] + ":";
    if(isNumber(upperBounds[i])) results += upperBounds[i] + ";]\n";
    else results += "parameters[:" + upperBounds[i] + "];]\n";
    indentation = indentation.substr(1);
    results += indentation + ")";
  }

  return results;
}

// --------------------------------------------------------------------------------
// Definition Tree

qoptic::DefinitionTree::DefinitionTree(std::string expressionIn, std::string nameIn, std::vector<std::string> indicesIn) :
  expression(expressionIn), name(nameIn), indices(indicesIn) {
  insertSpaces(expression); stripCurlyBracesInPlace(expression); tokenizeSummations(expression);
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

std::string qoptic::DefinitionTree::generateDefinition(std::string parameterCheck, std::string basisGeneration) {
  std::string results = "function _generate_" + stripCurlyBraces(name) +
    "(" + separateByComma(indices) + "; parameters::Dict)\n";
  results += parameterCheck;
  results += basisGeneration;

  std::string processedExpression = expression;
  for (int i = 0; i < _childrenTrees.size(); ++i) {
    std::string search = "#" + std::to_string(i);
    processedExpression.replace(
      processedExpression.find(search), search.size(), _childrenTrees[i]->generateDefinition("\t")
    );
  }
  results += "\t" + processedExpression;

  results += "end\n\n";

  return results;
}