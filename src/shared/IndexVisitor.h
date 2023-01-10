#pragma once

#include <vector>
#include <string>

#include <antlr4-runtime.h>
#include "QDSLParserBaseVisitor.h"

namespace qdsl {

class IndexVisitor : public QDSLParserBaseVisitor {
private:
  std::string _indexSampler;
  std::string _indentation;

  std::vector<std::string> _parameters;
  std::string _parameterCheck;
  void _generateParameterCheck();

  std::vector<std::string> _subsystems;

  std::vector<std::string> _operatorList;
  std::vector<std::string> _simpleOperatorGenerators;

public:
  antlrcpp::Any visitMain(                QDSLParser::MainContext                 *ctx);
  antlrcpp::Any visitParameters(          QDSLParser::ParametersContext           *ctx);
  antlrcpp::Any visitSubsystems(          QDSLParser::SubsystemsContext           *ctx);
  antlrcpp::Any visitSimpleDefinition(    QDSLParser::SimpleDefinitionContext     *ctx);
  antlrcpp::Any visitIndexedDefinition(   QDSLParser::IndexedDefinitionContext    *ctx);
  antlrcpp::Any visitSumExpression(       QDSLParser::SumExpressionContext        *ctx);
  antlrcpp::Any visitElementaryExpression(QDSLParser::ElementaryExpressionContext *ctx);

  std::string getIndexSampler() { return _indexSampler; };
  std::vector<std::string> getSimpleOperators() { return _simpleOperatorGenerators; };
};

} // namespace qdsl