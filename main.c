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
                if(verificarInicializacaoDaLista(listaInicializada))
                {   
                    Contato * contatoProcurado;
                    printf("\nDigite o nome do contato que deseja encontrar: ");
                    scanf("%[A-Z a-z]", strAux);
                    getchar();

                    /* Procura pelo contato que o usuário deseja modificar */
                    contatoProcurado = procurarContato(&listaTelefonica,strAux);
                    if(contatoProcurado != NULL)
                    {
                        limparTela();
                        /* Modifica o contato desejado */
                        modificarContato(contatoProcurado);
                        /* Após as modificações exibe o estado do novo contato */
                        exibirContato(contatoProcurado);
                    }
                }

                break;
            }

            /* Exibir contato */
            case 3:
            {
                /* Verifica se a lista foi inicializada */
                if(verificarInicializacaoDaLista(listaInicializada))
                {
                    getchar();
                    /* Vai para o menu de exibição */
                    exibicao(&listaTelefonica);
                }
                break;
            }

            /* Remover contato */
            case 4:
            {
                /* Verifica se a lista foi inicializada */
                if(verificarInicializacaoDaLista(listaInicializada))
                {
                    printf("\nDigite o nome do contato que deseja encontrar: ");
                    scanf("%[A-Z a-z]", strAux);
                    getchar();
                    removerContato(strAux,&listaTelefonica);
                }
                break;
            }

            case 0:
            {
                /* Quando o usuário deseja encerrar o programa, todos os contatos são salvos no arquivo*/
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