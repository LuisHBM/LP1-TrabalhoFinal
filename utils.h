#ifndef UTILS_H
#define UTILS_H
   
#include <stdlib.h>

/* Arquivo destinado para funções de utilidades em geral */

/* Função que limpa o terminal */
void limparTela();

/* Função que pausa a execução do programa */
void pausarExecucao();

/* Devido ao fgets e ao scanf sofrerem constantes erros em relação à leitura de strings, em alguns pontos, mesmo utilzando 
o getchar para retirar o último caractere digitado (\n, nesse caso) e retirando o "\n" no final das strings e substituindo-o
pelo "\0", em alguns pontos é necessário apertar enter duas vezes para prosseguir com uma entrada de strings - devido ao uso 
dos dois artifícios acima simultaneamente. Após vários testes, essa foi a solução encontrada pela equipe. 
*Portanto, a função abaixo imprime um aviso para o usuário apertar entender duas vezes após inserir um dado */
void atencao();

#endif