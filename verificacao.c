#include "verificacao.h"

bool validarDataDeNascimento(int dia, int mes, int ano)
{
    if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 2023)
    {
        return false;
    }

    return true;
}

bool validarTelefone(char *telefone, int tamanho)
{
    if(strlen(telefone) != tamanho)
    {
        return false;
    }
    else
    {
        for(int i = 0 ; i < tamanho ; i++)
        {
            if(!isdigit(telefone[i]) && i != 0 && i != 3 && i != 9)
            {
                return false;
            }
            else if(telefone[0] != '(')
            {
                return false;
            }
            else if(telefone[3] != ')')
            {
                return false;
            }
            else if(telefone[9] != '-')
            {
                return false;
            }
        }
    }
    return true;
}
