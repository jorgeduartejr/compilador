# Compilador Simples

Este é um compilador desenvolvido para a disciplina de Compiladores da UFRRJ. Ele é capaz de analisar e compilar um subconjunto de uma linguagem de programação fictícia chamada FOCA.

## Estrutura do Projeto

- `Makefile`: Script de automação para compilar o projeto.
- `lexica.l`: Arquivo de definição do analisador léxico.
- `sintatica.y`: Arquivo de definição do analisador sintático.
- `exemplo.foca`: Exemplo de código fonte na linguagem FOCA.
- `backups/`: Diretório contendo backups do arquivo `sintatica.y`.
- `.gitignore`: Arquivo de configuração para ignorar arquivos gerados.
- `LICENSE`: Licença MIT.
- `README.md`: Este arquivo.

## Dependências

Para compilar e executar este projeto, você precisará das seguintes ferramentas instaladas:

- `flex`: Gerador de analisadores léxicos.
- `bison`: Gerador de analisadores sintáticos.
- `g++`: Compilador de C++.

## Funcionalidades do Compilador

O compilador XGH é capaz de:

- Analisar e reconhecer tokens da linguagem FOCA, como identificadores, números, operadores, palavras-chave, etc.
- Realizar análise sintática para verificar a estrutura gramatical do código fonte.
- Gerar código intermediário em C++ a partir do código fonte FOCA.
- Suportar operações aritméticas, lógicas e relacionais.
- Suportar estruturas de controle como `if`, `else`, `while`, `for`, `do-while`.
- Suportar declarações e inicializações de variáveis de tipos `int`, `float`, `bool`, `char` e `string`.
- Suportar funções de entrada e saída como `print` e `scan`.

## Compilação e Execução

Siga os passos abaixo para compilar e executar o compilador:

1. **Clone o repositório:**

   ```sh
   git clone https://github.com/seu-usuario/compilador-xgh.git
   cd compilador-xgh
