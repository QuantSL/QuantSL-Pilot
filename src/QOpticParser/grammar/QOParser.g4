parser grammar QOParser;

options {
	tokenVocab = QOLexer;
}

main : (line)* EOF;

line : parameterLine | subsystemLine | definitionLine | NEWLINE;

parameterLine : PARAMETER parameters NEWLINE?;
parameters    : elements+=SYMBOLNAME (COMMA elements+=SYMBOLNAME)*;

subsystemLine : SUBSYSTEM subsystems NEWLINE?;
subsystems    : elements+=SYMBOLNAME (COMMA elements+=SYMBOLNAME)*;

definitionLine    : simpleDefinition | indexedDefinition;
simpleDefinition  : object=SYMBOLNAME          EQUAL definitions+=expression NEWLINE?;
indexedDefinition : object=SYMBOLNAME botindex EQUAL definitions+=expression NEWLINE?;

expression           : (arithmeticexpression | sumexpression) (artimethic (arithmeticexpression | sumexpression))*;
sumexpression        : SUM boundary=sumindices ARGOPEN arithmeticexpression ARGCLOSE;
arithmeticexpression : sign? SYMBOLNAME botindex? (artimethic (SYMBOLNAME botindex?))*;

sumindices        : botindex topindex;
botindex          : USCORE           indices+=SYMBOLNAME
									| USCORE INDEXOPEN indices+=SYMBOLNAME (COMMA indices+=SYMBOLNAME)* INDEXCLOSE;
topindex          : CARET            indices+=SYMBOLNAME
									| CARET  INDEXOPEN indices+=SYMBOLNAME (COMMA indices+=SYMBOLNAME)* INDEXCLOSE;

sign							: ADD | SUB;
artimethic				: ADD | SUB | MUL | DIV | CARET;
