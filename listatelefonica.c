#include "listatelefonica.h"

void inserindoContatos(Contato *listaTelefonica)
{
    /* função de inicializar  */
    /* Verificar se o arquivo possui algo , se tiver carrega, caso não segue */

    Contato * novoContato = (Contato *) malloc(sizeof(Contato));
    listaTelefonica->proximoContato = novoContato;
    printf("\nDigite o nome do contato: ");
    scanf("%[A-Z a-z]",novoContato->name);
    getchar();
    printf("\nDigite a data de nascimento de %s (DD MM AAAA): ", novoContato->name);
    scanf("%d %d %d", &novoContato->datadeNascimento.dia, &novoContato->datadeNascimento.mes, &novoContato->datadeNascimento.ano);
    getchar();
    printf("\nDigite seu endereço completo (rua, número, bairro, cidade, estado): ");
    fgets(novoContato->endereco.enderecoCompleto, MAX_LENGTH,stdin);
    /*A função sscanf não lê da entrada padrão(stdin), mas sim a partir de uma string; 
    Esse "%[^,]" têm esse -> ' ^ ' que é uma negação, então ele vai ler tudo que não for uma vírgula. Quando ele encontrar uma vígula
    ele vai parar de ler e alocar no endereco que vocẽ especificou*/
    sscanf(novoContato->endereco.enderecoCompleto, 
        "%[^,], %d, %[^,], %[^,], %[^\n]",
        novoContato->endereco.rua, 
        &novoContato->endereco.numero, 
        novoContato->endereco.bairro, 
        novoContato->endereco.cidade, 
        novoContato->endereco.estado);     

}