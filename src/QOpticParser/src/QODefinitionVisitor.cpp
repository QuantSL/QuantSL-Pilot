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
    _parameters.push_back(parameter->getText());
  }

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
  std::string functionName = "_generate_" + stripCurlyBraces(ctx->object->getText());
  _simpleOperatorGenerators.push_back(functionName);

  _definitions += "function " + functionName + "(; parameters::Dict)\n";
  _definitions += _parameterCheck;
  _definitions += _basisAndOperators;

  _definitions += "\treturn ";
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _definitions += "\nend\n\n";
  return visitedChildrenReturn;
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitIndexedDefinition(qoptic::QOParser::IndexedDefinitionContext *ctx) {
  _indentation += "\t";
  std::vector<std::string> indices;
  for ( auto index : ctx->botindex()->indices ) indices.push_back(index->getText());

  _definitions += "function _generate_" + stripCurlyBraces(ctx->object->getText()) +
    "(" + separateByComma(indices) + "; parameters::Dict)\n";
  _definitions += _parameterCheck;
  _definitions += _basisAndOperators;
  _definitions += _indentation + "results = ()\n";

  _definitions += "\treturn ";
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _definitions += "\nend\n\n";
  return visitedChildrenReturn;
}

antlrcpp::Any qoptic::QODefinitionVisitor::visitSumExpression(qoptic::QOParser::SumExpressionContext *ctx) {
  std::vector<std::string> indices;
  for ( auto index : ctx->boundary->botindex()->indices ) indices.push_back(index->getText());
  std::string upperBound = ctx->boundary->topindex()->getText();

  // Sum open
  for (int i = 0; i < indices.size(); i++) {
    _definitions += _indentation + "for " + indices[i] + " in [1:"; // TODO: Replace 1 with lower bound
    if(isNumber(upperBound)) _definitions += upperBound + ";]\n";
    else _definitions += "parameters[:" + upperBound + "];]\n";
    _indentation += "\t";
  }

  // Further Parse Tree
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);

  // Sum close
  for (int i = 0; i < indices.size(); i++) {
    _indentation = _indentation.substr(1);
    _definitions += _indentation + "end\n";
  }

  // Restore old indices and tree context, and return
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

  if      ( ctx->SIGMA()      != nullptr ) _definitions += _indentation + "push!(results, (" + separateByComma(indices) + "))\n";
  else if ( ctx->SYMBOLNAME() != nullptr ) {
    _definitions += _indentation + "push!(results, _generate_indices_from_" +
      stripCurlyBraces( ctx->SYMBOLNAME()->getText() ) + "(" + separateByComma(indices) +
      "; parameters::Dict) )\n";
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