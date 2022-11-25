#include <vector>
#include <string>

#include <antlr4-runtime.h>
#include "QOParserBaseVisitor.h"

namespace qoptic {

class  QOVisitor : public qoptic::QOParserBaseVisitor {
private:
  std::vector<std::string> _parameters;
  std::vector<std::string> _subsystems;

  std::vector<std::string> _objects;
  std::vector<std::string> _objectDefinitions;

  std::vector<std::string> _indexObjects;
  std::vector<std::string> _indexObjectDefinitions;
  std::vector<std::vector<std::string>> _indicesRegister;
  
  std::vector<std::string> _currentIndices;

public:
  antlrcpp::Any visitParameters(          qoptic::QOParser::ParametersContext           *ctx);
  antlrcpp::Any visitSubsystems(          qoptic::QOParser::SubsystemsContext           *ctx);
  antlrcpp::Any visitSimpleDefinition(    qoptic::QOParser::SimpleDefinitionContext     *ctx);
  antlrcpp::Any visitIndexedDefinition(   qoptic::QOParser::IndexedDefinitionContext    *ctx);
  antlrcpp::Any visitArithmeticexpression(qoptic::QOParser::ArithmeticexpressionContext *ctx);
  antlrcpp::Any visitSumexpression(       qoptic::QOParser::SumexpressionContext        *ctx);

  std::vector<std::string> getParameters() { return _parameters; }
  std::vector<std::string> getSubsystems() { return _subsystems; }
  std::vector<std::string> getObjects();
  std::vector<std::string> getIndexObjects();
};

}  // namespace qoptic