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

  _definitions += "\treturn ";
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _definitions += "\nend\n\n";
  return visitedChildrenReturn;
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitIndexedDefinition(qoptic::QOParser::IndexedDefinitionContext *ctx) {
  _indentation += "\t";
  std::vector<std::string> indices;
  for ( auto index : ctx->botindex()->indices ) indices.push_back(index->getText());

  std::string operatorName = stripCurlyBraces(ctx->object->getText());
  _operatorList.push_back(operatorName);

  _definitions += "function _generate_" + operatorName + "(" + separateByComma(indices) +
    "; basis, indexDict, operators, parameters::Dict)\n";
  _definitions += "\tσx, σy, σz, σp, σm = operators\n\n";

  _definitions += "\treturn (" + separateByComma(indices) + ") -> ";
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _definitions += "\nend\n\n";
  return visitedChildrenReturn;
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitSumExpression(qoptic::QOParser::SumExpressionContext *ctx) {
  std::vector<std::string> indices;
  for ( auto index : ctx->boundary->botindex()->indices ) indices.push_back(index->getText());
  std::string upperBound = ctx->boundary->topindex()->index->getText();

  // Sum open
  for (int i = 0; i < indices.size(); i++) {
    _indentation += "\t";
    _definitions += "sum(" + indices[i] + " -> \n" + _indentation;
  }

  // Further Parse Tree
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);

  // Sum close
  for (int i = 0; i < indices.size(); i++) {
    _indentation = _indentation.substr(1);
    _definitions += ", [1:";
    _definitions += isNumber(upperBound) ? upperBound + ";]\n" + _indentation + ")" :
      "parameters[:" + upperBound + "];]\n" + _indentation + ")" ;
  }

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

  if ( ctx->SIGMA() != nullptr ) {
    _definitions += "embed(basis, indexDict[";
    if      ( indices.size() == 0 ) _definitions += "1], σ";
    else if ( indices.size() == 1 ) _definitions += indices[0] + "], σ";
    else                            _definitions += "(" + separateByComma(indices) + ")], σ";
    _definitions += ctx->SIGMA()->getText().back(); _definitions += ")";
  }
  else if ( ctx->SYMBOLNAME() != nullptr ) {
    std::string symbolName = stripCurlyBraces( ctx->SYMBOLNAME()->getText() );
    if ( contains(_parameters, symbolName) ) _definitions += "parameters[:" + symbolName + "]";
    else _definitions += "_generate_" + symbolName + "(" + separateByComma(indices) + ")";
  }

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitSign(qoptic::QOParser::SignContext *ctx) {
  _definitions += ctx->getText() + " ";

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitArithmethic(qoptic::QOParser::ArithmethicContext *ctx) {
  if ( ctx->getText() == "^" ) _definitions += ctx->getText();
  else _definitions += " " + ctx->getText() + " ";

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