#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Estructura.h"
#include "Parser.h"

int main()
{
    char seguir='s';
    int opcion=0;

    char path1[150];
    char path2[150];

    ArrayList* listaBlanca = al_newArrayList();
    ArrayList* listaNegra = al_newArrayList();
    ArrayList* listaFinal = al_newArrayList();

    while(seguir=='s')
    {
        printf("1- Cargar destinatarios\n");
        printf("2- Cargar lista negra\n");
        printf("3- Depurar\n");
        printf("4- Listar\n");
        printf("5- Salir\n");

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                /*printf("Ingrese nombre del archivo 1: ");
                scanf("%s",archivo1);
                printf("Ingrese nombre del archivo 2: ");
                scanf("%s",archivo2);*/
                strcpy(path1, "destinatarios.csv");
                strcpy(path2, "black_list.csv");

                FILE* pFileListaB;
                FILE* pFileListaN;

                if((pFileListaB=fopen(path1, "r+"))==NULL ||(pFileListaN=fopen(path2, "r+"))==NULL)
                {
                    printf("No se ha podido leer los archivos\n");
                    exit(1);
                }

                //Parseo la lista blanca
                parserGenerico(pFileListaB , listaBlanca, path1);
                //Parseo la lista negra
                parserGenerico(pFileListaN , listaNegra, path2);
                //Hago la lista definitiva
                listaDefinitiva(listaBlanca, listaNegra, listaFinal);

                //Imprimo
                imprimir(listaFinal);

                ordenar(listaFinal);
                break;
            case 2:
                system("cls");
                break;
            case 3:
                system("cls");
                break;
            case 4:
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("Error, ingrese una opcion valida... \n");
                break;
        }
    }


    return 0;
}
