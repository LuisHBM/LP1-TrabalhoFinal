#ifndef ENDERECO_H
#define ENDERECO_H

#include <stdlib.h>

#define MAX_LENGTH 100

/* Struct que representa o endereco de um contato */
typedef struct Endereco
{
    char enderecoCompleto[MAX_LENGTH];
    char rua[MAX_LENGTH];
    int numero;
    char bairro[MAX_LENGTH];
    char cidade[MAX_LENGTH];
    char estado[MAX_LENGTH];
    
}Endereco;

#endif