#include <iostream>
#include <antlr4-runtime.h>
#include "QDSLLexer.h"
#include "QDSLParser.h"

#include "QOValidationVisitor.h"
#include "QOCodeGen.h"

int main(int argc, const char* argv[]) {
  std::ifstream stream;
  stream.open("../../../qobj examples/test.qobj");

  antlr4::ANTLRInputStream input(stream);
  qdsl::QDSLLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  qdsl::QDSLParser parser(&tokens);

  qdsl::QOValidationVisitor qovisitor;
  try {
    qovisitor.visitMain(parser.main());
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
    return -1;
  }
  
  std::cout << "Parsed parameters:\n";
  for(auto parameter : qovisitor.getParameters()) {
    std::cout << parameter << std::endl;
  }

  std::cout << "\nParsed subsystems:\n";
  for(auto parameter : qovisitor.getSubsystems()) {
    std::cout << parameter << std::endl;
  }

  std::cout << "\nParsed definitions:\n";
  for(auto object : qovisitor.getOperatorsDebug()) {
    std::cout << object << std::endl;
  }

  std::cout << "\nParsed indexed definitions:\n";
  for(auto object : qovisitor.getIndexedOperatorsDebug()) {
    std::cout << object << std::endl;
  }

  return qdsl::generateCode("../../QuantumOpticsTest.jl", parser);
}
