#include "listatelefonica.h"



int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Contato listaTelefonica;
    Contato *contatoAtual = &listaTelefonica;
    listaTelefonica.proximoContato = contatoAtual;

    lerArquivos(contatoAtual);
    getchar();

    char strAux[MAX_LENGTH];
    bool listaInicializada = false;
    int opcao;
    do
    {
        limparTela();
        exibirMenu();
        scanf("%d", &opcao);
        getchar();
        switch(opcao)
        {    
            /* Criant contato */
            case 1:
            {
                listaInicializada = true;
                criandoNovoContato(contatoAtual);
                contatoAtual = contatoAtual->proximoContato;
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
                        removerContato(contatoProcurado);
                    }
                    break;
                }
            }

            case 0:
            {
                return 0;
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