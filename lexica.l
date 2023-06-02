%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
BOOL \'(true|false)\'
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}

"float"		{return TK_TIPO_FLOAT;}

"bool"		{return TK_TIPO_BOOL;}

"char"		{return TK_TIPO_CHAR;}

[(){}[\];,]	{ return *yytext; }

[+\-*/^]	{ return *yytext; }

"="         { return '='; }

{NUM}		{ yylval.label = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{REAL}      { yylval.label = yytext; return TK_REAL; }
{CHAR}      { yylval.label = yytext; return TK_CHAR; }
{BOOL}      { yylval.label = yytext; return TK_BOOL; }
.			{ *yytext; }

%%
