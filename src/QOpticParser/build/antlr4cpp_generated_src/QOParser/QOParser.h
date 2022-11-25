
// Generated from QOParser.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"


namespace qoptic {


class  QOParser : public antlr4::Parser {
public:
  enum {
    NEWLINE = 1, Comment = 2, WS = 3, PARAMETER = 4, SUM = 5, EQUAL = 6, 
    COMMA = 7, ADD = 8, SUB = 9, MUL = 10, DIV = 11, CARET = 12, USCORE = 13, 
    INDEXOPEN = 14, INDEXCLOSE = 15, ARGOPEN = 16, ARGCLOSE = 17, SYMBOLNAME = 18
  };

  enum {
    RuleMain = 0, RuleLine = 1, RuleParameterLine = 2, RuleParameters = 3, 
    RuleDefinitionLine = 4, RuleSimpleDefinition = 5, RuleIndexedDefinition = 6, 
    RuleExpression = 7, RuleBotindex = 8, RuleTopindex = 9, RuleSumexpression = 10, 
    RuleSumindices = 11, RuleSign = 12, RuleArtimethic = 13
  };

  explicit QOParser(antlr4::TokenStream *input);
  ~QOParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class MainContext;
  class LineContext;
  class ParameterLineContext;
  class ParametersContext;
  class DefinitionLineContext;
  class SimpleDefinitionContext;
  class IndexedDefinitionContext;
  class ExpressionContext;
  class BotindexContext;
  class TopindexContext;
  class SumexpressionContext;
  class SumindicesContext;
  class SignContext;
  class ArtimethicContext; 

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MainContext* main();

  class  LineContext : public antlr4::ParserRuleContext {
  public:
    LineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParameterLineContext *parameterLine();
    DefinitionLineContext *definitionLine();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineContext* line();

  class  ParameterLineContext : public antlr4::ParserRuleContext {
  public:
    ParameterLineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PARAMETER();
    ParametersContext *parameters();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterLineContext* parameterLine();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *symbolnameToken = nullptr;
    std::vector<antlr4::Token *> elements;
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SYMBOLNAME();
    antlr4::tree::TerminalNode* SYMBOLNAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametersContext* parameters();

  class  DefinitionLineContext : public antlr4::ParserRuleContext {
  public:
    DefinitionLineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleDefinitionContext *simpleDefinition();
    IndexedDefinitionContext *indexedDefinition();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefinitionLineContext* definitionLine();

  class  SimpleDefinitionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *symbolnameToken = nullptr;
    std::vector<antlr4::Token *> objects;
    QOParser::ExpressionContext *expressionContext = nullptr;
    std::vector<ExpressionContext *> definitions;
    SimpleDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *SYMBOLNAME();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleDefinitionContext* simpleDefinition();

  class  IndexedDefinitionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *symbolnameToken = nullptr;
    std::vector<antlr4::Token *> objects;
    QOParser::ExpressionContext *expressionContext = nullptr;
    std::vector<ExpressionContext *> definitions;
    IndexedDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BotindexContext *botindex();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *SYMBOLNAME();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexedDefinitionContext* indexedDefinition();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SYMBOLNAME();
    antlr4::tree::TerminalNode* SYMBOLNAME(size_t i);
    std::vector<SumexpressionContext *> sumexpression();
    SumexpressionContext* sumexpression(size_t i);
    SignContext *sign();
    std::vector<ArtimethicContext *> artimethic();
    ArtimethicContext* artimethic(size_t i);
    std::vector<BotindexContext *> botindex();
    BotindexContext* botindex(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  BotindexContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *symbolnameToken = nullptr;
    std::vector<antlr4::Token *> elements;
    BotindexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USCORE();
    std::vector<antlr4::tree::TerminalNode *> SYMBOLNAME();
    antlr4::tree::TerminalNode* SYMBOLNAME(size_t i);
    antlr4::tree::TerminalNode *INDEXOPEN();
    antlr4::tree::TerminalNode *INDEXCLOSE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BotindexContext* botindex();

  class  TopindexContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *symbolnameToken = nullptr;
    std::vector<antlr4::Token *> elements;
    TopindexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CARET();
    std::vector<antlr4::tree::TerminalNode *> SYMBOLNAME();
    antlr4::tree::TerminalNode* SYMBOLNAME(size_t i);
    antlr4::tree::TerminalNode *INDEXOPEN();
    antlr4::tree::TerminalNode *INDEXCLOSE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TopindexContext* topindex();

  class  SumexpressionContext : public antlr4::ParserRuleContext {
  public:
    QOParser::SumindicesContext *sumindicesContext = nullptr;
    std::vector<SumindicesContext *> boundaries;
    SumexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUM();
    antlr4::tree::TerminalNode *ARGOPEN();
    std::vector<antlr4::tree::TerminalNode *> SYMBOLNAME();
    antlr4::tree::TerminalNode* SYMBOLNAME(size_t i);
    antlr4::tree::TerminalNode *ARGCLOSE();
    SumindicesContext *sumindices();
    SignContext *sign();
    std::vector<BotindexContext *> botindex();
    BotindexContext* botindex(size_t i);
    std::vector<ArtimethicContext *> artimethic();
    ArtimethicContext* artimethic(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SumexpressionContext* sumexpression();

  class  SumindicesContext : public antlr4::ParserRuleContext {
  public:
    SumindicesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BotindexContext *botindex();
    TopindexContext *topindex();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SumindicesContext* sumindices();

  class  SignContext : public antlr4::ParserRuleContext {
  public:
    SignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SignContext* sign();

  class  ArtimethicContext : public antlr4::ParserRuleContext {
  public:
    ArtimethicContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *CARET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArtimethicContext* artimethic();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace qoptic
