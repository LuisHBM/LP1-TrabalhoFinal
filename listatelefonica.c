#include "listatelefonica.h"

void limparTela();

void criandoNovoContato(Contato *listaTelefonica)
{
    /* Verificar se o arquivo possui algo , se tiver carrega, caso não segue */

    Contato * novoContato = (Contato *) malloc(sizeof(Contato));
    listaTelefonica->proximoContato = novoContato;

    printf("\nDigite o nome do contato: ");
    scanf("%[A-Z a-z]",novoContato->name);
    getchar();

    printf("\nDigite a data de nascimento de %s (DD MM AAAA): ", novoContato->name);
    scanf("%d %d %d", &novoContato->datadeNascimento.dia, &novoContato->datadeNascimento.mes, &novoContato->datadeNascimento.ano);
    getchar();

    printf("\nDigite o numero de telefone de %s (XX XXXXX-XXXX)",novoContato->numeroDeContato);
    scanf("%[0-9 () -]",novoContato->numeroDeContato);
    getchar();

    printf("\nDigite o endereço completo (rua, número, bairro, cidade, estado): ");
    fgets(novoContato->endereco.enderecoCompleto, MAX_LENGTH,stdin);
    /*A função sscanf não lê da entrada padrão(stdin), mas sim a partir de uma string; 
    Esse "%[^,]" têm esse -> ' ^ ' que é uma negação, então ele vai ler tudo que não for uma vírgula. Quando ele encontrar uma vígula
    ele vai parar de ler e alocar no endereco que vocẽ especificou*/
    sscanf(novoContato->endereco.enderecoCompleto, 
        "%[^,], %d, %[^,], %[^,], %[^\n]",
        novoContato->endereco.rua, 
        &novoContato->endereco.numero, 
        novoContato->endereco.bairro, 
        novoContato->endereco.cidade, 
        novoContato->endereco.estado);

    printf("\nDados cadastrados com sucesso!");
}

void exibirMenu()
{
    printf("\nSeja bem-vindo(a)!");
    printf("\nO que deseja fazer?");
    printf("\n1.Inserir novo contato");
    printf("\n2.Modificar informações de um contato");
    printf("\n3.Exibir informações de um contato");
    printf("\n0.Sair do programa");
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
                printf("\nDigite o novo endereço de %s", contatoAtual->name);
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
    printf("\nNome: %s", contatoAtual->name);
    printf("\nData de nascimento: %d/%d/%d", contatoAtual->datadeNascimento.dia,contatoAtual->datadeNascimento.mes, contatoAtual->datadeNascimento.ano);
    printf("\nEndereço: %s", contatoAtual->endereco.enderecoCompleto);
    printf("\nNumero de telefone: %s", contatoAtual->numeroDeContato);
}

void limparTela()
{
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear"); 
    #endif
}
