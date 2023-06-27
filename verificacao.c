#include "verificacao.h"

bool validarDataDeNascimento(int dia, int mes, int ano)
{
    if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 2023)
    {
        return false;
    }

    return true;
}
