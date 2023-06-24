#include "listatelefonica.h"

int main(void)
{
    /* Função que permite o print de acentos */
    setlocale(LC_ALL, "Portuguese");
    char strAux[MAX_LENGTH];
    bool listaInicializada = false;

    /* Criando o topo da lista*/
    Contato listaTelefonica;
    listaTelefonica.proximoContato = NULL;
    /* Dando nome para o topo da lista apenas para debug */
    strcpy(listaTelefonica.name,"ListaTelefonica");

    /* Lendo informações do arquivo e carregando contatos para a memória, caso existam.
    Seta a variável 'listaInicializada' para true, caso pelo menos um contato foi carregado*/
    lerArquivos(&listaTelefonica, &listaInicializada);

    /* Loopping principal do código */
    int opcao;
    do
    {
        limparTela();
        exibirMenu();
        scanf("%d", &opcao);
        getchar();
        switch(opcao)
        {    
            /* Criar contato */
            case 1:
            {
                /* Verifica se a lista foi inicializada */
                listaInicializada = true;
                criandoNovoContato(&listaTelefonica);
                break;
            }

            /* Modificar Contato */
            case 2:
            {
                /* Verifica se a lista foi inicializada */
                if(!listaInicializada)
                {
                    printf("\nAinda não há contatos na lista telefônica!");
                    printf("\nAcesse a opção número '1' para cadastrar novos contatos");
                    getchar();
                    break;
                }
                else
                {   
                    Contato * contatoProcurado;
                    printf("\nDigite o nome do contato que deseja encontrar: ");
                    scanf("%[A-Z a-z]", strAux);
                    getchar();

                    contatoProcurado = procurarContato(&listaTelefonica,strAux);
                    if(contatoProcurado == &listaTelefonica)
                    {
                        continue;
                    }
                    else
                    {
                        limparTela();
                        modificarContato(contatoProcurado);
                        exibirContato(contatoProcurado);
                    }
                    break;
                }
            }
            /* Exibir contato */
            case 3:
            {
                /* Verifica se a lista foi inicializada */
                if(!listaInicializada)
                {
                    printf("\nAinda não há contatos na lista telefônica!");
                    printf("\nAcesse a opção número '1' para cadastrar novos contatos");
                    getchar();  
                    break;
                }
                else
                {   
                    exibicao(&listaTelefonica);
                    break;
                }
            }

            /* Remover contato */
            case 4:
            {
                /* Verifica se a lista foi inicializada */
                if(!listaInicializada)
                {
                    printf("\nAinda não há contatos na lista telefônica!");
                    printf("\nAcesse a opção número '1' para cadastrar novos contatos");
                    getchar();
                    break;
                }
                else
                {   
                    Contato * contatoProcurado;
                    printf("\nDigite o nome do contato que deseja encontrar: ");
                    scanf("%[A-Z a-z]", strAux);
                    getchar();
                    removerContato(strAux,&listaTelefonica);
                    break;
                }
            }

            case 0:
            {
                salvarArquivos(&listaTelefonica);
                break;
            }
            default:
            {
                limparTela();
                printf("\nOpção inválida");
            }
        }
        
    }while(opcao != 0);

    return 0;
}