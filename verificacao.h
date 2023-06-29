#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/* Arquivo destinado às funções que irão verificar as entradas do usuário */

/* Função que irá retornar um boleano informando se a data inserida pelo usuário for válida */
bool validarDataDeNascimento(int dia, int mes, int ano);

/* Função que irá retornar um boleano informando se o número de telefone inserido pelo usuário for válida */
bool validarTelefone(char * telefone, int tamanho);