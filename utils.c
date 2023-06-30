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
