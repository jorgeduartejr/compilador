%{
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <set>

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
	string size = "";
	string sobrepor = "";
	stack<int> scope;
} TIPO_SIMBOLO;

int var_temp_qnt;
vector<TIPO_SIMBOLO> tabelaSimbolos;
int flag;
int marcador;
static int cont = 0;
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
		n += "\t" + tabelaSimbolos[i].tipoVariavel + "\t" + tabelaSimbolos[i].nomeTemp  + tabelaSimbolos[i].size + ";\n";
	}
	return n;
}
/*void printpilhasdeSimbolos()
{
	//string n = "";
	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		cout << "\t" << tabelaSimbolos[i].scope.top()<< " " <<tabelaSimbolos[i].nomeTemp<<endl;
	}
	//return n;
}*/
%}



%token TK_NUM TK_REAL TK_BOOL TK_CHAR TK_OP_REL  TK_STRING _STRING
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_CAST_INT TK_CAST_FLOAT TK_TIPO_STRING //TK_CAST_CHAR TK_CAST_BOOL
%token TK_FIM TK_ERROR  TK_PRINT TK_SCAN
%token TK_IG TK_DIF TK_MAIG TK_MEIG TK_MAIOR TK_MENOR TK_AND TK_OR TK_NOT TK_MAIS_MAIS TK_MENOS_MENOS TK_IF TK_ELSE_IF TK_ELSE TK_WHILE TK_DO TK_FOR TK_SWITCH TK_CASE TK_BREAK TK_DEFAULT TK_CONTINUE TK_RETURN

%start S

%left '+' '-'
%left '*'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				
				cout << "/*Compilador InsaneLabz XGH*/\n" << "#include <iostream>\n#include<string.h>\n#include<math.h>\n#include<stdio.h>\nint main(void)\n{\n" << printtabelaSimbolos() << $5.traducao  << "\treturn 0;\n}" << endl; 
				//printpilhasdeSimbolos();
			}
			;

BLOCO		: '{' INICIO COMANDOS FIM'}'
			{
				//escopototal.push(flag);
				//flag++;
				$$.traducao = $3.traducao;
				//escopototal.pop();

			}
			;

INICIO      : 
            {
	            flag++; 
				escopototal.push(flag);
				$$.traducao = "";
			}
            ;

FIM         :
            {
				escopototal.pop();
				$$.traducao = "";
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
CONDICAO	: TK_IF '(' E ')' BLOCO
			{
				cont ++;
                $$.label = gentempcode();
                addtabSimbolos($$.label,"int");
                $$.traducao =$3.traducao + "\t" + $$.label + " != " + $3.label + ";\n"; 
                $$.traducao+="\tif(" + $$.label + ") goto fim_if_Label" + to_string(cont) + ";\n" 
				+ $5.traducao + "\tfim_if_Label"+ to_string(cont) + ":\n\n";
			}
			|TK_ELSE_IF'(' E ')' BLOCO
            {	
				cont ++;
                $$.label = gentempcode();
                addtabSimbolos($$.label,"int");
                $$.traducao = $3.traducao + "\t" + $$.label + " != " + $3.label + ";\n"; 
                $$.traducao+="\tif("+ $$.label + ") goto fim_else_if_Label" + to_string(cont) + ";\n" 
				+ $5.traducao + "\tfim_else_if_Label" + to_string(cont) + ":\n\n";
            }
			| CONDICAO TK_ELSE BLOCO
            {
                $$.traducao= $1.traducao + "\tif(!" + $1.label + ") goto fim_else_Label" + to_string(cont) 
				+ ";\n" + $3.traducao + "\tfim_else_Label" + to_string(cont) + ";\n\n";
            }
			;
LOOP        : TK_WHILE '(' E ')' '{'INICIO COMANDOS BREAK1 FIM'}'
            {
                $$.label = gentempcode();
                string tempVar = gentempcode();
                addtabSimbolos($$.label,"int");

                //Adicionando na tabela de simbolos a temporária que verifica se while é verdadeiro.
                TIPO_SIMBOLO temp;
                temp.nomeVariavel = tempVar;
                temp.tipoVariavel = "int";
                temp.scope = escopototal;
                tabelaSimbolos.push_back(temp); 

                $$.traducao ="inicio_while"+ to_string(cont) +":\n"+ $3.traducao + "\t" + $$.label + " = " + $3.label + ";\n\t" + tempVar + " = !" + $$.label + ";\n"; 
                $$.traducao+="\tif(" + tempVar + ") goto fim_Label"+ to_string(cont)  +";\n" + $7.traducao + $8.traducao + "\tgoto inicio_while"+ to_string(cont) +";\n" +"fim_Label" + to_string(cont) + ":\n";
            }
            | TK_FOR '('E ';' E ';' E')' '{'INICIO COMANDOS BREAK1 FIM'}'
            {
                $$.label = gentempcode();
                string tempVar = gentempcode();
                addtabSimbolos($$.label,"int");
                $$.traducao ="inicio_for"+ to_string(cont) +":\n"+ $3.traducao + $5.traducao + "\t" + $$.label + " = " + $5.label + ";\n\t" + tempVar + " = !" + $$.label + ";\n"; 
                $$.traducao+="\tif(" + tempVar + ") goto fim_Label"+ to_string(cont) +";\n" + $11.traducao + $12.traducao + $7.traducao +"\tgoto inicio_for"+ to_string(cont) +";\n" +"fim_Label" + to_string(cont) + ":\n\n";

                //Adicionando na tabela de simbolos a temporária que verifica se while é verdadeiro.
                TIPO_SIMBOLO temp;
                temp.nomeVariavel = tempVar;
                temp.tipoVariavel = "int";
                temp.scope = escopototal;
                tabelaSimbolos.push_back(temp);
            }
            |TK_DO '{'INICIO COMANDOS BREAK1 FIM '}' TK_WHILE '(' E ')' ';'
            {
                $$.label = gentempcode();
                string tempVar = gentempcode();
                addtabSimbolos($$.label,"int");

                $$.traducao ="inicio_do_while"+ to_string(cont) +":\n"+ $4.traducao + $5.traducao; 
                $$.traducao+=$10.traducao + "\tif(" + $10.label + ") goto inicio_do_while"+ to_string(cont) + "\n";
            }
            ;

            //break e continue pro while
BREAK1       : TK_BREAK ';' COMANDOS BREAK1
            {
                
                $$.traducao = "\tgoto fim_Label" + to_string(cont) + ";\n" + $3.traducao + $4.traducao;
            }
            |
            TK_CONTINUE ';' COMANDOS BREAK1
            {
                $$.traducao = "\tgoto fim_Label" + to_string(cont) + ";\n" + $3.traducao + $4.traducao;
            }
            |
            {
                cont ++;
                $$.traducao = "";
            }
            ;
			/* | TK_WHILE '(' E ')' BLOCO{} */
			/* | TK_DO BLOCO TK_WHILE '(' E ')' BLOCO
			{} */
			/* | TK_FOR '(' E ';' E ';' E ')' BLOCO
			{} */
			/* | TK_SWITCH '(' E ')' '{' CASES DEFAULT '}'
			{} */
			/* | TK_BREAK ';'
			{} */
COMANDO 	: E ';'
			| CONDICAO
			| LOOP 
			| BLOCO
			{
				$$ = $1;
			} 
			| TK_TIPO_INT TK_ID ';'
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "int";
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
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
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
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
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
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
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
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
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
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
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
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
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
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
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);

				$$.traducao = "";
				$$.label = "";
			}
			| TK_TIPO_STRING TK_ID ';' // verificar isso aqui depois, pq pode ser que seja com vector
			{
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel =  "char*";
				valor.nomeTemp = gentempcode()  ; valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);

				$$.traducao = "";
				$$.label = "";
			}
			| TK_TIPO_STRING TK_ID  '=' E ';'
			{
				std::string str ($4.label);
				string a = std::to_string(str.length()-1);
				TIPO_SIMBOLO valor;
				//string a = '['+ $3.label +']';
				valor.nomeVariavel = $2.label;
				valor.tipoVariavel = "char*";
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);
                $2.label = valor.nomeTemp;
				$2.tipo = valor.tipoVariavel;
				$$.traducao = $4.traducao + "\t" + $2.label + '=' + "malloc" + '(' + a + '*' + "sizeof(char*)" + ')' + ";\n" + "\t" + "strcpy" + '(' + $2.label + " , " + $4.label + ')'  + ";\n";
				$$.label = "";
			}
			;
			
E 			: '('E')'
            {
			    $$ = $2;
			}
			|TK_STRING
			{
				$$.label = $1.label;
				$1.tipo = "string";
				$$ = $1;
			}
			| TK_PRINT '('E')'
			{
				if($3.tipo == "string")
				{
                    $$.traducao = $3.traducao + "\t" + "print"+ "f("+  $3.label + ")"+ ";\n";
				}
				else
				{
				    switch($3.tipo[0])
					{
						case 'i':
						$$.traducao = $3.traducao + "\t" + "print"+ "f("+ '%' + "d,"+ $3.label + ')'+ ";\n";
						break;
						case 'c':
						$$.traducao = $3.traducao +"\t" + "print"+ "f("+ '%' + "s,"+ $3.label + ')'+ ";\n";
						break;
						case 'f':
						$$.traducao = $3.traducao +"\t" + "print"+ "f("+ '%' + "f,"+ $3.label + ')'+ ";\n";
						break;
					}
				}
			}
			| TK_SCAN'('E')'
			{
				if($3.tipo == "char" || $3.tipo == "char*")
				{
					TIPO_SIMBOLO valor;
				    valor.nomeVariavel = "";
				    valor.tipoVariavel = "char*";
				    valor.nomeTemp = gentempcode(); 
					valor.scope = escopototal;
					//valor.size = "[1000]";
					TIPO_SIMBOLO valor2;
				    valor2.nomeVariavel = "";
				    valor2.tipoVariavel = "int";
				    valor2.nomeTemp = gentempcode(); 
					valor2.scope = escopototal;
					$$.label = valor.nomeTemp;
					$$.tipo = valor.tipoVariavel;
				    tabelaSimbolos.push_back(valor);
					tabelaSimbolos.push_back(valor2);
					int i = 1;
						string salvador1 = "";
						string salvador2 = "";
					while ($3.traducao[i] != '='){
                            salvador1 += $3.traducao[i];
							i++;
						} 
						i = i + 2;
						while ($3.traducao[i] != ';'){
                            salvador2 += $3.traducao[i];
							i++;
					}
                    $$.traducao = $3.traducao +"\t" + "scanf"+ "("+ '%' + "s," + '&' + $3.label + ")" + ";\n" + "\t" + valor2.nomeTemp + '=' + '0' + ";\n" + "\t" +"definidor:" + "\n" + "\t"
					 + "if(" + $3.label + '['+valor2.nomeTemp +']' + "!=" + '"' + '\\' + '0'+ '"' +')' + '{'+  valor2.nomeTemp + '=' + valor2.nomeTemp + '+' + '1' + ';' + "goto definidor;" + '}' + "\n" +
					"\t" + $$.label + '=' + "malloc(" + valor2.nomeTemp + '*' + "sizeof(char)" + ')' + ";\n" + "\t" +"strcpy(" + $$.label + ',' + $3.label+')' + ";\n" + "\t" + salvador2 + '=' + "malloc(" + valor2.nomeTemp + '*' + "sizeof(char)" + ')' + ";\n" + "\t" +"strcpy(" + salvador2 + ',' + $$.label+')' + ";\n";
				}
				else
				{
				    switch($3.tipo[0])
					{
						case 'i':
						{
						TIPO_SIMBOLO valori;
				        valori.nomeVariavel = "";
				        valori.tipoVariavel = "int";
				        valori.nomeTemp = gentempcode(); 
					    valori.scope = escopototal;
						tabelaSimbolos.push_back(valori);
						$$.label = valori.nomeTemp;
					    $$.tipo = valori.tipoVariavel;
						int i = 1;
						string salvador1 = "";
						string salvador2 = "";
						while ($3.traducao[i] != '='){
                            salvador1 += $3.traducao[i];
							i++;
						} 
						i++;
						while ($3.traducao[i] != ';'){
                            salvador2 += $3.traducao[i];
							i++;
						}
						$$.traducao = $3.traducao + "\t" + "scan"+ "f("+ '%' + "d," + '&' + $3.label + ')'+ ";\n" + "\t" + salvador2 + ' ' + '=' + ' ' +salvador1 + ";\n";
						break;
						}
						//case 'c':
						//$$.traducao = $3.traducao +"\t" + "print"+ "f("+ '%' + "c,"+ $3.label + ')'+ ";\n";
						//break;
						case 'f':
						{
						TIPO_SIMBOLO valorf;
				        valorf.nomeVariavel = "";
				        valorf.tipoVariavel = "float";
				        valorf.nomeTemp = gentempcode(); 
					    valorf.scope = escopototal;
						tabelaSimbolos.push_back(valorf);
						$$.label = valorf.nomeTemp;
					    $$.tipo = valorf.tipoVariavel;
						int i = 1;
						string salvador1 = "";
						string salvador2 = "";
						while ($3.traducao[i] != '='){
                            salvador1 += $3.traducao[i];
							i++;
						} 
						i++;
						while ($3.traducao[i] != ';'){
                            salvador2 += $3.traducao[i];
							i++;
						}
						$$.traducao = $3.traducao + "\t" + "scan"+ "f("+ '%' + "f," + '&' + $3.label + ')'+ ";\n" + "\t" + salvador2 + ' ' + '=' + ' ' +salvador1 + ";\n";
						break;
						}
					}
				}
			}
            | E '+' E //vou colocar o tipo float como default
			{
				if($1.tipo == "char" || $1.tipo == "char*")
				{
					$$.label = gentempcode();
				    addtabSimbolos( $$.label, $1.tipo);
                    $$.traducao = $1.traducao + $3.traducao + "\t"+ $$.label + '='+ "malloc("+"sizeof("+$1.label +')'+ '+'+ "sizeof(" + $3.label +')'+')'+";\n"+ "\t" + $$.label + '=' + "strcat" + '(' + $1.label + " , " + $3.label + ')'  + ";\n";
				}
				else{
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
				}}
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
				// if ($1.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
                // if ($3.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
				// if($1.tipo != $3.tipo) 
				
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
				if ($1.tipo != "bool"){
                    yyerror("ERRO! Operação inválida");
                }
                if ($3.tipo != "bool"){
                    yyerror("ERRO! Operação inválida");
                }
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
				// if ($1.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
                // if ($3.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
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
				} else {
						$$.label = gentempcode();
						$$.tipo = $1.tipo;
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + // a = $1, b = $3, c = $$ 
						" = " + $1.label + " > " + $3.label + ";\n";  // caracter = " < "
						// Atualizar tipo da temporária com base nos tipos dos operandos
						TIPO_SIMBOLO temp;
						temp.nomeVariavel = $$.label;
						temp.scope = escopototal;
						temp.tipoVariavel = $$.tipo;
						tabelaSimbolos.push_back(temp);
					}
			}
			| E TK_MENOR E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{
				// if ($1.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
                // if ($3.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
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
				} else {
					$$.label = gentempcode();
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + // a = $1, b = $3, c = $$ 
						" = " + $1.label + " < " + $3.label + ";\n";  // caracter = " < "
					// Atualizar tipo da temporária com base nos tipos dos operandos
					TIPO_SIMBOLO temp;
					temp.nomeVariavel = $$.label;
					temp.scope = escopototal;
					temp.tipoVariavel = $$.tipo;
					tabelaSimbolos.push_back(temp);
				}
			}
			| E TK_MAIG E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{	
				// if ($1.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
                // if ($3.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
				if($1.tipo != $3.tipo) {
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
				else {
					$$.label = gentempcode();
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + // a = $1, b = $3, c = $$ 
						" = " + $1.label + " >= " + $3.label + ";\n";  // caracter = " < "
					// Atualizar tipo da temporária com base nos tipos dos operandos
					TIPO_SIMBOLO temp;
					temp.nomeVariavel = $$.label;
					temp.scope = escopototal;
					temp.tipoVariavel = $$.tipo;
					tabelaSimbolos.push_back(temp);
				}
			}

			| E TK_MEIG E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{
				// if ($1.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
                // if ($3.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
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
				} else {
					$$.label = gentempcode();
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + // a = $1, b = $3, c = $$ 
						" = " + $1.label + " <= " + $3.label + ";\n";  // caracter = " < "
					// Atualizar tipo da temporária com base nos tipos dos operandos
					TIPO_SIMBOLO temp;
					temp.nomeVariavel = $$.label;
					temp.scope = escopototal;
					temp.tipoVariavel = $$.tipo;
					tabelaSimbolos.push_back(temp);
				}
			}
			| E TK_AND E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{	
				if ($1.tipo != "bool"){
                    yyerror("ERRO! Operação inválida");
                }
                if ($3.tipo != "bool"){
                    yyerror("ERRO! Operação inválida");
                }
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
				} else {
					$$.label = gentempcode();
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + // a = $1, b = $3, c = $$ 
						" = " + $1.label + " && " + $3.label + ";\n";  // caracter = " < "
					// Atualizar tipo da temporária com base nos tipos dos operandos
					TIPO_SIMBOLO temp;
					temp.nomeVariavel = $$.label;
					temp.scope = escopototal;
					temp.tipoVariavel = $$.tipo;
					tabelaSimbolos.push_back(temp);
				}
			}
			| E TK_OR E //PRECISA ADICIONAR NA TABELA E AJEITAR USE A FUNCAO addtabSimbolos()
			{	
				if ($1.tipo != "bool"){
                    yyerror("ERRO! Operação inválida");
                }
                if ($3.tipo != "bool"){
                    yyerror("ERRO! Operação inválida");
                }
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
				} else {
					$$.label = gentempcode();
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + // a = $1, b = $3, c = $$ 
						" = " + $1.label + " || " + $3.label + ";\n";  // caracter = " < "
					// Atualizar tipo da temporária com base nos tipos dos operandos
					TIPO_SIMBOLO temp;
					temp.nomeVariavel = $$.label;
					temp.scope = escopototal;
					temp.tipoVariavel = $$.tipo;
					tabelaSimbolos.push_back(temp);
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
				stack<int> ordem = escopototal;
                set<int> referencias;
                //int bob;
                bool fin;
                while(!ordem.empty()){
                    //bob = ordem.pop();
                    referencias.insert(ordem.top());
                    ordem.pop();
                }
                for(int i = 0; i < tabelaSimbolos.size(); i++){
                    fin = referencias.find(tabelaSimbolos[i].scope.top()) != referencias.end();
                    if(tabelaSimbolos[i].nomeVariavel == $1.label  && tabelaSimbolos[i].scope.size() <= escopototal.size() && fin == true){
                        variavel = tabelaSimbolos[i];
                        encontrei = true;
                    }
                }
				if(!encontrei){
					yyerror("Variavel nao declarada");
				}
				if($3.tipo == "string")
				{
					$1.label = variavel.nomeTemp;
					std::string criativo ($3.label);
					string tamanho = std::to_string(criativo.length()-1); 
                    $$.traducao = "\t" + $1.label + '=' + "malloc" + '(' + tamanho + '*' + "sizeof(char)" + ')' + ";\n" + $1.traducao + $3.traducao + "\t" + "strcpy(" + $1.label + " , " + $3.label + ')' + ";\n";
				}
				else if($3.tipo == "char*")
				{
					$1.label = variavel.nomeTemp;
                    $$.traducao = "\t" + $1.label + '=' + "malloc" + '(' + "sizeof(" + $3.label +')' + ')' + ";\n" + $1.traducao + $3.traducao + "\t" + "strcpy(" + $1.label + " , " + $3.label + ')' + ";\n";
				}
				else
				{
				    $1.label = variavel.nomeTemp;
				    $$.traducao = $1.traducao + $3.traducao + "\t" +  $1.label + " = " + $3.label + ";\n";
				}
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
					$$.tipo = "bool"; 
					$$.label = gentempcode();
					addtabSimbolos($$.label, $$.tipo);
					$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
				} 
				else {
					bool encontrei = false;
				TIPO_SIMBOLO variavel;
				stack<int> ordem = escopototal;
                set<int> referencias;
                //int bob;
                bool fin;
                while(!ordem.empty()){
                    //bob = ordem.pop();
                    referencias.insert(ordem.top());
                    ordem.pop();
                }
                for(int i = 0; i < tabelaSimbolos.size(); i++){
                    fin = referencias.find(tabelaSimbolos[i].scope.top()) != referencias.end();
                    if(tabelaSimbolos[i].nomeVariavel == $1.label  && tabelaSimbolos[i].scope.size() <= escopototal.size() && fin == true){
                        variavel = tabelaSimbolos[i];
                        encontrei = true;
                    }
                }
				if(!encontrei){
					if($1.label == "true" || $1.label == "false"){
						$$.tipo = "bool";
					} else {
						yyerror("Variavel nao declarada");
					}
				}
				else if(variavel.tipoVariavel == "char*")
				{
                    $1.label = variavel.nomeTemp;
				    $$.tipo = variavel.tipoVariavel;
				    $$.label = gentempcode();
					addtabSimbolos($$.label, $$.tipo);
					$$.traducao = "\t" + $$.label + '=' + "malloc(" + "sizeof(" + $1.label +')' + ')' + ";\n" + "\t" + $$.label + '=' + "strcpy(" + $$.label + ',' + $1.label + ')' + ";\n";
				}
				else{
                $1.label = variavel.nomeTemp;
				$$.tipo = variavel.tipoVariavel;
				$$.label = gentempcode();
				addtabSimbolos($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
				}
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