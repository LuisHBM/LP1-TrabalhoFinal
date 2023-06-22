#include "listatelefonica.h"

void criandoNovoContato(Contato *listaTelefonica)
{
    /* Verificar se o arquivo possui algo , se tiver carrega, caso não, segue */

    Contato * novoContato = (Contato *) malloc(sizeof(Contato));
    listaTelefonica->proximoContato = novoContato;
    novoContato->contatoAnterior = listaTelefonica;

    printf("\nDigite o nome do contato: ");
    scanf("%[A-Z a-z]",novoContato->name);
    getchar();

    printf("\nDigite a data de nascimento de %s (DD MM AAAA): ", novoContato->name);
    scanf("%d %d %d", &novoContato->datadeNascimento.dia, &novoContato->datadeNascimento.mes, &novoContato->datadeNascimento.ano);
    getchar();

    printf("\nDigite o numero de telefone de %s (XX XXXXX-XXXX)",novoContato->name);
    scanf("%[0-9 () -]",novoContato->numeroDeContato);
    getchar();

    printf("\nDigite o endereço completo (rua, número, bairro, cidade, estado): ");
    fgets(novoContato->endereco.enderecoCompleto, MAX_LENGTH,stdin);
    sscanf(novoContato->endereco.enderecoCompleto, 
        "%[^,], %d, %[^,], %[^,], %[^\n]",
        novoContato->endereco.rua, 
        &novoContato->endereco.numero, 
        novoContato->endereco.bairro, 
        novoContato->endereco.cidade, 
        novoContato->endereco.estado);

    printf("\nDados cadastrados com sucesso!");

    salvarArquivos(novoContato);
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
    printf("\nContato anterior: %s", contatoAtual->contatoAnterior->name);
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

void lerArquivos(Contato * listaTelefonica)
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
        char linha[MAX_LENGTH];
        while(fgets(linha, sizeof(linha), arquivo) != NULL)
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
                sscanf(linha,"Endereço %s", endereco.enderecoCompleto);
            }
            else if(strstr(linha,"Numero de telefone:"))
            {
                sscanf(linha,"Numero de telefone: %s", numeroDeContato);
            }
            //printf("%s",linha);
        }
        inserirContatosDoArquivo(listaTelefonica,nome,endereco,dataDeNascimento,numeroDeContato);
    }
    fclose(arquivo);
}

void salvarArquivos(Contato * contatoAtual)
{
    FILE * arquivo;
    arquivo = fopen("../lista_telefonica.txt", "w");
    if(arquivo == NULL)
    {
        printf("\nO arquivo não foi encontrado");
    }
    else
    {   
        fprintf(arquivo, "Nome: %s", contatoAtual->name);
        fprintf(arquivo, "\nData de nascimento: %d %d %d", contatoAtual->datadeNascimento.dia, contatoAtual->datadeNascimento.mes, contatoAtual->datadeNascimento.ano);
        fprintf(arquivo, "\nEndereço: %s", contatoAtual->endereco.enderecoCompleto);
        fprintf(arquivo, "\nNumero de telefone: %s", contatoAtual->numeroDeContato);
    }
    fclose(arquivo);
}

void inserirContatosDoArquivo(Contato * contatoAtual, char * nome, Endereco endereco, DataDeNascimento dataDeNascimento, char *numeroDeContato)
{
    Contato * novoContato = (Contato *) malloc(sizeof(Contato));
    contatoAtual->proximoContato = novoContato;
    novoContato->contatoAnterior = contatoAtual;

    novoContato->endereco = endereco;
    novoContato->datadeNascimento = dataDeNascimento;
    strcpy(novoContato->numeroDeContato, numeroDeContato);
    strcpy(novoContato->name, nome);
}

void removerContato(Contato *contatoAtual)
{
    Contato * aux = contatoAtual->proximoContato;
    contatoAtual->proximoContato->contatoAnterior = contatoAtual->contatoAnterior;
    contatoAtual->contatoAnterior->proximoContato = aux;
    free(contatoAtual);
    printf("\nContato removido com sucesso");
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
        return listaTelefonica;

    }
    else
    {
        return contatoAtual;
    }
}
