#pragma once

#include <vector>
#include <string>

#include <antlr4-runtime.h>
#include "QDSLParserBaseVisitor.h"

namespace qdsl {

class ITensorDefinitionVisitor : public qdsl::QDSLParserBaseVisitor {
private:
  const std::string _basisAndOperators = "\tindices = _generate_indices(parameters = parameters)\n"
    "\tindexDict = Dict(key => val for (val, key) in enumerate(indices))\n\n"
    "\toperators = [f(SpinBasis(1//2)) for f in (sigmax, sigmay, sigmaz, sigmap, sigmam)]\n\n";
  const std::string _basisAndOperatorsUser = "\tindices = _generate_indices(parameters = parameters)\n"
    "\tindexDict = Dict(key => val for (val, key) in enumerate(indices))\n\n";

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
  antlrcpp::Any visitMain(                qdsl::QDSLParser::MainContext                 *ctx);
  antlrcpp::Any visitParameters(          qdsl::QDSLParser::ParametersContext           *ctx);
  antlrcpp::Any visitSubsystems(          qdsl::QDSLParser::SubsystemsContext           *ctx);
  antlrcpp::Any visitSimpleDefinition(    qdsl::QDSLParser::SimpleDefinitionContext     *ctx);
  antlrcpp::Any visitIndexedDefinition(   qdsl::QDSLParser::IndexedDefinitionContext    *ctx);
  antlrcpp::Any visitSumExpression(       qdsl::QDSLParser::SumExpressionContext        *ctx);
  antlrcpp::Any visitElementaryExpression(qdsl::QDSLParser::ElementaryExpressionContext *ctx);
  antlrcpp::Any visitSign(                qdsl::QDSLParser::SignContext                 *ctx);
  antlrcpp::Any visitArithmethic(         qdsl::QDSLParser::ArithmethicContext          *ctx);

  std::string getDefinitions()     { return _definitions; };
  std::string getUserDefinitions() { return _userDefinitions; };
  std::string generateOperatorContainer();
  std::string generateSystem();
};

} // namespace qdsl