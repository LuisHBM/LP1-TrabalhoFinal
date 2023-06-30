#include "listatelefonica.h"
#include "exibicao.h"
#include "arquivo_io.h"
#include "utils.h"

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
        exibirMenuPrincipal();
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
                    printf("\n--->Atenção<---");
                    printf("\nQuando terminar de digitar o novo nome, aperte enter duas vezes para continuar");
                    printf("\n\nDigite o nome do contato que deseja encontrar: ");
                    fgets(strAux, NOME, stdin);
                    strAux[strcspn(strAux, "\n")] = '\0';
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
                /* Quando o usuário deseja encerrar o programa, todos os contatos são salvos no arquivo e toda a memória é desalocada.*/
                salvarArquivos(&listaTelefonica);
                
                /* Variável para passar o ponteiro do primeiro objeto da lista, pois se eu passar a variável 'listaTelefonica'
                ela não será desalocada, pois não foi alocada dinamicamente.*/
                Contato * primeiroContato = listaTelefonica.proximoContato;
                liberarMemoria(primeiroContato);
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