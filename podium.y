%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();

/* fazer o union, typedef */ 



/* Tokens */
%token SEASON_OPENING SEASON_FINALE
%token REGULATIONS CONSTRUCTORS DRIVERS SETUP
%token LET BE SETS TEAM_RADIO IF_YELLOW_FLAG ELSE_PIT_LANE WHILE_SAFETY_CAR
%token ADJUST CALL_PIT_STOP RADIO_TO DEPLOY ISSUE_PENALTY
%token AERO ENGINE CHASSIS BUDGET FRONT_WING REAR_WING DIFFUSER SUSPENSION MODE ERS TIRES CURRENT STINTS
%token TIRE_COMPOUND ENGINE_MODE ERS_MODE SAFETY_CAR_TYPE
%token DATE TIME NUMBER BUDGET_VALUE IDENTIFIER
%token PLUS MINUS TIMES DIVIDE EQUALS GT LT EQ NE GE LE OVERTAKES LOSES_TO

/* Types */
%type <node> program season_section regulations constructors drivers setup commands
%type <node> command declaration assignment print conditional loop
%type <node> telemetry_command strategy_command engineer_command race_control_command
%type <node> expression condition term factor
%type <node> constructor_list driver_list setup_sections
%type <node> adjustment_type penalty_type

%start program

%%

program: 
    SEASON_OPENING season_section SEASON_FINALE
    { 
        printf("Programa Podium validado com sucesso!\n");
        $$ = $2;
    }
    ;



regulation_items:
    engine_mode_rules
    | tire_rules
    | drs_rules
    | pit_stop_rules
    | regulation_items regulation_items
    ;


tire_settings:
    "compounds" tire_list ';'
    | "mandatory" tire_requirement ';'
    | "minPitStops" NUMBER ';'
    ;


drs_settings:
    "activationLap" NUMBER ';'
    | "zones" ID NUMBER ';'
    | "detectionPoints" zone_list ';'
    ;


setup_sections:
    aero_setup
    | suspension_setup
    | engine_setup
    | tire_setup
    | setup_sections setup_sections
    ;


aero_settings:
    "frontWing" NUMBER ';'
    | "rearWing" NUMBER ';'
    | "diffuser" NUMBER ';'
    | "brakeDucts" ID ';'
    ;

suspension_settings:
    "front" ID ';'
    | "rear" ID ';'
    | "rideHeight" NUMBER "mm" ';'
    | "camber" NUMBER '°' ';'
    ;


engine_settings:
    "mode" ID ';'
    | "ERS" ID ';'
    | "fuelMix" ID ';'
    ;


tire_settings:
    "current" ID ';'
    | "pressures" '{' pressure_settings '}'
    | "stints" stint_list ';'
    ;

pressure_settings:
    "front" NUMBER "psi" ';'
    | "rear" NUMBER "psi" ';'
    ;


command:
    declaration
    | assignment
    | print
    | conditional
    | loop
    | telemetry_command
    | strategy_command
    | engineer_command
    | race_control_command
    ;


adjustment_type:
    "frontWing"
    | "rearWing"
    | "diffuser"
    | "brakeBias"
    | "ERS"
    ;



penalty_type:
    "time" NUMBER
    | "grid" NUMBER
    | "driveThrough"
    | "stopGo"
    ;

expression:
    term
    | expression PLUS term
    | expression MINUS term
    ;

term:
    factor
    | term TIMES factor
    | term DIVIDE factor
    ;

factor:
    NUMBER
    | ID
    | '(' expression ')'
    | "getPoints" '(' ID ')'
    | "getTeamPoints" '(' ID ')'
    ;

condition:
    expression REL_OP expression
    ;

REL_OP:
    GT
    | LT
    | EQ
    | NE
    | GE
    | LE
    | OVERTAKES
    | LOSES_TO
    ;

TYPE:
    "int"
    | "float"
    | "string"
    | "bool"
    | "driver"
    | "team"
    | "track"
    | "tire"
    | "engineMode"
    | "aeroConfig"
    ;


}