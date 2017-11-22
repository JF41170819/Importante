#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Estructura.h"

eDestinatario* new_destinatario()
{
    eDestinatario* returnAux;

    returnAux = (eDestinatario*)malloc(sizeof(eDestinatario));

    if(returnAux != NULL)
    {
        strcpy(returnAux->nombre, "");
        strcpy(returnAux->email, "");
    }

    return returnAux;
}
