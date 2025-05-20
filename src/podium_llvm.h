#ifndef PODIUM_LLVM_H
#define PODIUM_LLVM_H


typedef struct {
    void* context;  
} LLVMContext;

// Funções 
LLVMContext* init_llvm();
void cleanup_llvm(LLVMContext* ctx);


int run_llvm_module(LLVMContext* ctx);

#endif 