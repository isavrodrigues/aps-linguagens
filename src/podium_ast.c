#include "podium_ast.h"


Environment* init_environment() {
    Environment* env = (Environment*)malloc(sizeof(Environment));
    env->var_count = 0;
    env->driver_count = 0;
    env->team_count = 0;
    return env;
}

void define_variable(Environment* env, const char* name, Value value) {
    for (int i = 0; i < env->var_count; i++) {
        if (strcmp(env->variables[i].name, name) == 0) {
            env->variables[i].value = value;
            return;
        }
    }
    if (env->var_count < 100) {
        env->variables[env->var_count].name = strdup(name);
        env->variables[env->var_count].value = value;
        env->var_count++;
    } else {
        printf("Erro: Muitas variáveis definidas\n");
        exit(1);
    }
}

void set_variable(Environment* env, const char* name, Value value) {
    for (int i = 0; i < env->var_count; i++) {
        if (strcmp(env->variables[i].name, name) == 0) {
            env->variables[i].value = value;
            return;
        }
    }
    printf("Erro: Variável '%s' não definida\n", name);
    exit(1);
}

Value get_variable(Environment* env, const char* name) {
    for (int i = 0; i < env->var_count; i++) {
        if (strcmp(env->variables[i].name, name) == 0) {
            return env->variables[i].value;
        }
    }
    printf("Erro: Variável '%s' não definida\n", name);
    exit(1);
}

int variable_exists(Environment* env, const char* name) {
    for (int i = 0; i < env->var_count; i++) {
        if (strcmp(env->variables[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}


void register_driver(Environment* env, const char* name) {
    for (int i = 0; i < env->driver_count; i++) {
        if (strcmp(env->drivers[i].name, name) == 0) {
            printf("Piloto '%s' já registrado\n", name);
            return;
        }
    }
    if (env->driver_count < 20) {
        env->drivers[env->driver_count].name = strdup(name);
        env->drivers[env->driver_count].points = 0;
        env->driver_count++;
        printf("Piloto registrado: %s\n", name);
    } else {
        printf("Erro: Muitos pilotos definidos\n");
        exit(1);
    }
}


void register_team(Environment* env, const char* name, const char* driver1, const char* driver2) {
    int driver1_idx = -1, driver2_idx = -1;
    for (int i = 0; i < env->driver_count; i++) {
        if (strcmp(env->drivers[i].name, driver1) == 0) driver1_idx = i;
        if (strcmp(env->drivers[i].name, driver2) == 0) driver2_idx = i;
    }
    if (driver1_idx == -1) {
        printf("Erro: Piloto '%s' não registrado\n", driver1);
        exit(1);
    }
    if (driver2_idx == -1) {
        printf("Erro: Piloto '%s' não registrado\n", driver2);
        exit(1);
    }
    if (env->team_count < 10) {
        env->teams[env->team_count].name = strdup(name);
        env->teams[env->team_count].driver1_idx = driver1_idx;
        env->teams[env->team_count].driver2_idx = driver2_idx;
        env->team_count++;
        printf("Equipe registrada: %s [%s, %s]\n", name, driver1, driver2);
    } else {
        printf("Erro: Muitas equipes definidas\n");
        exit(1);
    }
}

void add_points(Environment* env, const char* driver, int points) {
    for (int i = 0; i < env->driver_count; i++) {
        if (strcmp(env->drivers[i].name, driver) == 0) {
            env->drivers[i].points += points;
            printf("Pontos adicionados: %s agora tem %d pontos\n",
                   driver, env->drivers[i].points);
            return;
        }
    }
    printf("Erro: Piloto '%s' não registrado\n", driver);
    exit(1);
}

void pit_stop(Environment* env) {
    if (variable_exists(env, "tyreWear")) {
        Value tyre_wear = get_variable(env, "tyreWear");
        if (tyre_wear.type == VAL_INT) {
            tyre_wear.as.int_val = 0;
            set_variable(env, "tyreWear", tyre_wear);
        }
    }
    if (variable_exists(env, "fuelLoad")) {
        Value fuel = get_variable(env, "fuelLoad");
        if (fuel.type == VAL_INT) {
            fuel.as.int_val += 50;
            set_variable(env, "fuelLoad", fuel);
        }
    }
    printf("Pit Stop realizado! Pneus novos e combustível reabastecido.\n");
}


void push_lap(Environment* env) {
    if (variable_exists(env, "tyreWear")) {
        Value tyre_wear = get_variable(env, "tyreWear");
        if (tyre_wear.type == VAL_INT) {
            tyre_wear.as.int_val += 5;
            set_variable(env, "tyreWear", tyre_wear);
        }
    }
    if (variable_exists(env, "fuelLoad")) {
        Value fuel = get_variable(env, "fuelLoad");
        if (fuel.type == VAL_INT) {
            fuel.as.int_val -= 3;
            set_variable(env, "fuelLoad", fuel);
        }
    }
    printf("Push Lap! Modo de ataque ativado.\n");
}


void radio_message(const char* message) {
    printf("Radio: %s\n", message);
}


int to_bool(Value v) {
    switch (v.type) {
        case VAL_BOOL:
            return v.as.bool_val;
        case VAL_INT:
            return (v.as.int_val != 0);
        case VAL_LAPTIME:
            return (v.as.laptime_val != 0);
        case VAL_STRING:
            return (v.as.str_val != NULL && v.as.str_val[0] != '\0');
        default:
            printf("Erro: Tipo %d não pode ser convertido para boolean\n", v.type);
            exit(1);
    }
}

Value create_int_value(int val) {
    Value v;
    v.type = VAL_INT;
    v.as.int_val = val;
    return v;
}

Value create_bool_value(int val) {
    Value v;
    v.type = VAL_BOOL;
    v.as.bool_val = val ? 1 : 0;
    return v;
}

Value create_laptime_value(int val) {
    Value v;
    v.type = VAL_LAPTIME;
    v.as.laptime_val = val;
    return v;
}

Value create_string_value(const char* val) {
    Value v;
    v.type = VAL_STRING;
    v.as.str_val = strdup(val);
    return v;
}


void print_value(Value val) {
    switch (val.type) {
        case VAL_INT:
            printf("%d", val.as.int_val);
            break;
        case VAL_BOOL:
            printf("%s", val.as.bool_val ? "true" : "false");
            break;
        case VAL_LAPTIME: {
            int mins = val.as.laptime_val / 60000;
            int secs = (val.as.laptime_val % 60000) / 1000;
            int ms = val.as.laptime_val % 1000;
            printf("%d:%02d.%03d", mins, secs, ms);
            break;
        }
        case VAL_STRING:
            printf("%s", val.as.str_val);
            break;
    }
}

// Operações aritméticas e lógicas básicas
Value value_add(Value a, Value b) {
    if (a.type == VAL_INT && b.type == VAL_INT) {
        return create_int_value(a.as.int_val + b.as.int_val);
    } else if (a.type == VAL_LAPTIME || b.type == VAL_LAPTIME) {
        int a_val = (a.type == VAL_LAPTIME) ? a.as.laptime_val : a.as.int_val;
        int b_val = (b.type == VAL_LAPTIME) ? b.as.laptime_val : b.as.int_val;
        return create_laptime_value(a_val + b_val);
    }
    printf("Erro: Tipos incompatíveis para adição\n");
    exit(1);
}

Value value_sub(Value a, Value b) {
    if (a.type == VAL_INT && b.type == VAL_INT) {
        return create_int_value(a.as.int_val - b.as.int_val);
    } else if (a.type == VAL_LAPTIME || b.type == VAL_LAPTIME) {
        int a_val = (a.type == VAL_LAPTIME) ? a.as.laptime_val : a.as.int_val;
        int b_val = (b.type == VAL_LAPTIME) ? b.as.laptime_val : b.as.int_val;
        return create_laptime_value(a_val - b_val);
    }
    printf("Erro: Tipos incompatíveis para subtração\n");
    exit(1);
}

Value value_mul(Value a, Value b) {
    if (a.type == VAL_INT && b.type == VAL_INT) {
        return create_int_value(a.as.int_val * b.as.int_val);
    } else if ((a.type == VAL_LAPTIME && b.type == VAL_INT) ||
               (a.type == VAL_INT && b.type == VAL_LAPTIME)) {
        int laptime = (a.type == VAL_LAPTIME) ? a.as.laptime_val : b.as.laptime_val;
        int factor  = (a.type == VAL_INT)     ? a.as.int_val       : b.as.int_val;
        return create_laptime_value(laptime * factor);
    }
    printf("Erro: Tipos incompatíveis para multiplicação\n");
    exit(1);
}

Value value_div(Value a, Value b) {
    if (b.type == VAL_INT && b.as.int_val == 0) {
        printf("Erro: Divisão por zero\n");
        exit(1);
    }
    if (a.type == VAL_INT && b.type == VAL_INT) {
        return create_int_value(a.as.int_val / b.as.int_val);
    } else if (a.type == VAL_LAPTIME && b.type == VAL_INT) {
        return create_laptime_value(a.as.laptime_val / b.as.int_val);
    }
    printf("Erro: Tipos incompatíveis para divisão\n");
    exit(1);
}

Value value_eq(Value a, Value b) {
    if (a.type != b.type) {
        if ((a.type == VAL_INT && b.type == VAL_LAPTIME) ||
            (a.type == VAL_LAPTIME && b.type == VAL_INT)) {
            int a_val = (a.type == VAL_LAPTIME) ? a.as.laptime_val : a.as.int_val;
            int b_val = (b.type == VAL_LAPTIME) ? b.as.laptime_val : b.as.int_val;
            return create_bool_value(a_val == b_val);
        }
        return create_bool_value(0);
    }
    switch (a.type) {
        case VAL_INT:
            return create_bool_value(a.as.int_val == b.as.int_val);
        case VAL_BOOL:
            return create_bool_value(a.as.bool_val == b.as.bool_val);
        case VAL_LAPTIME:
            return create_bool_value(a.as.laptime_val == b.as.laptime_val);
        case VAL_STRING:
            return create_bool_value(strcmp(a.as.str_val, b.as.str_val) == 0);
    }
    return create_bool_value(0);
}

Value value_ne(Value a, Value b) {
    Value eq = value_eq(a, b);
    return create_bool_value(!eq.as.bool_val);
}

// Funções de comparação corrigidas
Value value_lt(Value a, Value b) {
    int a_val, b_val;
    if (a.type == VAL_INT) {
        a_val = a.as.int_val;
    } else if (a.type == VAL_LAPTIME) {
        a_val = a.as.laptime_val;
    } else if (a.type == VAL_BOOL) {
        a_val = a.as.bool_val ? 1 : 0;
    } else {
        printf("Erro: Tipo não suporta comparação '<' (esquerdo)\n");
        exit(1);
    }
    if (b.type == VAL_INT) {
        b_val = b.as.int_val;
    } else if (b.type == VAL_LAPTIME) {
        b_val = b.as.laptime_val;
    } else if (b.type == VAL_BOOL) {
        b_val = b.as.bool_val ? 1 : 0;
    } else {
        printf("Erro: Tipo não suporta comparação '<' (direito)\n");
        exit(1);
    }
    return create_bool_value(a_val < b_val);
}

Value value_gt(Value a, Value b) {
    int a_val, b_val;
    if (a.type == VAL_INT) {
        a_val = a.as.int_val;
    } else if (a.type == VAL_LAPTIME) {
        a_val = a.as.laptime_val;
    } else if (a.type == VAL_BOOL) {
        a_val = a.as.bool_val ? 1 : 0;
    } else {
        printf("Erro: Tipo não suporta comparação '>' (esquerdo)\n");
        exit(1);
    }
    if (b.type == VAL_INT) {
        b_val = b.as.int_val;
    } else if (b.type == VAL_LAPTIME) {
        b_val = b.as.laptime_val;
    } else if (b.type == VAL_BOOL) {
        b_val = b.as.bool_val ? 1 : 0;
    } else {
        printf("Erro: Tipo não suporta comparação '>' (direito)\n");
        exit(1);
    }
    return create_bool_value(a_val > b_val);
}

Value value_le(Value a, Value b) {
    int a_val, b_val;
    if (a.type == VAL_INT) {
        a_val = a.as.int_val;
    } else if (a.type == VAL_LAPTIME) {
        a_val = a.as.laptime_val;
    } else if (a.type == VAL_BOOL) {
        a_val = a.as.bool_val ? 1 : 0;
    } else {
        printf("Erro: Tipo não suporta comparação '<=' (esquerdo)\n");
        exit(1);
    }
    if (b.type == VAL_INT) {
        b_val = b.as.int_val;
    } else if (b.type == VAL_LAPTIME) {
        b_val = b.as.laptime_val;
    } else if (b.type == VAL_BOOL) {
        b_val = b.as.bool_val ? 1 : 0;
    } else {
        printf("Erro: Tipo não suporta comparação '<=' (direito)\n");
        exit(1);
    }
    return create_bool_value(a_val <= b_val);
}

Value value_ge(Value a, Value b) {
    int a_val, b_val;
    if (a.type == VAL_INT) {
        a_val = a.as.int_val;
    } else if (a.type == VAL_LAPTIME) {
        a_val = a.as.laptime_val;
    } else if (a.type == VAL_BOOL) {
        a_val = a.as.bool_val ? 1 : 0;
    } else {
        printf("Erro: Tipo não suporta comparação '>=' (esquerdo)\n");
        exit(1);
    }
    if (b.type == VAL_INT) {
        b_val = b.as.int_val;
    } else if (b.type == VAL_LAPTIME) {
        b_val = b.as.laptime_val;
    } else if (b.type == VAL_BOOL) {
        b_val = b.as.bool_val ? 1 : 0;
    } else {
        printf("Erro: Tipo não suporta comparação '>=' (direito)\n");
        exit(1);
    }
    return create_bool_value(a_val >= b_val);
}

Value value_and(Value a, Value b) {
    int a_bool, b_bool;
    if (a.type == VAL_BOOL) {
        a_bool = a.as.bool_val;
    } else if (a.type == VAL_INT) {
        a_bool = (a.as.int_val != 0);
    } else if (a.type == VAL_LAPTIME) {
        a_bool = (a.as.laptime_val != 0);
    } else {
        printf("Erro: Operador '&&' não suporta tipo %d\n", a.type);
        exit(1);
    }
    if (!a_bool) {
        return create_bool_value(0);
    }
    if (b.type == VAL_BOOL) {
        b_bool = b.as.bool_val;
    } else if (b.type == VAL_INT) {
        b_bool = (b.as.int_val != 0);
    } else if (b.type == VAL_LAPTIME) {
        b_bool = (b.as.laptime_val != 0);
    } else {
        printf("Erro: Operador '&&' não suporta tipo %d\n", b.type);
        exit(1);
    }
    return create_bool_value(a_bool && b_bool);
}

Value value_or(Value a, Value b) {
    int a_bool, b_bool;
    if (a.type == VAL_BOOL) {
        a_bool = a.as.bool_val;
    } else if (a.type == VAL_INT) {
        a_bool = (a.as.int_val != 0);
    } else if (a.type == VAL_LAPTIME) {
        a_bool = (a.as.laptime_val != 0);
    } else {
        printf("Erro: Operador '||' não suporta tipo %d\n", a.type);
        exit(1);
    }
    if (a_bool) {
        return create_bool_value(1);
    }
    if (b.type == VAL_BOOL) {
        b_bool = b.as.bool_val;
    } else if (b.type == VAL_INT) {
        b_bool = (b.as.int_val != 0);
    } else if (b.type == VAL_LAPTIME) {
        b_bool = (b.as.laptime_val != 0);
    } else {
        printf("Erro: Operador '||' não suporta tipo %d\n", b.type);
        exit(1);
    }
    return create_bool_value(a_bool || b_bool);
}

Value value_min(Value a, Value b) {
    if (a.type == VAL_INT && b.type == VAL_INT) {
        return create_int_value(a.as.int_val < b.as.int_val ? a.as.int_val : b.as.int_val);
    } else if (a.type == VAL_LAPTIME && b.type == VAL_LAPTIME) {
        return create_laptime_value(a.as.laptime_val < b.as.laptime_val ? a.as.laptime_val : b.as.laptime_val);
    } else if (a.type == VAL_INT && b.type == VAL_LAPTIME) {
        return create_laptime_value(a.as.int_val < b.as.laptime_val ? a.as.int_val : b.as.laptime_val);
    } else if (a.type == VAL_LAPTIME && b.type == VAL_INT) {
        return create_laptime_value(a.as.laptime_val < b.as.int_val ? a.as.laptime_val : b.as.int_val);
    }
    printf("Erro: Função min requer operandos do mesmo tipo (int ou lapTime)\n");
    exit(1);
}

Value value_max(Value a, Value b) {
    if (a.type == VAL_INT && b.type == VAL_INT) {
        return create_int_value(a.as.int_val > b.as.int_val ? a.as.int_val : b.as.int_val);
    } else if (a.type == VAL_LAPTIME && b.type == VAL_LAPTIME) {
        return create_laptime_value(a.as.laptime_val > b.as.laptime_val ? a.as.laptime_val : b.as.laptime_val);
    } else if (a.type == VAL_INT && b.type == VAL_LAPTIME) {
        return create_laptime_value(a.as.int_val > b.as.laptime_val ? a.as.int_val : b.as.laptime_val);
    } else if (a.type == VAL_LAPTIME && b.type == VAL_INT) {
        return create_laptime_value(a.as.laptime_val > b.as.int_val ? a.as.laptime_val : b.as.int_val);
    }
    printf("Erro: Função max requer operandos do mesmo tipo (int ou lapTime)\n");
    exit(1);
}