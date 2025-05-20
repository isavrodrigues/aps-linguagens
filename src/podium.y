%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "podium_ast.h"
#include "podium_llvm.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(const char* s);

Environment* env;

// LLVM global 
extern LLVMContext* llvm_ctx;
%}

%union {
    int int_val;
    char* str_val;
    Value value;
}


%token GREENLIGHT CHEQUEREDFLAG
%token DRIVER TEAM
%token TYPE_INT TYPE_BOOL TYPE_LAPTIME
%token IFPIT ELSEPIT FORLAP WHILESC
%token PITSTOP PUSHLAP RADIO MIN MAX ADDPOINT
%token EQ NE LE GE AND OR DOTDOT COLON
%token TRUE FALSE

%token <str_val> IDENTIFIER STRING
%token <int_val> NUMBER


%type <value> expression term factor
%type <str_val> type


%left OR
%left AND
%left EQ NE
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%nonassoc '!'

%%

program:
    GREENLIGHT 
    { 
        env = init_environment(); 
        printf("=== Início da Execução ===\n");
    }
    statement_list CHEQUEREDFLAG
    {
        printf("\n=== Fim da Execução ===\n");
        printf("\n--- Resultados ---\n");
        printf("Pilotos registrados: %d\n", env->driver_count);
        for (int i = 0; i < env->driver_count; i++) {
            printf("  %s: %d pontos\n", env->drivers[i].name, env->drivers[i].points);
        }
        
        printf("\nEquipes registradas: %d\n", env->team_count);
        for (int i = 0; i < env->team_count; i++) {
            int team_points = env->drivers[env->teams[i].driver1_idx].points + 
                             env->drivers[env->teams[i].driver2_idx].points;
            printf("  %s: %d pontos (%s: %d, %s: %d)\n", 
                   env->teams[i].name, 
                   team_points,
                   env->drivers[env->teams[i].driver1_idx].name,
                   env->drivers[env->teams[i].driver1_idx].points,
                   env->drivers[env->teams[i].driver2_idx].name,
                   env->drivers[env->teams[i].driver2_idx].points);
        }
    }
    ;

statement_list:
    | statement_list statement
    ;

statement:
    declaration
    | assignment
    | conditional
    | loop
    | command ';'
    ;

declaration:
    driver_decl
    | team_decl
    | var_decl ';'
    ;

driver_decl:
    DRIVER IDENTIFIER ';'
    {
        register_driver(env, $2);
    }
    ;

team_decl:
    TEAM IDENTIFIER '[' IDENTIFIER ',' IDENTIFIER ']' ';'
    {
        register_team(env, $2, $4, $6);
    }
    ;

var_decl:
    IDENTIFIER COLON type
    {
        if (strcmp($3, "int") == 0) {
            define_variable(env, $1, create_int_value(0));
        } else if (strcmp($3, "bool") == 0) {
            define_variable(env, $1, create_bool_value(0));
        } else if (strcmp($3, "lapTime") == 0) {
            define_variable(env, $1, create_laptime_value(0));
        }
    }
    | IDENTIFIER COLON type '=' expression
    {
        // Para lapTime, fazer conversão automática de int
        if (strcmp($3, "int") == 0 && $5.type != VAL_INT) {
            printf("Erro: Tipo incompatível na inicialização da variável '%s'\n", $1);
            exit(1);
        } else if (strcmp($3, "bool") == 0 && $5.type != VAL_BOOL) {
            printf("Erro: Tipo incompatível na inicialização da variável '%s'\n", $1);
            exit(1);
        } else if (strcmp($3, "lapTime") == 0) {
            if ($5.type == VAL_INT) {
                // Converter int para lapTime
                define_variable(env, $1, create_laptime_value($5.as.int_val));
            } else if ($5.type == VAL_LAPTIME) {
                define_variable(env, $1, $5);
            } else {
                printf("Erro: Tipo incompatível na inicialização da variável '%s'\n", $1);
                exit(1);
            }
        } else {
            define_variable(env, $1, $5);
        }
    }
    ;

type:
    TYPE_INT  { $$ = "int"; }
    | TYPE_BOOL   { $$ = "bool"; }
    | TYPE_LAPTIME    { $$ = "lapTime"; }
    ;

assignment:
    IDENTIFIER '=' expression ';'
    {
        if (!variable_exists(env, $1)) {
            printf("Erro: Variável '%s' não definida\n", $1);
            exit(1);
        }
        
        set_variable(env, $1, $3);
    }
    ;

expression:
    term
    {
        $$ = $1;
    }
    | expression '+' term
    {
        $$ = value_add($1, $3);
    }
    | expression '-' term
    {
        $$ = value_sub($1, $3);
    }
    | expression EQ term
    {
        $$ = value_eq($1, $3);
    }
    | expression NE term
    {
        $$ = value_ne($1, $3);
    }
    | expression '<' term
    {
        $$ = value_lt($1, $3);
    }
    | expression '>' term
    {
        $$ = value_gt($1, $3);
    }
    | expression LE term
    {
        $$ = value_le($1, $3);
    }
    | expression GE term
    {
        $$ = value_ge($1, $3);
    }
    | expression AND term
    {
        $$ = value_and($1, $3);
    }
    | expression OR term
    {
        $$ = value_or($1, $3);
    }
    ;

term:
    factor
    {
        $$ = $1;
    }
    | term '*' factor
    {
        $$ = value_mul($1, $3);
    }
    | term '/' factor
    {
        $$ = value_div($1, $3);
    }
    ;

factor:
    NUMBER
    {
        $$ = create_int_value($1);
    }
    | TRUE
    {
        $$ = create_bool_value(1);
    }
    | FALSE
    {
        $$ = create_bool_value(0);
    }
    | STRING
    {
        $$ = create_string_value($1);
    }
    | IDENTIFIER
    {
        if (!variable_exists(env, $1)) {
            printf("Erro: Variável '%s' não definida\n", $1);
            exit(1);
        }
        $$ = get_variable(env, $1);
    }
    | '(' expression ')'
    {
        $$ = $2;
    }
    | MIN '(' expression ',' expression ')'
    {
        $$ = value_min($3, $5);
    }
    | MAX '(' expression ',' expression ')'
    {
        $$ = value_max($3, $5);
    }
    | '-' factor %prec UMINUS
    {
        if ($2.type == VAL_INT) {
            $$ = create_int_value(-$2.as.int_val);
        } else if ($2.type == VAL_LAPTIME) {
            $$ = create_laptime_value(-$2.as.laptime_val);
        } else {
            printf("Erro: Operador '-' unário não pode ser aplicado a este tipo\n");
            exit(1);
        }
    }
    | '!' factor
    {
        if ($2.type == VAL_BOOL) {
            $$ = create_bool_value(!$2.as.bool_val);
        } else {
            printf("Erro: Operador '!' requer operando booleano\n");
            exit(1);
        }
    }
    ;

conditional:
    IFPIT '(' expression ')' block
    {
        
    }
    | IFPIT '(' expression ')' block ELSEPIT block
    {
        
    }
    ;

block:
    '{' 
    {
        
    }
    statement_list '}'
    {
        
    }
    ;

loop:
    FORLAP '(' expression DOTDOT expression ')'
    {
        if ($3.type != VAL_INT || $5.type != VAL_INT) {
            printf("Erro: Limites do loop 'forLap' devem ser inteiros\n");
            exit(1);
        }
        
        // Salvar valores do loop para uso posterior
        int start = $3.as.int_val;
        int end = $5.as.int_val;
        
        for (int i = start; i <= end; i++) {
            printf("--- Volta %d ---\n", i);
            
            // Definir variável de índice
            define_variable(env, "current_lap", create_int_value(i));
        }
    }
    block
    {
        
    }
    | WHILESC '(' expression ')' block
    {
        
    }
    ;

command:
    PITSTOP '(' ')'
    {
        pit_stop(env);
    }
    | PUSHLAP '(' ')'
    {
        push_lap(env);
    }
    | RADIO '(' expression ')'
    {
        if ($3.type == VAL_STRING) {
            radio_message($3.as.str_val);
        } else {
            printf("Erro: Argumento para radio deve ser uma string\n");
            exit(1);
        }
    }
    | ADDPOINT '(' IDENTIFIER ',' expression ')'
    {
        if ($5.type != VAL_INT) {
            printf("Erro: Pontos devem ser do tipo int\n");
            exit(1);
        }
        
        add_points(env, $3, $5.as.int_val);
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Erro sintático na linha %d: %s próximo a '%s'\n", yylineno, s, yytext);
}