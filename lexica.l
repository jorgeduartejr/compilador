%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
ID {LETRA}({LETRA}|{NUM})*
CHAR \'({LETRA}|{NUM})\'
BOOL \'(true|false)\'

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}

"float"		{return TK_TIPO_FLOAT;}

"bool"		{return TK_TIPO_BOOL;}

"char"		{return TK_TIPO_CHAR;}

"(int)"		{return TK_CAST_INT;}

"(float)"	{return TK_CAST_FLOAT;}

[(){}[\];,]	{ return *yytext; }

[+\-*/]	    { return *yytext; }

"="         { return '='; }

"=="        { return TK_IG; }

"!="        { return TK_DIF; }

">="        { return TK_MAIG; }

"<="        { return TK_MEIG; }

">"         { return TK_MAIOR; }

"<"         { return TK_MENOR; }

"&&"        { return TK_AND; }

"||"        { return TK_OR; }


{NUM}		{ yylval.label = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{REAL}      { yylval.label = yytext; return TK_REAL; }
{CHAR}      { yylval.label = yytext; return TK_CHAR; }
{BOOL}      { yylval.label = yytext; return TK_BOOL; }


%%
