
// Generated from QOLexer.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"


namespace qoptic {


class  QOLexer : public antlr4::Lexer {
public:
  enum {
    NEWLINE = 1, Comment = 2, WS = 3, PARAMETER = 4, SUM = 5, EQUAL = 6, 
    COMMA = 7, ADD = 8, SUB = 9, MUL = 10, DIV = 11, CARET = 12, USCORE = 13, 
    INDEXOPEN = 14, INDEXCLOSE = 15, ARGOPEN = 16, ARGCLOSE = 17, SYMBOLNAME = 18
  };

  enum {
    CommentsChannel = 2
  };

  explicit QOLexer(antlr4::CharStream *input);
  ~QOLexer();



  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace qoptic
