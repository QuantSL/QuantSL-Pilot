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
  _arithmethicLocation = std::vector<int>(1, 0);
  _expressionRegister.clear();
  _arithmethicRegister.clear();
  _indicesStack.clear();
  _indentation = "\t"; _expression = ""; _requiredOperators.clear();

  std::string operatorName = stripCurlyBraces(ctx->object->getText());
  _operatorList.push_back(operatorName);
  _generateFunctionHeader(operatorName);

  // Generate function body
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  for (int i = _arithmethicRegister.size() - 1; i >= 0; i--) {
    for (auto op : _arithmethicRegister[i]) _expression += op + "\n";
  }
  _expression += "\treturn OpSum() + " + _expressionRegister[0] + "\nend\n\n";

  // Generate required operators and add expression to definitions
  _generateRequiredOperators();
  _definitions     += _expression;
  _userDefinitions += _expression;

  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitIndexedDefinition(QDSLParser::IndexedDefinitionContext *ctx) {
  _arithmethicLocation = std::vector<int>(1, 0);
  _expressionRegister.clear();
  _arithmethicRegister.clear();
  _indicesStack.clear();
  _indentation = "\t"; _expression = ""; _requiredOperators.clear();

  std::string operatorName = stripCurlyBraces(ctx->object->getText());
  _operatorList.push_back(operatorName);
  _generateFunctionHeader(operatorName);

  // Generate function body
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  for (int i = _arithmethicRegister.size() - 1; i >= 0; i--) {
    for (auto op : _arithmethicRegister[i]) _expression += op + "\n";
  }
  stds::vector<std::string> argumentList = std::vector<std::string>();
  for ( auto index : ctx->botindex()->indices ) argumentList.push_back(index->getText());
  _expression += "\treturn (" + separateByComma(argumentList) + ") -> OpSum() + " + _expressionRegister[0] + "\nend\n\n";

  // Generate required operators and add expression to definitions
  _generateRequiredOperators();
  _definitions     += _expression;
  _userDefinitions += _expression;

  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitExpression(QDSLParser::ExpressionContext *ctx) {
  _arithmethicRegister.push_back(std::vector<std::string>());
  _indicesStack.push_back(std::vector<std::string>());

  std::string prefix = separateByUnderscore<int>(_arithmethicLocation),
    arguments = separateByComma(_argumentList);
  prefix = prefix.substr(0, prefix.size() - 1);

  _expressionRegister.push_back("os" + prefix + "1(" + arguments + ")");
  for (int i = 0; i < ctx->arithmethic().size(); i++) {
    _expressionRegister.back() += " " + ctx->arithmethic(i)->getText() + " " +
      "os" + prefix + std::to_string(i + 2) + "(" + arguments + ")";
  }

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitSumExpression(QDSLParser::SumExpressionContext *ctx) {
  ++_arithmethicLocation.back();

  std::vector<std::string> indices;
  for ( auto index : ctx->boundary->botindex()->indices ) indices.push_back(index->getText());
  std::string upperBound = ctx->boundary->topindex()->index->getText();

  // Sum open
  _arithmethicRegister.back().push_back(
    _indentation + "os" + separateByUnderscore<int>(_arithmethicLocation) + "(" +
    separateByComma(_argumentList) + ") = OpSum() + "
  );
  for (int i = 0; i < indices.size(); i++) {
    _indentation += "\t";
    _arithmethicRegister.back().back() += "sum(" + indices[i] + " -> \n" + _indentation;
  }

  // Sum body, Further Parse Tree
  size_t currentPos = _arithmethicRegister.size() - 1;
  _arithmethicLocation.push_back(0);
  antlrcpp::Any visitedChildrenReturn = visitChildren(ctx);
  _arithmethicRegister[currentPos].back() += _expressionRegister.back();
  std::cout << _expressionRegister.back() << std::endl;
  _expressionRegister.pop_back();
  _arithmethicLocation.pop_back();

  // Sum close
  for (int i = 0; i < indices.size(); i++) {
    _indentation = _indentation.substr(1);
    _arithmethicRegister[currentPos].back() += ", [1:" +
      (isNumber(upperBound) ? upperBound : "parameters[:" + upperBound + "]") +
      ";]\n" + _indentation + ")";
  }

  return visitedChildrenReturn;
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitArithmeticExpression(QDSLParser::ArithmeticExpressionContext *ctx){
  ++_arithmethicLocation.back();

  _arithmethicRegister.back().push_back(
    _indentation + "os" + separateByUnderscore<int>(_arithmethicLocation) + "(" +
    separateByComma(_argumentList) + ") = OpSum() + "
  );

  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitElementaryExpression(QDSLParser::ElementaryExpressionContext *ctx) {
  std::vector<std::string> indices;
  if (ctx->botindex() != nullptr) {
    for ( auto index : ctx->botindex()->indices ) {
      std::string indexName = index->getText();
      indices.push_back( formatIndex(_subsystems, indexName) );
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

  _arithmethicRegister.back().back() += expression;
  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitSign(QDSLParser::SignContext *ctx) {
  if ( ctx->SUB() != nullptr ) _arithmethicRegister.back().back() += "-1 * ";
  return visitChildren(ctx);
}

antlrcpp::Any qdsl::ITensorDefinitionVisitor::visitArithmethic(QDSLParser::ArithmethicContext *ctx) {
  if ( ctx->getText() == "^" ) _arithmethicRegister.back().back() += ctx->getText();
  else _arithmethicRegister.back().back() += " " + ctx->getText() + " ";

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
      "(basis = basis, indexDict = indexDict, parameters = parameters)" );
  }
  generateSystem += separateByComma(operatorGenerators);
  generateSystem += "\n\t)\nend\n\n";
  return generateSystem;
}