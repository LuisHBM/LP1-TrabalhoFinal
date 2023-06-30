#ifndef EXIBICAO_H
#define EXIBICAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include "listatelefonica.h"
#include "utils.h"
/* Arquivo destinado para funções de exibição */

/* Função que exibe e controla o menu de exibição */
void exibicao(Contato * listaTelefonica);

/* Função que printa o menu principal do código */
void exibirMenuPrincipal();

/* Função que exibe as informações de um contato */
void exibirContato(Contato * contatoAtual);

/* Função que exibe os contatos em ordem alfabética */
void exibirContatosOrdenados(Contato* listaTelefonica);

/* Função que exibe o menu que printa as opções de procura por um contato */
void exibirMenuDeProcura(Contato * listatelefonica);

/* Função que pergunta ao usuário por qual informação de endereço ele deseja procurar um contato */
void exibirOpcoesDeEndereco(Contato * listaTelefonica);

#endif

