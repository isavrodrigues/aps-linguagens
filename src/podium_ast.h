#ifndef PODIUM_AST_H
#define PODIUM_AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    VAL_INT,
    VAL_BOOL,
    VAL_LAPTIME,
    VAL_STRING
} ValueType;

typedef struct {
    ValueType type;
    union {
        int int_val;
        int bool_val;    
        int laptime_val; 
        char* str_val;
    } as;
} Value;


typedef struct {
    // Tabela de símbolos
    struct {
        char* name;
        Value value;
    } variables[100];
    int var_count;
    
    // Pilotos
    struct {
        char* name;
        int points;
    } drivers[20];
    int driver_count;
    
    // Equipes
    struct {
        char* name;
        int driver1_idx;
        int driver2_idx;
    } teams[10];
    int team_count;
} Environment;


Environment* init_environment();

void define_variable(Environment* env, const char* name, Value value);
void set_variable(Environment* env, const char* name, Value value);
Value get_variable(Environment* env, const char* name);
int variable_exists(Environment* env, const char* name);

void register_driver(Environment* env, const char* name);
void register_team(Environment* env, const char* name, const char* driver1, const char* driver2);
void add_points(Environment* env, const char* driver, int points);


void pit_stop(Environment* env);
void push_lap(Environment* env);
void radio_message(const char* message);

Value create_int_value(int val);
Value create_bool_value(int val);
Value create_laptime_value(int val);
Value create_string_value(const char* val);
void print_value(Value val);

Value value_add(Value a, Value b);
Value value_sub(Value a, Value b);
Value value_mul(Value a, Value b);
Value value_div(Value a, Value b);
Value value_eq(Value a, Value b);
Value value_ne(Value a, Value b);
Value value_lt(Value a, Value b);
Value value_gt(Value a, Value b);
Value value_le(Value a, Value b);
Value value_ge(Value a, Value b);
Value value_and(Value a, Value b);
Value value_or(Value a, Value b);
Value value_min(Value a, Value b);
Value value_max(Value a, Value b);

#endif 