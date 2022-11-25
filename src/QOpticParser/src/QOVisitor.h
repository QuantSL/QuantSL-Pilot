#include <vector>
#include <string>

#include <antlr4-runtime.h>
#include "QOParserBaseVisitor.h"

namespace qoptic {

class  QOVisitor : public qoptic::QOParserBaseVisitor {
private:
  std::vector<std::string> _parameters;
  std::vector<std::string> _indices;

  std::vector<std::string> _objects;
  std::vector<std::string> _objectDefinitions;

  std::vector<std::string> _indexObjects;
  std::vector<std::string> _indexObjectDefinitions;
  std::vector<std::vector<std::string>> _indicesRegister;

public:
  antlrcpp::Any visitParameters(       qoptic::QOParser::ParametersContext        *ctx);
  antlrcpp::Any visitIndices(          qoptic::QOParser::IndicesContext           *ctx);
  antlrcpp::Any visitSimpleDefinition( qoptic::QOParser::SimpleDefinitionContext  *ctx);
  antlrcpp::Any visitIndexedDefinition(qoptic::QOParser::IndexedDefinitionContext *ctx);

  std::vector<std::string> getParameters() { return _parameters; }
  std::vector<std::string> getIndices()    { return _indices; }
  std::vector<std::string> getObjects();
  std::vector<std::string> getIndexObjects();
};

}  // namespace qoptic