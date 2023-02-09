#include "ITensorDefinitionVisitor.h"

#include "../../shared/StringTools.h"

void qdsl::ITensorDefinitionVisitor::_generateParameterCheck() {
  _parameterCheck = std::string("\tfor parameter in [" +
    separateByComma(toSymbol(stripCurlyBraces(_parameters))) +
    "] # Check if all parameters are defined\n"
    "\t\t!haskey(parameters, parameter) && error(\"Parameter $parameter not defined\")\n"
    "\tend\n\n");
}

void qdsl::ITensorDefinitionVisitor::_newExpressionSetup() {
  _arithmeticLocation.clear();
  _expressionRegister.clear();
  _arithmeticRegister.clear();
  _code = ""; _requiredOperators.clear();
}

void qdsl::ITensorDefinitionVisitor::_generateExpression() {
  _expressionRegister.push_back("");
  _argumentList.clear();
  std::string indexedOperatorSum;

  for (auto arithmeticExpression : _arithmeticRegister.back()) {
    addUnique(_argumentList, arithmeticExpression.parameters);
    indexedOperatorSum = "os" + separateByUnderscore(arithmeticExpression.identifier);
    if ( !arithmeticExpression.parameters.empty() ) {
      indexedOperatorSum += "(" + separateByComma(arithmeticExpression.parameters) + ")";
    }
    _expressionRegister.back() += indexedOperatorSum + arithmeticExpression.separator;
    _code += "\t" + indexedOperatorSum + " = OpSum() + " + arithmeticExpression.expression + "\n";
  }

  _arithmeticRegister.pop_back();
}

void qdsl::ITensorDefinitionVisitor::_generateDefinition() {
  _generateRequiredOperators();
  _code += "\treturn ";
  if ( !_argumentList.empty() ) _code += "(" + separateByComma(_argumentList) + ") -> ";
  _code += "OpSum() + " + _expressionRegister[0] + "\nend\n\n";
  _definitions     += _code;
  _userDefinitions += _code;
}

void qdsl::ITensorDefinitionVisitor::_generateFunctionHeader(std::string operatorName) {
  // Generate function header and necessary objects, check parameters
  _definitions += "function _generate_" + operatorName + "(; indexDict, parameters::Dict)\n";
  // parameter check occurs only when generating entire system

  _userDefinitions += "function generate_" + operatorName + "(; parameters::Dict)\n";
  _userDefinitions += _parameterCheck;
  _userDefinitions += _basisAndOperators;
}

void qdsl::ITensorDefinitionVisitor::_generateRequiredOperators() {
  if ( _requiredOperators.empty() ) return;

  std::string requiredOperators = "";
  for (auto requiredOperator : _requiredOperators) {
    requiredOperators += "\t" + requiredOperator + " = _generate_" + requiredOperator +
      "(; indexDict = indexDict, parameters = parameters)\n";
  }

  _definitions     += requiredOperators + "\n";
  _userDefinitions += requiredOperators + "\n";
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitParameters(QDSLParser::ParametersContext *ctx) {
  for (auto parameter : ctx->elements) {
    _parameters.push_back( stripCurlyBraces( parameter->getText() ) );
  }
  _generateParameterCheck();

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitSubsystems(QDSLParser::SubsystemsContext *ctx) {
  for (auto subsystem : ctx->elements) {
    _subsystems.push_back(subsystem->getText());
  }

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitSimpleDefinition(QDSLParser::SimpleDefinitionContext *ctx) {
  _newExpressionSetup();

  std::string operatorName = stripCurlyBraces(ctx->object->getText());
  _operatorList.push_back(operatorName);
  _generateFunctionHeader(operatorName);

  // Generate function body
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  // _argumentList.clear();
  _generateDefinition();
  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitIndexedDefinition(QDSLParser::IndexedDefinitionContext *ctx) {
  _newExpressionSetup();

  std::string operatorName = stripCurlyBraces(ctx->object->getText());
  _operatorList.push_back(operatorName);
  _generateFunctionHeader(operatorName);

  // Generate function body
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  // _argumentList.clear();
  // for ( auto index : ctx->botindex()->indices ) _argumentList.push_back(index->getText());
  _generateDefinition();
  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitExpression(QDSLParser::ExpressionContext *ctx) {
  _arithmeticLocation.push_back(0);
  _arithmeticRegister.push_back(std::vector<ArithmeticExpression>());
  mode = ParseMode::expressionParse;

  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _generateExpression();
  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitSumExpression(QDSLParser::SumExpressionContext *ctx) {
  ++_arithmeticLocation.back();

  std::vector<std::string> indices;
  for ( auto index : ctx->boundary->botindex()->indices ) indices.push_back(index->getText());
  std::string upperBound = ctx->boundary->topindex()->index->getText();

  // Sum open
  _arithmeticRegister.back().push_back( ArithmeticExpression(_arithmeticLocation) );
  std::string indentation("\t");
  for (int i = 0; i < indices.size(); i++) {
    indentation += "\t";
    _arithmeticRegister.back().back().expression += "sum(" + indices[i] + " -> \n" + indentation;
  }

  // Sum body, Further Parse Tree
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _arithmeticRegister.back().back().expression += _expressionRegister.back();
  for ( auto argument : _argumentList ) {
    if ( !contains(indices, argument) ) _arithmeticRegister.back().back().parameters.push_back(argument);
  }
  _expressionRegister.pop_back();
  _arithmeticLocation.pop_back();

  // Sum close
  for (int i = 0; i < indices.size(); i++) {
    indentation = indentation.substr(1);
    _arithmeticRegister.back().back().expression += ", [1:" +
      (isNumber(upperBound) ? upperBound : "parameters[:" + upperBound + "]") +
      ";]\n" + indentation + ")";
  }

  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitArithmeticExpression(QDSLParser::ArithmeticExpressionContext *ctx){
  ++_arithmeticLocation.back();
  mode = ParseMode::arithmeticParse;

  _arithmeticRegister.back().push_back( ArithmeticExpression(_arithmeticLocation) );

  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  mode = ParseMode::expressionParse;
  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitElementaryExpression(QDSLParser::ElementaryExpressionContext *ctx) {
  std::vector<std::string> indices;
  if (ctx->botindex() != nullptr) {
    for ( auto index : ctx->botindex()->indices ) {
      std::string indexName = index->getText();
      if ( !contains(_arithmeticRegister.back().back().parameters, indexName) &&
           !contains(_subsystems, indexName) ) {
        _arithmeticRegister.back().back().parameters.push_back(indexName);
      }
      indices.push_back(formatIndex(_subsystems, indexName));
    }
  }

  std::string expression("");
  if (ctx->SIGMA() != nullptr) {
    expression += std::string() + "Op(\"S" + ctx->SIGMA()->getText().back() + "\", indexDict[";
    if      ( indices.size() == 0 ) expression += "1])";
    else if ( indices.size() == 1 ) expression += indices[0] + "])";
    else                            expression += "(" + separateByComma(indices) + ")])";
  }
  else if ((ctx->SYMBOLNAME() != nullptr)) {
    std::string symbolName = stripCurlyBraces( ctx->SYMBOLNAME()->getText() );
    if ( contains(_parameters, symbolName) ) expression += "parameters[:" + symbolName + "]";
    else {
      if ( !contains(_requiredOperators, symbolName) ) _requiredOperators.push_back(symbolName);
      expression += symbolName;
      if ( !indices.empty() ) expression += "(" + separateByComma(indices) + ")";
    }
  }
  else {
    expression += "(";
    antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
    // TODO: here shall be the operator sums of the children
    expression += ")";
    return visitedChildrenReturn;
  }

  _arithmeticRegister.back().back().expression += expression;
  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitSign(QDSLParser::SignContext *ctx) {
  if ( ctx->SUB() != nullptr ) _arithmeticRegister.back().back().expression += "-1 * ";
  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitArithmethic(QDSLParser::ArithmethicContext *ctx) {
  if ( mode == ParseMode::expressionParse ) {
    if ( ctx->getText() == "^" ) _arithmeticRegister.back().back().separator += ctx->getText();
    else _arithmeticRegister.back().back().separator += " " + ctx->getText() + " ";
  }
  else if ( mode == ParseMode::arithmeticParse ) {
    if ( ctx->getText() == "^" ) _arithmeticRegister.back().back().expression += ctx->getText();
    else _arithmeticRegister.back().back().expression += " " + ctx->getText() + " ";
  }
  return visitChildren(ctx);
}

std::string qdsl::ITensorDefinitionVisitor::generateOperatorContainer() {
  std::string container = "struct OperatorContainer\n";
  for (auto operatorName : _operatorList) {
    container += "\t" + stripCurlyBraces(operatorName) + "\n";
  }
  container += "end\n\n";
  return container;
}

std::string qdsl::ITensorDefinitionVisitor::generateSystem() {
  std::string generateSystem = "function generateSystem(; parameters::Dict)\n";
  generateSystem += _parameterCheck;
  generateSystem += _basisAndOperators;

  generateSystem += "\tOperatorContainer(";
  std::vector<std::string> operatorGenerators;
  for (auto operatorName : _operatorList) {
    operatorGenerators.push_back( "\n\t\t_generate_" + stripCurlyBraces(operatorName) +
      "(indexDict = indexDict, parameters = parameters)" );
  }
  generateSystem += separateByComma(operatorGenerators);
  generateSystem += "\n\t)\nend\n\n";
  return generateSystem;
}