#include "QOVisitor.h"
#include <string>

antlrcpp::Any qoptic::QOVisitor::visitParameters(QOParser::ParametersContext *ctx) {
  for (auto parameter : ctx->elements) {
    _parameters.push_back(parameter->getText());
  }

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QOVisitor::visitSimpleDefinition(qoptic::QOParser::SimpleDefinitionContext *ctx) {
  for (auto object : ctx->objects) {
    _objects.push_back(object->getText());
  }

  for (auto definition : ctx->definitions) {
    _objectDefinitions.push_back(definition->getText());
  }

  return visitChildren(ctx);
}

antlrcpp::Any qoptic::QOVisitor::visitIndexedDefinition(qoptic::QOParser::IndexedDefinitionContext *ctx) {
  for (auto object : ctx->objects) {
    _indexObjects.push_back(object->getText());
  }

  std::vector<std::string> indices;
  for (auto index : ctx->index()->elements) {
    indices.push_back(index->getText());
  }
  _indicesRegister.push_back(indices);

  for (auto definition : ctx->definitions) {
    _indexObjectDefinitions.push_back(definition->getText());
  }

  return visitChildren(ctx);
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