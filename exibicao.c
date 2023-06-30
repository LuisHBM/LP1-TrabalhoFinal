#include "exibicao.h"

void exibicao(Contato * listaTelefonica)
{
    char strAux[MAX_LENGTH];
    int opcao;
    do
    {
        limparTela();
        printf("\nO que você deseja fazer?");
        printf("\n1.Exibir todos os contatos cadastrados em ordem alfabética");
        printf("\n2.Exibir um contato específico");
        printf("\n0.Sair");
        printf("\n\nDigite sua opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao)
        {
            /* Exibe todos os contatos ordenados por ordem alfabética */
            case 1:
            {
                limparTela();
                exibirContatosOrdenados(listaTelefonica);
                break;
            }

            /* Exibe as informações de um contato em específico */
            case 2:
            {
                exibirMenuDeProcura(listaTelefonica);
            }
            case 0:
            {
                return;
            }

            default:
            {
                limparTela();
                printf("\nOpção inválida!");
                printf("\n");
                pausarExecucao();
                break;
            }
        }
    } while (opcao != 0);
    
}

void exibirMenuPrincipal()
{
    printf("\nSeja bem-vindo(a)!");
    printf("\nO que deseja fazer?");
    printf("\n1.Inserir novo contato");
    printf("\n2.Modificar informações de um contato");
    printf("\n3.Menu de exibição");
    printf("\n4.Remover um contato da lista");
    printf("\n0.Sair do programa");
    printf("\n\nDigite sua opção: ");
}

void exibirContato(Contato *contatoAtual)
{
    limparTela();
    printf("\nInformações do contato:");
    printf("\nNome: %s", contatoAtual->name);
    printf("\nNumero de telefone: %s", contatoAtual->numeroDeContato);
    printf("\nData de nascimento: %d/%d/%d", contatoAtual->datadeNascimento.dia,contatoAtual->datadeNascimento.mes, contatoAtual->datadeNascimento.ano);
    printf("\nEndereço:");
    printf("\nRua: %s", contatoAtual->endereco.rua);
    printf("\nNúmero: %d",contatoAtual->endereco.numero);
    printf("\nBairro: %s", contatoAtual->endereco.bairro);
    printf("\nCidade: %s",contatoAtual->endereco.cidade);
    printf("\nEstado: %s",contatoAtual->endereco.estado);
    pausarExecucao();
}

void exibirContatosOrdenados(Contato *listaTelefonica)
{
    /* Vetor de pointeiros de contatos */
    Contato* contatos[contadorDeContatos(listaTelefonica)];
    int numContatos = 0;

    /* Vetor que percorre toda a lista, guardando suas referências no vetor */
    Contato* contatoAtual = listaTelefonica->proximoContato;
    while (contatoAtual != NULL) 
    {
        contatos[numContatos] = contatoAtual;
        contatoAtual = contatoAtual->proximoContato;
        numContatos++;
    }

    /* Ordena o vetor de contatos em ordem alfabética, usando o bubble sort */
    int i, j;
    for (i = 0; i < numContatos; i++) 
    {
        for (j = 0; j < numContatos - 1; j++) 
        {
            if (strcmp(contatos[j]->name, contatos[j + 1]->name) > 0) 
            {
                Contato* temp = contatos[j];
                contatos[j] = contatos[j + 1];
                contatos[j + 1] = temp;
            }
        }
    }

    /* Printa as informações do contato */ 
    for (i = 0; i < numContatos; i++) 
    {
        printf("Nome: %s\n", contatos[i]->name);
        printf("Número de Contato: %s", contatos[i]->numeroDeContato);
        printf("\nEndereço:");
        printf("\nRua: %s", contatos[i]->endereco.rua);
        printf("\nNúmero: %d",contatos[i]->endereco.numero);
        printf("\nBairro: %s", contatos[i]->endereco.bairro);
        printf("\nCidade: %s",contatos[i]->endereco.cidade);
        printf("\nEstado: %s",contatos[i]->endereco.estado);
        printf("\nData de Nascimento: %d/%d/%d\n", contatos[i]->datadeNascimento.dia, contatos[i]->datadeNascimento.mes, contatos[i]->datadeNascimento.ano);
        printf("//----------------------------------//\n");
    }
    pausarExecucao();
}

void exibirMenuDeProcura(Contato *listatelefonica)
{
    int opcao;
    do
    {
        limparTela();
        printf("\nDeseja procurar o contato através de qual informação?");
        printf("\n1.Nome");
        printf("\n2.Data de nascimento");
        printf("\n3.Número de telefone");
        printf("\n4.Endereço");
        printf("\n0.Sair");
        printf("\n\nDigite sua opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao)
        {
            case 1:
            {
                char strAux[NOME];

                limparTela();
                Contato * contatoProcurado;
                printf("\nDigite o nome do contato que deseja encontrar: ");
                fgets(strAux, NOME, stdin);
                strAux[strcspn(strAux, "\n")] = '\0';

                contatoProcurado = procurarContato(listatelefonica,strAux);
                if(contatoProcurado != NULL)
                {
                    limparTela();
                    exibirContato(contatoProcurado);
                }
                break;
            }
            case 2:
            {
                int diaProcurado,mesProcurado,anoProcurado;
                Contato * contatoProcurado;
                limparTela();
                printf("\nInforme a data de nascimento do contato que deseja procurar DD MM AAAA: ");
                scanf(" %d %d %d", &diaProcurado, &mesProcurado, &anoProcurado);
                getchar();

                contatoProcurado = procurarContatoPorData(listatelefonica, diaProcurado, mesProcurado, anoProcurado);
                if(contatoProcurado != NULL)
                {
                    exibirContato(contatoProcurado);
                }

                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                printf("\nOpção inválida!");
            }
        }
    }while(opcao != 0);
}

