%{
#include "podium.tab.h"
#include <stdlib.h>
%}

/* Ignora comentários de linha */
\/\/[^\n]*    /* skip single-line comments */

/* Ignora espaços em branco */
[ \t\r\n]+   /* skip whitespace */

%%

"greenLight"        return GREENLIGHT;
"chequeredFlag"     return CHEQUEREDFLAG;
"driver"            return DRIVER;
"team"              return TEAM;
"ifPit"             return IFPIT;
"elsePit"           return ELSEPIT;
"forLap"            return FORLAP;
"whileSC"           return WHILESC;
"pitStop"           return PITSTOP;
"pushLap"           return PUSHLAP;

/* Literais de string para radio */
\"[^\"]*\"         {
                      yylval.str = strdup(yytext+1);
                      yylval.str[strlen(yylval.str)-1] = '\0';
                      return STRING;
                   }

/* Funções min/max para expressão */
"min"               return MIN;
"max"               return MAX;

/* Operador lógico OU */
"\|\|"             return OR;
/* Operador lógico E */
"&&"               return AND;

"radio"             return RADIO;
"addPoint"          return ADDPOINT;

/* Números */
[0-9]+              { yylval.num = atoi(yytext); return NUMBER; }

/* Identificadores */
[a-zA-Z_][a-zA-Z0-9_]* {
                      yylval.id = strdup(yytext);
                      return IDENTIFIER;
                   }

/* Operadores e pontuação */
"="                 return '=';
"<="                return LE;
">="                return GE;
"=="                return EQ;
"!="                return NE;
"<"                 return '<';
">"                 return '>';
"\.\."              return DOTDOT;
":"                 return ':';
";"                 return ';';
","                 return ',';
"\("                return '(';
"\)"                return ')';
"\{"                return '{';
"\}"                return '}';

/* Qualquer outro caracter */
.                   return yytext[0];

%%

int yywrap(void) { return 1; }
