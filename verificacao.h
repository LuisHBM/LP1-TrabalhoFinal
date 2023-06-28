#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTHNUM 9


/* Arquivo destinado às funções que irão verificar as entradas do usuário */

/* Função que irá retornar um boleano informando se a data inserida pelo usuário é válida */
bool validarDataDeNascimento(int dia, int mes, int ano);

/* Função que recebe a Strig número de telefone e verifica se é digito numerico */
bool validarNumeroDeTelefone(char telefone[MAX_LENGTHNUM]);

