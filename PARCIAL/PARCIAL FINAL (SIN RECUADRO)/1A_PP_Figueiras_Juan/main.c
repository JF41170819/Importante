#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib.h"

#define DUENIOS 10
#define AUTOS 10

int main()
{
    char continuar='s';
    int opcion;

    eDuenio lista[DUENIOS]={{1,"Juan Perez",4767100839392076,"Calle100",1},{2,"Jose Ramirez",4148643322847478,"Calle101",1},{3,"Guido Hernandez",4197168399725118,"Calle102",1},{4,"Ramon Gomez",4870922650614476,"Calle103",1},{5,"Milena Vasquez",4048149035222844,"Calle104",1},{6,"Laura Ramos",4342580062354063,"Calle105",1},{7,"Emilio Morales",5153345002084914,"Calle106",1},{8,"Carlos Garcia",5187910192133407,"Calle107",1},{9,"Hugo Diaz",5466410311204116,"Calle108",1},{10,"Juana Lopez",5401683093120787,"Calle109",1}};
    eAuto listaAuto[AUTOS]={{1,"ABC123",1,"ALPHA ROMERO",6,10,0},{2,"DEF456",1,"ALPHA ROMERO",1,4,0},{3,"GHI789",3,"AUDI",7,8,1},{4,"JKL123",3,"AUDI",3,8,1},{5,"MNO456",3,"AUDI",5,9,1},{6,"PQR789",2,"FERRARI",2,6,0},{7,"STU123",2,"FERRARI",5,7,1},{8,"VWX456",2,"FERRARI",8,11,0},{9,"YZA789",4,"OTRO",11,13,0},{10,"BCD123",4,"OTRO",14,16,1}};

    /*eDuenio lista[DUENIOS];
    eAuto listaAuto[AUTOS];
    inicializarDuenio(lista,DUENIOS);
    inicializarAuto(listaAuto,AUTOS);*/

    while(continuar=='s')
    {
        system("COLOR 03");
        char n=164;
        printf("+--------------------------+\n");
        printf("|                          |\n");
        printf("| SISTEMA DE COCHERA v1.0  |\n");
        printf("|                          |\n");
        printf("+--------------------------+\n");
        printf("|                          |\n");
        printf("| 1- Alta de due%co         |\n",n);
        printf("| 2- Modificacion de due%co |\n",n);
        printf("| 3- Ingreso del automovil |\n");
        printf("| 4- Egreso del automovil  |\n");
        printf("| 5- Informar              |\n");
        printf("| 6- Salir                 |\n");
        printf("|                          |\n");
        printf("+--------------------------+\n");
        printf("\n");
        printf("Introduce una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                fLimpiar();
                altaDuenio(lista,DUENIOS);
                break;
            case 2:
                fLimpiar();
                modifDuenio(lista,DUENIOS);
                break;
            case 3:
                fLimpiar();
                altaAuto(lista,DUENIOS,listaAuto,AUTOS);
                break;
            case 4:
                fLimpiar();
                bajaAuto(listaAuto,AUTOS,lista,DUENIOS);
                break;
            case 5:
                fLimpiar();
                ordenar(listaAuto,AUTOS);
                informar(lista,DUENIOS,listaAuto,AUTOS);
                break;
            case 6:
                continuar='n';
                break;
        }
    }
    return 0;
}
