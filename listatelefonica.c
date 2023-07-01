#include "listatelefonica.h"

void criandoNovoContato(Contato *listaTelefonica)
{
    bool valido = false;
    Contato * ultimoContatoDaLista = listaTelefonica;
    /* Certificando-se que o contato atual é o último contato da lista */
    while(ultimoContatoDaLista->proximoContato != NULL)
    {
        ultimoContatoDaLista = ultimoContatoDaLista->proximoContato;
    }

    /* Alocando dinamicamente um novo contato e fazendo o contato atual apontar para o novo */
    Contato * novoContato = (Contato *) malloc(sizeof(Contato));
    ultimoContatoDaLista->proximoContato = novoContato;
    novoContato->proximoContato = NULL;

    /* Solicitando os dados do novo contato para o usuário */
    printf("\nDigite o nome do contato: ");
    fgets(novoContato->name, NOME,stdin);
    novoContato->name[strcspn(novoContato->name, " \n")] = '\0';

    /* Validando a entrada de data de nascimento */
    do
    {
        int dia, mes,ano;
        valido = false;
        printf("\nDigite a data de nascimento de %s (DD MM AAAA): ", novoContato->name);
        scanf(" %d %d %d", &dia, &mes, &ano);
        getchar();
        if(!validarDataDeNascimento(dia,mes,ano))
        {
            printf("\nData inválida! Por farvor insira uma data que seja válida e que segue o formato -> DD MM AAAA");
        }
        else
        {
            novoContato->datadeNascimento.dia = dia;
            novoContato->datadeNascimento.mes = mes;
            novoContato->datadeNascimento.ano = ano;
            valido = true;
        }

    }while(!valido);

    /* Validando a entrada do numero de telefone */
    do
    {
        char telefone[TELEFONE];
        valido = false;
        printf("\nDigite o numero de telefone de %s '(DD)9XXXX-XXXX' : ",novoContato->name);
        fgets(telefone, TELEFONE, stdin);
        telefone[strcspn(telefone, " \n")] = '\0';
        getchar();
        if(!validarTelefone(telefone, TELEFONE))  
        {
            printf("\nNúmero de telefone inválido!! insira um número que seja válido e que segue o formato -> '(DD)9XXXX-XXXX'");
        }
        else
        {
            strcpy(novoContato->numeroDeContato, telefone);
            valido = true;
        }

    }while(!valido);

        printf("\nO endereço deve ser separado por vírgulas. Exemplo: Silveira Martins, 8, Cabula, Salvador, Bahia");
        printf("\nDigite o endereço completo: ");
        fgets(novoContato->endereco.enderecoCompleto, MAX_LENGTH, stdin);
        novoContato->endereco.enderecoCompleto[strcspn(novoContato->endereco.enderecoCompleto, "\n")] = '\0';

        sscanf(novoContato->endereco.enderecoCompleto,
           "%[^,], %d, %[^,], %[^,], %[^\n]",
           novoContato->endereco.rua,
           &novoContato->endereco.numero,
           novoContato->endereco.bairro,
           novoContato->endereco.cidade,
           novoContato->endereco.estado);
    limparTela();
    printf("\nDados cadastrados com sucesso!");
    pausarExecucao();
}

void modificarContato(Contato * contatoAtual)
{
    limparTela();
    char strAux[MAX_LENGTH];

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
                atencao();
                printf("\n\nDigite o novo nome: ");
                fgets(strAux, NOME, stdin);
                strAux[strcspn(strAux, "\n")] = '\0';
                getchar();
                strcpy(contatoAtual->name,strAux);
                limparTela();
                printf("\nModificação realizada com sucesso!");
                pausarExecucao();
                break;
            }

            case 2:
            {
                bool valido = false;
                do
                {   
                    int dia, mes, ano;
                    printf("\nDigite a nova data de nascimento de %s (DD MM AAAA):", contatoAtual->name);
                    scanf(" %d %d %d", &dia, &mes, &ano);
                    getchar();
                    if(!validarDataDeNascimento(dia,mes,ano))
                    {
                        printf("\nData inválida! Por favor insira uma data que seja válida e que segue o formato -> DD MM AAAA");
                    }
                    else
                    {
                        contatoAtual->datadeNascimento.dia = dia;
                        contatoAtual->datadeNascimento.mes = mes;
                        contatoAtual->datadeNascimento.ano = ano;
                        valido = true;
                    }

                }while(!valido);
                
                limparTela();
                printf("\nModificação realizada com sucesso!");
                pausarExecucao();
                break;
            }

            case 3:
            {
                printf("\nO novo endereço deve ser separado por vírgulas. Exemplo: Silveira Martins, 8, Cabula, Salvador, Bahia");
                printf("\nDigite o novo endereço de %s: ", contatoAtual->name);
                fgets(contatoAtual->endereco.enderecoCompleto, MAX_LENGTH,stdin);
                sscanf(contatoAtual->endereco.enderecoCompleto, 
                        "%[^,], %d, %[^,], %[^,], %[^\n]",
                        contatoAtual->endereco.rua, 
                        &contatoAtual->endereco.numero, 
                        contatoAtual->endereco.bairro, 
                        contatoAtual->endereco.cidade, 
                        contatoAtual->endereco.estado);
                limparTela();
                printf("Modificação realizada com sucesso!");     
                pausarExecucao();
                break;
            }

            case 4:
            {
                bool valido;

                do
                {
                    char telefone[TELEFONE];
                    valido = false;
                    printf("\nDigite o numero de telefone de %s '(DD)9XXXX-XXXX' : ",contatoAtual->name);
                    fgets(telefone, TELEFONE, stdin);
                    telefone[strcspn(telefone, " \n")] = '\0';
                    getchar();
                    if(!validarTelefone(telefone, TELEFONE))
                    {
                        printf("\nNúmero de telefone inválido!! insira um número que seja válido e que segue o formato -> '(DD)9XXXX-XXXX'");
                    }
                    else
                    {
                        strcpy(contatoAtual->numeroDeContato, telefone);
                        valido = true;
                    }
                }while(!valido);
                limparTela();
                printf("\nModificação realizada com sucesso!");
                pausarExecucao();     
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

Contato * procurarContato(Contato *listaTelefonica, char * nome)
{
    Contato * contatoAtual = listaTelefonica;
    bool contatoEncontrado = false;
    
    while(contatoAtual != NULL)
    {
        if(strcasecmp(contatoAtual->name,nome) == 0)
        {   
            printf("\nContato encontrado com sucesso!");
            return contatoAtual;
        }

        contatoAtual = contatoAtual->proximoContato;
    }

    limparTela();
    printf("\nContato não encontrado");
    pausarExecucao();

    return NULL;

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
        limparTela();
        printf("\nAinda não há contatos na lista telefônica!");
        printf("\nAcesse a opção número '1' para cadastrar novos contatos");
        pausarExecucao();

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

void verificarListaVazia(Contato ** listaDePonteiros, int tam)
{
    bool vazio = true;

    for (int i = 0; i < tam; i++)
    {
        if (listaDePonteiros[i] != NULL)
        {
            vazio = false;
        }
    
    }

    if (vazio)
    {
        limparTela();
        printf("\nContato não encontrado!");
        pausarExecucao();
    }
}

void procurarContatosPorData(Contato *listaTelefonica, Contato ** ponteirosDeContato, int dia, int mes, int ano)
{
    int contador;
    Contato * contatoProcurado = listaTelefonica->proximoContato;
    DataDeNascimento dataDoContatoAtual;

    while(contatoProcurado != NULL)
    {
        dataDoContatoAtual.dia = contatoProcurado->datadeNascimento.dia;
        dataDoContatoAtual.mes = contatoProcurado->datadeNascimento.mes;
        dataDoContatoAtual.ano = contatoProcurado->datadeNascimento.ano;

        if(dia == dataDoContatoAtual.dia && mes == dataDoContatoAtual.mes && ano == dataDoContatoAtual.ano)
        {
            ponteirosDeContato[contador] = contatoProcurado;
        }

        contatoProcurado = contatoProcurado->proximoContato;
        contador++;
    }
    
    verificarListaVazia(ponteirosDeContato, contadorDeContatos(listaTelefonica));
}

void procurarContatosPorNumeroDeTelefone(Contato *listaTelefonica, Contato **ponteirosDeContato, char * numeroDeTelefone)
{
    int contador = 0;
    Contato * contatoProcurado = listaTelefonica->proximoContato;

    while(contatoProcurado != NULL)
    {
        if(strcasecmp(numeroDeTelefone, contatoProcurado->numeroDeContato) == 0)
        {
            ponteirosDeContato[contador] = contatoProcurado;
        }

        contatoProcurado = contatoProcurado->proximoContato;
        contador++;
    }

    verificarListaVazia(ponteirosDeContato, contadorDeContatos(listaTelefonica));
}

void procurarContatosPorEndereco(Contato *listaTelefonica, Contato **ponteirosDeContato, char * informacao, int opcao)
{
    int contador = 0;
    Contato * contatoProcurado;

    contatoProcurado = listaTelefonica->proximoContato;

    switch(opcao)
    {
        /* Procurar por rua */
        case 1:
        {
            while(contatoProcurado != NULL)
            {
                if(strcasecmp(informacao, contatoProcurado->endereco.rua) == 0)
                {
                    ponteirosDeContato[contador] = contatoProcurado;    
                }

                contatoProcurado = contatoProcurado->proximoContato;
                contador++;
            }
            break;
        }
        /* Procurar por bairro */
        case 3:
        {
            while(contatoProcurado != NULL)
            {
                if(strcasecmp(informacao, contatoProcurado->endereco.bairro) == 0)
                {
                    ponteirosDeContato[contador] = contatoProcurado;    
                }

                contatoProcurado = contatoProcurado->proximoContato;
                contador++;
            }
            break;
        }

        /* Procurar por cidade */
        case 4:
        {
            while(contatoProcurado != NULL)
            {
                if(strcasecmp(informacao, contatoProcurado->endereco.cidade) == 0)
                {
                    ponteirosDeContato[contador] = contatoProcurado;    
                }

                contatoProcurado = contatoProcurado->proximoContato;
                contador++;
            }
            break;
        }

        /* Procurar por estado */
        case 5:
        {
            while(contatoProcurado != NULL)
            {
                if(strcasecmp(informacao, contatoProcurado->endereco.estado) == 0)
                {
                    ponteirosDeContato[contador] = contatoProcurado;    
                }

                contatoProcurado = contatoProcurado->proximoContato;
                contador++;
            }
            break;
        }
        default:
        {
            limparTela();
            printf("\nOpção inválida");
        }
    }

    verificarListaVazia(ponteirosDeContato, contadorDeContatos(listaTelefonica));
}

void procurarPorNumeroDeEndereco(Contato *listaTelefonica, Contato **ponteirosDeContato, int numero)
{
    
    int contador = 0;
    Contato * contatoProcurado = listaTelefonica->proximoContato;

    while(contatoProcurado != NULL)
    {
        if(numero == contatoProcurado->endereco.numero)
        {
            ponteirosDeContato[contador] = contatoProcurado;
        }

        contatoProcurado = contatoProcurado->proximoContato;
        contador++;
    }
    
    verificarListaVazia(ponteirosDeContato, contadorDeContatos(listaTelefonica));
}

void removerContato(char * contatoProcurado, Contato * listaTelefonica)
{
    Contato * contato = listaTelefonica->proximoContato;
    Contato * contatoAnterior = listaTelefonica;

    /* Enquanto não for o fim da lista */
    while(contato != NULL)
    {   
        if(strcasecmp(contatoProcurado, contato->name) == 0)
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
    pausarExecucao();
}

void procurarContatosPorNome(Contato *listaTelefonica, Contato ** ponteiroDeContatos, char * nome)
{
    int contador = 0;
    Contato * contatoProcurado = listaTelefonica->proximoContato;

    while(contatoProcurado != NULL)
    {
        if(strcasecmp(contatoProcurado->name,nome) == 0)
        {   
            ponteiroDeContatos[contador] = contatoProcurado;
        }

        contatoProcurado = contatoProcurado->proximoContato;
        contador++;
    }

    verificarListaVazia(ponteiroDeContatos, contadorDeContatos(listaTelefonica));
}
