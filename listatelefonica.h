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
#define TELEFONE 15

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

/* Procura um contato através do nome e retorna sua referência*/
Contato * procurarContato(Contato * listaTelefonica, char * nome);

/* Função que remove um contato */
void removerContato(char * contatoProcurado, Contato * listaTelefonica);

/* Função que conta quantos contatos há na lista */
int contadorDeContatos(Contato * listaTelefonica);

/* Função que verifica se a lista foi iniciada */
bool verificarInicializacaoDaLista(bool listaInicializada);

/* Função que desaloca a memória alocada ao fim do programa*/
void liberarMemoria(Contato * listaTelefonica);

/* Verifica se a lista está vazia, se sim printa que está vazia, se não, não faz nada*/
void verificarListaVazia(Contato ** listaDePonteiros, int tam);

/* Função que procura contatos através do nome da rua, bairro, cidade ou estado */
void procurarContatosPorEndereco(Contato * listaTelefonica, Contato **ponteirosDeContato, char * informacao, int opcao);

/* Função que procura contatos através da data de nascimento */
void procurarContatosPorData(Contato * listaTelefonica, Contato **ponteirosDeContato, int dia, int mes, int ano);

/* Função que procura contatos através de um numero de telefone */
void procurarContatosPorNumeroDeTelefone(Contato * listaTelefonica, Contato **ponteirosDeContato, char * numeroDeTelefone);

/* Função que procura contatos através do número do endereço */
void procurarPorNumeroDeEndereco(Contato * listaTelefonica, Contato **ponteirosDeContato, int numero);

/* Função que procura contatos na lista pelo nome e me retorna um ponteiro para esse contato*/
void procurarContatosPorNome(Contato * listaTelefonica, Contato **ponteirosDeContato, char * nome);

#endif
