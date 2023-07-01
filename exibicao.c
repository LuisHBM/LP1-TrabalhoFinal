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
        printf("\n2.Procurar contatos");
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
                break;
            }

            default:
            {
                limparTela();
                printf("\nOpção inválida!");
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

void exibirContatoEmCadeia(Contato *contatoAtual)
{
    printf("\nInformações do contato:");
    printf("\nNome: %s", contatoAtual->name);
    printf("\nNumero de telefone: %s", contatoAtual->numeroDeContato);
    printf("\nData de nascimento: %d/%d/%d", contatoAtual->datadeNascimento.dia,contatoAtual->datadeNascimento.mes, contatoAtual->datadeNascimento.ano);
    printf("\nEndereço:");
    printf("\nRua: %s", contatoAtual->endereco.rua);
    printf("\nNúmero: %d",contatoAtual->endereco.numero);
    printf("\nBairro: %s", contatoAtual->endereco.bairro);
    printf("\nCidade: %s",contatoAtual->endereco.cidade);
    printf("\nEstado: %s\n",contatoAtual->endereco.estado);
}

void exibirContatosOrdenados(Contato *listaTelefonica)
{
    /* Vetor de pointeiros de contatos */
    Contato* contatos[contadorDeContatos(listaTelefonica)];
    int numContatos = 0;

    /* Vetor que percorre toda a lista telefônica e guarda suas referências */
    Contato* contatoAtual = listaTelefonica->proximoContato;
    while (contatoAtual != NULL) 
    {
        contatos[numContatos] = contatoAtual;
        contatoAtual = contatoAtual->proximoContato;
        numContatos++;
    }

    /* Ordena o vetor de ponteiros de contatos em ordem alfabética, usando o bubble sort. */
    int i, j;
    for (i = 0; i < numContatos; i++) 
    {
        for (j = 0; j < numContatos - 1; j++) 
        {
            if (strcasecmp(contatos[j]->name, contatos[j + 1]->name) > 0) 
            {
                Contato* temp = contatos[j];
                contatos[j] = contatos[j + 1];
                contatos[j + 1] = temp;
            }
        }
    }

    /* Printa as informações dos contatos */ 
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
    int qntDeContatos = contadorDeContatos(listatelefonica);
    Contato * ponteirosDeContato[qntDeContatos];

    for (int i = 0; i < qntDeContatos; i++)
    {
        ponteirosDeContato[i] = NULL;
    }
    
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
            /* Procuro um contato através de um nome */
            case 1:
            {
                char strAux[NOME];

                limparTela();
                Contato * contatoProcurado;
                printf("\nDigite o nome do contato que deseja encontrar: ");
                fgets(strAux, NOME, stdin);
                strAux[strcspn(strAux, "\n")] = '\0';
                
                /* Procuro o contato através do nome */
                procurarContatosPorNome(listatelefonica, ponteirosDeContato, strAux);
                for (int i = 0; i < qntDeContatos; i++)
                {
                    if (ponteirosDeContato[i] != NULL)
                    {
                        exibirContatoEmCadeia(ponteirosDeContato[i]);
                    }
                
                }
                pausarExecucao();
                break;
            }

            /* Procuro um contato através de uma data de nascimento */
            case 2:
            {
                int diaProcurado,mesProcurado,anoProcurado;
                bool valido;

                /* Valido data de nascimento inserida pelo usuário antes de utilizá-la na busca */
                do
                {
                    valido = false;
                    limparTela();
                    printf("\nInforme a data de nascimento do contato que deseja procurar DD MM AAAA: ");
                    scanf(" %d %d %d", &diaProcurado, &mesProcurado, &anoProcurado);
                    getchar();

                    if(!validarDataDeNascimento(diaProcurado, mesProcurado, anoProcurado))
                    {
                        printf("\nData inválida! Por farvor insira uma data que seja válida e que segue o formato -> DD MM AAAA");
                    }
                    else
                    {
                        /* Procuro o contato através da data de nascimento */
                        procurarContatosPorData(listatelefonica, ponteirosDeContato, diaProcurado, mesProcurado, anoProcurado);
                        for (int i = 0; i < qntDeContatos; i++)
                        {
                            if (ponteirosDeContato[i] != NULL)
                            {
                                exibirContatoEmCadeia(ponteirosDeContato[i]);
                            }
                        
                        }
                        pausarExecucao();

                        valido = true;
                    }
                }while(!valido);

                break;
            }

            /* Procuro um contato através de um número de telefone */
            case 3:
            {
                char numeroDeTelefone[TELEFONE];
                bool valido = false;

                /* Valido o numero de telefone antes de utilizá-lo na busca */
                do
                {
                    limparTela();
                    printf("\nDigite o numero de telefone do contato que deseja encontrar '(DD)9XXXX-XXXX': ");
                    fgets(numeroDeTelefone, TELEFONE, stdin);
                    numeroDeTelefone[strcspn(numeroDeTelefone, "\n")] = '\0';
                    getchar();
                    
                    if(!validarTelefone(numeroDeTelefone, TELEFONE))
                    {
                        printf("\nNúmero de telefone inválido!! insira um número que seja válido e que segue o formato -> '(DD)9XXXX-XXXX'");
                    }
                    else
                    {
                        /* Procuro o contato através do número telefônico */
                        procurarContatosPorNumeroDeTelefone(listatelefonica, ponteirosDeContato, numeroDeTelefone);
                        for (int i = 0; i < qntDeContatos; i++)
                        {
                            if (ponteirosDeContato[i] != NULL)
                            {
                                exibirContatoEmCadeia(ponteirosDeContato[i]);
                            }
                        
                        }
                        pausarExecucao();
                        valido = true;
                    }
                }while(!valido);
                
                break;
            }

            /*Busco um contato através de alguma informação de endereço (Rua, Número, Bairo, Cidade, Estado)  */
            case 4:
            {
                /* Exibo o menu de opções de busca através de uma informação de endereço */
                exibirOpcoesDeEndereco(listatelefonica);
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

void exibirOpcoesDeEndereco(Contato *listaTelefonica)
{
    int opcao, contador = 0, qntDeContatos = contadorDeContatos(listaTelefonica);

    Contato *ponteirosDeContato[qntDeContatos]; //armazena os ponteiros dos contatos que foram encontrados
    for (int i = 0; i < qntDeContatos; i++)
    {
        ponteirosDeContato[i] = NULL;
    }

    char strAux[MAX_LENGTH];

    do
    {
        limparTela();
        printf("\nPor qual informação de endereço você deseja procurar o contato?");
        printf("\n1.Rua");
        printf("\n2.Numero");
        printf("\n3.Bairro");
        printf("\n4.Cidade");
        printf("\n5.Estado");
        printf("\n0.Sair");
        printf("\n\nDigite sua opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao)
        {
            /* Procuro por um contato através do nome da rua */
            case 1:
            {
                limparTela();

                printf("\nDigite o nome da rua: ");
                fgets(strAux, MAX_LENGTH, stdin);
                strAux[strcspn(strAux, "\n")] = '\0';

                procurarContatosPorEndereco(listaTelefonica, ponteirosDeContato, strAux, opcao);
                for (int i = 0; i < qntDeContatos; i++)
                {
                   if (ponteirosDeContato[i] != NULL)
                   {
                        exibirContatoEmCadeia(ponteirosDeContato[i]);
                   }
                   
                }
                pausarExecucao();

                break;
            }

            /* Procuro por um contato através de um número de endereço */
            case 2:
            {
                limparTela();

                int numeroProcurado;
                printf("\nDigite o numero do endereço: ");
                scanf("%d", &numeroProcurado);
                getchar();

                procurarPorNumeroDeEndereco(listaTelefonica, ponteirosDeContato, numeroProcurado);
                for (int i = 0; i < qntDeContatos; i++)
                {
                   if (ponteirosDeContato[i] != NULL)
                   {
                        exibirContatoEmCadeia(ponteirosDeContato[i]);
                   }
                   
                }
                pausarExecucao();

                break;
            }

            /* Procuro por um contato através do nome do bairro*/
            case 3:
            {
                limparTela();

                printf("\nDigite o nome do bairro: ");
                fgets(strAux, MAX_LENGTH, stdin);
                strAux[strcspn(strAux, "\n")] = '\0';

                procurarContatosPorEndereco(listaTelefonica, ponteirosDeContato, strAux, opcao);
                for (int i = 0; i < qntDeContatos; i++)
                {
                   if (ponteirosDeContato[i] != NULL)
                   {
                        exibirContatoEmCadeia(ponteirosDeContato[i]);
                   }
                   
                }
                pausarExecucao();

                break;
            }

            /* Procuro por um contato através do nome da cidade */
            case 4:
            {
                limparTela();

                printf("\nDigite o nome da cidade: ");
                fgets(strAux, MAX_LENGTH, stdin);
                strAux[strcspn(strAux, "\n")] = '\0';

                procurarContatosPorEndereco(listaTelefonica, ponteirosDeContato, strAux, opcao);
                for (int i = 0; i < qntDeContatos; i++)
                {
                   if (ponteirosDeContato[i] != NULL)
                    {
                        exibirContatoEmCadeia(ponteirosDeContato[i]);
                    }
                   
                }
                pausarExecucao();

                break;
            }

            /* Procuro por um contato através do nome do estado */
            case 5:
            {
                limparTela();

                printf("\nDigite o nome do estado: ");
                fgets(strAux, MAX_LENGTH, stdin);
                strAux[strcspn(strAux, "\n")] = '\0';

                procurarContatosPorEndereco(listaTelefonica, ponteirosDeContato, strAux, opcao);
                for (int i = 0; i < qntDeContatos; i++)
                {
                   if (ponteirosDeContato[i] != NULL)
                    {
                        exibirContatoEmCadeia(ponteirosDeContato[i]);
                    }
                   
                }
                pausarExecucao();

                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                printf("\nOpção inválida");
            }
        }

    }while(opcao != 0);
}
