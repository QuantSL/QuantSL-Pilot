#include <iostream>
#include <antlr4-runtime.h>
#include "QOLexer.h"
#include "QOParser.h"

#include "QOVisitor.h"

int main(int argc, const char* argv[]) {
  std::ifstream stream;
  stream.open("../../../qobj examples/test.qobj");

  antlr4::ANTLRInputStream input(stream);
  qoptic::QOLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  qoptic::QOParser parser(&tokens);

  qoptic::QOVisitor qovisitor;
  qovisitor.visitMain(parser.main());

  std::cout << "Parsed parameters:\n";
  for(auto parameter : qovisitor.getParameters()) {
    std::cout << parameter << std::endl;
  }

  std::cout << "\nParsed subsystems:\n";
  for(auto parameter : qovisitor.getSubsystems()) {
    std::cout << parameter << std::endl;
  }

  std::cout << "\nParsed definitions:\n";
  for(auto object : qovisitor.getObjects()) {
    std::cout << object << std::endl;
  }

  std::cout << "\nParsed indexed definitions:\n";
  for(auto object : qovisitor.getIndexObjects()) {
    std::cout << object << std::endl;
  }

  return 0;
}
