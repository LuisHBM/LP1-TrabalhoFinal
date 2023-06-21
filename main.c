#include "listatelefonica.h"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Contato listaTelefonica;
    inserindoContatos(&listaTelefonica);

    return 0;
}