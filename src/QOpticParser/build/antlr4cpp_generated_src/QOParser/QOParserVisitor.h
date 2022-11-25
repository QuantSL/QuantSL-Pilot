
// Generated from QOParser.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "QOParser.h"


namespace qoptic {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by QOParser.
 */
class  QOParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by QOParser.
   */
    virtual antlrcpp::Any visitMain(QOParser::MainContext *context) = 0;

    virtual antlrcpp::Any visitLine(QOParser::LineContext *context) = 0;

    virtual antlrcpp::Any visitParameterLine(QOParser::ParameterLineContext *context) = 0;

    virtual antlrcpp::Any visitParameters(QOParser::ParametersContext *context) = 0;

    virtual antlrcpp::Any visitDefinitionLine(QOParser::DefinitionLineContext *context) = 0;

    virtual antlrcpp::Any visitSimpleDefinition(QOParser::SimpleDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitIndexedDefinition(QOParser::IndexedDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitExpression(QOParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBotindex(QOParser::BotindexContext *context) = 0;

    virtual antlrcpp::Any visitTopindex(QOParser::TopindexContext *context) = 0;

    virtual antlrcpp::Any visitSumexpression(QOParser::SumexpressionContext *context) = 0;

    virtual antlrcpp::Any visitSumindices(QOParser::SumindicesContext *context) = 0;

    virtual antlrcpp::Any visitSign(QOParser::SignContext *context) = 0;

    virtual antlrcpp::Any visitArtimethic(QOParser::ArtimethicContext *context) = 0;


};

}  // namespace qoptic
