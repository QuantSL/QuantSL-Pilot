#include "QODefinitionVisitor.h"

#include "StringTools.h"

void qoptic::QODefinitionVisitor::_generateParameterCheck() {
  _parameterCheck = std::string("\tfor parameter in [" +
    separateByComma(toSymbol(stripCurlyBraces(_parameters))) +
    "] # Check if all parameters are defined\n"
    "\t\t!haskey(parameters, parameter) && error(\"Parameter $parameter not defined\")\n"
    "\tend\n\n");
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitMain(QOParser::MainContext *ctx) {
  _definitions = "";

  return visitChildren(ctx);
}


antlrcpp::Any qoptic::QODefinitionVisitor::visitParameters(QOParser::ParametersContext *ctx) {
  for (auto parameter : ctx->elements) {
    _parameters.push_back( stripCurlyBraces( parameter->getText() ) );
  }
  _generateParameterCheck();

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitSubsystems(QOParser::SubsystemsContext *ctx) {
  for (auto subsystem : ctx->elements) {
    _subsystems.push_back(subsystem->getText());
  }

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitSimpleDefinition(qoptic::QOParser::SimpleDefinitionContext *ctx) {
  _indentation = "\t";
  std::string operatorName = stripCurlyBraces(ctx->object->getText());
  _operatorList.push_back(operatorName);

  _definitions += "function _generate_" + operatorName +
    "(; basis, indexDict, operators, parameters::Dict)\n";
  _definitions += "\tσx, σy, σz, σp, σm = operators\n\n";

  _userDefinitions += "function generate_" + operatorName + "(; parameters::Dict)\n";
  _userDefinitions += _parameterCheck;
  _userDefinitions += _basisAndOperatorsUser;

  _definitions += "\treturn "; _userDefinitions += "\treturn ";
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _definitions += "\nend\n\n"; _userDefinitions += "\nend\n\n";
  return visitedChildrenReturn;
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitIndexedDefinition(qoptic::QOParser::IndexedDefinitionContext *ctx) {
  _indentation += "\t";
  std::vector<std::string> indices;
  for ( auto index : ctx->botindex()->indices ) indices.push_back(index->getText());

  std::string operatorName = stripCurlyBraces(ctx->object->getText());
  _operatorList.push_back(operatorName);

  _definitions += "function _generate_" + operatorName + "(; basis, indexDict, operators, parameters::Dict)\n";
  _definitions += "\tσx, σy, σz, σp, σm = operators\n\n";

  _userDefinitions += "function generate_" + operatorName + "(; parameters::Dict)\n";
  _userDefinitions += _parameterCheck;
  _userDefinitions += _basisAndOperatorsUser;

  _definitions += "\treturn (" + separateByComma(indices) + ") -> ";
  _userDefinitions += "\treturn (" + separateByComma(indices) + ") -> ";
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _definitions += "\nend\n\n"; _userDefinitions += "\nend\n\n";
  return visitedChildrenReturn;
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitSumExpression(qoptic::QOParser::SumExpressionContext *ctx) {
  std::vector<std::string> indices;
  for ( auto index : ctx->boundary->botindex()->indices ) indices.push_back(index->getText());
  std::string upperBound = ctx->boundary->topindex()->index->getText();

  // Sum open
  std::string sumResult = "";
  for (int i = 0; i < indices.size(); i++) {
    _indentation += "\t";
    sumResult += "sum(" + indices[i] + " -> \n" + _indentation;
  }
  _definitions += sumResult; _userDefinitions += sumResult;

  // Further Parse Tree
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);

  // Sum close
  sumResult = "";
  for (int i = 0; i < indices.size(); i++) {
    _indentation = _indentation.substr(1);
    sumResult += ", [1:";
    sumResult += isNumber(upperBound) ? upperBound + ";]\n" + _indentation + ")" :
      "parameters[:" + upperBound + "];]\n" + _indentation + ")" ;
  }
  _definitions += sumResult; _userDefinitions += sumResult;

  return visitedChildrenReturn;
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitElementaryExpression(qoptic::QOParser::ElementaryExpressionContext *ctx) {
  std::vector<std::string> indices;
  if (ctx->botindex() != nullptr) {
    for ( auto index : ctx->botindex()->indices ) {
      std::string indexName = index->getText();
      if ( contains(_subsystems, indexName) ) indices.push_back(":" + indexName);
      else indices.push_back(indexName);
    }
  }

  std::string expression = "";
  if ( ctx->SIGMA() != nullptr ) {
    expression += "embed(basis, indexDict[";
    if      ( indices.size() == 0 ) expression += "1], σ";
    else if ( indices.size() == 1 ) expression += indices[0] + "], σ";
    else                            expression += "(" + separateByComma(indices) + ")], σ";
    expression += ctx->SIGMA()->getText().back(); expression += ")";
  }
  else if ( ctx->SYMBOLNAME() != nullptr ) {
    std::string symbolName = stripCurlyBraces( ctx->SYMBOLNAME()->getText() );
    if ( contains(_parameters, symbolName) ) expression += "parameters[:" + symbolName + "]";
    else expression += "_generate_" + symbolName +
      "(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)(" +
      separateByComma(indices) + ")";
  }
  _definitions += expression; _userDefinitions += expression;

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitSign(qoptic::QOParser::SignContext *ctx) {
  _definitions += ctx->getText() + " "; _userDefinitions += ctx->getText() + " ";

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitArithmethic(qoptic::QOParser::ArithmethicContext *ctx) {
  std::string arithmethicString = "";
  if ( ctx->getText() == "^" ) arithmethicString += ctx->getText();
  else arithmethicString += " " + ctx->getText() + " ";
  _definitions += arithmethicString; _userDefinitions += arithmethicString;

  return visitChildren(ctx);
}

std::string qoptic::QODefinitionVisitor::generateOperatorContainer() {
  std::string container = "struct OperatorContainer\n";
  for (auto operatorName : _operatorList) {
    container += "\t" + stripCurlyBraces(operatorName) + "\n";
  }
  container += "end\n\n";
  return container;
}

std::string qoptic::QODefinitionVisitor::generateSystem() {
  std::string generateSystem = "function generateSystem(; parameters::Dict)\n";
  generateSystem += _parameterCheck;
  generateSystem += _basisAndOperators;

  generateSystem += "\tOperatorContainer(";
  std::vector<std::string> operatorGenerators;
  for (auto operatorName : _operatorList) {
    operatorGenerators.push_back( "\n\t\t_generate_" + stripCurlyBraces(operatorName) +
      "(basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)" );
  }
  generateSystem += separateByComma(operatorGenerators);
  generateSystem += "\n\t)\nend\n\n";
  return generateSystem;
}