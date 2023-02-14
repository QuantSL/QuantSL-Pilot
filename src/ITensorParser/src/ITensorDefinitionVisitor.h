#pragma once

#include <vector>
#include <string>

#include <antlr4-runtime.h>
#include "QDSLParserBaseVisitor.h"

namespace qdsl {

struct ArithmeticExpression {
  std::vector<int> identifier;
  std::vector<std::string> parameters;
  std::string expression;

  ArithmeticExpression(std::vector<int> _identifier) : identifier(_identifier), expression("OpSum() + ") {}
};

class ITensorDefinitionVisitor : public qdsl::QDSLParserBaseVisitor {
private:
  const std::string _basisAndOperators = "\tindices = _generate_indices(parameters = parameters)\n"
    "\tindexDict = Dict(key => val for (val, key) in enumerate(indices))\n\n";

  std::string _code;
  std::string _definitions;
  std::string _userDefinitions;
  std::vector<std::string> _requiredOperators;

  std::vector<int> _arithmeticLocation;
  std::vector<std::string> _argumentList;
  std::vector<ArithmeticExpression> _arithmeticRegister;
  bool hasIntermediates = false;

  std::vector<std::string> _parameters;
  std::string _parameterCheck;
  void _generateParameterCheck();

  void _newExpressionSetup(std::string operatorName);
  std::string _generateIntermediateExpression();
  void _generateDefinition();
  void _generateFunctionHeader(std::string operatorName);
  void _generateRequiredOperators();

  std::vector<std::string> _subsystems;

  std::vector<std::string> _operatorList;

public:
  antlrcpp::Any visitParameters(          QDSLParser::ParametersContext           *ctx);
  antlrcpp::Any visitSubsystems(          QDSLParser::SubsystemsContext           *ctx);
  antlrcpp::Any visitSimpleDefinition(    QDSLParser::SimpleDefinitionContext     *ctx);
  antlrcpp::Any visitIndexedDefinition(   QDSLParser::IndexedDefinitionContext    *ctx);
  antlrcpp::Any visitExpression(          QDSLParser::ExpressionContext           *ctx);
  antlrcpp::Any visitSumExpression(       QDSLParser::SumExpressionContext        *ctx);
  antlrcpp::Any visitArithmeticExpression(QDSLParser::ArithmeticExpressionContext *ctx);
  antlrcpp::Any visitElementaryExpression(QDSLParser::ElementaryExpressionContext *ctx);
  antlrcpp::Any visitSign(                QDSLParser::SignContext                 *ctx);
  antlrcpp::Any visitArithmethic(         QDSLParser::ArithmethicContext          *ctx);

  std::string getDefinitions()     { return _definitions; }
  std::string getUserDefinitions() { return _userDefinitions; }
  std::string generateOperatorContainer();
  std::string generateSystem();
};

} // namespace qdsl