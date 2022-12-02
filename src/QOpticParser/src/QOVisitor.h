#pragma once

#include <vector>
#include <string>

#include <antlr4-runtime.h>
#include "QOParserBaseVisitor.h"

namespace qoptic {

class  QOVisitor : public qoptic::QOParserBaseVisitor {
private:
  int _lineNumber = 0;

  std::vector<std::string> _parameters;
  std::vector<std::string> _subsystems;

  std::vector<std::string> _operators;
  std::vector<std::string> _operatorDefinitions;

  std::vector<std::string> _indexedOperators;
  std::vector<std::string> _indexedOperatorDefinitions;
  std::vector<std::vector<std::string>> _indicesRegister;

  std::vector<std::string> _currentIndices;

public:
  // TODO: let the elementary operators be defined by the user, by 'using Spin(1//2)' for example
  const std::vector<std::string> elementaryOperators { "σx", "σy", "σz", "sigmax", "sigmay", "sigmaz", "sigmap", "sigmam" };

  antlrcpp::Any visitLine(QOParser::LineContext *ctx) { _lineNumber++; return visitChildren(ctx); }
  antlrcpp::Any visitParameters(          qoptic::QOParser::ParametersContext           *ctx);
  antlrcpp::Any visitSubsystems(          qoptic::QOParser::SubsystemsContext           *ctx);
  antlrcpp::Any visitSimpleDefinition(    qoptic::QOParser::SimpleDefinitionContext     *ctx);
  antlrcpp::Any visitIndexedDefinition(   qoptic::QOParser::IndexedDefinitionContext    *ctx);
  antlrcpp::Any visitElementaryExpression(qoptic::QOParser::ElementaryExpressionContext *ctx);
  antlrcpp::Any visitSumExpression(       qoptic::QOParser::SumExpressionContext        *ctx);

  std::vector<std::string> getParameters()       { return _parameters; }
  std::vector<std::string> getSubsystems()       { return _subsystems; }
  std::vector<std::string> getOperators()        { return _operators; };
  std::vector<std::string> getIndexedOperators() { return _indexedOperators; };
  std::vector<std::string> getOperatorsDebug();
  std::vector<std::string> getIndexedOperatorsDebug();
};

} // namespace qoptic