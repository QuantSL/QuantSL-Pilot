#pragma once

#include <vector>
#include <string>

#include <antlr4-runtime.h>
#include "QOParserBaseVisitor.h"

namespace qoptic {

class  QODefinitionVisitor : public qoptic::QOParserBaseVisitor {
private:
  const std::string _basisAndOperators = "\tindices = _generate_indices(parameters = parameters)\n"
    "\tindexDict = Dict(key => val for (val, key) in enumerate(indices))\n\n"
    "\tbasis = reduce( ⊗, repeat( [SpinBasis(1//2)], length(indices) ) )\n\n"
    "\tσx, σy, σz, σp, σm = [f(SpinBasis(1//2)) for f in (sigmax, sigmay, sigmaz, sigmap, sigmam)]\n\n";

  std::string _definitions;
  std::string _indentation;

  std::vector<std::string> _parameters;
  std::string _parameterCheck;
  void _generateParameterCheck();

  std::vector<std::string> _subsystems;

  std::vector<std::string> _simpleOperatorGenerators;

public:
  antlrcpp::Any visitMain(                qoptic::QOParser::MainContext                 *ctx);
  antlrcpp::Any visitParameters(          qoptic::QOParser::ParametersContext           *ctx);
  antlrcpp::Any visitSubsystems(          qoptic::QOParser::SubsystemsContext           *ctx);
  antlrcpp::Any visitSimpleDefinition(    qoptic::QOParser::SimpleDefinitionContext     *ctx);
  antlrcpp::Any visitIndexedDefinition(   qoptic::QOParser::IndexedDefinitionContext    *ctx);
  antlrcpp::Any visitSumExpression(       qoptic::QOParser::SumExpressionContext        *ctx);
  antlrcpp::Any visitElementaryExpression(qoptic::QOParser::ElementaryExpressionContext *ctx);
  antlrcpp::Any visitSign(                qoptic::QOParser::SignContext                 *ctx);
  antlrcpp::Any visitArithmethic(         qoptic::QOParser::ArithmethicContext          *ctx);

  std::vector<std::string> getSimpleOperators() { return _simpleOperatorGenerators; };
};

} // namespace qoptic