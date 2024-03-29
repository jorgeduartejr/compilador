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
BOOL "true"|"false"
STRING \"(({LETRA}|{NUM}|{ESPACO}|[(){}[];,]|[+-/=%$#@!&¨<>,.;|^~`´?]|[éÉçÇãÃáÁÀàÊêõÕôôÔÓóÒòÚú])+)?\"

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

"!"         { return TK_NOT; }

"++"        { return TK_MAIS_MAIS; }

"--"        { return TK_MENOS_MENOS; }

"if"        { return TK_IF; }

"else"      { return TK_ELSE; }

"else if"    { return TK_ELSE_IF; }

"while"     { return TK_WHILE; }

"for"       { return TK_FOR; }

"return"    { return TK_RETURN; }

"break"     { return TK_BREAK; }

"continue"  { return TK_CONTINUE; }

"string"    { return TK_TIPO_STRING; }

"print"     { return TK_PRINT; }

"scan"      { return TK_SCAN; }

{STRING}    { yylval.label = yytext; return TK_STRING; }
{NUM}		{ yylval.label = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{REAL}      { yylval.label = yytext; return TK_REAL; }
{CHAR}      { yylval.label = yytext; return TK_CHAR; }
{BOOL}      { yylval.label = yytext; return TK_BOOL; }


%%
