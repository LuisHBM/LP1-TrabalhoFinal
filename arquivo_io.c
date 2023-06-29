#include "arquivo_io.h"

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
