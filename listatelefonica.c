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

Contato * procurarContatoPorData(Contato *listaTelefonica, int dia, int mes, int ano)
{
    Contato * contatoProcurado = listaTelefonica->proximoContato;
    DataDeNascimento dataDoContatoAtual;
    printf("\n %d %d %d", dia, mes, ano);
    while(contatoProcurado != NULL)
    {
        dataDoContatoAtual.dia = contatoProcurado->datadeNascimento.dia;
        printf("\n%d", dataDoContatoAtual.dia);
        dataDoContatoAtual.mes = contatoProcurado->datadeNascimento.mes;
        printf("\n%d", dataDoContatoAtual.mes);
        dataDoContatoAtual.ano = contatoProcurado->datadeNascimento.ano;
        printf("\n%d", dataDoContatoAtual.ano);

        if(dia == dataDoContatoAtual.dia && mes == dataDoContatoAtual.mes && ano == dataDoContatoAtual.ano)
        {
            limparTela();
            printf("\nContato encontrado com sucesso!");
            return contatoProcurado;
        }

        contatoProcurado = contatoProcurado->proximoContato;
    }
    limparTela();
    printf("\nContato não encontrado!");
    pausarExecucao();

    return NULL;
}

Contato * procurarContatoPorNumeroDeTelefone(Contato *listaTelefonica, char * numeroDeTelefone)
{
    Contato * contatoProcurado = listaTelefonica->proximoContato;

    while(contatoProcurado != NULL)
    {
        if(strcasecmp(numeroDeTelefone, contatoProcurado->numeroDeContato) == 0)
        {
            limparTela();
            printf("\nContato encontrado com sucesso!");
            pausarExecucao();
            return contatoProcurado;
        }

        contatoProcurado = contatoProcurado->proximoContato;
    }

    limparTela();
    printf("\nContato não encontrado!");
    pausarExecucao();

    return NULL;
}

void procurarContatosPorEndereco(Contato *listaTelefonica, Contato **ponteirosDeContato, char * informacao, int opcao)
{
    Contato * contatoProcurado;
    char teste[MAX_LENGTH];

    int qntDeContatos = contadorDeContatos(listaTelefonica), contador = 0;
    for (int i = 0; i < qntDeContatos; i++)
    {
        ponteirosDeContato[i] = NULL;
    }

    switch(opcao)
    {
        /* Procurar por rua */
        case 1:
        {
            contatoProcurado = listaTelefonica->proximoContato;
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
            contatoProcurado = listaTelefonica->proximoContato;
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
            contatoProcurado = listaTelefonica->proximoContato;
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
            contatoProcurado = listaTelefonica->proximoContato;
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

    int vazio = 0;
    for (int i = 0; i < qntDeContatos; i++)
    {
        if (ponteirosDeContato[i] != NULL)
        {
            vazio = 1;
        }
        
    }

    if (vazio == 0)
    {
        printf("Nenhum contato encontrado\n");
        getchar();
    }
    

}

Contato * procurarPorNumeroDeEndereco(Contato *listaTelefonica, int numero)
{
    Contato * contatoProcurado = listaTelefonica->proximoContato;
    while(contatoProcurado != NULL)
    {
        if(numero == contatoProcurado->endereco.numero)
        {
            limparTela();
            printf("\nContato encontrado com sucesso!");
            pausarExecucao();
            return contatoProcurado;
        }

        contatoProcurado = contatoProcurado->proximoContato;
    }

    limparTela();
    printf("\nContato não encontrado!");
    pausarExecucao();

    return NULL;
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
