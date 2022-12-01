lexer grammar QOLexer;

// Preamble
channels { CommentsChannel }

// Rudimentary comment and line handling
NEWLINE   : '\r'? '\n';

Comment : '#' ~[\r\n]* -> channel(CommentsChannel);
WS      : ([ \t]+ | '\\' ' '* NEWLINE) -> skip;

// Keywords
PARAMETER : 'parameter';
SUM       : 'sum';
SUBSYSTEM : 'subsystem';

// Elementary Operators
// TODO: let the elementary operators be defined by the user, by 'using Spin(1//2)' for example
SIGMA : ('σ' | 'sigma') ('x' | 'y' | 'z' | '⁺' | '⁻');

// Mathematical constructs
EQUAL : '=';
COMMA : ',';

ADD   : '+';
SUB   : '-';
MUL   : '*';
DIV   : '/';

// Index Constructs

CARET  : '^';
USCORE : '_';

INDEXOPEN      : '[';
INDEXCLOSE     : ']';
ARGOPEN        : '(';
ARGCLOSE       : ')';

// Unicode Names and fragments

SYMBOLNAME : UNICODENAME SUBSCRIPTNAME?;
fragment UNICODENAME : UNICODELETTER UNICODESYMBOL*;
fragment UNICODELETTER : [a-zA-Z\u0391-\u03C9];     // Include greek symbols
fragment UNICODESYMBOL : [a-zA-Z0-9\u0391-\u03C9];
fragment SUBSCRIPTNAME : USCORE '{' UNICODESYMBOL+ '}';
