#pragma once

#include <vector>
#include <string>

#include <antlr4-runtime.h>
#include "QDSLParserBaseVisitor.h"

namespace qdsl {

class  ITensorValidationVisitor : public qdsl::QDSLParserBaseVisitor {
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

  antlrcpp::Any visitLine(QDSLParser::LineContext *ctx) { _lineNumber++;  return visitChildren(ctx); }
  antlrcpp::Any visitParameters(          QDSLParser::ParametersContext           *ctx);
  antlrcpp::Any visitSubsystems(          QDSLParser::SubsystemsContext           *ctx);
  antlrcpp::Any visitDefinitionLine(      QDSLParser::DefinitionLineContext       *ctx);
  antlrcpp::Any visitSimpleDefinition(    QDSLParser::SimpleDefinitionContext     *ctx);
  antlrcpp::Any visitIndexedDefinition(   QDSLParser::IndexedDefinitionContext    *ctx);
  antlrcpp::Any visitElementaryExpression(QDSLParser::ElementaryExpressionContext *ctx);
  antlrcpp::Any visitSumExpression(       QDSLParser::SumExpressionContext        *ctx);

  std::vector<std::string> getParameters()       { return _parameters; }
  std::vector<std::string> getSubsystems()       { return _subsystems; }
  std::vector<std::string> getOperators()        { return _operators; };
  std::vector<std::string> getIndexedOperators() { return _indexedOperators; };
  std::vector<std::string> getOperatorsDebug();
  std::vector<std::string> getIndexedOperatorsDebug();
};

} // namespace qdsl