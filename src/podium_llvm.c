#include "podium_llvm.h"
#include <stdlib.h>
#include <stdio.h>

LLVMContext* init_llvm() {
    LLVMContext* ctx = (LLVMContext*)malloc(sizeof(LLVMContext));
    ctx->context = NULL;
    printf("[LLVM] Inicializado (simulação)\n");
    return ctx;
}

void cleanup_llvm(LLVMContext* ctx) {
    if (ctx) {
        free(ctx);
        printf("[LLVM] Liberado (simulação)\n");
    }
}


int run_llvm_module(LLVMContext* ctx) {
    printf("[LLVM] Executando módulo (simulação)\n");
    return 0; // Sucesso
}