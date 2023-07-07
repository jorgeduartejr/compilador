%{
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>


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
	string nomeTemp;
	stack<int> scope;
} TIPO_SIMBOLO;

int var_temp_qnt;
vector<TIPO_SIMBOLO> tabelaSimbolos;
int flag;
int marcador;
stack<int> escopototal;
int yylex(void);
void yyerror(string);
string gentempcode();
void addtabSimbolos(string ntemp, string tipo)
{
	TIPO_SIMBOLO novovar;
	novovar.nomeVariavel = "";
	novovar.tipoVariavel = tipo;
	novovar.nomeTemp = ntemp;
	novovar.scope = escopototal;
	tabelaSimbolos.push_back(novovar);
}
//void execute_casting(string label)
string printtabelaSimbolos()
{
	string n = "";
	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		n += "\t" + tabelaSimbolos[i].tipoVariavel + "\t" + tabelaSimbolos[i].nomeTemp + "\n";
	}
	return n;
}
%}



%token TK_NUM TK_REAL TK_BOOL TK_CHAR TK_OP_REL 
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_CAST_INT TK_CAST_FLOAT //TK_CAST_CHAR TK_CAST_BOOL
%token TK_FIM TK_ERROR 
%token TK_IG TK_DIF TK_MAIG TK_MEIG TK_MAIOR TK_MENOR TK_AND TK_OR TK_NOT TK_MAIS_MAIS TK_MENOS_MENOS TK_IF TK_ELSE TK_WHILE TK_DO TK_FOR TK_SWITCH TK_CASE TK_BREAK TK_DEFAULT TK_CONTINUE TK_RETURN

%start S

%left '+' '-'
%left '*'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<math.h>\n#include<stdio.h>\nint main(void)\n{\n" << printtabelaSimbolos() << $5.traducao << "\treturn 0;\n}" << endl; 
				
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
				escopototal.pop();

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
            | BLOCO
			{
                flag++;
				escopototal.push(flag);

			}
			| TK_TIPO_INT TK_ID ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "int";
				valor.nomeTemp = gentempcode();
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel && tabelaSimbolos[i].scope == escopototal)
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
				valor.tipoVariavel = "int";
				valor.nomeTemp = gentempcode();
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel && tabelaSimbolos[i].scope == escopototal)
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
				valor.tipoVariavel = "int";
				valor.nomeTemp = gentempcode();
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel && tabelaSimbolos[i].scope == escopototal)
					{
						yyerror("Variavel ja declarada");
					}
				}
				tabelaSimbolos.push_back(valor);
                $2.label = valor.nomeTemp;
				$2.tipo = valor.tipoVariavel;
				$$.traducao = $4.traducao + "\t" + $2.label + " = " + $4.label + ";\n";
				$$.label = "";
			} 

			| TK_TIPO_INT TK_ID '=' E ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "int";
				valor.nomeTemp = gentempcode();
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel && tabelaSimbolos[i].scope == escopototal)
					{
						yyerror("Variavel ja declarada");
					}
				}
				tabelaSimbolos.push_back(valor);
                $2.label = valor.nomeTemp;
				$2.tipo = valor.tipoVariavel;
				$$.traducao = $4.traducao + "\t" + $2.label + " = " + $4.label + ";\n";
				$$.label = "";
			}
			| TK_TIPO_CHAR TK_ID '=' E ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "char";
				valor.nomeTemp = gentempcode();
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel && tabelaSimbolos[i].scope == escopototal)
					{
						yyerror("Variavel ja declarada");
					}
				}
				tabelaSimbolos.push_back(valor);
                $2.label = valor.nomeTemp;
				$2.tipo = valor.tipoVariavel;
				$$.traducao = $4.traducao + "\t" + $2.label + " = " + $4.label + ";\n";
				$$.label = "";
			}
			| TK_TIPO_FLOAT TK_ID '=' E ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "float";
				valor.nomeTemp = gentempcode();
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel && tabelaSimbolos[i].scope == escopototal)
					{
						yyerror("Variavel ja declarada");
					}
				}
				tabelaSimbolos.push_back(valor);

                $2.label = valor.nomeTemp;
				$2.tipo = valor.tipoVariavel;
				$$.traducao = $4.traducao + "\t" + $2.label + " = " + $4.label + ";\n";
				$$.label = "";
			}
			| TK_TIPO_FLOAT TK_ID ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "float";
				valor.nomeTemp = gentempcode();
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel && tabelaSimbolos[i].scope == escopototal)
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
				valor.nomeTemp = gentempcode();
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel && tabelaSimbolos[i].scope == escopototal)
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
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " + " + $3.label + ";\n";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $3.label + ";\n" + "\t" + $$.label +
					    " = " + $1.label + " + " + castvar + ";\n";
					}
				}
				else{
				$$.label = gentempcode();
				addtabSimbolos( $$.label, $1.tipo);
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label +
					" = " + $1.label + " + " + $3.label + ";\n";
				}
			}
			| E '-' E
			{
				if($1.tipo != $3.tipo) //default = tipo float mas talvez precise mudar
				{
					if($1.tipo == "int" && $3.tipo == "float") 
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " - " + $3.label + ";\n";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $3.label + ";\n" + "\t" + $$.label +
					    " = " + $1.label + " - " + castvar + ";\n";
					}
				}
				else{
				$$.label = gentempcode();
				addtabSimbolos($$.label, $1.tipo);
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label +
					" = " + $1.label + " - " + $3.label + ";\n";
				}
			}
			| E '*' E
			{
				if($1.tipo != $3.tipo) //default = tipo float mas talvez precise mudar
				{
					if($1.tipo == "int" && $3.tipo == "float") 
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " * " + $3.label + ";\n";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $3.label + ";\n" + "\t" + $$.label +
					    " = " + $1.label + " * " + castvar + ";\n";
					}
				}
				else{
				$$.label = gentempcode();
				addtabSimbolos($$.label, $1.tipo);
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label +
					" = " + $1.label + " * " + $3.label + ";\n";
				}
			}
			| E '/' E
			{
				if($1.tipo != $3.tipo) //default = tipo float mas talvez precise mudar
				{
					if($1.tipo == "int" && $3.tipo == "float") 
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " / " + $3.label + ";\n";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $3.label + ";\n" + "\t" + $$.label +
					    " = " + $1.label + " / " + castvar + ";\n";
					}
				}
				else{
				$$.label = gentempcode();
				addtabSimbolos($$.label, $1.tipo);
				$$.traducao = $1.traducao + $3.traducao  + "\t" + $$.label +
					" = " + $1.label + " / " + $3.label + ";\n";
				}
			}
			| E TK_IG E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{	
				
				if($1.tipo != $3.tipo) 
				{
					if($1.tipo == "int" && $3.tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " == " + $3.label + ";\n";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " == " + $3.label + ";\n";
					}
				} 
			}
			| E TK_DIF E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{
				//$$.label = gentempcode();
				//$$.tipo = "bool";
				if($1.tipo != $3.tipo) 
				{
					if($1.tipo == "int" && $3.tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " != " + $3.label + ";\n";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " != " + $3.label + ";\n";
					}
				} 
				
			}
			| E TK_MAIOR E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{
				if($1.tipo != $3.tipo) 
				{
					if($1.tipo == "int" && $3.tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " > " + $3.label + ";\n";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " > " + $3.label + ";\n";
					}
				} 
			}
			| E TK_MENOR E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{
				if($1.tipo != $3.tipo) 
				{
					if($1.tipo == "int" && $3.tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " < " + $3.label + ";\n";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " < " + $3.label + ";\n";
					}
				} 
			}
			| E TK_MAIG E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{
				if($1.tipo != $3.tipo) 
				{
					if($1.tipo == "int" && $3.tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " >= " + $3.label + ";\n";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " >= " + $3.label + ";\n";
					}
				} 
			}
			| E TK_MEIG E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{
				if($1.tipo != $3.tipo) 
				{
					if($1.tipo == "int" && $3.tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " <= " + $3.label + ";\n";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " <= " + $3.label + ";\n";
					}
				} 
			}
			| E TK_AND E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{
				if($1.tipo != $3.tipo) 
				{
					if($1.tipo == "int" && $3.tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " && " + $3.label + ";\n";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " && " + $3.label + ";\n";
					}
				} 
			}
			| E TK_OR E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{
				if($1.tipo != $3.tipo) 
				{
					if($1.tipo == "int" && $3.tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " || " + $3.label + ";\n";
					}
					else if($1.tipo == "float" && $3.tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						$$.label = gentempcode();
				        addtabSimbolos( $$.label, "float");
				        $$.traducao = $1.traducao + $3.traducao + "\t" + castvar + " = " + "(float)" + $1.label + ";\n" + "\t" + $$.label +
					    " = " + castvar + " || " + $3.label + ";\n";
					}
				} 
			}
			| TK_NOT E
			{
				$$.label = gentempcode();
				$$.traducao = $2.traducao + "\t" + $$.label +
				" = ! " + $2.label + ";\n";
			}
			| E TK_MAIS_MAIS // incremental ++
			{
				$$.label = gentempcode();
				$$.tipo = "int";
				if($1.tipo != "int")
				{
					yyerror("Operacao invalida: incrementar variavel nao inteira");
				} else {
					addtabSimbolos($$.label, $$.tipo);
				}
				$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label + " + 1;\n";

			}
			| E TK_MENOS_MENOS // decremental --
			{
				$$.label = gentempcode();
				$$.tipo = "int";
				if($1.tipo != "int")
				{
					yyerror("Operacao invalida: decrementar variavel nao inteira");
				} else {
					addtabSimbolos($$.label, $$.tipo);
				}
				$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label + " - 1;\n";
			}
			| TK_CAST_INT E
			{
				if($2.tipo == "float")
				{
					$2.label = "(int)" + $2.label;
					$2.tipo = "int";
				}
				$$.label = gentempcode();
				$$.tipo = "int";
				$$.traducao = $2.traducao + "\t" + $$.label + " = " + $2.label + ";\n";
			}
			| TK_CAST_FLOAT E
			{
				if($2.tipo == "int")
				{
					$2.label = "(float)" + $2.label;
					$2.tipo = "float";
				}
				$$.label = gentempcode();
				$$.tipo = "float";
				$$.traducao = $2.traducao + "\t" + $$.label + " = " + $2.label + ";\n";
			}
			| TK_ID '=' E
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
				$1.label = variavel.nomeTemp;
				$$.traducao = $1.traducao + $3.traducao + "\t" +  $1.label + " = " + $3.label + ";\n";
			}
			| TK_NUM
			{	

				$$.tipo = "int";
				$$.label = gentempcode();
				addtabSimbolos($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_REAL
			{
				$$.tipo = "float";
				$$.label = gentempcode();
				addtabSimbolos($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}

			/* | TK_BOOL
			{
				$$.tipo = "bool"; // nao era pra ser secretamente int? 
				$$.label = gentempcode();
				addtabSimbolos($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			} */

			| TK_ID
			{
				if ($1.label == "true" || $1.label == "false"){
					$$.tipo = "int";
					$$.label = gentempcode();
					addtabSimbolos($$.label, $$.tipo);
					$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
				} else {
					bool encontrei = false;
				TIPO_SIMBOLO variavel;
				for(int i = tabelaSimbolos.size(); i >= 0; i--){
					if(tabelaSimbolos[i].nomeVariavel == $1.label && tabelaSimbolos[i].scope.size() <= escopototal.size() && tabelaSimbolos[i].scope.top()<=tabelaSimbolos[i].scope.top()){
						variavel = tabelaSimbolos[i];
						encontrei = true;
					}
				}
				if(!encontrei){
					if($1.label == "true" || $1.label == "false"){
						$$.tipo = "int";
					} else {
						yyerror("Variavel nao declarada");
					}
				}
                $1.label = variavel.nomeTemp;
				$$.tipo = variavel.tipoVariavel;
				$$.label = gentempcode();
				addtabSimbolos($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
				}
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
    flag = 0;
	var_temp_qnt = 0;
    escopototal.push(flag);
	yyparse();
    //cout << printtabelaSimbolos();
	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				