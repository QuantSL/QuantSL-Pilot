parser grammar QDSLParser;

options {
	tokenVocab = QDSLLexer;
}

main : (line)* EOF;

line : parameterLine | subsystemLine | definitionLine | NEWLINE;

parameterLine : PARAMETER parameters NEWLINE?;
parameters    : elements+=SYMBOLNAME (COMMA elements+=SYMBOLNAME)*;

subsystemLine : SUBSYSTEM subsystems NEWLINE?;
subsystems    : elements+=SYMBOLNAME (COMMA elements+=SYMBOLNAME)*;

definitionLine    : simpleDefinition | indexedDefinition;
simpleDefinition  : object=SYMBOLNAME          EQUAL definition=expression NEWLINE?;
indexedDefinition : object=SYMBOLNAME botindex EQUAL definition=expression NEWLINE?;

expression           : (arithmeticExpression | sumExpression) (arithmethic (arithmeticExpression | sumExpression))*;
sumExpression        : SUM boundary=sumindices ARGOPEN expression ARGCLOSE;
arithmeticExpression : sign? elementaryExpression (arithmethic elementaryExpression)*;
elementaryExpression : (name=(SIGMA | SYMBOLNAME) botindex?) | (ARGOPEN expression ARGCLOSE);

sumindices        : botindex topindex;
// TODO: add support for interger indices
botindex          : USCORE           indices+=SYMBOLNAME
									| USCORE INDEXOPEN indices+=SYMBOLNAME (COMMA indices+=SYMBOLNAME)* INDEXCLOSE;
topindex          : CARET               index=SYMBOLNAME
									| CARET  INDEXOPEN    index=SYMBOLNAME INDEXCLOSE;

sign							: ADD | SUB;
arithmethic				: ADD | SUB | MUL | DIV | CARET;
