#ifndef LISTATELEFONICA_H
#define LISTATELEFONICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include "verificacao.h"
#include "endereco.h"
#include "datadenascimento.h"
#include "utils.h"

#define NOME 40
#define MAX_LENGTH 100
#define TELEFONE 14

/* Arquivo destinado à struct Contato, cujo conjunto de objetos formam a lista telefônica, e suas funções */

/* Struct que representa um contato*/
typedef struct Contato
{
    char name[NOME];
    char numeroDeContato[TELEFONE];
    Endereco endereco;
    DataDeNascimento datadeNascimento;
    struct Contato * proximoContato;
    
}Contato;

/* Função que insere novos contatos na lista */
void criandoNovoContato(Contato * listaTelefonica);

/* Função que seta os atributos de um contato passado no parâmetro */
void modificarContato(Contato * contatoAtual);

/* Função que procura o contato na lista pelo nome e me retorna um ponteiro para esse contato*/
Contato * procurarContato(Contato * listaTelefonica, char * nome);

/* Função que remove um contato */
void removerContato(char * contatoProcurado, Contato * listaTelefonica);

/* Função que conta quantos contatos há na lista */
int contadorDeContatos(Contato * listaTelefonica);

/* Função que verifica se a lista foi iniciada */
bool verificarInicializacaoDaLista(bool listaInicializada);

/* Função que desaloca a memória alocada ao fim do programa*/
void liberarMemoria(Contato * listaTelefonica);

/* Função que procura por um contato através da data de nascimento */
Contato * procurarContatoPorData(Contato * listaTelefonica, int dia, int mes, int ano);

#endif
