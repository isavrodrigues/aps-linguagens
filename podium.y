%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Protótipos para evitar declarações implícitas */
int yylex(void);
void yyerror(const char *s);
%}

%union {
    int num;
    char *id;
    char *str;
}

%token <id> IDENTIFIER
%token <num> NUMBER
%token <str> STRING

%token GREENLIGHT CHEQUEREDFLAG DRIVER TEAM IFPIT ELSEPIT FORLAP WHILESC PITSTOP PUSHLAP RADIO MIN MAX ADDPOINT
%token LE GE EQ NE DOTDOT OR AND

%left OR
%left AND
%left '>' '<' LE GE EQ NE
%left '+' '-'
%left '*' '/'

%%

program:
    GREENLIGHT stmtList CHEQUEREDFLAG
    ;

stmtList:
    /* empty */
    | stmtList statement
    ;

statement:
    declaration
    | assignment ';'
    | conditional
    | loop
    | command ';'
    ;

declaration:
    DRIVER IDENTIFIER ';'
    | TEAM IDENTIFIER '[' IDENTIFIER ',' IDENTIFIER ']' ';'
    | IDENTIFIER ':' IDENTIFIER ';'
    ;

assignment:
    IDENTIFIER '=' expr
    ;

expr:
      expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | MIN '(' expr ',' expr ')'
    | MAX '(' expr ',' expr ')'
    | '(' expr ')'
    | NUMBER
    | IDENTIFIER
    ;

conditional:
      IFPIT '(' condition ')' block
    | IFPIT '(' condition ')' block ELSEPIT block
    ;

condition:
      condition OR condition
    | condition AND condition
    | expr '>' expr
    | expr '<' expr
    | expr EQ expr
    | expr NE expr
    | expr LE expr
    | expr GE expr
    ;

loop:
      FORLAP '(' expr DOTDOT expr ')' block
    | WHILESC '(' condition ')' block
    ;

command:
      PITSTOP
    | PUSHLAP
    | RADIO '(' STRING ')'
    | RADIO '(' expr ')'
    | ADDPOINT '(' IDENTIFIER ',' expr ')'
    ;

block:
    '{' stmtList '}'
    ;

%%

int main(void) {
    return yyparse();
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
