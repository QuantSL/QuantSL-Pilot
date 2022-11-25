parser grammar QOParser;

options {
	tokenVocab = QOLexer;
}

main : (line)* EOF;

line : parameterLine | indexLine | definitionLine | NEWLINE;

parameterLine : PARAMETER parameters NEWLINE?;
parameters    : elements+=SYMBOLNAME (COMMA elements+=SYMBOLNAME)*;

indexLine : INDEX indices NEWLINE?;
indices   : elements+=SYMBOLNAME (COMMA elements+=SYMBOLNAME)*;

definitionLine    : simpleDefinition | indexedDefinition;
simpleDefinition  : object=SYMBOLNAME          EQUAL definitions+=expression NEWLINE?;
indexedDefinition : object=SYMBOLNAME botindex EQUAL definitions+=expression NEWLINE?;

expression        : sign? (SYMBOLNAME botindex? | sumexpression) (artimethic (SYMBOLNAME botindex? | sumexpression))*;
sumexpression     : SUM boundary=sumindices
										ARGOPEN
											sign? SYMBOLNAME botindex? (artimethic (SYMBOLNAME botindex?))*
										ARGCLOSE;

sumindices        : botindex topindex;
botindex          : USCORE           elements+=SYMBOLNAME
									| USCORE INDEXOPEN elements+=SYMBOLNAME (COMMA elements+=SYMBOLNAME)* INDEXCLOSE;
topindex          : CARET            elements+=SYMBOLNAME
									| CARET  INDEXOPEN elements+=SYMBOLNAME (COMMA elements+=SYMBOLNAME)* INDEXCLOSE;

sign							: ADD | SUB;
artimethic				: ADD | SUB | MUL | DIV | CARET;
