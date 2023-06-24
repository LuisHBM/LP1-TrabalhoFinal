#include "listatelefonica.h"

void criandoNovoContato(Contato *listaTelefonica)
{
    Contato * ultimoContatoDaLista = listaTelefonica;
    /* Certificando-se que o contato atual é o último contato da lista */
    while(ultimoContatoDaLista->proximoContato != NULL)
    {
        ultimoContatoDaLista = ultimoContatoDaLista->proximoContato;
    }

    Contato * novoContato = (Contato *) malloc(sizeof(Contato));
    ultimoContatoDaLista->proximoContato = novoContato;
    novoContato->proximoContato = NULL;

    printf("\nDigite o nome do contato: ");
    fgets(novoContato->name, NOME,stdin);
    novoContato->name[strcspn(novoContato->name, "\n")] = '\0';


    printf("\nDigite a data de nascimento de %s (DD MM AAAA): ", novoContato->name);
    scanf(" %d %d %d", &novoContato->datadeNascimento.dia, &novoContato->datadeNascimento.mes, &novoContato->datadeNascimento.ano);


    printf("\nDigite o numero de telefone de %s (XX XXXXX-XXXX)",novoContato->name);
    scanf(" %[0-9 () -]",novoContato->numeroDeContato);
    novoContato->numeroDeContato[strcspn(novoContato->name, "\n")] = '\0';

    getchar();

    printf("\nDigite o endereço completo (rua, número, bairro, cidade, estado): ");
    fgets(novoContato->endereco.enderecoCompleto, MAX_LENGTH,stdin);
    novoContato->endereco.enderecoCompleto[strcspn(novoContato->endereco.enderecoCompleto, "\n")] = '\0';
    sscanf(novoContato->endereco.enderecoCompleto, 
        "%[^,], %d, %[^,], %[^,], %[^\n]",
        novoContato->endereco.rua, 
        &novoContato->endereco.numero, 
        novoContato->endereco.bairro, 
        novoContato->endereco.cidade, 
        novoContato->endereco.estado);

    system("clear||cls");
    printf("\nDados cadastrados com sucesso!");
    getchar();
}

void exibirMenu()
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

void modificarContato(Contato * contatoAtual)
{
    limparTela();

    int opcao;
    do{
    printf("\nO que deseja modificar?");
    printf("\n1.Nome ");
    printf("\n2.Data de nascimento");
    printf("\n3.Endereço");
    printf("\n4.Número de contato");
    printf("\n0.Sair");
    printf("\n\nDigite sua opção: ");
    scanf("%d", &opcao);
    getchar();
    limparTela();

        switch(opcao)
        {
            case 1:
            {
                printf("\nDigite o novo nome: ");
                scanf("%[A-Z a-z]",contatoAtual->name);
                getchar();
                break;
            }

            case 2:
            {
                printf("\nDigite a noma data de nascimento de %s (DD MM AAAA):", contatoAtual->name);
                scanf("%d %d %d", &contatoAtual->datadeNascimento.dia, &contatoAtual->datadeNascimento.mes, &contatoAtual->datadeNascimento.ano);
                getchar();
                break;
            }

            case 3:
            {
                printf("\nDigite o novo endereço de %s :", contatoAtual->name);
                fgets(contatoAtual->endereco.enderecoCompleto, MAX_LENGTH,stdin);
                sscanf(contatoAtual->endereco.enderecoCompleto, 
                        "%[^,], %d, %[^,], %[^,], %[^\n]",
                        contatoAtual->endereco.rua, 
                        &contatoAtual->endereco.numero, 
                        contatoAtual->endereco.bairro, 
                        contatoAtual->endereco.cidade, 
                        contatoAtual->endereco.estado);     
                getchar();
                break;
            }

            case 4:
            {
                printf("\nDigite o novo numero de telefone de %s (XX XXXXX-XXXX)",contatoAtual->numeroDeContato);
                scanf("%[0-9 ]",contatoAtual->numeroDeContato);
                getchar();                
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
    printf("\n\nDigite qualquer tecla para continuar");
    getchar();
}

void limparTela()
{
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear"); 
    #endif
}

void lerArquivos(Contato * listaTelefonica, bool * listaInicializada)
{
    FILE * arquivo;
    Endereco endereco;
    DataDeNascimento dataDeNascimento;
    char nome[MAX_LENGTH];
    char numeroDeContato[MAX_LENGTH];
    
    /* Abre o arquivo em moro de escrita */
    arquivo = fopen("../lista_telefonica.txt", "r");
    /* Verifica se o arquivo foi encontrado*/
    if(arquivo == NULL)
    {
        printf("\nO arquivo não foi encontrado");
    }
    else
    {
        /* Cetifica-se de que ainda não foi cadastrado nenhum contato */
        if(listaTelefonica ->proximoContato == NULL)
        {
            limparTela();
            *listaInicializada = true;
            char linha[MAX_LENGTH];

            /* Verifica se o arquivo está vazio */
            if(fgets(linha, sizeof(linha), arquivo) == NULL)
            {
                limparTela();
                printf("\nNão há contatos para carregar!");
                printf("\n\nDigite qualquer tecla para continuar");
                getchar();
            }
            else
            {
                /* Itera o arquivo enquanto houver uma linha escrita e não for o fim do arquivo 'feof */
                while(fgets(linha, sizeof(linha), arquivo) != NULL && !feof(arquivo))
                {
                    if(strstr(linha, "Nome:"))
                    {
                        sscanf(linha, "Nome: %[^\n]", nome);
                    }
                    else if(strstr(linha,"Data de nascimento:"))
                    {
                        sscanf(linha,"Data de nascimento: %d %d %d", &dataDeNascimento.dia, &dataDeNascimento.mes, &dataDeNascimento.ano);
                    }
                    else if(strstr(linha,"Endereço:"))
                    {
                        sscanf(linha,"Endereço: %[^\n]", endereco.enderecoCompleto);
                        sscanf(linha,"Endereço: %[^,], %d, %[^,], %[^,], %[^\n]", endereco.rua, &endereco.numero, endereco.bairro, endereco.cidade, endereco.estado);
                    }
                    else if(strstr(linha,"Numero de telefone:"))
                    {
                        /* Quando a iteração estiver na última linha do contato ("Endereço"), iremos criá-lo dinamicamente */
                        sscanf(linha,"Numero de telefone: %s", numeroDeContato);
                        inserirContatosDoArquivo(listaTelefonica,nome,endereco,dataDeNascimento,numeroDeContato);
                    }
                }
                printf("\nContatos carregados com sucesso!");
                printf("\n\nDigite qualquer tecla para continuar");
                getchar();
                limparTela();
            }
        }
    }
    fclose(arquivo);
}

void salvarArquivos(Contato* listaTelefonica) {
    FILE* arquivo;
    Contato* contatoAtual = listaTelefonica;

    /*Caso não haja nenhum contato cadastrado*/
    if(listaTelefonica->proximoContato == NULL)
    {
        limparTela();
        printf("\nNenhum contato foi salvo, pois não havia contatos a serem gravados!");
        getchar();
    }
    else
    {
        contatoAtual = contatoAtual->proximoContato;
        /* Abre o arquivo em modo escrita, sobreescrevendo tudo que havia ali 
        O ccs=UTF-8 é só para dizer ao SO escrever no arquivo em uma linguagem padrão.
        Estava acontecendo de caracteres como 'ç' ficarem desfigurados no arquivo*/
        arquivo = fopen("../lista_telefonica.txt", "w, ccs=UTF-8");

        /* Verifica se o arquivo foi encontrado */
        if (arquivo == NULL) 
        {
            printf("\nO arquivo não foi encontrado");
        } 
        else 
        {
            /* Escreve o print abaixo apenas para sobreescrever tudo que havia ali e fechar o arquivo*/
            fprintf(arquivo, "-------->Lista telefônica<------------\n");
            fclose(arquivo);

            /* O arquivo sobreescrito e vazio então é aberto novamento em modo 'add' para que todos os contatos
            sejam escritos somente ao final do arquivo */
            arquivo = fopen("../lista_telefonica.txt", "a, ccs=UTF-8");

            /* Verifica novamente se o arquivo foi encontrado, apenas por precaução*/
            if (arquivo == NULL)
            {
                printf("\nO arquivo não foi encontrado");
            } 
            else 
            {
                /* Itera toda a lista até que ela seja completamente percorrida*/
                while (contatoAtual != NULL) 
                {
                    fprintf(arquivo, "Nome: %s", contatoAtual->name);
                    fprintf(arquivo, "\nData de nascimento: %d %d %d", contatoAtual->datadeNascimento.dia, contatoAtual->datadeNascimento.mes, contatoAtual->datadeNascimento.ano);
                    fprintf(arquivo, "\nEndereço: %s\n", contatoAtual->endereco.enderecoCompleto);
                    fprintf(arquivo, "Numero de telefone: %s\n\n", contatoAtual->numeroDeContato);
                    contatoAtual = contatoAtual->proximoContato;
                }
                fclose(arquivo);
            }
        }
        limparTela();
        printf("\nTodos os contatos foram salvos com sucesso!");
        getchar();
    }
}


void inserirContatosDoArquivo(Contato * listaTelefonica, char * nome, Endereco endereco, DataDeNascimento dataDeNascimento, char *numeroDeContato)
{
    Contato * ultimoContatoDaLista = listaTelefonica;

    /* Verificando se o contato atual é o último da lista */
    while(ultimoContatoDaLista->proximoContato != NULL)
    {
        ultimoContatoDaLista = ultimoContatoDaLista->proximoContato;
    }

    /* Verificação apenas por precaução: se o último da lista estiver apontando para NULL, é criado um novo contato */
    if(ultimoContatoDaLista->proximoContato == NULL)
    {
        Contato * novoContato = (Contato *) malloc(sizeof(Contato));
        novoContato->proximoContato = NULL;

        strcpy(novoContato->name, nome);
        ultimoContatoDaLista->proximoContato = novoContato;
        novoContato->endereco = endereco;
        novoContato->datadeNascimento = dataDeNascimento;
        strcpy(novoContato->numeroDeContato, numeroDeContato);
        printf("Carregando contato: %s\n", novoContato->name);
    }
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
        printf("\n\nDigite qualquer tecla para continuar");
    }
    getchar();
}

int contadorDeContatos(Contato *listaTelefonica)
{
    Contato * contatoAtual = listaTelefonica;
    int totalDeContatos = 0;
    while(contatoAtual->proximoContato != NULL)
    {
        totalDeContatos ++;
        contatoAtual = contatoAtual->proximoContato;
    }

    return totalDeContatos;
}

bool verificarInicializacaoDaLista(bool listaInicializada)
{
    if(!listaInicializada)
    {
        printf("\nAinda não há contatos na lista telefônica!");
        printf("\nAcesse a opção número '1' para cadastrar novos contatos");
        getchar(); 

        return false;
    }

    return true;
}

void liberarMemoria(Contato *listaTelefonica)
{
    Contato * contatoAtual = listaTelefonica;
    Contato * proximoContato = NULL;

    while(contatoAtual != NULL)
    {
        proximoContato = contatoAtual->proximoContato;
        free(contatoAtual);
        contatoAtual = proximoContato;
    }
}

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
                limparTela();
                Contato * contatoProcurado;
                printf("\nDigite o nome do contato que deseja encontrar: ");
                fgets(strAux, MAX_LENGTH, stdin);
                strAux[strcspn(strAux, "\n")] = '\0';
            
                /* Procura pelo contato, caso exista suas informações serão exibidas*/
                contatoProcurado = procurarContato(listaTelefonica,strAux);
                if(contatoProcurado != NULL)
                {
                    limparTela();
                    exibirContato(contatoProcurado);
                }
                break;
            }
            case 0:
            {
                return;
            }

            default:
            {
                limparTela();
                printf("\nOpção inválida!");
                getchar();
                break;
            }
        }
    } while (opcao != 0);
    
}

void removerContato(char * contatoProcurado, Contato * listaTelefonica)
{
    Contato * contato = listaTelefonica->proximoContato;
    Contato * contatoAnterior = listaTelefonica;

    /* Enquanto não for o fim da lista */
    while(contato != NULL)
    {   
        if(strcmp(contatoProcurado, contato->name) == 0)
        {
            contatoAnterior->proximoContato = contato->proximoContato;
            free(contato);
            printf("\nContato removido com sucesso");
            limparTela();
            return;

        }
        else
        {
            contatoAnterior = contato;
            contato = contato->proximoContato;
        }
    }

    printf("\nContato não encontrado!");
    getchar();
}

Contato * procurarContato(Contato *listaTelefonica, char * nome)
{
    Contato * contatoAtual = listaTelefonica;
    bool contatoEncontrado = false;
    int flag =0;
    while(contatoAtual != NULL)
    {
        flag ++;
        printf("Contato %d : %s", flag, contatoAtual->name);
        if(strcmp(contatoAtual->name,nome) == 0)
        {   
            printf("\nContato encontrado com sucesso!");
            return contatoAtual;
        }

        contatoAtual = contatoAtual->proximoContato;
    }

    limparTela();
    printf("\nContato não encontrado");
    getchar();

    return NULL;

}
