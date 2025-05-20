%{
#include "podium_ast.h"
#include "podium.tab.h"
#include <string.h>
%}

%option noyywrap
%option yylineno


DIGIT       [0-9]
LETTER      [a-zA-Z]
ID          {LETTER}({LETTER}|{DIGIT}|_)*
NUMBER      {DIGIT}+
WHITESPACE  [ \t\r\n]+
COMMENT     \/\/[^\n]*

%%
{WHITESPACE}    { /* Ignora espaços em branco */ }
{COMMENT}       { /* Ignora comentários */ }

"greenLight"    { return GREENLIGHT; }
"chequeredFlag" { return CHEQUEREDFLAG; }
"driver"        { return DRIVER; }
"team"          { return TEAM; }
":"             { return COLON; }
"int"           { return TYPE_INT; }
"bool"          { return TYPE_BOOL; }
"lapTime"       { return TYPE_LAPTIME; }
"ifPit"         { return IFPIT; }
"elsePit"       { return ELSEPIT; }
"forLap"        { return FORLAP; }
"whileSC"       { return WHILESC; }
"pitStop"       { return PITSTOP; }
"pushLap"       { return PUSHLAP; }
"radio"         { return RADIO; }
"min"           { return MIN; }
"max"           { return MAX; }
"addPoint"      { return ADDPOINT; }
"true"          { return TRUE; }
"false"         { return FALSE; }

{ID}            { 
                  yylval.str_val = strdup(yytext); 
                  return IDENTIFIER; 
                }

{NUMBER}        { 
                  yylval.int_val = atoi(yytext); 
                  return NUMBER; 
                }

\"[^\"]*\"      { 
                  yytext[yyleng-1] = '\0';  /* Remove aspas finais */
                  yylval.str_val = strdup(yytext+1);  /* Remove aspas iniciais */
                  return STRING; 
                }

"!"             { return '!'; }  
"=="            { return EQ; }
"!="            { return NE; }
"<="            { return LE; }
">="            { return GE; }
"&&"            { return AND; }
"||"            { return OR; }
".."            { return DOTDOT; }

"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"="             { return '='; }
"<"             { return '<'; }
">"             { return '>'; }
"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
"["             { return '['; }
"]"             { return ']'; }
";"             { return ';'; }
","             { return ','; }

.               { printf("Caractere não reconhecido: %c\n", *yytext); }

%%