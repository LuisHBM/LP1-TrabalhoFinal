#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define NOME 40
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

/* Struct que representa a data de nascimento de um contato */
typedef struct DataDeNascimento
{
    int dia;
    int mes;
    int ano;
}DataDeNascimento;

/* Struct que representa um contato*/
typedef struct Contato
{
    char name[NOME];
    char numeroDeContato[MAX_LENGTH];
    Endereco endereco;
    DataDeNascimento datadeNascimento;
    struct Contato * proximoContato;
}Contato;


/* Função que insere novos contatos na lista */
void inserindoContatos(Contato * listaTelefonica);






