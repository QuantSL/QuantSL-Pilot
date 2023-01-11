#include "ITensorValidationVisitor.h"
#include <stdexcept>

#include "../../shared/StringTools.h"

antlrcpp::Any qdsl::ITensorValidationVisitor::visitParameters(QDSLParser::ParametersContext *ctx) {
  for (auto parameter : ctx->elements) {
    _parameters.push_back( stripCurlyBraces( parameter->getText() ) );
  }

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorValidationVisitor::visitSubsystems(QDSLParser::SubsystemsContext *ctx) {
  for (auto subsystem : ctx->elements) {
    _subsystems.push_back(subsystem->getText());
  }

  return visitChildren(ctx);
}


antlrcpp::Any qdsl::ITensorValidationVisitor::visitDefinitionLine(QDSLParser::DefinitionLineContext *ctx) {
  std::string expressionName = ctx->simpleDefinition() != nullptr ?
    ctx->simpleDefinition()->object->getText() :
    ctx->indexedDefinition()->object->getText();

  // Validate against redefinition
  if ( contains(_operators, expressionName) || contains(_indexedOperators, expressionName) ) {
    throw std::invalid_argument(
      "Expression error at line " + std::to_string(_lineNumber) + ":\n" +
      "Symbol '" + expressionName + "' was already defined and cannot be redefined."
    );
  }

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorValidationVisitor::visitSimpleDefinition(QDSLParser::SimpleDefinitionContext *ctx) {
  _operators.push_back( stripCurlyBraces( ctx->object->getText() ) );
  _currentIndices.clear();

  _operatorDefinitions.push_back(ctx->definition->getText());

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorValidationVisitor::visitIndexedDefinition(QDSLParser::IndexedDefinitionContext *ctx) {
  _indexedOperators.push_back( stripCurlyBraces( ctx->object->getText() ) );

  // Validate for correct indices
  _currentIndices.clear();
  for (auto index : ctx->botindex()->indices) {
    std::string indexName = index->getText();
    if ( contains(_subsystems, indexName) ) {
      throw std::invalid_argument(
        "Index error at line " + std::to_string(_lineNumber) + ":\n" +
        "Index '" + indexName + "' denotes a subsystem and cannot an argument of " +
        ctx->object->getText() + "."
      );
    }
    _currentIndices.push_back(indexName);
  }
  _indicesRegister.push_back(_currentIndices);

  _indexedOperatorDefinitions.push_back(ctx->definition->getText());

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorValidationVisitor::visitElementaryExpression(QDSLParser::ElementaryExpressionContext *ctx) {
  // Leave early if we have a bracketed expression or not an indexed expression
  if ( ctx->name == nullptr ) return visitChildren(ctx);

  // Validate existence of expression
  std::string expressionName = stripCurlyBraces( ctx->name->getText() );
  if ( !contains(elementaryOperators, expressionName) && !contains(_operators, expressionName) &&
       !contains(_indexedOperators,   expressionName) && !contains(_parameters, expressionName)) {
    throw std::invalid_argument(
      "Symbol error at line " + std::to_string(_lineNumber) + ":\n" +
      "Symbol '" + expressionName + "' is not defined."
    );
  }


  // Validate indices, then add to index list
  std::vector<std::string> indices;
  if ( ctx->botindex() != nullptr ) {
    for (auto index : ctx->botindex()->indices) { 
      std::string indexName = index->getText();
      // TODO: Check if index is just a number
      if ( !contains(_currentIndices, indexName) && !contains(_subsystems, indexName) ) {
        throw std::invalid_argument(
          "Index error at line " + std::to_string(_lineNumber) + " in expression: " + ctx->getText() + "\n" +
          "Index '" + indexName + "' is not defined."
        );
      }

      indices.push_back(formatIndex(_subsystems, indexName));
    }
  }

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorValidationVisitor::visitSumExpression(QDSLParser::SumExpressionContext *ctx) {
  // Store old indices and tree context
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
    
    indices.push_back(formatIndex(_subsystems, indexName));
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

  // Restore old indices and return
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _currentIndices = oldIndices;
  return visitedChildrenReturn;
}


std::vector<std::string> qdsl::ITensorValidationVisitor::getOperatorsDebug() {
  std::vector<std::string> results(_operators);
  for (int i = 0; i < results.size(); ++i) {
    results[i] += " = " + _operatorDefinitions[i];
  }

  return results;
}

std::vector<std::string> qdsl::ITensorValidationVisitor::getIndexedOperatorsDebug() {
  std::vector<std::string> results(_indexedOperators);
  for (int i = 0; i < results.size(); ++i) {
    results[i] += " = " + _indexedOperatorDefinitions[i] + "\t\tparsed indices: ";
    for (auto index : _indicesRegister[i]) results[i] += index + ", ";
  }

  return results;
}