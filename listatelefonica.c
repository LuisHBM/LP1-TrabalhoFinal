#include "listatelefonica.h"

void criandoNovoContato(Contato *listaTelefonica)
{
    Contato * ultimoContatoDaLista = listaTelefonica;

    while(ultimoContatoDaLista->proximoContato != NULL)
    {
        ultimoContatoDaLista = ultimoContatoDaLista->proximoContato;
    }
    if(ultimoContatoDaLista->proximoContato == NULL)
    {
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
    

}

void exibirMenu()
{
    printf("\nSeja bem-vindo(a)!");
    printf("\nO que deseja fazer?");
    printf("\n1.Inserir novo contato");
    printf("\n2.Modificar informações de um contato");
    printf("\n3.Exibir informações de um contato");
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
                scanf("%[0-9 () -]",contatoAtual->numeroDeContato);
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
    printf("\nEndereço: %s", contatoAtual->endereco.enderecoCompleto);
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
    

    arquivo = fopen("../lista_telefonica.txt", "r");
    if(arquivo == NULL)
    {
        printf("\nO arquivo não foi encontrado");
    }
    else
    {
        if(listaTelefonica ->proximoContato == NULL)
        {
            *listaInicializada = true;
            char linha[MAX_LENGTH];
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
                }
                else if(strstr(linha,"Numero de telefone:"))
                {
                    sscanf(linha,"Numero de telefone: %s", numeroDeContato);
                    inserirContatosDoArquivo(listaTelefonica,nome,endereco,dataDeNascimento,numeroDeContato);
                }
            }
        }
    }
    fclose(arquivo);
}

void salvarArquivos(Contato* listaTelefonica) {
    FILE* arquivo;
    Contato* contatoAtual = listaTelefonica;
    if(listaTelefonica->proximoContato == NULL)
    {
        limparTela();
        printf("\nNenhum contato foi salvo, pois não havia contatos a serem gravados!");
        getchar();
    }
    else
    {

        contatoAtual = contatoAtual->proximoContato;
        arquivo = fopen("../lista_telefonica.txt", "w, ccs=UTF-8");
        if (arquivo == NULL) 
        {
            printf("\nO arquivo não foi encontrado");
        } 
        else 
        {
            fprintf(arquivo, "-------->Lista telefônica<------------\n");
            fclose(arquivo);

            arquivo = fopen("../lista_telefonica.txt", "a, ccs=UTF-8");
            if (arquivo == NULL)
            {
                printf("\nO arquivo não foi encontrado");
            } 
            else 
            {
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

    while(ultimoContatoDaLista->proximoContato != NULL)
    {
        ultimoContatoDaLista = ultimoContatoDaLista->proximoContato;
    }
    if(ultimoContatoDaLista->proximoContato == NULL)
    {

        Contato * novoContato = (Contato *) malloc(sizeof(Contato));
        novoContato->proximoContato = NULL;

        strcpy(novoContato->name, nome);
        printf("\nCadastrando contato: %s", novoContato->name);

        ultimoContatoDaLista->proximoContato = novoContato;
        novoContato->endereco = endereco;
        novoContato->datadeNascimento = dataDeNascimento;
        strcpy(novoContato->numeroDeContato, numeroDeContato);
    }
    printf("\n");
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

    for (i = 0; i < numContatos; i++) 
    {
        printf("Nome: %s\n", contatos[i]->name);
        printf("Número de Contato: %s\n", contatos[i]->numeroDeContato);
        //printf("Endereço: %s\n", contatos[i]->endereco);
        printf("Data de Nascimento: %d/%d/%d\n", contatos[i]->datadeNascimento.dia, contatos[i]->datadeNascimento.mes, contatos[i]->datadeNascimento.ano);
        printf("------------------------\n");
    }
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

void removerContato(char * contatoProcurado, Contato * listaTelefonica)
{
    Contato * contato = listaTelefonica->proximoContato;
    Contato * contatoAnterior = listaTelefonica;

    while(contato != NULL)
    {
        if(strcmp(contatoProcurado, contato->name) == 0)
        {
            contatoAnterior->proximoContato = contato->proximoContato;
            free(contato);
            printf("\nContato removido com sucesso");
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

    while(true)
    {
        if(strcmp(contatoAtual->name,nome) == 0)
        {   
            contatoEncontrado = true;
            printf("\nContato encontrado com sucesso!");
            break;
        }
        else
        {
            if(contatoAtual->proximoContato == NULL)
            {
                break;
            }
            contatoAtual = contatoAtual->proximoContato;
        }
    }
        
    if(!contatoEncontrado)
    {
        printf("\nContato não encontrado");
        getchar();
        limparTela();
        return listaTelefonica;
    }
    else
    {
        return contatoAtual;
    }
}
