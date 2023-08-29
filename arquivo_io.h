#ifndef ARQUIVO_IO_H
#define ARQUIVO_IO_H

#include <stdbool.h>
#include <stdio.h>
#include "listatelefonica.h"
#include "utils.h"
/* Arquivo destinado para funções de manipulações de arquivos */

/* Função que lê arquivos  */
void lerArquivos(Contato * listaTelefonica, bool * listaInicializada);

/* Função que salva informações no arquivo */
void salvarArquivos(Contato * listaTelefonica);

/* Função que cria novos contatos a partir do arquvo */
void inserirContatosDoArquivo(Contato * listaTelefonica, char * nome, Endereco endereco, DataDeNascimento dataDeNascimento, char * numeroDeContato);


#endif