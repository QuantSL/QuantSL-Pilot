
// Generated from QOParser.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "QOParserVisitor.h"


namespace qoptic {

/**
 * This class provides an empty implementation of QOParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  QOParserBaseVisitor : public QOParserVisitor {
public:

  virtual antlrcpp::Any visitMain(QOParser::MainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLine(QOParser::LineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterLine(QOParser::ParameterLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameters(QOParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitionLine(QOParser::DefinitionLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleDefinition(QOParser::SimpleDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexedDefinition(QOParser::IndexedDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(QOParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBotindex(QOParser::BotindexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTopindex(QOParser::TopindexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSumexpression(QOParser::SumexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSumindices(QOParser::SumindicesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSign(QOParser::SignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArtimethic(QOParser::ArtimethicContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace qoptic
