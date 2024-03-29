#include "IndexVisitor.h"

#include "StringTools.h"

void qdsl::IndexVisitor::_generateParameterCheck() {
  _parameterCheck = std::string("\tfor parameter in [" +
    separateByComma(toSymbol(stripCurlyBraces(_parameters))) +
    "] # Check if all parameters are defined\n"
    "\t\t!haskey(parameters, parameter) && error(\"Parameter $parameter not defined\")\n"
    "\tend\n\n");
}

antlrcpp::Any qdsl::IndexVisitor::visitMain(QDSLParser::MainContext *ctx) {
  _indexSampler = "";

  return visitChildren(ctx);
}


antlrcpp::Any qdsl::IndexVisitor::visitParameters(QDSLParser::ParametersContext *ctx) {
  for (auto parameter : ctx->elements) {
    _parameters.push_back(parameter->getText());
  }
  _generateParameterCheck();

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::IndexVisitor::visitSubsystems(QDSLParser::SubsystemsContext *ctx) {
  for (auto subsystem : ctx->elements) {
    _subsystems.push_back(subsystem->getText());
  }

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::IndexVisitor::visitSimpleDefinition(QDSLParser::SimpleDefinitionContext *ctx) {
  _indentation = "\t";

  std::string operatorName = stripCurlyBraces(ctx->object->getText());
  std::string functionName = "_generate_indices_from_" + operatorName;
  _simpleOperatorGenerators.push_back(functionName);
  _operatorList.push_back(operatorName);

  _indexSampler += "function " + functionName + "(; parameters::Dict)\n";
  _indexSampler += _parameterCheck;
  _indexSampler += _indentation + "results = ()\n";

  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _indexSampler += "\treturn results\nend\n\n";
  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::IndexVisitor::visitIndexedDefinition(QDSLParser::IndexedDefinitionContext *ctx) {
  _indentation += "\t";

  std::string operatorName = stripCurlyBraces(ctx->object->getText());
  _operatorList.push_back(operatorName);

  std::vector<std::string> indices;
  for ( auto index : ctx->botindex()->indices ) indices.push_back(index->getText());

  _indexSampler += "function _generate_indices_from_" + operatorName +
    "(" + separateByComma(indices) + "; parameters::Dict)\n";
  _indexSampler += _parameterCheck;
  _indexSampler += _indentation + "results = ()\n";

  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _indexSampler += "\treturn results\nend\n\n";
  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::IndexVisitor::visitSumExpression(QDSLParser::SumExpressionContext *ctx) {
  std::vector<std::string> indices;
  for ( auto index : ctx->boundary->botindex()->indices ) indices.push_back(index->getText());
  std::string upperBound = ctx->boundary->topindex()->index->getText();

  // Sum open
  for (int i = 0; i < indices.size(); i++) {
    _indexSampler += _indentation + "for " + indices[i] + " in [1:"; // TODO: Replace 1 with lower bound
    _indexSampler += isNumber(upperBound) ? upperBound + ";]\n" : "parameters[:" + upperBound + "];]\n";
    _indentation += "\t";
  }

  // Further Parse Tree
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);

  // Sum close
  for (int i = 0; i < indices.size(); i++) {
    _indentation = _indentation.substr(1);
    _indexSampler += _indentation + "end\n";
  }

  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::IndexVisitor::visitElementaryExpression(QDSLParser::ElementaryExpressionContext *ctx) {
  std::vector<std::string> indices;
  if (ctx->botindex() != nullptr) {
    for ( auto index : ctx->botindex()->indices ) {
      std::string indexName = index->getText();
      if ( contains(_subsystems, indexName) ) indices.push_back(":" + indexName);
      else indices.push_back(indexName);
    }
  }

  if ( ctx->SIGMA() != nullptr ) {
    _indexSampler += _indentation + "results = results..., (" + separateByComma(indices) + ")\n";
  }
  else if ( ctx->SYMBOLNAME() != nullptr ) {
    std::string operatorName = stripCurlyBraces(ctx->SYMBOLNAME()->getText());
    if ( contains(_operatorList, operatorName) ) {
      _indexSampler += _indentation + "results = results..., ( _generate_indices_from_" +
        operatorName + "(" + separateByComma(indices) + "; parameters = parameters) )...\n";
    }
  }

  return visitChildren(ctx);
}