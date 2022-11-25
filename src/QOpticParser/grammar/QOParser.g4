parser grammar QOParser;

options {
	tokenVocab = QOLexer;
}

main : (line)* EOF;

line : parameterLine | definitionLine | NEWLINE;

parameterLine : PARAMETER parameters NEWLINE?;
parameters    : elements+=SYMBOLNAME (COMMA elements+=SYMBOLNAME)*;

definitionLine    : simpleDefinition | indexedDefinition;
simpleDefinition  : objects+=SYMBOLNAME       EQUAL definitions+=expression NEWLINE?;
indexedDefinition : objects+=SYMBOLNAME index EQUAL definitions+=expression NEWLINE?;
// indexedDefinition : objects+=SYMBOLNAME indices+=INDICES EQUAL definitions+=expression NEWLINE?;
expression        : ADDITION? (SYMBOLNAME index? | sumexpression) (ARITHMETIC (SYMBOLNAME index? | sumexpression))*;
index             : SINGLEINDEX elements+=SYMBOLNAME
									| INDEXOPEN   elements+=SYMBOLNAME (COMMA elements+=SYMBOLNAME)* INDEXCLOSE;
sumexpression     : SUM ARGOPEN ADDITION? SYMBOLNAME index? (ARITHMETIC (SYMBOLNAME index?))* ARGCLOSE;