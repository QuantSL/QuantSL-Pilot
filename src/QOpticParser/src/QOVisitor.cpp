#include "QOVisitor.h"
#include <string>
#include <stdexcept>

#include "StringTools.h"

antlrcpp::Any qoptic::QOVisitor::visitParameters(QOParser::ParametersContext *ctx) {
  for (auto parameter : ctx->elements) {
    _parameters.push_back(parameter->getText());
  }

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QOVisitor::visitSubsystems(QOParser::SubsystemsContext *ctx) {
  for (auto subsystem : ctx->elements) {
    _subsystems.push_back(subsystem->getText());
  }

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QOVisitor::visitSimpleDefinition(qoptic::QOParser::SimpleDefinitionContext *ctx) {
  _currentIndices.clear();

  _operators.push_back(ctx->object->getText());

  qoptic::DefinitionTree* tree = new qoptic::DefinitionTree(ctx->object->getText(), std::vector<std::string>());
  _definitionTrees.push_back(tree);
  _currentTreeContext = tree;

  for (auto definition : ctx->definitions) {
    _operatorDefinitions.push_back(definition->getText());
  }

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QOVisitor::visitIndexedDefinition(qoptic::QOParser::IndexedDefinitionContext *ctx) {
  _indexedOperators.push_back(ctx->object->getText());

  _currentIndices.clear();
  for (auto index : ctx->botindex()->indices) {
    std::string indexName = index->getText();
    if (qoptic::contains(_subsystems, indexName)) {
      throw std::invalid_argument(
        "Index error at line " + std::to_string(_lineNumber) + " in definition:\n" + ctx->getText() +
        "Index '" + indexName + "' denotes a subsystem and cannot an argument of " +
        ctx->object->getText() + "."
      );
    }
    _currentIndices.push_back(indexName);
  }
  _indicesRegister.push_back(_currentIndices);

  for (auto definition : ctx->definitions) {
    _indexedOperatorDefinitions.push_back(definition->getText());
  }

  qoptic::DefinitionTree* tree = new qoptic::DefinitionTree(ctx->object->getText(), _currentIndices);
  _definitionTrees.push_back(tree);
  _currentTreeContext = tree;

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QOVisitor::visitElementaryExpression(qoptic::QOParser::ElementaryExpressionContext *ctx) {
  // Leave early if we have a bracketed expression or not an indexed expression
  if ( ctx->name == nullptr || ctx->botindex() == nullptr ) return visitChildren(ctx);

  std::vector<std::string> indices;

  // Sanitise input, then add to indices
  for (auto index : ctx->botindex()->indices) { 
    std::string indexName = index->getText();
    // TODO: Check if index is just a number
    if ( !contains(_currentIndices, indexName) && !contains(_subsystems, indexName) ) {
      throw std::invalid_argument(
        "Index error at line " + std::to_string(_lineNumber) + " in expression:\n" + ctx->getText() + "\n" +
        "Index '" + indexName + "' is not defined."
      );
    }

    indices.push_back(qoptic::formatIndex(_subsystems, indexName));
  }

  std::string objectName = ctx->name->getText();
  if ( contains(elementaryOperators,  objectName) ) _currentTreeContext->addChildIndices(indices);
  else if ( contains(_indexedOperators, objectName ) ) _currentTreeContext->addChildOperator(objectName, indices);
  else if ( !contains(_operators, objectName ) ) {
    throw std::invalid_argument(
      "Object error at line " + std::to_string(_lineNumber) + " in expression:\n" + ctx->getText() + "\n" +
      "Object '" + ctx->name->getText() + "' is not defined."
    );
  }

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QOVisitor::visitSumExpression(qoptic::QOParser::SumExpressionContext *ctx) {
  // Store old indices and tree context
  BaseTree* oldTreeContext = _currentTreeContext;
  std::vector<std::string> oldIndices = _currentIndices;
  
  // Sanitise input, then add to indices
  std::vector<std::string> indices;
  for (auto index : ctx->sumindices()->botindex()->indices) {
    std::string indexName = index->getText();
    if ( contains(_currentIndices, indexName) ) {
      throw std::invalid_argument(
        "Summation index error at line " + std::to_string(_lineNumber) + " in expression:\n" + ctx->getText() + "\n" +
        "Summation index '" + indexName + "' already occurs in the object definition or in another sum."
      );
    }
    _currentIndices.push_back(indexName);
    
    indices.push_back(qoptic::formatIndex(_subsystems, indexName));
  }
  std::vector<std::string> lowerBounds(indices.size(), "1"); // TODO: Add support for integer bounds

  std::string upperBound = ctx->sumindices()->topindex()->index->getText();
  if ( !contains(_parameters, upperBound) && !isNumber(upperBound) ) {
    throw std::invalid_argument(
      "Summation index error at line " + std::to_string(_lineNumber) + " in expression:\n" + ctx->getText() + "\n" +
      "Summation index '" + upperBound + "' is not a defined parameter."
    );
  }
  std::vector<std::string> upperBounds(indices.size(), upperBound);

  SummationTree* tree = new SummationTree(indices, lowerBounds, upperBounds);
  _currentTreeContext->addChildTree(tree);
  _currentTreeContext = tree;
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);

  // Restore old indices and tree context, and return
  _currentIndices = oldIndices;
  _currentTreeContext = oldTreeContext;
  return visitedChildrenReturn;
}


std::vector<std::string> qoptic::QOVisitor::getOperatorsDebug() {
  std::vector<std::string> results(_operators);
  for (int i = 0; i < results.size(); ++i) {
    results[i] += " = " + _operatorDefinitions[i];
  }

  return results;
}

std::vector<std::string> qoptic::QOVisitor::getIndexedOperatorsDebug() {
  std::vector<std::string> results(_indexedOperators);
  for (int i = 0; i < results.size(); ++i) {
    results[i] += " = " + _indexedOperatorDefinitions[i] + "\t\tparsed indices: ";
    for (auto index : _indicesRegister[i]) results[i] += index + ", ";
  }

  return results;
}