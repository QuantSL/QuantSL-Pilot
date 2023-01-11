// Generated from /Users/kevin/Documents/QTune/Pilot Julia/src/grammar/QDSLParser.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class QDSLParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		NEWLINE=1, Comment=2, WS=3, PARAMETER=4, SUM=5, SUBSYSTEM=6, SIGMA=7, 
		EQUAL=8, COMMA=9, ADD=10, SUB=11, MUL=12, DIV=13, CARET=14, USCORE=15, 
		INDEXOPEN=16, INDEXCLOSE=17, ARGOPEN=18, ARGCLOSE=19, SYMBOLNAME=20;
	public static final int
		RULE_main = 0, RULE_line = 1, RULE_parameterLine = 2, RULE_parameters = 3, 
		RULE_subsystemLine = 4, RULE_subsystems = 5, RULE_definitionLine = 6, 
		RULE_simpleDefinition = 7, RULE_indexedDefinition = 8, RULE_expression = 9, 
		RULE_sumExpression = 10, RULE_arithmeticExpression = 11, RULE_elementaryExpression = 12, 
		RULE_sumindices = 13, RULE_botindex = 14, RULE_topindex = 15, RULE_sign = 16, 
		RULE_arithmethic = 17;
	private static String[] makeRuleNames() {
		return new String[] {
			"main", "line", "parameterLine", "parameters", "subsystemLine", "subsystems", 
			"definitionLine", "simpleDefinition", "indexedDefinition", "expression", 
			"sumExpression", "arithmeticExpression", "elementaryExpression", "sumindices", 
			"botindex", "topindex", "sign", "arithmethic"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, "'parameter'", "'sum'", "'subsystem'", null, 
			"'='", "','", "'+'", "'-'", "'*'", "'/'", "'^'", "'_'", "'['", "']'", 
			"'('", "')'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "NEWLINE", "Comment", "WS", "PARAMETER", "SUM", "SUBSYSTEM", "SIGMA", 
			"EQUAL", "COMMA", "ADD", "SUB", "MUL", "DIV", "CARET", "USCORE", "INDEXOPEN", 
			"INDEXCLOSE", "ARGOPEN", "ARGCLOSE", "SYMBOLNAME"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "QDSLParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public QDSLParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class MainContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(QDSLParser.EOF, 0); }
		public List<LineContext> line() {
			return getRuleContexts(LineContext.class);
		}
		public LineContext line(int i) {
			return getRuleContext(LineContext.class,i);
		}
		public MainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_main; }
	}

	public final MainContext main() throws RecognitionException {
		MainContext _localctx = new MainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_main);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(39);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << NEWLINE) | (1L << PARAMETER) | (1L << SUBSYSTEM) | (1L << SYMBOLNAME))) != 0)) {
				{
				{
				setState(36);
				line();
				}
				}
				setState(41);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(42);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LineContext extends ParserRuleContext {
		public ParameterLineContext parameterLine() {
			return getRuleContext(ParameterLineContext.class,0);
		}
		public SubsystemLineContext subsystemLine() {
			return getRuleContext(SubsystemLineContext.class,0);
		}
		public DefinitionLineContext definitionLine() {
			return getRuleContext(DefinitionLineContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(QDSLParser.NEWLINE, 0); }
		public LineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_line; }
	}

	public final LineContext line() throws RecognitionException {
		LineContext _localctx = new LineContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_line);
		try {
			setState(48);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PARAMETER:
				enterOuterAlt(_localctx, 1);
				{
				setState(44);
				parameterLine();
				}
				break;
			case SUBSYSTEM:
				enterOuterAlt(_localctx, 2);
				{
				setState(45);
				subsystemLine();
				}
				break;
			case SYMBOLNAME:
				enterOuterAlt(_localctx, 3);
				{
				setState(46);
				definitionLine();
				}
				break;
			case NEWLINE:
				enterOuterAlt(_localctx, 4);
				{
				setState(47);
				match(NEWLINE);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterLineContext extends ParserRuleContext {
		public TerminalNode PARAMETER() { return getToken(QDSLParser.PARAMETER, 0); }
		public ParametersContext parameters() {
			return getRuleContext(ParametersContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(QDSLParser.NEWLINE, 0); }
		public ParameterLineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterLine; }
	}

	public final ParameterLineContext parameterLine() throws RecognitionException {
		ParameterLineContext _localctx = new ParameterLineContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_parameterLine);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(50);
			match(PARAMETER);
			setState(51);
			parameters();
			setState(53);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				{
				setState(52);
				match(NEWLINE);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParametersContext extends ParserRuleContext {
		public Token SYMBOLNAME;
		public List<Token> elements = new ArrayList<Token>();
		public List<TerminalNode> SYMBOLNAME() { return getTokens(QDSLParser.SYMBOLNAME); }
		public TerminalNode SYMBOLNAME(int i) {
			return getToken(QDSLParser.SYMBOLNAME, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(QDSLParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(QDSLParser.COMMA, i);
		}
		public ParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameters; }
	}

	public final ParametersContext parameters() throws RecognitionException {
		ParametersContext _localctx = new ParametersContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_parameters);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(55);
			((ParametersContext)_localctx).SYMBOLNAME = match(SYMBOLNAME);
			((ParametersContext)_localctx).elements.add(((ParametersContext)_localctx).SYMBOLNAME);
			setState(60);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(56);
				match(COMMA);
				setState(57);
				((ParametersContext)_localctx).SYMBOLNAME = match(SYMBOLNAME);
				((ParametersContext)_localctx).elements.add(((ParametersContext)_localctx).SYMBOLNAME);
				}
				}
				setState(62);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SubsystemLineContext extends ParserRuleContext {
		public TerminalNode SUBSYSTEM() { return getToken(QDSLParser.SUBSYSTEM, 0); }
		public SubsystemsContext subsystems() {
			return getRuleContext(SubsystemsContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(QDSLParser.NEWLINE, 0); }
		public SubsystemLineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_subsystemLine; }
	}

	public final SubsystemLineContext subsystemLine() throws RecognitionException {
		SubsystemLineContext _localctx = new SubsystemLineContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_subsystemLine);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(63);
			match(SUBSYSTEM);
			setState(64);
			subsystems();
			setState(66);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				{
				setState(65);
				match(NEWLINE);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SubsystemsContext extends ParserRuleContext {
		public Token SYMBOLNAME;
		public List<Token> elements = new ArrayList<Token>();
		public List<TerminalNode> SYMBOLNAME() { return getTokens(QDSLParser.SYMBOLNAME); }
		public TerminalNode SYMBOLNAME(int i) {
			return getToken(QDSLParser.SYMBOLNAME, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(QDSLParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(QDSLParser.COMMA, i);
		}
		public SubsystemsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_subsystems; }
	}

	public final SubsystemsContext subsystems() throws RecognitionException {
		SubsystemsContext _localctx = new SubsystemsContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_subsystems);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(68);
			((SubsystemsContext)_localctx).SYMBOLNAME = match(SYMBOLNAME);
			((SubsystemsContext)_localctx).elements.add(((SubsystemsContext)_localctx).SYMBOLNAME);
			setState(73);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(69);
				match(COMMA);
				setState(70);
				((SubsystemsContext)_localctx).SYMBOLNAME = match(SYMBOLNAME);
				((SubsystemsContext)_localctx).elements.add(((SubsystemsContext)_localctx).SYMBOLNAME);
				}
				}
				setState(75);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DefinitionLineContext extends ParserRuleContext {
		public SimpleDefinitionContext simpleDefinition() {
			return getRuleContext(SimpleDefinitionContext.class,0);
		}
		public IndexedDefinitionContext indexedDefinition() {
			return getRuleContext(IndexedDefinitionContext.class,0);
		}
		public DefinitionLineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_definitionLine; }
	}

	public final DefinitionLineContext definitionLine() throws RecognitionException {
		DefinitionLineContext _localctx = new DefinitionLineContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_definitionLine);
		try {
			setState(78);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(76);
				simpleDefinition();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(77);
				indexedDefinition();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SimpleDefinitionContext extends ParserRuleContext {
		public Token object;
		public ExpressionContext expression;
		public List<ExpressionContext> definitions = new ArrayList<ExpressionContext>();
		public TerminalNode EQUAL() { return getToken(QDSLParser.EQUAL, 0); }
		public TerminalNode SYMBOLNAME() { return getToken(QDSLParser.SYMBOLNAME, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(QDSLParser.NEWLINE, 0); }
		public SimpleDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleDefinition; }
	}

	public final SimpleDefinitionContext simpleDefinition() throws RecognitionException {
		SimpleDefinitionContext _localctx = new SimpleDefinitionContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_simpleDefinition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(80);
			((SimpleDefinitionContext)_localctx).object = match(SYMBOLNAME);
			setState(81);
			match(EQUAL);
			setState(82);
			((SimpleDefinitionContext)_localctx).expression = expression();
			((SimpleDefinitionContext)_localctx).definitions.add(((SimpleDefinitionContext)_localctx).expression);
			setState(84);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				{
				setState(83);
				match(NEWLINE);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IndexedDefinitionContext extends ParserRuleContext {
		public Token object;
		public ExpressionContext expression;
		public List<ExpressionContext> definitions = new ArrayList<ExpressionContext>();
		public BotindexContext botindex() {
			return getRuleContext(BotindexContext.class,0);
		}
		public TerminalNode EQUAL() { return getToken(QDSLParser.EQUAL, 0); }
		public TerminalNode SYMBOLNAME() { return getToken(QDSLParser.SYMBOLNAME, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(QDSLParser.NEWLINE, 0); }
		public IndexedDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_indexedDefinition; }
	}

	public final IndexedDefinitionContext indexedDefinition() throws RecognitionException {
		IndexedDefinitionContext _localctx = new IndexedDefinitionContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_indexedDefinition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(86);
			((IndexedDefinitionContext)_localctx).object = match(SYMBOLNAME);
			setState(87);
			botindex();
			setState(88);
			match(EQUAL);
			setState(89);
			((IndexedDefinitionContext)_localctx).expression = expression();
			((IndexedDefinitionContext)_localctx).definitions.add(((IndexedDefinitionContext)_localctx).expression);
			setState(91);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				{
				setState(90);
				match(NEWLINE);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public List<ArithmeticExpressionContext> arithmeticExpression() {
			return getRuleContexts(ArithmeticExpressionContext.class);
		}
		public ArithmeticExpressionContext arithmeticExpression(int i) {
			return getRuleContext(ArithmeticExpressionContext.class,i);
		}
		public List<SumExpressionContext> sumExpression() {
			return getRuleContexts(SumExpressionContext.class);
		}
		public SumExpressionContext sumExpression(int i) {
			return getRuleContext(SumExpressionContext.class,i);
		}
		public List<ArithmethicContext> arithmethic() {
			return getRuleContexts(ArithmethicContext.class);
		}
		public ArithmethicContext arithmethic(int i) {
			return getRuleContext(ArithmethicContext.class,i);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(95);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SIGMA:
			case ADD:
			case SUB:
			case ARGOPEN:
			case SYMBOLNAME:
				{
				setState(93);
				arithmeticExpression();
				}
				break;
			case SUM:
				{
				setState(94);
				sumExpression();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(104);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ADD) | (1L << SUB) | (1L << MUL) | (1L << DIV) | (1L << CARET))) != 0)) {
				{
				{
				setState(97);
				arithmethic();
				setState(100);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case SIGMA:
				case ADD:
				case SUB:
				case ARGOPEN:
				case SYMBOLNAME:
					{
					setState(98);
					arithmeticExpression();
					}
					break;
				case SUM:
					{
					setState(99);
					sumExpression();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				}
				setState(106);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SumExpressionContext extends ParserRuleContext {
		public SumindicesContext boundary;
		public TerminalNode SUM() { return getToken(QDSLParser.SUM, 0); }
		public TerminalNode ARGOPEN() { return getToken(QDSLParser.ARGOPEN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode ARGCLOSE() { return getToken(QDSLParser.ARGCLOSE, 0); }
		public SumindicesContext sumindices() {
			return getRuleContext(SumindicesContext.class,0);
		}
		public SumExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sumExpression; }
	}

	public final SumExpressionContext sumExpression() throws RecognitionException {
		SumExpressionContext _localctx = new SumExpressionContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_sumExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(107);
			match(SUM);
			setState(108);
			((SumExpressionContext)_localctx).boundary = sumindices();
			setState(109);
			match(ARGOPEN);
			setState(110);
			expression();
			setState(111);
			match(ARGCLOSE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArithmeticExpressionContext extends ParserRuleContext {
		public List<ElementaryExpressionContext> elementaryExpression() {
			return getRuleContexts(ElementaryExpressionContext.class);
		}
		public ElementaryExpressionContext elementaryExpression(int i) {
			return getRuleContext(ElementaryExpressionContext.class,i);
		}
		public SignContext sign() {
			return getRuleContext(SignContext.class,0);
		}
		public List<ArithmethicContext> arithmethic() {
			return getRuleContexts(ArithmethicContext.class);
		}
		public ArithmethicContext arithmethic(int i) {
			return getRuleContext(ArithmethicContext.class,i);
		}
		public ArithmeticExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arithmeticExpression; }
	}

	public final ArithmeticExpressionContext arithmeticExpression() throws RecognitionException {
		ArithmeticExpressionContext _localctx = new ArithmeticExpressionContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_arithmeticExpression);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(114);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ADD || _la==SUB) {
				{
				setState(113);
				sign();
				}
			}

			setState(116);
			elementaryExpression();
			setState(122);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(117);
					arithmethic();
					setState(118);
					elementaryExpression();
					}
					} 
				}
				setState(124);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ElementaryExpressionContext extends ParserRuleContext {
		public Token name;
		public TerminalNode SIGMA() { return getToken(QDSLParser.SIGMA, 0); }
		public TerminalNode SYMBOLNAME() { return getToken(QDSLParser.SYMBOLNAME, 0); }
		public BotindexContext botindex() {
			return getRuleContext(BotindexContext.class,0);
		}
		public TerminalNode ARGOPEN() { return getToken(QDSLParser.ARGOPEN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode ARGCLOSE() { return getToken(QDSLParser.ARGCLOSE, 0); }
		public ElementaryExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_elementaryExpression; }
	}

	public final ElementaryExpressionContext elementaryExpression() throws RecognitionException {
		ElementaryExpressionContext _localctx = new ElementaryExpressionContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_elementaryExpression);
		int _la;
		try {
			setState(133);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SIGMA:
			case SYMBOLNAME:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(125);
				((ElementaryExpressionContext)_localctx).name = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==SIGMA || _la==SYMBOLNAME) ) {
					((ElementaryExpressionContext)_localctx).name = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(127);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==USCORE) {
					{
					setState(126);
					botindex();
					}
				}

				}
				}
				break;
			case ARGOPEN:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(129);
				match(ARGOPEN);
				setState(130);
				expression();
				setState(131);
				match(ARGCLOSE);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SumindicesContext extends ParserRuleContext {
		public BotindexContext botindex() {
			return getRuleContext(BotindexContext.class,0);
		}
		public TopindexContext topindex() {
			return getRuleContext(TopindexContext.class,0);
		}
		public SumindicesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sumindices; }
	}

	public final SumindicesContext sumindices() throws RecognitionException {
		SumindicesContext _localctx = new SumindicesContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_sumindices);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(135);
			botindex();
			setState(136);
			topindex();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BotindexContext extends ParserRuleContext {
		public Token SYMBOLNAME;
		public List<Token> indices = new ArrayList<Token>();
		public TerminalNode USCORE() { return getToken(QDSLParser.USCORE, 0); }
		public List<TerminalNode> SYMBOLNAME() { return getTokens(QDSLParser.SYMBOLNAME); }
		public TerminalNode SYMBOLNAME(int i) {
			return getToken(QDSLParser.SYMBOLNAME, i);
		}
		public TerminalNode INDEXOPEN() { return getToken(QDSLParser.INDEXOPEN, 0); }
		public TerminalNode INDEXCLOSE() { return getToken(QDSLParser.INDEXCLOSE, 0); }
		public List<TerminalNode> COMMA() { return getTokens(QDSLParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(QDSLParser.COMMA, i);
		}
		public BotindexContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_botindex; }
	}

	public final BotindexContext botindex() throws RecognitionException {
		BotindexContext _localctx = new BotindexContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_botindex);
		int _la;
		try {
			setState(151);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(138);
				match(USCORE);
				setState(139);
				((BotindexContext)_localctx).SYMBOLNAME = match(SYMBOLNAME);
				((BotindexContext)_localctx).indices.add(((BotindexContext)_localctx).SYMBOLNAME);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(140);
				match(USCORE);
				setState(141);
				match(INDEXOPEN);
				setState(142);
				((BotindexContext)_localctx).SYMBOLNAME = match(SYMBOLNAME);
				((BotindexContext)_localctx).indices.add(((BotindexContext)_localctx).SYMBOLNAME);
				setState(147);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(143);
					match(COMMA);
					setState(144);
					((BotindexContext)_localctx).SYMBOLNAME = match(SYMBOLNAME);
					((BotindexContext)_localctx).indices.add(((BotindexContext)_localctx).SYMBOLNAME);
					}
					}
					setState(149);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(150);
				match(INDEXCLOSE);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TopindexContext extends ParserRuleContext {
		public Token index;
		public TerminalNode CARET() { return getToken(QDSLParser.CARET, 0); }
		public TerminalNode SYMBOLNAME() { return getToken(QDSLParser.SYMBOLNAME, 0); }
		public TerminalNode INDEXOPEN() { return getToken(QDSLParser.INDEXOPEN, 0); }
		public TerminalNode INDEXCLOSE() { return getToken(QDSLParser.INDEXCLOSE, 0); }
		public TopindexContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_topindex; }
	}

	public final TopindexContext topindex() throws RecognitionException {
		TopindexContext _localctx = new TopindexContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_topindex);
		try {
			setState(159);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(153);
				match(CARET);
				setState(154);
				((TopindexContext)_localctx).index = match(SYMBOLNAME);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(155);
				match(CARET);
				setState(156);
				match(INDEXOPEN);
				setState(157);
				((TopindexContext)_localctx).index = match(SYMBOLNAME);
				setState(158);
				match(INDEXCLOSE);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SignContext extends ParserRuleContext {
		public TerminalNode ADD() { return getToken(QDSLParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(QDSLParser.SUB, 0); }
		public SignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sign; }
	}

	public final SignContext sign() throws RecognitionException {
		SignContext _localctx = new SignContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_sign);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(161);
			_la = _input.LA(1);
			if ( !(_la==ADD || _la==SUB) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArithmethicContext extends ParserRuleContext {
		public TerminalNode ADD() { return getToken(QDSLParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(QDSLParser.SUB, 0); }
		public TerminalNode MUL() { return getToken(QDSLParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(QDSLParser.DIV, 0); }
		public TerminalNode CARET() { return getToken(QDSLParser.CARET, 0); }
		public ArithmethicContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arithmethic; }
	}

	public final ArithmethicContext arithmethic() throws RecognitionException {
		ArithmethicContext _localctx = new ArithmethicContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_arithmethic);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(163);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ADD) | (1L << SUB) | (1L << MUL) | (1L << DIV) | (1L << CARET))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\26\u00a8\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\3\2\7\2(\n\2\f\2\16\2+\13\2\3\2\3\2\3\3\3\3\3\3\3\3\5\3\63"+
		"\n\3\3\4\3\4\3\4\5\48\n\4\3\5\3\5\3\5\7\5=\n\5\f\5\16\5@\13\5\3\6\3\6"+
		"\3\6\5\6E\n\6\3\7\3\7\3\7\7\7J\n\7\f\7\16\7M\13\7\3\b\3\b\5\bQ\n\b\3\t"+
		"\3\t\3\t\3\t\5\tW\n\t\3\n\3\n\3\n\3\n\3\n\5\n^\n\n\3\13\3\13\5\13b\n\13"+
		"\3\13\3\13\3\13\5\13g\n\13\7\13i\n\13\f\13\16\13l\13\13\3\f\3\f\3\f\3"+
		"\f\3\f\3\f\3\r\5\ru\n\r\3\r\3\r\3\r\3\r\7\r{\n\r\f\r\16\r~\13\r\3\16\3"+
		"\16\5\16\u0082\n\16\3\16\3\16\3\16\3\16\5\16\u0088\n\16\3\17\3\17\3\17"+
		"\3\20\3\20\3\20\3\20\3\20\3\20\3\20\7\20\u0094\n\20\f\20\16\20\u0097\13"+
		"\20\3\20\5\20\u009a\n\20\3\21\3\21\3\21\3\21\3\21\3\21\5\21\u00a2\n\21"+
		"\3\22\3\22\3\23\3\23\3\23\2\2\24\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36"+
		" \"$\2\5\4\2\t\t\26\26\3\2\f\r\3\2\f\20\2\u00aa\2)\3\2\2\2\4\62\3\2\2"+
		"\2\6\64\3\2\2\2\b9\3\2\2\2\nA\3\2\2\2\fF\3\2\2\2\16P\3\2\2\2\20R\3\2\2"+
		"\2\22X\3\2\2\2\24a\3\2\2\2\26m\3\2\2\2\30t\3\2\2\2\32\u0087\3\2\2\2\34"+
		"\u0089\3\2\2\2\36\u0099\3\2\2\2 \u00a1\3\2\2\2\"\u00a3\3\2\2\2$\u00a5"+
		"\3\2\2\2&(\5\4\3\2\'&\3\2\2\2(+\3\2\2\2)\'\3\2\2\2)*\3\2\2\2*,\3\2\2\2"+
		"+)\3\2\2\2,-\7\2\2\3-\3\3\2\2\2.\63\5\6\4\2/\63\5\n\6\2\60\63\5\16\b\2"+
		"\61\63\7\3\2\2\62.\3\2\2\2\62/\3\2\2\2\62\60\3\2\2\2\62\61\3\2\2\2\63"+
		"\5\3\2\2\2\64\65\7\6\2\2\65\67\5\b\5\2\668\7\3\2\2\67\66\3\2\2\2\678\3"+
		"\2\2\28\7\3\2\2\29>\7\26\2\2:;\7\13\2\2;=\7\26\2\2<:\3\2\2\2=@\3\2\2\2"+
		"><\3\2\2\2>?\3\2\2\2?\t\3\2\2\2@>\3\2\2\2AB\7\b\2\2BD\5\f\7\2CE\7\3\2"+
		"\2DC\3\2\2\2DE\3\2\2\2E\13\3\2\2\2FK\7\26\2\2GH\7\13\2\2HJ\7\26\2\2IG"+
		"\3\2\2\2JM\3\2\2\2KI\3\2\2\2KL\3\2\2\2L\r\3\2\2\2MK\3\2\2\2NQ\5\20\t\2"+
		"OQ\5\22\n\2PN\3\2\2\2PO\3\2\2\2Q\17\3\2\2\2RS\7\26\2\2ST\7\n\2\2TV\5\24"+
		"\13\2UW\7\3\2\2VU\3\2\2\2VW\3\2\2\2W\21\3\2\2\2XY\7\26\2\2YZ\5\36\20\2"+
		"Z[\7\n\2\2[]\5\24\13\2\\^\7\3\2\2]\\\3\2\2\2]^\3\2\2\2^\23\3\2\2\2_b\5"+
		"\30\r\2`b\5\26\f\2a_\3\2\2\2a`\3\2\2\2bj\3\2\2\2cf\5$\23\2dg\5\30\r\2"+
		"eg\5\26\f\2fd\3\2\2\2fe\3\2\2\2gi\3\2\2\2hc\3\2\2\2il\3\2\2\2jh\3\2\2"+
		"\2jk\3\2\2\2k\25\3\2\2\2lj\3\2\2\2mn\7\7\2\2no\5\34\17\2op\7\24\2\2pq"+
		"\5\24\13\2qr\7\25\2\2r\27\3\2\2\2su\5\"\22\2ts\3\2\2\2tu\3\2\2\2uv\3\2"+
		"\2\2v|\5\32\16\2wx\5$\23\2xy\5\32\16\2y{\3\2\2\2zw\3\2\2\2{~\3\2\2\2|"+
		"z\3\2\2\2|}\3\2\2\2}\31\3\2\2\2~|\3\2\2\2\177\u0081\t\2\2\2\u0080\u0082"+
		"\5\36\20\2\u0081\u0080\3\2\2\2\u0081\u0082\3\2\2\2\u0082\u0088\3\2\2\2"+
		"\u0083\u0084\7\24\2\2\u0084\u0085\5\24\13\2\u0085\u0086\7\25\2\2\u0086"+
		"\u0088\3\2\2\2\u0087\177\3\2\2\2\u0087\u0083\3\2\2\2\u0088\33\3\2\2\2"+
		"\u0089\u008a\5\36\20\2\u008a\u008b\5 \21\2\u008b\35\3\2\2\2\u008c\u008d"+
		"\7\21\2\2\u008d\u009a\7\26\2\2\u008e\u008f\7\21\2\2\u008f\u0090\7\22\2"+
		"\2\u0090\u0095\7\26\2\2\u0091\u0092\7\13\2\2\u0092\u0094\7\26\2\2\u0093"+
		"\u0091\3\2\2\2\u0094\u0097\3\2\2\2\u0095\u0093\3\2\2\2\u0095\u0096\3\2"+
		"\2\2\u0096\u0098\3\2\2\2\u0097\u0095\3\2\2\2\u0098\u009a\7\23\2\2\u0099"+
		"\u008c\3\2\2\2\u0099\u008e\3\2\2\2\u009a\37\3\2\2\2\u009b\u009c\7\20\2"+
		"\2\u009c\u00a2\7\26\2\2\u009d\u009e\7\20\2\2\u009e\u009f\7\22\2\2\u009f"+
		"\u00a0\7\26\2\2\u00a0\u00a2\7\23\2\2\u00a1\u009b\3\2\2\2\u00a1\u009d\3"+
		"\2\2\2\u00a2!\3\2\2\2\u00a3\u00a4\t\3\2\2\u00a4#\3\2\2\2\u00a5\u00a6\t"+
		"\4\2\2\u00a6%\3\2\2\2\25)\62\67>DKPV]afjt|\u0081\u0087\u0095\u0099\u00a1";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}