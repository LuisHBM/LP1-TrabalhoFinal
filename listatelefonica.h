#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

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
void criandoNovoContato(Contato * listaTelefonica);

/* Função que printa o menu */
void exibirMenu();

/* Função que seta os atributos de um contato passado no parâmetro */
void modificarContato(Contato * contatoAtual);

/* Função que exibe as informações de um contato */
void exibirContato(Contato * contatoAtual);

/* Função que limpa o terminal */
void limparTela();

/* Função que procura o contato na lista pelo nome e me retorna um ponteiro para esse contato*/
Contato * procurarContato(Contato * listaTelefonica, char * nome);

/* Função que remove um contato */
void removerContato(char * contatoProcurado, Contato * listaTelefonica);

/* Função que lê arquivos  */
void lerArquivos(Contato * listaTelefonica, bool * listaInicializada);

/* Função que salva informações no arquivo */
void salvarArquivos(Contato * listaTelefonica);

/* Função que cria novos contatos a partir do arquvo */
void inserirContatosDoArquivo(Contato * listaTelefonica, char * nome, Endereco endereco, DataDeNascimento dataDeNascimento, char * numeroDeContato);

/* Função que exibe os contatos em ordem alfabética */
void exibirContatosOrdenados(Contato* listaTelefonica);

/* Função que conta quantos contatos há na lista */
int contadorDeContatos(Contato * listaTelefonica);


/* Função que exibe e controla o menu de exibição */
void exibicao(Contato * listaTelefonica);
