/* Arquivo podium.h */
#ifndef PODIUM_H
#define PODIUM_H

/* Tipos de nós da AST */
enum node_type {
    NODE_PROGRAM,
    NODE_CONSTRUCTOR,
    NODE_DRIVER,
    NODE_CIRCUIT,
    NODE_REGULATION,
    NODE_SETUP,
    NODE_STRATEGY,
    NODE_EXPRESSION,
    NODE_ASSIGNMENT,
    NODE_FUNCTION_CALL,
    NODE_CONDITIONAL,
    NODE_LOOP,
    NODE_RETURN
};

/* Estrutura para nós da AST */
typedef struct ast_node {
    enum node_type type;
    union {
        int int_val;
        float float_val;
        char *str_val;
        struct {
            struct ast_node *left;
            struct ast_node *right;
        } binary;
        struct {
            struct ast_node *condition;
            struct ast_node *then_branch;
            struct ast_node *else_branch;
        } if_stmt;
        struct {
            struct ast_node *condition;
            struct ast_node *body;
        } loop;
        struct {
            char *name;
            struct ast_node *params;
            struct ast_node *body;
        } function;
    } data;
} ast_node;

#endif /* PODIUM_H */