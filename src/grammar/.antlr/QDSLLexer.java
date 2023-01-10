// Generated from /Users/kevin/Documents/QTune/Pilot Julia/src/ITensorParser/grammar/QDSLLexer.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class QDSLLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		NEWLINE=1, Comment=2, WS=3, PARAMETER=4, SUM=5, SUBSYSTEM=6, SIGMA=7, 
		EQUAL=8, COMMA=9, ADD=10, SUB=11, MUL=12, DIV=13, CARET=14, USCORE=15, 
		INDEXOPEN=16, INDEXCLOSE=17, ARGOPEN=18, ARGCLOSE=19, SYMBOLNAME=20;
	public static final int
		CommentsChannel=2;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN", "CommentsChannel"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"NEWLINE", "Comment", "WS", "PARAMETER", "SUM", "SUBSYSTEM", "SIGMA", 
			"EQUAL", "COMMA", "ADD", "SUB", "MUL", "DIV", "CARET", "USCORE", "INDEXOPEN", 
			"INDEXCLOSE", "ARGOPEN", "ARGCLOSE", "SYMBOLNAME", "UNICODENAME", "UNICODELETTER", 
			"UNICODESYMBOL", "SUBSCRIPTNAME"
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


	public QDSLLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "QDSLLexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\26\u00a4\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\3\2\5\2\65\n\2\3\2\3\2\3\3\3\3\7\3;\n\3\f\3\16\3>\13\3\3\3\3\3\3"+
		"\4\6\4C\n\4\r\4\16\4D\3\4\3\4\7\4I\n\4\f\4\16\4L\13\4\3\4\5\4O\n\4\3\4"+
		"\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\7\3\7\3"+
		"\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3\b\3\b\5\bq\n\b\3\b\3"+
		"\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\20"+
		"\3\20\3\21\3\21\3\22\3\22\3\23\3\23\3\24\3\24\3\25\3\25\5\25\u008f\n\25"+
		"\3\26\3\26\7\26\u0093\n\26\f\26\16\26\u0096\13\26\3\27\3\27\3\30\3\30"+
		"\3\31\3\31\3\31\6\31\u009f\n\31\r\31\16\31\u00a0\3\31\3\31\2\2\32\3\3"+
		"\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21"+
		"!\22#\23%\24\'\25)\26+\2-\2/\2\61\2\3\2\7\4\2\f\f\17\17\4\2\13\13\"\""+
		"\6\2oorrz|\u207c\u207d\5\2C\\c|\u0393\u03cb\6\2\62;C\\c|\u0393\u03cb\2"+
		"\u00a8\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2"+
		"\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3"+
		"\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2"+
		"\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\3\64\3\2\2\2\58\3\2\2\2"+
		"\7N\3\2\2\2\tR\3\2\2\2\13\\\3\2\2\2\r`\3\2\2\2\17p\3\2\2\2\21t\3\2\2\2"+
		"\23v\3\2\2\2\25x\3\2\2\2\27z\3\2\2\2\31|\3\2\2\2\33~\3\2\2\2\35\u0080"+
		"\3\2\2\2\37\u0082\3\2\2\2!\u0084\3\2\2\2#\u0086\3\2\2\2%\u0088\3\2\2\2"+
		"\'\u008a\3\2\2\2)\u008c\3\2\2\2+\u0090\3\2\2\2-\u0097\3\2\2\2/\u0099\3"+
		"\2\2\2\61\u009b\3\2\2\2\63\65\7\17\2\2\64\63\3\2\2\2\64\65\3\2\2\2\65"+
		"\66\3\2\2\2\66\67\7\f\2\2\67\4\3\2\2\28<\7%\2\29;\n\2\2\2:9\3\2\2\2;>"+
		"\3\2\2\2<:\3\2\2\2<=\3\2\2\2=?\3\2\2\2><\3\2\2\2?@\b\3\2\2@\6\3\2\2\2"+
		"AC\t\3\2\2BA\3\2\2\2CD\3\2\2\2DB\3\2\2\2DE\3\2\2\2EO\3\2\2\2FJ\7^\2\2"+
		"GI\7\"\2\2HG\3\2\2\2IL\3\2\2\2JH\3\2\2\2JK\3\2\2\2KM\3\2\2\2LJ\3\2\2\2"+
		"MO\5\3\2\2NB\3\2\2\2NF\3\2\2\2OP\3\2\2\2PQ\b\4\3\2Q\b\3\2\2\2RS\7r\2\2"+
		"ST\7c\2\2TU\7t\2\2UV\7c\2\2VW\7o\2\2WX\7g\2\2XY\7v\2\2YZ\7g\2\2Z[\7t\2"+
		"\2[\n\3\2\2\2\\]\7u\2\2]^\7w\2\2^_\7o\2\2_\f\3\2\2\2`a\7u\2\2ab\7w\2\2"+
		"bc\7d\2\2cd\7u\2\2de\7{\2\2ef\7u\2\2fg\7v\2\2gh\7g\2\2hi\7o\2\2i\16\3"+
		"\2\2\2jq\7\u03c5\2\2kl\7u\2\2lm\7k\2\2mn\7i\2\2no\7o\2\2oq\7c\2\2pj\3"+
		"\2\2\2pk\3\2\2\2qr\3\2\2\2rs\t\4\2\2s\20\3\2\2\2tu\7?\2\2u\22\3\2\2\2"+
		"vw\7.\2\2w\24\3\2\2\2xy\7-\2\2y\26\3\2\2\2z{\7/\2\2{\30\3\2\2\2|}\7,\2"+
		"\2}\32\3\2\2\2~\177\7\61\2\2\177\34\3\2\2\2\u0080\u0081\7`\2\2\u0081\36"+
		"\3\2\2\2\u0082\u0083\7a\2\2\u0083 \3\2\2\2\u0084\u0085\7]\2\2\u0085\""+
		"\3\2\2\2\u0086\u0087\7_\2\2\u0087$\3\2\2\2\u0088\u0089\7*\2\2\u0089&\3"+
		"\2\2\2\u008a\u008b\7+\2\2\u008b(\3\2\2\2\u008c\u008e\5+\26\2\u008d\u008f"+
		"\5\61\31\2\u008e\u008d\3\2\2\2\u008e\u008f\3\2\2\2\u008f*\3\2\2\2\u0090"+
		"\u0094\5-\27\2\u0091\u0093\5/\30\2\u0092\u0091\3\2\2\2\u0093\u0096\3\2"+
		"\2\2\u0094\u0092\3\2\2\2\u0094\u0095\3\2\2\2\u0095,\3\2\2\2\u0096\u0094"+
		"\3\2\2\2\u0097\u0098\t\5\2\2\u0098.\3\2\2\2\u0099\u009a\t\6\2\2\u009a"+
		"\60\3\2\2\2\u009b\u009c\5\37\20\2\u009c\u009e\7}\2\2\u009d\u009f\5/\30"+
		"\2\u009e\u009d\3\2\2\2\u009f\u00a0\3\2\2\2\u00a0\u009e\3\2\2\2\u00a0\u00a1"+
		"\3\2\2\2\u00a1\u00a2\3\2\2\2\u00a2\u00a3\7\177\2\2\u00a3\62\3\2\2\2\f"+
		"\2\64<DJNp\u008e\u0094\u00a0\4\2\4\2\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}