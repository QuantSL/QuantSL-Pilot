
// Generated from QOParser.g4 by ANTLR 4.9.3


#include "QOParserVisitor.h"

#include "QOParser.h"


using namespace antlrcpp;
using namespace qoptic;
using namespace antlr4;

QOParser::QOParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

QOParser::~QOParser() {
  delete _interpreter;
}

std::string QOParser::getGrammarFileName() const {
  return "QOParser.g4";
}

const std::vector<std::string>& QOParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& QOParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- MainContext ------------------------------------------------------------------

QOParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QOParser::MainContext::EOF() {
  return getToken(QOParser::EOF, 0);
}

std::vector<QOParser::LineContext *> QOParser::MainContext::line() {
  return getRuleContexts<QOParser::LineContext>();
}

QOParser::LineContext* QOParser::MainContext::line(size_t i) {
  return getRuleContext<QOParser::LineContext>(i);
}


size_t QOParser::MainContext::getRuleIndex() const {
  return QOParser::RuleMain;
}


antlrcpp::Any QOParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

QOParser::MainContext* QOParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, QOParser::RuleMain);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QOParser::NEWLINE)
      | (1ULL << QOParser::PARAMETER)
      | (1ULL << QOParser::SYMBOLNAME))) != 0)) {
      setState(28);
      line();
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(34);
    match(QOParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

QOParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QOParser::ParameterLineContext* QOParser::LineContext::parameterLine() {
  return getRuleContext<QOParser::ParameterLineContext>(0);
}

QOParser::DefinitionLineContext* QOParser::LineContext::definitionLine() {
  return getRuleContext<QOParser::DefinitionLineContext>(0);
}

tree::TerminalNode* QOParser::LineContext::NEWLINE() {
  return getToken(QOParser::NEWLINE, 0);
}


size_t QOParser::LineContext::getRuleIndex() const {
  return QOParser::RuleLine;
}


antlrcpp::Any QOParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

QOParser::LineContext* QOParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, QOParser::RuleLine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(39);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QOParser::PARAMETER: {
        enterOuterAlt(_localctx, 1);
        setState(36);
        parameterLine();
        break;
      }

      case QOParser::SYMBOLNAME: {
        enterOuterAlt(_localctx, 2);
        setState(37);
        definitionLine();
        break;
      }

      case QOParser::NEWLINE: {
        enterOuterAlt(_localctx, 3);
        setState(38);
        match(QOParser::NEWLINE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterLineContext ------------------------------------------------------------------

QOParser::ParameterLineContext::ParameterLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QOParser::ParameterLineContext::PARAMETER() {
  return getToken(QOParser::PARAMETER, 0);
}

QOParser::ParametersContext* QOParser::ParameterLineContext::parameters() {
  return getRuleContext<QOParser::ParametersContext>(0);
}

tree::TerminalNode* QOParser::ParameterLineContext::NEWLINE() {
  return getToken(QOParser::NEWLINE, 0);
}


size_t QOParser::ParameterLineContext::getRuleIndex() const {
  return QOParser::RuleParameterLine;
}


antlrcpp::Any QOParser::ParameterLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitParameterLine(this);
  else
    return visitor->visitChildren(this);
}

QOParser::ParameterLineContext* QOParser::parameterLine() {
  ParameterLineContext *_localctx = _tracker.createInstance<ParameterLineContext>(_ctx, getState());
  enterRule(_localctx, 4, QOParser::RuleParameterLine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    match(QOParser::PARAMETER);
    setState(42);
    parameters();
    setState(44);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(43);
      match(QOParser::NEWLINE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

QOParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> QOParser::ParametersContext::SYMBOLNAME() {
  return getTokens(QOParser::SYMBOLNAME);
}

tree::TerminalNode* QOParser::ParametersContext::SYMBOLNAME(size_t i) {
  return getToken(QOParser::SYMBOLNAME, i);
}

std::vector<tree::TerminalNode *> QOParser::ParametersContext::COMMA() {
  return getTokens(QOParser::COMMA);
}

tree::TerminalNode* QOParser::ParametersContext::COMMA(size_t i) {
  return getToken(QOParser::COMMA, i);
}


size_t QOParser::ParametersContext::getRuleIndex() const {
  return QOParser::RuleParameters;
}


antlrcpp::Any QOParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

QOParser::ParametersContext* QOParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 6, QOParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    antlrcpp::downCast<ParametersContext *>(_localctx)->symbolnameToken = match(QOParser::SYMBOLNAME);
    antlrcpp::downCast<ParametersContext *>(_localctx)->elements.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->symbolnameToken);
    setState(51);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == QOParser::COMMA) {
      setState(47);
      match(QOParser::COMMA);
      setState(48);
      antlrcpp::downCast<ParametersContext *>(_localctx)->symbolnameToken = match(QOParser::SYMBOLNAME);
      antlrcpp::downCast<ParametersContext *>(_localctx)->elements.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->symbolnameToken);
      setState(53);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionLineContext ------------------------------------------------------------------

QOParser::DefinitionLineContext::DefinitionLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QOParser::SimpleDefinitionContext* QOParser::DefinitionLineContext::simpleDefinition() {
  return getRuleContext<QOParser::SimpleDefinitionContext>(0);
}

QOParser::IndexedDefinitionContext* QOParser::DefinitionLineContext::indexedDefinition() {
  return getRuleContext<QOParser::IndexedDefinitionContext>(0);
}


size_t QOParser::DefinitionLineContext::getRuleIndex() const {
  return QOParser::RuleDefinitionLine;
}


antlrcpp::Any QOParser::DefinitionLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitDefinitionLine(this);
  else
    return visitor->visitChildren(this);
}

QOParser::DefinitionLineContext* QOParser::definitionLine() {
  DefinitionLineContext *_localctx = _tracker.createInstance<DefinitionLineContext>(_ctx, getState());
  enterRule(_localctx, 8, QOParser::RuleDefinitionLine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(56);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(54);
      simpleDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(55);
      indexedDefinition();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleDefinitionContext ------------------------------------------------------------------

QOParser::SimpleDefinitionContext::SimpleDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QOParser::SimpleDefinitionContext::EQUAL() {
  return getToken(QOParser::EQUAL, 0);
}

tree::TerminalNode* QOParser::SimpleDefinitionContext::SYMBOLNAME() {
  return getToken(QOParser::SYMBOLNAME, 0);
}

QOParser::ExpressionContext* QOParser::SimpleDefinitionContext::expression() {
  return getRuleContext<QOParser::ExpressionContext>(0);
}

tree::TerminalNode* QOParser::SimpleDefinitionContext::NEWLINE() {
  return getToken(QOParser::NEWLINE, 0);
}


size_t QOParser::SimpleDefinitionContext::getRuleIndex() const {
  return QOParser::RuleSimpleDefinition;
}


antlrcpp::Any QOParser::SimpleDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitSimpleDefinition(this);
  else
    return visitor->visitChildren(this);
}

QOParser::SimpleDefinitionContext* QOParser::simpleDefinition() {
  SimpleDefinitionContext *_localctx = _tracker.createInstance<SimpleDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 10, QOParser::RuleSimpleDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    antlrcpp::downCast<SimpleDefinitionContext *>(_localctx)->symbolnameToken = match(QOParser::SYMBOLNAME);
    antlrcpp::downCast<SimpleDefinitionContext *>(_localctx)->objects.push_back(antlrcpp::downCast<SimpleDefinitionContext *>(_localctx)->symbolnameToken);
    setState(59);
    match(QOParser::EQUAL);
    setState(60);
    antlrcpp::downCast<SimpleDefinitionContext *>(_localctx)->expressionContext = expression();
    antlrcpp::downCast<SimpleDefinitionContext *>(_localctx)->definitions.push_back(antlrcpp::downCast<SimpleDefinitionContext *>(_localctx)->expressionContext);
    setState(62);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(61);
      match(QOParser::NEWLINE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexedDefinitionContext ------------------------------------------------------------------

QOParser::IndexedDefinitionContext::IndexedDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QOParser::BotindexContext* QOParser::IndexedDefinitionContext::botindex() {
  return getRuleContext<QOParser::BotindexContext>(0);
}

tree::TerminalNode* QOParser::IndexedDefinitionContext::EQUAL() {
  return getToken(QOParser::EQUAL, 0);
}

tree::TerminalNode* QOParser::IndexedDefinitionContext::SYMBOLNAME() {
  return getToken(QOParser::SYMBOLNAME, 0);
}

QOParser::ExpressionContext* QOParser::IndexedDefinitionContext::expression() {
  return getRuleContext<QOParser::ExpressionContext>(0);
}

tree::TerminalNode* QOParser::IndexedDefinitionContext::NEWLINE() {
  return getToken(QOParser::NEWLINE, 0);
}


size_t QOParser::IndexedDefinitionContext::getRuleIndex() const {
  return QOParser::RuleIndexedDefinition;
}


antlrcpp::Any QOParser::IndexedDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitIndexedDefinition(this);
  else
    return visitor->visitChildren(this);
}

QOParser::IndexedDefinitionContext* QOParser::indexedDefinition() {
  IndexedDefinitionContext *_localctx = _tracker.createInstance<IndexedDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 12, QOParser::RuleIndexedDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    antlrcpp::downCast<IndexedDefinitionContext *>(_localctx)->symbolnameToken = match(QOParser::SYMBOLNAME);
    antlrcpp::downCast<IndexedDefinitionContext *>(_localctx)->objects.push_back(antlrcpp::downCast<IndexedDefinitionContext *>(_localctx)->symbolnameToken);
    setState(65);
    botindex();
    setState(66);
    match(QOParser::EQUAL);
    setState(67);
    antlrcpp::downCast<IndexedDefinitionContext *>(_localctx)->expressionContext = expression();
    antlrcpp::downCast<IndexedDefinitionContext *>(_localctx)->definitions.push_back(antlrcpp::downCast<IndexedDefinitionContext *>(_localctx)->expressionContext);
    setState(69);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(68);
      match(QOParser::NEWLINE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

QOParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> QOParser::ExpressionContext::SYMBOLNAME() {
  return getTokens(QOParser::SYMBOLNAME);
}

tree::TerminalNode* QOParser::ExpressionContext::SYMBOLNAME(size_t i) {
  return getToken(QOParser::SYMBOLNAME, i);
}

std::vector<QOParser::SumexpressionContext *> QOParser::ExpressionContext::sumexpression() {
  return getRuleContexts<QOParser::SumexpressionContext>();
}

QOParser::SumexpressionContext* QOParser::ExpressionContext::sumexpression(size_t i) {
  return getRuleContext<QOParser::SumexpressionContext>(i);
}

QOParser::SignContext* QOParser::ExpressionContext::sign() {
  return getRuleContext<QOParser::SignContext>(0);
}

std::vector<QOParser::ArtimethicContext *> QOParser::ExpressionContext::artimethic() {
  return getRuleContexts<QOParser::ArtimethicContext>();
}

QOParser::ArtimethicContext* QOParser::ExpressionContext::artimethic(size_t i) {
  return getRuleContext<QOParser::ArtimethicContext>(i);
}

std::vector<QOParser::BotindexContext *> QOParser::ExpressionContext::botindex() {
  return getRuleContexts<QOParser::BotindexContext>();
}

QOParser::BotindexContext* QOParser::ExpressionContext::botindex(size_t i) {
  return getRuleContext<QOParser::BotindexContext>(i);
}


size_t QOParser::ExpressionContext::getRuleIndex() const {
  return QOParser::RuleExpression;
}


antlrcpp::Any QOParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

QOParser::ExpressionContext* QOParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 14, QOParser::RuleExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QOParser::ADD

    || _la == QOParser::SUB) {
      setState(71);
      sign();
    }
    setState(79);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QOParser::SYMBOLNAME: {
        setState(74);
        match(QOParser::SYMBOLNAME);
        setState(76);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == QOParser::USCORE) {
          setState(75);
          botindex();
        }
        break;
      }

      case QOParser::SUM: {
        setState(78);
        sumexpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(91);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QOParser::ADD)
      | (1ULL << QOParser::SUB)
      | (1ULL << QOParser::MUL)
      | (1ULL << QOParser::DIV)
      | (1ULL << QOParser::CARET))) != 0)) {
      setState(81);
      artimethic();
      setState(87);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case QOParser::SYMBOLNAME: {
          setState(82);
          match(QOParser::SYMBOLNAME);
          setState(84);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == QOParser::USCORE) {
            setState(83);
            botindex();
          }
          break;
        }

        case QOParser::SUM: {
          setState(86);
          sumexpression();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(93);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BotindexContext ------------------------------------------------------------------

QOParser::BotindexContext::BotindexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QOParser::BotindexContext::USCORE() {
  return getToken(QOParser::USCORE, 0);
}

std::vector<tree::TerminalNode *> QOParser::BotindexContext::SYMBOLNAME() {
  return getTokens(QOParser::SYMBOLNAME);
}

tree::TerminalNode* QOParser::BotindexContext::SYMBOLNAME(size_t i) {
  return getToken(QOParser::SYMBOLNAME, i);
}

tree::TerminalNode* QOParser::BotindexContext::INDEXOPEN() {
  return getToken(QOParser::INDEXOPEN, 0);
}

tree::TerminalNode* QOParser::BotindexContext::INDEXCLOSE() {
  return getToken(QOParser::INDEXCLOSE, 0);
}

std::vector<tree::TerminalNode *> QOParser::BotindexContext::COMMA() {
  return getTokens(QOParser::COMMA);
}

tree::TerminalNode* QOParser::BotindexContext::COMMA(size_t i) {
  return getToken(QOParser::COMMA, i);
}


size_t QOParser::BotindexContext::getRuleIndex() const {
  return QOParser::RuleBotindex;
}


antlrcpp::Any QOParser::BotindexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitBotindex(this);
  else
    return visitor->visitChildren(this);
}

QOParser::BotindexContext* QOParser::botindex() {
  BotindexContext *_localctx = _tracker.createInstance<BotindexContext>(_ctx, getState());
  enterRule(_localctx, 16, QOParser::RuleBotindex);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(107);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(94);
      match(QOParser::USCORE);
      setState(95);
      antlrcpp::downCast<BotindexContext *>(_localctx)->symbolnameToken = match(QOParser::SYMBOLNAME);
      antlrcpp::downCast<BotindexContext *>(_localctx)->elements.push_back(antlrcpp::downCast<BotindexContext *>(_localctx)->symbolnameToken);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(96);
      match(QOParser::USCORE);
      setState(97);
      match(QOParser::INDEXOPEN);
      setState(98);
      antlrcpp::downCast<BotindexContext *>(_localctx)->symbolnameToken = match(QOParser::SYMBOLNAME);
      antlrcpp::downCast<BotindexContext *>(_localctx)->elements.push_back(antlrcpp::downCast<BotindexContext *>(_localctx)->symbolnameToken);
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == QOParser::COMMA) {
        setState(99);
        match(QOParser::COMMA);
        setState(100);
        antlrcpp::downCast<BotindexContext *>(_localctx)->symbolnameToken = match(QOParser::SYMBOLNAME);
        antlrcpp::downCast<BotindexContext *>(_localctx)->elements.push_back(antlrcpp::downCast<BotindexContext *>(_localctx)->symbolnameToken);
        setState(105);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(106);
      match(QOParser::INDEXCLOSE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TopindexContext ------------------------------------------------------------------

QOParser::TopindexContext::TopindexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QOParser::TopindexContext::CARET() {
  return getToken(QOParser::CARET, 0);
}

std::vector<tree::TerminalNode *> QOParser::TopindexContext::SYMBOLNAME() {
  return getTokens(QOParser::SYMBOLNAME);
}

tree::TerminalNode* QOParser::TopindexContext::SYMBOLNAME(size_t i) {
  return getToken(QOParser::SYMBOLNAME, i);
}

tree::TerminalNode* QOParser::TopindexContext::INDEXOPEN() {
  return getToken(QOParser::INDEXOPEN, 0);
}

tree::TerminalNode* QOParser::TopindexContext::INDEXCLOSE() {
  return getToken(QOParser::INDEXCLOSE, 0);
}

std::vector<tree::TerminalNode *> QOParser::TopindexContext::COMMA() {
  return getTokens(QOParser::COMMA);
}

tree::TerminalNode* QOParser::TopindexContext::COMMA(size_t i) {
  return getToken(QOParser::COMMA, i);
}


size_t QOParser::TopindexContext::getRuleIndex() const {
  return QOParser::RuleTopindex;
}


antlrcpp::Any QOParser::TopindexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitTopindex(this);
  else
    return visitor->visitChildren(this);
}

QOParser::TopindexContext* QOParser::topindex() {
  TopindexContext *_localctx = _tracker.createInstance<TopindexContext>(_ctx, getState());
  enterRule(_localctx, 18, QOParser::RuleTopindex);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(122);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(109);
      match(QOParser::CARET);
      setState(110);
      antlrcpp::downCast<TopindexContext *>(_localctx)->symbolnameToken = match(QOParser::SYMBOLNAME);
      antlrcpp::downCast<TopindexContext *>(_localctx)->elements.push_back(antlrcpp::downCast<TopindexContext *>(_localctx)->symbolnameToken);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(111);
      match(QOParser::CARET);
      setState(112);
      match(QOParser::INDEXOPEN);
      setState(113);
      antlrcpp::downCast<TopindexContext *>(_localctx)->symbolnameToken = match(QOParser::SYMBOLNAME);
      antlrcpp::downCast<TopindexContext *>(_localctx)->elements.push_back(antlrcpp::downCast<TopindexContext *>(_localctx)->symbolnameToken);
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == QOParser::COMMA) {
        setState(114);
        match(QOParser::COMMA);
        setState(115);
        antlrcpp::downCast<TopindexContext *>(_localctx)->symbolnameToken = match(QOParser::SYMBOLNAME);
        antlrcpp::downCast<TopindexContext *>(_localctx)->elements.push_back(antlrcpp::downCast<TopindexContext *>(_localctx)->symbolnameToken);
        setState(120);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(121);
      match(QOParser::INDEXCLOSE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SumexpressionContext ------------------------------------------------------------------

QOParser::SumexpressionContext::SumexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QOParser::SumexpressionContext::SUM() {
  return getToken(QOParser::SUM, 0);
}

tree::TerminalNode* QOParser::SumexpressionContext::ARGOPEN() {
  return getToken(QOParser::ARGOPEN, 0);
}

std::vector<tree::TerminalNode *> QOParser::SumexpressionContext::SYMBOLNAME() {
  return getTokens(QOParser::SYMBOLNAME);
}

tree::TerminalNode* QOParser::SumexpressionContext::SYMBOLNAME(size_t i) {
  return getToken(QOParser::SYMBOLNAME, i);
}

tree::TerminalNode* QOParser::SumexpressionContext::ARGCLOSE() {
  return getToken(QOParser::ARGCLOSE, 0);
}

QOParser::SumindicesContext* QOParser::SumexpressionContext::sumindices() {
  return getRuleContext<QOParser::SumindicesContext>(0);
}

QOParser::SignContext* QOParser::SumexpressionContext::sign() {
  return getRuleContext<QOParser::SignContext>(0);
}

std::vector<QOParser::BotindexContext *> QOParser::SumexpressionContext::botindex() {
  return getRuleContexts<QOParser::BotindexContext>();
}

QOParser::BotindexContext* QOParser::SumexpressionContext::botindex(size_t i) {
  return getRuleContext<QOParser::BotindexContext>(i);
}

std::vector<QOParser::ArtimethicContext *> QOParser::SumexpressionContext::artimethic() {
  return getRuleContexts<QOParser::ArtimethicContext>();
}

QOParser::ArtimethicContext* QOParser::SumexpressionContext::artimethic(size_t i) {
  return getRuleContext<QOParser::ArtimethicContext>(i);
}


size_t QOParser::SumexpressionContext::getRuleIndex() const {
  return QOParser::RuleSumexpression;
}


antlrcpp::Any QOParser::SumexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitSumexpression(this);
  else
    return visitor->visitChildren(this);
}

QOParser::SumexpressionContext* QOParser::sumexpression() {
  SumexpressionContext *_localctx = _tracker.createInstance<SumexpressionContext>(_ctx, getState());
  enterRule(_localctx, 20, QOParser::RuleSumexpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(QOParser::SUM);
    setState(125);
    antlrcpp::downCast<SumexpressionContext *>(_localctx)->sumindicesContext = sumindices();
    antlrcpp::downCast<SumexpressionContext *>(_localctx)->boundaries.push_back(antlrcpp::downCast<SumexpressionContext *>(_localctx)->sumindicesContext);
    setState(126);
    match(QOParser::ARGOPEN);
    setState(128);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QOParser::ADD

    || _la == QOParser::SUB) {
      setState(127);
      sign();
    }
    setState(130);
    match(QOParser::SYMBOLNAME);
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QOParser::USCORE) {
      setState(131);
      botindex();
    }
    setState(141);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QOParser::ADD)
      | (1ULL << QOParser::SUB)
      | (1ULL << QOParser::MUL)
      | (1ULL << QOParser::DIV)
      | (1ULL << QOParser::CARET))) != 0)) {
      setState(134);
      artimethic();

      setState(135);
      match(QOParser::SYMBOLNAME);
      setState(137);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == QOParser::USCORE) {
        setState(136);
        botindex();
      }
      setState(143);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(144);
    match(QOParser::ARGCLOSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SumindicesContext ------------------------------------------------------------------

QOParser::SumindicesContext::SumindicesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QOParser::BotindexContext* QOParser::SumindicesContext::botindex() {
  return getRuleContext<QOParser::BotindexContext>(0);
}

QOParser::TopindexContext* QOParser::SumindicesContext::topindex() {
  return getRuleContext<QOParser::TopindexContext>(0);
}


size_t QOParser::SumindicesContext::getRuleIndex() const {
  return QOParser::RuleSumindices;
}


antlrcpp::Any QOParser::SumindicesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitSumindices(this);
  else
    return visitor->visitChildren(this);
}

QOParser::SumindicesContext* QOParser::sumindices() {
  SumindicesContext *_localctx = _tracker.createInstance<SumindicesContext>(_ctx, getState());
  enterRule(_localctx, 22, QOParser::RuleSumindices);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    botindex();
    setState(147);
    topindex();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

QOParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QOParser::SignContext::ADD() {
  return getToken(QOParser::ADD, 0);
}

tree::TerminalNode* QOParser::SignContext::SUB() {
  return getToken(QOParser::SUB, 0);
}


size_t QOParser::SignContext::getRuleIndex() const {
  return QOParser::RuleSign;
}


antlrcpp::Any QOParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

QOParser::SignContext* QOParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 24, QOParser::RuleSign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    _la = _input->LA(1);
    if (!(_la == QOParser::ADD

    || _la == QOParser::SUB)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArtimethicContext ------------------------------------------------------------------

QOParser::ArtimethicContext::ArtimethicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QOParser::ArtimethicContext::ADD() {
  return getToken(QOParser::ADD, 0);
}

tree::TerminalNode* QOParser::ArtimethicContext::SUB() {
  return getToken(QOParser::SUB, 0);
}

tree::TerminalNode* QOParser::ArtimethicContext::MUL() {
  return getToken(QOParser::MUL, 0);
}

tree::TerminalNode* QOParser::ArtimethicContext::DIV() {
  return getToken(QOParser::DIV, 0);
}

tree::TerminalNode* QOParser::ArtimethicContext::CARET() {
  return getToken(QOParser::CARET, 0);
}


size_t QOParser::ArtimethicContext::getRuleIndex() const {
  return QOParser::RuleArtimethic;
}


antlrcpp::Any QOParser::ArtimethicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QOParserVisitor*>(visitor))
    return parserVisitor->visitArtimethic(this);
  else
    return visitor->visitChildren(this);
}

QOParser::ArtimethicContext* QOParser::artimethic() {
  ArtimethicContext *_localctx = _tracker.createInstance<ArtimethicContext>(_ctx, getState());
  enterRule(_localctx, 26, QOParser::RuleArtimethic);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QOParser::ADD)
      | (1ULL << QOParser::SUB)
      | (1ULL << QOParser::MUL)
      | (1ULL << QOParser::DIV)
      | (1ULL << QOParser::CARET))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> QOParser::_decisionToDFA;
atn::PredictionContextCache QOParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN QOParser::_atn;
std::vector<uint16_t> QOParser::_serializedATN;

std::vector<std::string> QOParser::_ruleNames = {
  "main", "line", "parameterLine", "parameters", "definitionLine", "simpleDefinition", 
  "indexedDefinition", "expression", "botindex", "topindex", "sumexpression", 
  "sumindices", "sign", "artimethic"
};

std::vector<std::string> QOParser::_literalNames = {
  "", "", "", "", "'parameter'", "'sum'", "'='", "','", "'+'", "'-'", "'*'", 
  "'/'", "'^'", "'_'", "'['", "']'", "'('", "')'"
};

std::vector<std::string> QOParser::_symbolicNames = {
  "", "NEWLINE", "Comment", "WS", "PARAMETER", "SUM", "EQUAL", "COMMA", 
  "ADD", "SUB", "MUL", "DIV", "CARET", "USCORE", "INDEXOPEN", "INDEXCLOSE", 
  "ARGOPEN", "ARGCLOSE", "SYMBOLNAME"
};

dfa::Vocabulary QOParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> QOParser::_tokenNames;

QOParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x14, 0x9c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x3, 0x2, 0x7, 0x2, 0x20, 0xa, 
       0x2, 0xc, 0x2, 0xe, 0x2, 0x23, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2a, 0xa, 0x3, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x5, 0x4, 0x2f, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x7, 0x5, 0x34, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x37, 0xb, 0x5, 
       0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x3b, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x41, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x48, 0xa, 0x8, 0x3, 0x9, 
       0x5, 0x9, 0x4b, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x4f, 0xa, 
       0x9, 0x3, 0x9, 0x5, 0x9, 0x52, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x5, 0x9, 0x57, 0xa, 0x9, 0x3, 0x9, 0x5, 0x9, 0x5a, 0xa, 0x9, 
       0x7, 0x9, 0x5c, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x5f, 0xb, 0x9, 0x3, 
       0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
       0x7, 0xa, 0x68, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x6b, 0xb, 0xa, 0x3, 
       0xa, 0x5, 0xa, 0x6e, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x77, 0xa, 0xb, 0xc, 
       0xb, 0xe, 0xb, 0x7a, 0xb, 0xb, 0x3, 0xb, 0x5, 0xb, 0x7d, 0xa, 0xb, 
       0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x83, 0xa, 0xc, 
       0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x87, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 
       0x3, 0xc, 0x5, 0xc, 0x8c, 0xa, 0xc, 0x7, 0xc, 0x8e, 0xa, 0xc, 0xc, 
       0xc, 0xe, 0xc, 0x91, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x2, 0x2, 0x10, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
       0x16, 0x18, 0x1a, 0x1c, 0x2, 0x4, 0x3, 0x2, 0xa, 0xb, 0x3, 0x2, 0xa, 
       0xe, 0x2, 0xa3, 0x2, 0x21, 0x3, 0x2, 0x2, 0x2, 0x4, 0x29, 0x3, 0x2, 
       0x2, 0x2, 0x6, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x30, 0x3, 0x2, 0x2, 
       0x2, 0xa, 0x3a, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3c, 0x3, 0x2, 0x2, 0x2, 
       0xe, 0x42, 0x3, 0x2, 0x2, 0x2, 0x10, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x12, 
       0x6d, 0x3, 0x2, 0x2, 0x2, 0x14, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x16, 0x7e, 
       0x3, 0x2, 0x2, 0x2, 0x18, 0x94, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x97, 0x3, 
       0x2, 0x2, 0x2, 0x1c, 0x99, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x20, 0x5, 0x4, 
       0x3, 0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x23, 0x3, 0x2, 0x2, 
       0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 
       0x22, 0x24, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x24, 
       0x25, 0x7, 0x2, 0x2, 0x3, 0x25, 0x3, 0x3, 0x2, 0x2, 0x2, 0x26, 0x2a, 
       0x5, 0x6, 0x4, 0x2, 0x27, 0x2a, 0x5, 0xa, 0x6, 0x2, 0x28, 0x2a, 0x7, 
       0x3, 0x2, 0x2, 0x29, 0x26, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 
       0x2, 0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x5, 0x3, 0x2, 0x2, 
       0x2, 0x2b, 0x2c, 0x7, 0x6, 0x2, 0x2, 0x2c, 0x2e, 0x5, 0x8, 0x5, 0x2, 
       0x2d, 0x2f, 0x7, 0x3, 0x2, 0x2, 0x2e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2e, 
       0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x30, 0x35, 
       0x7, 0x14, 0x2, 0x2, 0x31, 0x32, 0x7, 0x9, 0x2, 0x2, 0x32, 0x34, 
       0x7, 0x14, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x34, 0x37, 
       0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 
       0x2, 0x2, 0x2, 0x36, 0x9, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 
       0x2, 0x2, 0x38, 0x3b, 0x5, 0xc, 0x7, 0x2, 0x39, 0x3b, 0x5, 0xe, 0x8, 
       0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x39, 0x3, 0x2, 0x2, 0x2, 
       0x3b, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x14, 0x2, 0x2, 0x3d, 
       0x3e, 0x7, 0x8, 0x2, 0x2, 0x3e, 0x40, 0x5, 0x10, 0x9, 0x2, 0x3f, 
       0x41, 0x7, 0x3, 0x2, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 
       0x3, 0x2, 0x2, 0x2, 0x41, 0xd, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x7, 
       0x14, 0x2, 0x2, 0x43, 0x44, 0x5, 0x12, 0xa, 0x2, 0x44, 0x45, 0x7, 
       0x8, 0x2, 0x2, 0x45, 0x47, 0x5, 0x10, 0x9, 0x2, 0x46, 0x48, 0x7, 
       0x3, 0x2, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 
       0x2, 0x2, 0x48, 0xf, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4b, 0x5, 0x1a, 0xe, 
       0x2, 0x4a, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x3, 0x2, 0x2, 0x2, 
       0x4b, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4e, 0x7, 0x14, 0x2, 0x2, 
       0x4d, 0x4f, 0x5, 0x12, 0xa, 0x2, 0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 
       0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x52, 0x3, 0x2, 0x2, 0x2, 0x50, 
       0x52, 0x5, 0x16, 0xc, 0x2, 0x51, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x51, 
       0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x53, 0x59, 
       0x5, 0x1c, 0xf, 0x2, 0x54, 0x56, 0x7, 0x14, 0x2, 0x2, 0x55, 0x57, 
       0x5, 0x12, 0xa, 0x2, 0x56, 0x55, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 
       0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x5, 
       0x16, 0xc, 0x2, 0x59, 0x54, 0x3, 0x2, 0x2, 0x2, 0x59, 0x58, 0x3, 
       0x2, 0x2, 0x2, 0x5a, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x53, 0x3, 0x2, 
       0x2, 0x2, 0x5c, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 
       0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x11, 0x3, 0x2, 0x2, 0x2, 
       0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0xf, 0x2, 0x2, 0x61, 
       0x6e, 0x7, 0x14, 0x2, 0x2, 0x62, 0x63, 0x7, 0xf, 0x2, 0x2, 0x63, 
       0x64, 0x7, 0x10, 0x2, 0x2, 0x64, 0x69, 0x7, 0x14, 0x2, 0x2, 0x65, 
       0x66, 0x7, 0x9, 0x2, 0x2, 0x66, 0x68, 0x7, 0x14, 0x2, 0x2, 0x67, 
       0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 
       0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6c, 0x3, 
       0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6e, 0x7, 0x11, 
       0x2, 0x2, 0x6d, 0x60, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x62, 0x3, 0x2, 0x2, 
       0x2, 0x6e, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0xe, 0x2, 0x2, 
       0x70, 0x7d, 0x7, 0x14, 0x2, 0x2, 0x71, 0x72, 0x7, 0xe, 0x2, 0x2, 
       0x72, 0x73, 0x7, 0x10, 0x2, 0x2, 0x73, 0x78, 0x7, 0x14, 0x2, 0x2, 
       0x74, 0x75, 0x7, 0x9, 0x2, 0x2, 0x75, 0x77, 0x7, 0x14, 0x2, 0x2, 
       0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x77, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x78, 
       0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7b, 
       0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7d, 0x7, 
       0x11, 0x2, 0x2, 0x7c, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x71, 0x3, 
       0x2, 0x2, 0x2, 0x7d, 0x15, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x7, 
       0x2, 0x2, 0x7f, 0x80, 0x5, 0x18, 0xd, 0x2, 0x80, 0x82, 0x7, 0x12, 
       0x2, 0x2, 0x81, 0x83, 0x5, 0x1a, 0xe, 0x2, 0x82, 0x81, 0x3, 0x2, 
       0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 
       0x2, 0x84, 0x86, 0x7, 0x14, 0x2, 0x2, 0x85, 0x87, 0x5, 0x12, 0xa, 
       0x2, 0x86, 0x85, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 0x2, 
       0x87, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x5, 0x1c, 0xf, 0x2, 
       0x89, 0x8b, 0x7, 0x14, 0x2, 0x2, 0x8a, 0x8c, 0x5, 0x12, 0xa, 0x2, 
       0x8b, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 
       0x8e, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x91, 
       0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 
       0x2, 0x2, 0x2, 0x90, 0x92, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 
       0x2, 0x2, 0x92, 0x93, 0x7, 0x13, 0x2, 0x2, 0x93, 0x17, 0x3, 0x2, 
       0x2, 0x2, 0x94, 0x95, 0x5, 0x12, 0xa, 0x2, 0x95, 0x96, 0x5, 0x14, 
       0xb, 0x2, 0x96, 0x19, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x9, 0x2, 0x2, 
       0x2, 0x98, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x9, 0x3, 0x2, 0x2, 
       0x9a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x17, 0x21, 0x29, 0x2e, 0x35, 0x3a, 
       0x40, 0x47, 0x4a, 0x4e, 0x51, 0x56, 0x59, 0x5d, 0x69, 0x6d, 0x78, 
       0x7c, 0x82, 0x86, 0x8b, 0x8f, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

QOParser::Initializer QOParser::_init;
