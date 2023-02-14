#include "ITensorDefinitionVisitor.h"
#include <iostream>

#include "../../shared/StringTools.h"

void qdsl::ITensorDefinitionVisitor::_generateParameterCheck() {
  _parameterCheck = std::string("\tfor parameter in [" +
    separateByComma(toSymbol(stripCurlyBraces(_parameters))) +
    "] # Check if all parameters are defined\n"
    "\t\t!haskey(parameters, parameter) && error(\"Parameter $parameter not defined\")\n"
    "\tend\n\n");
}

void qdsl::ITensorDefinitionVisitor::_newExpressionSetup(std::string operatorName) {
  _arithmeticLocation.clear();
  _arithmeticRegister.clear();
  _code = ""; _requiredOperators.clear();

  _operatorList.push_back(operatorName);
  _generateFunctionHeader(operatorName);
}

std::string qdsl::ITensorDefinitionVisitor::_generateIntermediateExpression() {
  _argumentList.clear(); hasIntermediates = true;
  std::string intermediateExpression = "";

  ArithmeticExpression arithmeticExpression = _arithmeticRegister.back();
  intermediateExpression += "os" + separateByUnderscore(arithmeticExpression.identifier);
  if ( !arithmeticExpression.parameters.empty() ) {
    intermediateExpression += "(" + separateByComma(arithmeticExpression.parameters) + ")";
    addUnique(_argumentList, arithmeticExpression.parameters);
  }
  _code += "\t" + intermediateExpression + " = " + arithmeticExpression.expression + "\n";

  _arithmeticRegister.pop_back();
  return intermediateExpression;
}

void qdsl::ITensorDefinitionVisitor::_generateDefinition() {
  _generateRequiredOperators();
  _code += hasIntermediates ? "\n\treturn " : "\treturn ";
  if ( !_argumentList.empty() ) _code += "(" + separateByComma(_argumentList) + ") -> ";
  _code += _arithmeticRegister[0].expression + "\nend\n\n";
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
      "(; indexDict = indexDict, parameters = parameters)\n\n";
  }

  _definitions     += requiredOperators;
  _userDefinitions += requiredOperators;
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
  _newExpressionSetup( stripCurlyBraces(ctx->object->getText()) );

  // Generate function body
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _argumentList.clear();
  _generateDefinition();
  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitIndexedDefinition(QDSLParser::IndexedDefinitionContext *ctx) {
  _newExpressionSetup( stripCurlyBraces(ctx->object->getText()) );

  // Generate function body
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _argumentList.clear();
  for ( auto index : ctx->botindex()->indices ) _argumentList.push_back( index->getText() );
  _generateDefinition();
  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitExpression(QDSLParser::ExpressionContext *ctx) {
  _arithmeticLocation.push_back(1);
  _arithmeticRegister.push_back(ArithmeticExpression(_arithmeticLocation));

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitSumExpression(QDSLParser::SumExpressionContext *ctx) {
  std::vector<std::string> indices;
  for ( auto index : ctx->boundary->botindex()->indices ) indices.push_back(index->getText());
  std::string upperBound = ctx->boundary->topindex()->index->getText();

  // Sum open
  std::string indentation("\t");
  for (int i = 0; i < indices.size(); i++) {
    indentation += "\t";
    _arithmeticRegister.back().expression += "sum(" + indices[i] + " -> \n" + indentation;
  }

  // Sum body, Further Parse Tree
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _arithmeticRegister.back().expression += _generateIntermediateExpression();
  for ( auto argument : _argumentList ) {
    if ( !contains(indices, argument) ) _arithmeticRegister.back().parameters.push_back(argument);
  }

  // Sum close
  for (int i = 0; i < indices.size(); i++) {
    indentation = indentation.substr(1);
    _arithmeticRegister.back().expression += ", [1:" +
      (isNumber(upperBound) ? upperBound : "parameters[:" + upperBound + "]") +
      ";]\n" + indentation + ")";
  }

  ++_arithmeticLocation.back();
  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitArithmeticExpression(QDSLParser::ArithmeticExpressionContext *ctx){
  ++_arithmeticLocation.back();
  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitElementaryExpression(QDSLParser::ElementaryExpressionContext *ctx) {
  std::vector<std::string> indices;
  if (ctx->botindex() != nullptr) {
    for ( auto index : ctx->botindex()->indices ) {
      std::string indexName = index->getText();
      if ( !contains(_arithmeticRegister.back().parameters, indexName) &&
           !contains(_subsystems, indexName) ) {
        _arithmeticRegister.back().parameters.push_back(indexName);
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

  _arithmeticRegister.back().expression += expression;
  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitSign(QDSLParser::SignContext *ctx) {
  if ( ctx->SUB() != nullptr ) _arithmeticRegister.back().expression += "-1 * ";
  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitArithmethic(QDSLParser::ArithmethicContext *ctx) {
  if ( ctx->getText() == "^" ) _arithmeticRegister.back().expression += "^";
  else if ( ctx->getText() == "*" ) _arithmeticRegister.back().expression += " × "; // Custom Operator defined in 'CodeGen.cpp'
  else _arithmeticRegister.back().expression += " " + ctx->getText() + " ";
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