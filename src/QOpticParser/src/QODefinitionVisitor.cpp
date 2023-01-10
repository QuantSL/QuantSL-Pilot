#include "QODefinitionVisitor.h"

#include "../../shared/StringTools.h"

void qdsl::QODefinitionVisitor::_generateParameterCheck() {
  _parameterCheck = std::string("\tfor parameter in [" +
    separateByComma(toSymbol(stripCurlyBraces(_parameters))) +
    "] # Check if all parameters are defined\n"
    "\t\t!haskey(parameters, parameter) && error(\"Parameter $parameter not defined\")\n"
    "\tend\n\n");
}

void qdsl::QODefinitionVisitor::_generateFunctionHeader(std::string operatorName) {
  // Generate function header and necessary objects, check parameters
  _definitions += "function _generate_" + operatorName + "(; basis, indexDict, operators, parameters::Dict)\n";
  _definitions += "\tσx, σy, σz, σp, σm = operators\n\n";

  _userDefinitions += "function generate_" + operatorName + "(; parameters::Dict)\n";
  _userDefinitions += _parameterCheck;
  _userDefinitions += _basisAndOperatorsUser;
}

void qdsl::QODefinitionVisitor::_generateRequiredOperators() {
  if ( _requiredOperators.empty() ) return;

  std::string requiredOperators = "";
  for (auto requiredOperator : _requiredOperators) {
    requiredOperators += "\t" + requiredOperator + " = _generate_" + requiredOperator +
      "(; basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)\n";
  }

  _definitions     += requiredOperators + "\n";
  _userDefinitions += requiredOperators + "\n";
}

antlrcpp::Any qdsl::QODefinitionVisitor::visitMain(QDSLParser::MainContext *ctx) {
  _definitions = "";

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::QODefinitionVisitor::visitParameters(QDSLParser::ParametersContext *ctx) {
  for (auto parameter : ctx->elements) {
    _parameters.push_back( stripCurlyBraces( parameter->getText() ) );
  }
  _generateParameterCheck();

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::QODefinitionVisitor::visitSubsystems(QDSLParser::SubsystemsContext *ctx) {
  for (auto subsystem : ctx->elements) {
    _subsystems.push_back(subsystem->getText());
  }

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::QODefinitionVisitor::visitSimpleDefinition(qdsl::QDSLParser::SimpleDefinitionContext *ctx) {
  _indentation = "\t"; _expression = ""; _requiredOperators.clear();
  std::string operatorName = stripCurlyBraces(ctx->object->getText());
  _operatorList.push_back(operatorName);

  _generateFunctionHeader(operatorName);

  // Generate function body
  _expression += "\treturn ";
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _expression += "\nend\n\n";

  // Generate required operators and add expression to definitions
  _generateRequiredOperators();
  _definitions     += _expression;
  _userDefinitions += _expression;

  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::QODefinitionVisitor::visitIndexedDefinition(qdsl::QDSLParser::IndexedDefinitionContext *ctx) {
  _indentation = "\t"; _expression = ""; _requiredOperators.clear();
  std::vector<std::string> indices;
  for ( auto index : ctx->botindex()->indices ) indices.push_back(index->getText());

  std::string operatorName = stripCurlyBraces(ctx->object->getText());
  _operatorList.push_back(operatorName);

  _generateFunctionHeader(operatorName);

  // Generate function body
  _expression += "\treturn (" + separateByComma(indices) + ") -> ";
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _expression += "\nend\n\n";

  // Generate required operators and add expression to definitions
  _generateRequiredOperators();
  _definitions     += _expression;
  _userDefinitions += _expression;

  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::QODefinitionVisitor::visitSumExpression(qdsl::QDSLParser::SumExpressionContext *ctx) {
  std::vector<std::string> indices;
  for ( auto index : ctx->boundary->botindex()->indices ) indices.push_back(index->getText());
  std::string upperBound = ctx->boundary->topindex()->index->getText();

  // Sum open
  std::string sumResult = "";
  for (int i = 0; i < indices.size(); i++) {
    _indentation += "\t";
    sumResult += "sum(" + indices[i] + " -> \n" + _indentation;
  }
  _expression += sumResult;

  // Further Parse Tree
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);

  // Sum close
  sumResult = "";
  for (int i = 0; i < indices.size(); i++) {
    _indentation = _indentation.substr(1);
    sumResult += ", [1:";
    sumResult += isNumber(upperBound) ? upperBound + ";]\n" + _indentation + ")" :
      "parameters[:" + upperBound + "];]\n" + _indentation + ")" ;
  }
  _expression += sumResult;

  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::QODefinitionVisitor::visitElementaryExpression(qdsl::QDSLParser::ElementaryExpressionContext *ctx) {
  std::vector<std::string> indices;
  if (ctx->botindex() != nullptr) {
    for ( auto index : ctx->botindex()->indices ) {
      std::string indexName = index->getText();
      if ( contains(_subsystems, indexName) ) indices.push_back(":" + indexName);
      else indices.push_back(indexName);
    }
  }

  if ( ctx->SIGMA() != nullptr ) {
    _expression += "embed(basis, indexDict[";
    if      ( indices.size() == 0 ) _expression += "1], σ";
    else if ( indices.size() == 1 ) _expression += indices[0] + "], σ";
    else                            _expression += "(" + separateByComma(indices) + ")], σ";
    _expression += ctx->SIGMA()->getText().back(); _expression += ")";
  }
  else if ( ctx->SYMBOLNAME() != nullptr ) {
    std::string symbolName = stripCurlyBraces( ctx->SYMBOLNAME()->getText() );
    if ( contains(_parameters, symbolName) ) _expression += "parameters[:" + symbolName + "]";
    else {
      if ( !contains(_requiredOperators, symbolName) ) _requiredOperators.push_back(symbolName);
      _expression += symbolName;
      if ( !indices.empty() ) _expression += "(" + separateByComma(indices) + ")";
    }
  }

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::QODefinitionVisitor::visitSign(qdsl::QDSLParser::SignContext *ctx) {
  _expression += ctx->getText() + " ";

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::QODefinitionVisitor::visitArithmethic(qdsl::QDSLParser::ArithmethicContext *ctx) {
  std::string arithmethicString = "";
  if ( ctx->getText() == "^" ) arithmethicString += ctx->getText();
  else arithmethicString += " " + ctx->getText() + " ";
  _expression += arithmethicString;

  return visitChildren(ctx);
}

std::string qdsl::QODefinitionVisitor::generateOperatorContainer() {
  std::string container = "struct OperatorContainer\n";
  for (auto operatorName : _operatorList) {
    container += "\t" + stripCurlyBraces(operatorName) + "\n";
  }
  container += "end\n\n";
  return container;
}

std::string qdsl::QODefinitionVisitor::generateSystem() {
  std::string generateSystem = "function generateSystem(; parameters::Dict)\n";
  generateSystem += _parameterCheck;
  generateSystem += _basisAndOperators;

  generateSystem += "\tOperatorContainer(";
  std::vector<std::string> operatorGenerators;
  for (auto operatorName : _operatorList) {
    operatorGenerators.push_back( "\n\t\t_generate_" + stripCurlyBraces(operatorName) +
      "(basis = basis, indexDict = indexDict, operators = operators, parameters = parameters)" );
  }
  generateSystem += separateByComma(operatorGenerators);
  generateSystem += "\n\t)\nend\n\n";
  return generateSystem;
}