#pragma once

#include <vector>
#include <string>

#include <antlr4-runtime.h>
#include "QDSLParserBaseVisitor.h"

namespace qdsl {

class  ITensorIndexVisitor : public qdsl::QDSLParserBaseVisitor {
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
  antlrcpp::Any visitMain(                qdsl::QDSLParser::MainContext                 *ctx);
  antlrcpp::Any visitParameters(          qdsl::QDSLParser::ParametersContext           *ctx);
  antlrcpp::Any visitSubsystems(          qdsl::QDSLParser::SubsystemsContext           *ctx);
  antlrcpp::Any visitSimpleDefinition(    qdsl::QDSLParser::SimpleDefinitionContext     *ctx);
  antlrcpp::Any visitIndexedDefinition(   qdsl::QDSLParser::IndexedDefinitionContext    *ctx);
  antlrcpp::Any visitSumExpression(       qdsl::QDSLParser::SumExpressionContext        *ctx);
  antlrcpp::Any visitElementaryExpression(qdsl::QDSLParser::ElementaryExpressionContext *ctx);

  std::string getIndexSampler() { return _indexSampler; };
  std::vector<std::string> getSimpleOperators() { return _simpleOperatorGenerators; };
};

} // namespace qdsl