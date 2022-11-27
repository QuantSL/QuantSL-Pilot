#include "QOVisitor.h"
#include <string>
#include <algorithm>
#include <stdexcept>

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

  _objects.push_back(ctx->object->getText());

  for (auto definition : ctx->definitions) {
    _objectDefinitions.push_back(definition->getText());
  }

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QOVisitor::visitIndexedDefinition(qoptic::QOParser::IndexedDefinitionContext *ctx) {
  _indexObjects.push_back(ctx->object->getText());

  _currentIndices.clear();
  for (auto index : ctx->botindex()->indices) {
    _currentIndices.push_back(index->getText());
  }
  _indicesRegister.push_back(_currentIndices);

  for (auto definition : ctx->definitions) {
    _indexObjectDefinitions.push_back(definition->getText());
  }

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QOVisitor::visitArithmeticexpression(qoptic::QOParser::ArithmeticexpressionContext *ctx) {
  for (auto botIndeces : ctx->botindex()) {
    for (auto index : botIndeces->indices) { 
      std::string indexName = index->getText();
      if ( !std::any_of(_currentIndices.begin(), _currentIndices.end(), [&](auto comp) { return indexName==comp; })
        && !std::any_of(_subsystems.begin(),     _subsystems.end(),     [&](auto comp) { return indexName==comp; }) ) {
        throw std::invalid_argument(
          "Index error at line " + std::to_string(_lineNumber) + " in expression:\n" + ctx->getText() + "\n" +
          "Index '" + indexName + "' is not defined."
        );
      }
    }
  }

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QOVisitor::visitSumexpression(qoptic::QOParser::SumexpressionContext *ctx) {
  // Store old indices and add sum indices to the current lust
  std::vector<std::string> oldIndices = _currentIndices;
  for (auto index : ctx->sumindices()->botindex()->indices) {
    std::string indexName = index->getText();
    if ( std::any_of(_currentIndices.begin(), _currentIndices.end(), [&](auto comp) { return indexName==comp; }) ) {
      throw std::invalid_argument(
        "Index used multiple times at line " + std::to_string(_lineNumber) + ".\n" +
        "Summation index '" + indexName + "' already occurs in the object definition."
      );
    }
    _currentIndices.push_back(indexName);
  }

  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);

  _currentIndices = oldIndices; // Restore old indices

  return visitedChildrenReturn;
}


std::vector<std::string> qoptic::QOVisitor::getObjects() {
  std::vector<std::string> results(_objects);
  for (int i = 0; i < results.size(); ++i) {
    results[i] += " = " + _objectDefinitions[i];
  }

  return results;
}

std::vector<std::string> qoptic::QOVisitor::getIndexObjects() {
  // return _indexObjectDefinitions;
  std::vector<std::string> results(_indexObjects);
  for (int i = 0; i < results.size(); ++i) {
    results[i] += " = " + _indexObjectDefinitions[i] + "\t\tparsed indices: ";
    for (auto index : _indicesRegister[i]) results[i] += index + ", ";
  }

  return results;
}