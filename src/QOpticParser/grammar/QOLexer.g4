lexer grammar QOLexer;

channels { CommentsChannel }

NEWLINE   : '\r'? '\n';

Comment : '#' ~[\r\n]* NEWLINE? -> channel(CommentsChannel);
WS      : ([ \t]+ | '\\' ' '* NEWLINE) -> skip;

EQUAL : '=';
COMMA : ',';

// Keywords
PARAMETER : 'parameter';
SUM       : 'sum';

// Sigma : ('σ' | 'sigma') ('x' | 'y' | 'z' | '⁺' | '⁻') INDEX;
// fragment INDEX : '_' [a-z];

// TODO: right now SYMBOLNAME clashes with too many things, I have to find a more generic solution
SYMBOLNAME : UNICODENAME SUBSCRIPTNAME?;
fragment UNICODENAME : UNICODELETTER UNICODESYMBOL*;
fragment UNICODELETTER : [a-zA-Z\u0391-\u03C9];     // Include greek symbols
fragment UNICODESYMBOL : [a-zA-Z0-9\u0391-\u03C9];
fragment SUBSCRIPTNAME : '_{' UNICODESYMBOL+ '}';

SINGLEINDEX : '_';
INDEXOPEN   : '_[';
INDEXCLOSE  : ']';
ARGOPEN     : '(';
ARGCLOSE    : ')';

ARITHMETIC : ADDITION | '*' | '/' | '^';
ADDITION   : '+' | '-';
