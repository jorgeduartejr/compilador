%{
#include <iostream>
#include <string>
#include <sstream>
#include <vector>



#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
};
typedef struct{
	string nomeVariavel;
	string tipoVariavel;
} TIPO_SIMBOLO;

int var_temp_qnt;
vector<TIPO_SIMBOLO> tabelaSimbolos;

int yylex(void);
void yyerror(string);
string gentempcode();
%}

%token TK_NUM TK_REAL TK_BOOL TK_CHAR
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL
%token TK_FIM TK_ERROR

%start S

%left '+'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<math.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			| TK_TIPO_INT TK_ID ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "int";
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
						yyerror("Variavel ja declarada");
					}
				}
				tabelaSimbolos.push_back(valor);

				$$.traducao = "";
				$$.label = "";
			}
			| TK_TIPO_BOOL TK_ID ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "bool";
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
						yyerror("Variavel ja declarada");
					}
				}
				tabelaSimbolos.push_back(valor);

				$$.traducao = "";
				$$.label = "";
			}
			| TK_TIPO_BOOL TK_ID '=' E ';'{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "bool";
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
						yyerror("Variavel ja declarada");
					}
				}
				tabelaSimbolos.push_back(valor);

				$$.traducao = $4.traducao + "\t" + $2.tipo + "\t" + $2.label + " = " + $4.label + ";\n";
				$$.label = "";
			} 

			| TK_TIPO_INT TK_ID '=' E ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "int";
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
						yyerror("Variavel ja declarada");
					}
				}
				tabelaSimbolos.push_back(valor);

				$$.traducao = $4.traducao + "\t" + $2.tipo + "\t" + $2.label + " = " + $4.label + ";\n";
				$$.label = "";
			}
			| TK_TIPO_CHAR TK_ID '=' E ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "char";
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
						yyerror("Variavel ja declarada");
					}
				}
				tabelaSimbolos.push_back(valor);

				$$.traducao = $4.traducao + "\t" + $2.tipo + "\t" + $2.label + " = " + $4.label + ";\n";
				$$.label = "";
			}
			| TK_TIPO_FLOAT TK_ID '=' E ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "float";
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
						yyerror("Variavel ja declarada");
					}
				}
				tabelaSimbolos.push_back(valor);

				$$.traducao = $4.traducao + "\t" + $2.tipo + "\t" + $2.label + " = " + $4.label + ";\n";
				$$.label = "";
			}
			| TK_TIPO_FLOAT TK_ID ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "float";
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
						yyerror("Variavel ja declarada");
					}
				}
				tabelaSimbolos.push_back(valor);

				$$.traducao = "";
				$$.label = "";
			}
			| TK_TIPO_CHAR TK_ID ';' // verificar isso aqui depois, pq pode ser que seja com vector
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "char";
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
						yyerror("Variavel ja declarada");
					}
				}
				tabelaSimbolos.push_back(valor);

				$$.traducao = "";
				$$.label = "";
			}
			;
			
E 			: '('E')'
            {
			    $$ = $2;
			}
            | E '+' E //vou colocar o tipo float como default
			{
			
			
				if($1.tipo != $3.tipo) //default = tipo float mas talvez precise mudar
				{
					if($1.tipo == "int" && $3.tipo == "float") 
					{
						$1.label = "(float)" + $1.label;
						$1.tipo = "float";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						$3.label = "(float)" + $3.label;
						$3.tipo = "float";
					}
				}
				$$.label = gentempcode();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $1.tipo + "\t" + $$.label +
					" = " + $1.label + " + " + $3.label + ";\n";
			}
			| E '-' E
			{
				if($1.tipo != $3.tipo) //default = tipo float mas talvez precise mudar
				{
					if($1.tipo == "int" && $3.tipo == "float") 
					{
						$1.label = "(float)" + $1.label;
						$1.tipo = "float";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						$3.label = "(float)" + $3.label;
						$3.tipo = "float";
					}
				}
				$$.label = gentempcode();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $1.tipo + "\t" + $$.label +
					" = " + $1.label + " - " + $3.label + ";\n";
			}
			| E '*' E
			{
				if($1.tipo != $3.tipo) //default = tipo float mas talvez precise mudar
				{
					if($1.tipo == "int" && $3.tipo == "float") 
					{
						$1.label = "(float)" + $1.label;
						$1.tipo = "float";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						$3.label = "(float)" + $3.label;
						$3.tipo = "float";
					}
				}
				$$.label = gentempcode();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $1.tipo + "\t" + $$.label +
					" = " + $1.label + " * " + $3.label + ";\n";
			}
			| E '/' E
			{
				if($1.tipo != $3.tipo) //default = tipo float mas talvez precise mudar
				{
					if($1.tipo == "int" && $3.tipo == "float") 
					{
						$1.label = "(float)" + $1.label;
						$1.tipo = "float";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						$3.label = "(float)" + $3.label;
						$3.tipo = "float";
					}
				}
				$$.label = gentempcode();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $1.tipo + "\t" + $$.label +
					" = " + $1.label + " / " + $3.label + ";\n";
			}
			| E '^' E
			{
				if($1.tipo != "float" || $3.tipo != "float") // talvez precise de typecasting na hora da igualacao em caso de inteiro 
				{                                            // porem o compilador C aparentemente trunca isso ai entao da pra tankar
					
						$1.label = "(float)" + $1.label;
						$1.tipo = "float";
						$3.label = "(float)" + $3.label;
						$3.tipo = "float";
					
				}
				$$.label = gentempcode();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $1.tipo + "\t" + $$.label +
					" = " "powf("+ $1.label + "," + $3.label + ")" + ";\n";
			}
			| TK_ID '=' E
			{
				$$.traducao = $1.traducao + $3.traducao +  "\t" + $3.tipo + "\t" +  $1.label + " = " + $3.label + ";\n";
			}
			| TK_NUM
			{	
				$$.tipo = "int";
				$$.label = gentempcode();
				$$.traducao = "\t"+ $$.tipo + "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_REAL
			{
				$$.tipo = "float";
				$$.label = gentempcode();
				$$.traducao = "\t"+ $$.tipo + "\t" + $$.label + " = " + $1.label + ";\n";
			}

			| TK_BOOL
			{
				$$.tipo = "bool";
				$$.label = gentempcode();
				$$.traducao = "\t"+ $$.tipo + "\t" + $$.label + " = " + $1.label + ";\n";
			}

			| TK_ID
			{
				bool encontrei = false;
				TIPO_SIMBOLO variavel;
				for(int i = 0; i < tabelaSimbolos.size(); i++){
					if(tabelaSimbolos[i].nomeVariavel == $1.label){
						variavel = tabelaSimbolos[i];
						encontrei = true;
					}
				}
				if(!encontrei){
					yyerror("Variavel nao declarada");
				}

				$$.tipo = variavel.tipoVariavel;
				$$.label = gentempcode();
				$$.traducao = "\t" + $$.tipo + "\t" + $$.label + " = " + $1.label + ";\n";
			}	
			;

%%

#include "lex.yy.c"

int yyparse();

string gentempcode(){
	var_temp_qnt++;
	return "t" + std::to_string(var_temp_qnt);
}

int main( int argc, char* argv[] )
{

	var_temp_qnt = 0;

	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				