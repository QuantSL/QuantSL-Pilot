#pragma once

#include <vector>
#include <string>

#include <antlr4-runtime.h>
#include "QDSLParserBaseVisitor.h"

namespace qdsl {

class  QODefinitionVisitor : public qdsl::QDSLParserBaseVisitor {
private:
  const std::string _basisAndOperators = "\tindices = _generate_indices(parameters = parameters)\n"
    "\tbasis = reduce( ⊗, repeat( [SpinBasis(1//2)], length(indices) ) )\n\n"
    "\tindexDict = Dict(key => val for (val, key) in enumerate(indices))\n\n"
    "\toperators = [f(SpinBasis(1//2)) for f in (sigmax, sigmay, sigmaz, sigmap, sigmam)]\n\n";

  std::string _definitions;
  std::string _userDefinitions;
  std::vector<std::string> _requiredOperators;
  std::string _expression;
  std::string _indentation;
  void _generateFunctionHeader(std::string operatorName);
  void _generateRequiredOperators();

  std::vector<std::string> _parameters;
  std::string _parameterCheck;
  void _generateParameterCheck();

  std::vector<std::string> _subsystems;

  std::vector<std::string> _operatorList;

public:
  antlrcpp::Any visitParameters(          QDSLParser::ParametersContext           *ctx);
  antlrcpp::Any visitSubsystems(          QDSLParser::SubsystemsContext           *ctx);
  antlrcpp::Any visitSimpleDefinition(    QDSLParser::SimpleDefinitionContext     *ctx);
  antlrcpp::Any visitIndexedDefinition(   QDSLParser::IndexedDefinitionContext    *ctx);
  antlrcpp::Any visitSumExpression(       QDSLParser::SumExpressionContext        *ctx);
  antlrcpp::Any visitElementaryExpression(QDSLParser::ElementaryExpressionContext *ctx);
  antlrcpp::Any visitSign(                QDSLParser::SignContext                 *ctx);
  antlrcpp::Any visitArithmethic(         QDSLParser::ArithmethicContext          *ctx);

  std::string getDefinitions()     { return _definitions; }
  std::string getUserDefinitions() { return _userDefinitions; }
  std::string generateOperatorContainer();
  std::string generateSystem();
};

} // namespace qdsl