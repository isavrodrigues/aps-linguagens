%{
#include "podium.tab.h"
#include <stdio.h>
#include <string.h>

void yyerror(const char *s);
%}

%option noyywrap

DIGIT    [0-9]
ID       [a-zA-Z_][a-zA-Z0-9_]*
TIME     [0-9]{1,2}:[0-9]{2}\.[0-9]{3}
DATE     [0-9]{4}-[0-9]{2}-[0-9]{2}

%%

"seasonOpening"   { return SEASON_OPENING; }
"seasonFinale"    { return SEASON_FINALE; }
"regulations"     { return REGULATIONS; }
"constructors"    { return CONSTRUCTORS; }
"drivers"         { return DRIVERS; }
"setup"           { return SETUP; }
"let"             { return LET; }
"be"              { return BE; }
"sets"            { return SETS; }
"teamRadio"       { return TEAM_RADIO; }
"ifYellowFlag"    { return IF_YELLOW_FLAG; }
"elsePitLane"     { return ELSE_PIT_LANE; }
"whileSafetyCar"  { return WHILE_SAFETY_CAR; }
"adjust"          { return ADJUST; }
"callPitStop"     { return CALL_PIT_STOP; }
"radioTo"         { return RADIO_TO; }
"deploy"          { return DEPLOY; }
"issuePenalty"    { return ISSUE_PENALTY; }

"aero"            { return AERO; }
"engine"          { return ENGINE; }
"chassis"         { return CHASSIS; }
"budget"          { return BUDGET; }
"frontWing"       { return FRONT_WING; }
"rearWing"        { return REAR_WING; }
"diffuser"        { return DIFFUSER; }
"suspension"      { return SUSPENSION; }
"mode"            { return MODE; }
"ERS"             { return ERS; }
"tires"           { return TIRES; }
"current"         { return CURRENT; }
"stints"          { return STINTS; }

"Soft"|"Medium"|"Hard"|"Inter"|"Wet" { yylval.str = strdup(yytext); return TIRE_COMPOUND; }
"race"|"qualy"|"safety"|"save"       { yylval.str = strdup(yytext); return ENGINE_MODE; }
"defend"|"overtake"|"hotlap"|"recovery" { yylval.str = strdup(yytext); return ERS_MODE; }
"virtual"|"full"                      { yylval.str = strdup(yytext); return SAFETY_CAR_TYPE; }

{DATE}            { yylval.str = strdup(yytext); return DATE; }
{TIME}            { yylval.str = strdup(yytext); return TIME; }
{DIGIT}+          { yylval.num = atoi(yytext); return NUMBER; }
{DIGIT}+"million" { yylval.num = atoi(yytext) * 1000000; return BUDGET_VALUE; }
{DIGIT}+"billion" { yylval.num = atoi(yytext) * 1000000000; return BUDGET_VALUE; }
{ID}              { yylval.str = strdup(yytext); return IDENTIFIER; }

"+"               { return PLUS; }
"-"               { return MINUS; }
"*"               { return TIMES; }
"/"               { return DIVIDE; }
"="               { return EQUALS; }
">"               { return GT; }
"<"               { return LT; }
"=="              { return EQ; }
"!="              { return NE; }
">="              { return GE; }
"<="              { return LE; }
"overtakes"       { return OVERTAKES; }
"losesTo"         { return LOSES_TO; }

"{"               { return '{'; }
"}"               { return '}'; }
"("               { return '('; }
")"               { return ')'; }
"["               { return '['; }
"]"               { return ']'; }
","               { return ','; }
":"               { return ':'; }
";"               { return ';'; }

[ \t\n]           ; /* ignore whitespace */
.                 { printf("Caractere inválido: %s\n", yytext); }

%%