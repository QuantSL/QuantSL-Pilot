// Generated from /Users/kevin/Documents/QTune/Pilot Julia/src/QOpticParser/grammar/TLexer.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class TLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Comment=1, WS=2, NEWLINE=3, PARAMETER=4, EQUAL=5, COMMA=6, NAME=7, Sigma=8;
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
			"Comment", "WS", "NEWLINE", "PARAMETER", "EQUAL", "COMMA", "NAME", "Sigma", 
			"INDEX"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, "'parameter'", "'='", "','"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "Comment", "WS", "NEWLINE", "PARAMETER", "EQUAL", "COMMA", "NAME", 
			"Sigma"
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


	public TLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "TLexer.g4"; }

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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\n^\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\3\2\3\2"+
		"\7\2\30\n\2\f\2\16\2\33\13\2\3\2\5\2\36\n\2\3\2\3\2\3\2\3\2\3\3\6\3%\n"+
		"\3\r\3\16\3&\3\3\3\3\7\3+\n\3\f\3\16\3.\13\3\3\3\5\3\61\n\3\3\3\5\3\64"+
		"\n\3\3\3\3\3\3\4\5\49\n\4\3\4\3\4\6\4=\n\4\r\4\16\4>\3\5\3\5\3\5\3\5\3"+
		"\5\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\t"+
		"\5\tW\n\t\3\t\3\t\3\t\3\n\3\n\3\n\2\2\13\3\3\5\4\7\5\t\6\13\7\r\b\17\t"+
		"\21\n\23\2\3\2\7\4\2\f\f\17\17\4\2\13\13\"\"\3\2..\4\2z|\u207c\u207d\5"+
		"\2))cc||\2f\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2"+
		"\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\3\25\3\2\2\2\5\63\3\2\2\2\7<"+
		"\3\2\2\2\t@\3\2\2\2\13J\3\2\2\2\rL\3\2\2\2\17N\3\2\2\2\21V\3\2\2\2\23"+
		"[\3\2\2\2\25\31\7%\2\2\26\30\n\2\2\2\27\26\3\2\2\2\30\33\3\2\2\2\31\27"+
		"\3\2\2\2\31\32\3\2\2\2\32\35\3\2\2\2\33\31\3\2\2\2\34\36\7\17\2\2\35\34"+
		"\3\2\2\2\35\36\3\2\2\2\36\37\3\2\2\2\37 \7\f\2\2 !\3\2\2\2!\"\b\2\2\2"+
		"\"\4\3\2\2\2#%\t\3\2\2$#\3\2\2\2%&\3\2\2\2&$\3\2\2\2&\'\3\2\2\2\'\64\3"+
		"\2\2\2(,\7^\2\2)+\7\"\2\2*)\3\2\2\2+.\3\2\2\2,*\3\2\2\2,-\3\2\2\2-\60"+
		"\3\2\2\2.,\3\2\2\2/\61\7\17\2\2\60/\3\2\2\2\60\61\3\2\2\2\61\62\3\2\2"+
		"\2\62\64\7\f\2\2\63$\3\2\2\2\63(\3\2\2\2\64\65\3\2\2\2\65\66\b\3\3\2\66"+
		"\6\3\2\2\2\679\7\17\2\28\67\3\2\2\289\3\2\2\29:\3\2\2\2:=\7\f\2\2;=\7"+
		"\17\2\2<8\3\2\2\2<;\3\2\2\2=>\3\2\2\2><\3\2\2\2>?\3\2\2\2?\b\3\2\2\2@"+
		"A\7r\2\2AB\7c\2\2BC\7t\2\2CD\7c\2\2DE\7o\2\2EF\7g\2\2FG\7v\2\2GH\7g\2"+
		"\2HI\7t\2\2I\n\3\2\2\2JK\7?\2\2K\f\3\2\2\2LM\7.\2\2M\16\3\2\2\2NO\n\4"+
		"\2\2O\20\3\2\2\2PW\7\u03c5\2\2QR\7u\2\2RS\7k\2\2ST\7i\2\2TU\7o\2\2UW\7"+
		"c\2\2VP\3\2\2\2VQ\3\2\2\2WX\3\2\2\2XY\t\5\2\2YZ\5\23\n\2Z\22\3\2\2\2["+
		"\\\7a\2\2\\]\t\6\2\2]\24\3\2\2\2\r\2\31\35&,\60\638<>V\4\2\4\2\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}