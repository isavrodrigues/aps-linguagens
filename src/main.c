#include <stdio.h>
#include <stdlib.h>
#include "podium_ast.h"
#include "podium_llvm.h"
extern FILE* yyin;
extern int yyparse();


LLVMContext* llvm_ctx;

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Uso: podium [arquivo.pod]\n");
        return 1;
    }
    
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Erro ao abrir arquivo: %s\n", argv[1]);
        return 1;
    }
    
 
    yyin = file;
    
    llvm_ctx = init_llvm();
    
    int parse_result = yyparse();
    fclose(file);
    
    if (parse_result != 0) {
        fprintf(stderr, "Erro durante a compilação!\n");
        cleanup_llvm(llvm_ctx);
        return 1;
    }
    
    // Executar o módulo LLVM
    printf("\nExecutando o programa compilado via LLVM...\n");
    int result = run_llvm_module(llvm_ctx);
    
    cleanup_llvm(llvm_ctx);
    
    printf("\nExecução concluída com código de saída: %d\n", result);
    return 0;
}