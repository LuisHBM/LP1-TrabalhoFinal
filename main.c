#include "listatelefonica.h"



int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Contato listaTelefonica;
    Contato *contatoAtual = &listaTelefonica;
    listaTelefonica.proximoContato = contatoAtual;

    char strAux[MAX_LENGTH];
    bool listaInicializada = false;
    int opcao;
    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        getchar();
        switch(opcao)
        {    
            case 1:
            {
                listaInicializada = true;
                criandoNovoContato(contatoAtual);
                contatoAtual = contatoAtual->proximoContato;
                break;
            }

            case 2:
            {
                /* Verifica se a lista foi inicializada */
                if(!listaInicializada)
                {
                    printf("\nAinda não há contatos na lista telefônica!");
                    printf("\nAcesse a opção número '1' para cadastrar novos contatos");
                    break;
                }
                else
                {   
                    modificarContato(contatoAtual);
                    break;
                }
            }

            case 3:
            {
                /* Verifica se a lista foi inicializada */
                if(!listaInicializada)
                {
                    printf("\nAinda não há contatos na lista telefônica!");
                    printf("\nAcesse a opção número '1' para cadastrar novos contatos");
                    break;
                }
                else
                {
                    exibirContato(contatoAtual);
                    break;
                }
            }

            case 4:
                /* Verifica se a lista foi inicializada */
                if(!listaInicializada)
                {
                    printf("\nAinda não há contatos na lista telefônica!");
                    printf("\nAcesse a opção número '1' para cadastrar novos contatos");
                    break;
                }
                else
                {
                    printf("\nDigite o nome do contato: ");
                    scanf("%[A-Z a-z]", strAux);
                    procurarContato(&listaTelefonica, strAux);
                    break;
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