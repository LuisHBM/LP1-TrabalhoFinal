#include <stdio.h>
#include "utils.h"

void limparTela()
{
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear"); 
    #endif
}

void pausarExecucao()
{
    printf("\n\n");

    #ifdef _WIN32
        system("pause");
    #else
        printf("Pressione Enter para continuar...");
        getchar();
    #endif
}

void atencao()
{
    printf("\n--->Atenção<---");
    printf("\nQuando terminar de digitar o novo nome, aperte enter duas vezes para continuar");
}
