#include "listatelefonica.h"



int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    /* Topo da lista */
    Contato listaTelefonica;
    listaTelefonica.proximoContato = NULL;
    listaTelefonica.contatoAnterior = NULL;
    strcpy(listaTelefonica.name,"ListaTelefonica");

    char strAux[MAX_LENGTH];
    bool listaInicializada = false;
    lerArquivos(&listaTelefonica, &listaInicializada);


    int opcao;
    do
    {
        //limparTela();
        exibirMenu();
        scanf("%d", &opcao);
        getchar();
        switch(opcao)
        {    
            /* Criar contato */
            case 1:
            {
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
                        exibirContato(contatoProcurado);
                    }
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
                
                    contatoProcurado = procurarContato(&listaTelefonica,strAux);
                    if(contatoProcurado == &listaTelefonica)
                    {
                        continue;
                    }
                    else
                    {
                        removerContato(contatoProcurado,&listaTelefonica);
                    }
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