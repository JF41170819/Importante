#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

void fLimpiar()
{
    system("cls");
}
int getInt(char mensajeamostrar[],char erroramostrar[],int minimo,int maximo,int largoentero)
{

    int bandera;
    int validacion;
    int numero;
    char numeroAUX[largoentero];

    do
    {
        bandera=0;

        printf(mensajeamostrar);
        fflush(stdin);
        scanf("%s",numeroAUX);

        validacion=validaNumero(numeroAUX,largoentero);

        if(validacion!=0)
        {
            numero=atoi(numeroAUX);
            if(numero>=minimo && numero<=maximo)
            {
                return numero;
            }
            else
            {
                printf(erroramostrar);
                bandera++;
            }
        }
        else
        {
            printf(erroramostrar);
            bandera++;
        }
    }
    while(bandera!=0);
}
int validaNumero(char datoAValidar[],int largoDato)
{
    int i;
    int largoNumero;
    int bandera=0;

    largoNumero=strlen(datoAValidar);

    if((largoNumero>largoDato) && (largoDato!=0))
    {
        return 0;
    }

    for(i=0; i<largoNumero; i++)
    {
        if(!(isdigit(datoAValidar[i])))
        {
            bandera=1;
            break;
        }
    }

    if(bandera==1)
    {
        return 0;
    }

    return 1;
}
void getChar(char ingreso[],char mensajeamostrar[],char erroramostrar[],int largoChar)
{
    int bandera;
    int validacion;

    do
    {
        bandera=0;

        printf(mensajeamostrar);
        fflush(stdin);
        gets(ingreso);

        validacion=validaLetra(ingreso,largoChar);

        if(validacion==0)
        {
            printf(erroramostrar);
            bandera++;
        }
    }
    while(bandera!=0);
}
int validaLetra(char datoAValidar[],int largoChar)
{
    int i;
    int largoC;
    int bandera=0;

    largoC=strlen(datoAValidar);

    if((largoC>largoChar) && (largoChar!=0))
    {
        return 0;
    }

    for(i=0; i<largoC; i++)
    {
        if((isdigit(datoAValidar[i])) || ((datoAValidar[i]<'A') || (datoAValidar[i]>'Z' && datoAValidar[i]<'a') || (datoAValidar[i]>'z')) )
        {
            bandera=1;
            break;
        }
    }

    if(bandera==1)
    {
        return 0;
    }

    return 1;
}
void inicializarDuenio(eDuenio lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }

}
void inicializarAuto(eAuto listaAuto[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listaAuto[i].estadoAuto=0;
    }

}
int buscarEspacioLibreDuenio(eDuenio lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            return i; //Devuelvo indice
        }
    }

    return -1; //Devuelvo -1 (no es un indice)
}
int buscarEspacioLibreAuto(eAuto listaAuto[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listaAuto[i].estadoAuto==0)
        {
            return i; //Devuelvo indice
        }
    }

    return -1; //Devuelvo -1 (no es un indice)
}
int buscarID(int id, eDuenio lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].idDuenio==id && lista[i].estado==1)
        {
            return i;
        }
    }

    return -1;
}
int buscarPatenteAuto(char patente[], eAuto listaAuto[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(strcmp(listaAuto[i].patente,patente)==0 && listaAuto[i].estadoAuto==1)
        {
            return i;
        }
    }

    return -1;
}
void altaDuenio(eDuenio lista[],int tam)
{
    int indice;
    int idDuenio;
    char nombre[200];
    char apellido[200];
    char direccionNombre[200];
    int direccionNumero;
    char direccionNumeroAUX[200];
    int tarjetaDeCredito;
    int validacion;

    indice=buscarEspacioLibreDuenio(lista,tam);

    if(indice!=-1)
    {

        //Ingreso id
        idDuenio=getInt("Ingrese ID: ", "Error, el ID va de 1 a 10...\n",1,10,2);

        validacion=buscarID(idDuenio,lista,tam);

        while(validacion!=-1)
        {
            printf("Error, el ID ya esta en el sistema!.\n");
            idDuenio=getInt("Ingrese ID: ", "Error, el ID va de 1 a 10...\n",1,10,2);
            //Importante
            validacion=buscarID(idDuenio,lista,tam);
        }

        //Guardo el ID
        lista[indice].idDuenio=idDuenio;

        //Ingreso nombre
        getChar(nombre,"Ingrese nombre: ", "Nombre invalido...\n", 100);

        //Ingreso apellido
        getChar(apellido,"Ingrese apellido: ", "Apellido invalido...\n", 100);


        //Guardo el nombre y apellido
        strcpy(lista[indice].nombreApellido,nombre);
        strcat(lista[indice].nombreApellido,",");
        strcat(lista[indice].nombreApellido,apellido);

        ////////////////////////////////////////////////////

        getChar(direccionNombre,"Ingrese nombre de la calle (SOLO NOMBRE): ", "Calle invalida...\n", 100);

        direccionNumero=getInt("Ingrese altura de la calle (NUMERO): ", "Error, altura invalida...\n",1,5000,4);

        itoa(direccionNumero, direccionNumeroAUX,10);

        //Guardo la direccion
        strcpy(lista[indice].direccion,direccionNombre);
        strcat(lista[indice].direccion, " ");
        strcat(lista[indice].direccion,direccionNumeroAUX);

        //Ingreso numero de tarjeta de credito
        printf("Ingrese tarjeta de credito: ");
        scanf("%d",&tarjetaDeCredito);

        //Guardo la tarjeta de credito
        lista[indice].tarjetaDeCredito=tarjetaDeCredito;

        lista[indice].estado=1;

        system("pause");
    }
    else
    {
        printf("Error no hay mas espacio!.\n");
        system("pause");
    }
}
void modifDuenio(eDuenio lista[],int tam)
{
    int idDuenio;
    int indice;
    int tarjetaDeCredito;

    //Pido el ingreso del indice
    idDuenio=getInt("Ingrese ID: ", "Error, el ID va de 1 a 10...\n",1,10,2);

    indice=buscarID(idDuenio,lista,tam);

    if(indice!=-1)
    {
        printf("ID encontrado, notifique el cambio a continuacion...\n");

        printf("Ingrese la nueva tarjeta de credito: ");
        scanf("%d",&tarjetaDeCredito);
        //Guardo la tarjeta de credito
        lista[indice].tarjetaDeCredito=tarjetaDeCredito;
    }
    else
    {
        printf("Error, no se encontro el ID.\n");
        system("pause");
    }
}
void altaAuto(eDuenio lista[], int tamDuenio, eAuto listaAuto[], int tamAuto)
{
    int indiceAuto;
    int indiceDuenio;
    char patente[200];
    int marca;
    int idDuenio;
    int horaEntrada;

    indiceAuto=buscarEspacioLibreAuto(listaAuto,tamAuto);

    if(indiceAuto!=-1)
    {
        //Pido el ingreso del indice
        idDuenio=getInt("Ingrese ID: ", "Error, el ID va de 1 a 10...\n",1,10,2);
        indiceDuenio=buscarID(idDuenio,lista,tamDuenio);

        if(indiceDuenio==-1)
        {
            printf("Error, ese ID no se encuentra en el sistema.\n");
        }
        else
        {
            printf("ID correcto\n");

            //Copio el ID a la estructura del auto
            listaAuto[indiceAuto].idDuenio=idDuenio;

            printf("Ingrese pantente: ");
            scanf("%s",patente);

            int buscar;
            buscar=buscarPatenteAuto(patente,listaAuto,tamAuto);

            while(buscar!=-1)
            {
                printf("Error, esa pantente se encuentra en el sistema. Ingrese una patente valida: ");
                scanf("%s",patente);
                buscar=buscarPatenteAuto(patente,listaAuto,tamAuto);
            }

            //Guardo patente
            strcpy(listaAuto[indiceAuto].patente,patente);

            printf("------------------\n");
            printf("1-Alpha romero\n");
            printf("2-Ferrari\n");
            printf("3-Audi\n");
            printf("4-Otro\n");
            printf("Ingrese marca: ");
            scanf("%d",&marca);

            while(marca<1 || marca>4)
            {
                printf("Error, ingrese una marca correcta: ");
                scanf("%d",&marca);
            }

            //Guardo marca
            listaAuto[indiceAuto].marca=marca;

            if(marca==1)
            {
                strcpy(listaAuto[indiceAuto].marcaString,"ALPHA ROMERO");
            }
            else if(marca==2)
            {
                strcpy(listaAuto[indiceAuto].marcaString,"FERRARI");
            }
            else if(marca==3)
            {
                strcpy(listaAuto[indiceAuto].marcaString,"AUDI");
            }
            else
            {
                strcpy(listaAuto[indiceAuto].marcaString,"OTRO");
            }

            horaEntrada=getInt("Ingrese hora de entrada: ", "Error, el formato es de 24hs...\n",1,24,2);

            //Guardo hora de entrada
            listaAuto[indiceAuto].horaEntrada=horaEntrada;

            listaAuto[indiceAuto].estadoAuto=1;
        }
    }
    else
    {
        printf("Error no hay mas espacio!.\n");
    }
}
void bajaAuto(eAuto listaAuto[], int tamA, eDuenio lista[], int tamD)
{
    char patente[200];
    int indiceAuto;
    int horaEntrada;
    int horaSalida;
    float valorEstadia;
    int resta;

    //Pido el ingreso del indice
    printf("Ingrese pantente: ");
    scanf("%s",patente);

    indiceAuto=buscarPatenteAuto(patente,listaAuto,tamA);

    if(indiceAuto==-1)
    {
        printf("Error, no se encontro la patente.\n");
    }
    else
    {
        printf("Patente correcta\n");
        horaSalida=getInt("Ingrese hora de salida: ", "Error, el formato es de 24hs...\n",1,24,2);

        horaEntrada=listaAuto[indiceAuto].horaEntrada;
        resta=(horaSalida - horaEntrada);

        while(resta<1)
        {
            printf("Error ingrese una hora de salida correcta... \n");
            horaSalida=getInt("Ingrese hora de salida: ", "Error, el formato es de 24hs...\n",1,24,2);
            resta=(horaSalida - horaEntrada);
        }

        listaAuto[indiceAuto].horaSalida=horaSalida;

        listaAuto[indiceAuto].estadoAuto=0;

        int i,indiceDuenio;
        for(i=0; i<tamD; i++)
        {
            if(listaAuto[indiceAuto].idDuenio==lista[i].idDuenio)
            {
                indiceDuenio=i;
                break;
            }
        }

        switch(listaAuto[indiceAuto].marca)
        {
        case 1:
            valorEstadia=(resta*ALPHA_ROMERO);
            fLimpiar();
            printf("+---------------------------------------------------------------------------------------------------------------------+\n");
            printf("NOMBRE: %s\tPATENTE: %s\tMARCA: ALPHA ROMERO\tVALOR ESTADIA: %.2f\n",lista[indiceDuenio].nombreApellido,listaAuto[indiceAuto].patente,valorEstadia);
            printf("\n");
            system("pause");
            break;
        case 2:
            valorEstadia=(resta*FERRARI);
            fLimpiar();
            printf("+---------------------------------------------------------------------------------------------------------------------+\n");
            printf("NOMBRE: %s\tPATENTE: %s\tMARCA: FERRARI\tVALOR ESTADIA: %.2f\n",lista[indiceDuenio].nombreApellido,listaAuto[indiceAuto].patente,valorEstadia);
            printf("+---------------------------------------------------------------------------------------------------------------------+\n");
            printf("\n");
            system("pause");
            break;
        case 3:
            valorEstadia=(resta*AUDI);
            fLimpiar();
            printf("+---------------------------------------------------------------------------------------------------------------------+\n");
            printf("NOMBRE: %s\tPATENTE: %s\tMARCA: AUDI\tVALOR ESTADIA: %.2f\n",lista[indiceDuenio].nombreApellido,listaAuto[indiceAuto].patente,valorEstadia);
            printf("+---------------------------------------------------------------------------------------------------------------------+\n");
            printf("\n");
            system("pause");
            break;
        case 4:
            valorEstadia=(resta*OTRO);
            fLimpiar();
            printf("+---------------------------------------------------------------------------------------------------------------------+\n");
            printf("NOMBRE: %s\tPATENTE: %s\tMARCA: OTRO\tVALOR ESTADIA: %.2f\n",lista[indiceDuenio].nombreApellido,listaAuto[indiceAuto].patente,valorEstadia);
            printf("+---------------------------------------------------------------------------------------------------------------------+\n");
            printf("\n");
            system("pause");
            break;
        }
    }

}
void informar(eDuenio lista[], int tamD, eAuto listaAuto[], int tamA)
{
    int opcion;
    int i,j;
    char continuar='s';

    while(continuar=='s')
    {
        printf("1-Listado de autos estacionados con sus due%cos, ordenado por hora de entrada y patente.\n",164);
        printf("2-Todos los propietarios de autos de marca AUDI.\n");
        printf("3-Recaudacion total por marca.\n");
        printf("4-Recaudacion total del estacionamiento.\n");
        printf("5-Volver al menu principal.\n");

        printf("Introduce una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            fLimpiar();
            int bandera=0;
            for(i=0; i<tamA; i++)
            {
                for(j=0; j<tamD; j++)
                {
                    if(listaAuto[i].estadoAuto!=0 && listaAuto[i].idDuenio==lista[j].idDuenio)
                    {
                        printf("+---------------------------------------------------------------------------------------------------------------------+\n");
                        printf("NOMBRE: %s\tMARCA: %s\tHORA DE ENTRADA: %d\tPATENTE: %s\n",lista[j].nombreApellido,listaAuto[i].marcaString,listaAuto[i].horaEntrada,listaAuto[i].patente);
                        printf("+---------------------------------------------------------------------------------------------------------------------+\n");
                        bandera=1;
                    }
                }

            }
            if(bandera==0)
            {
              printf("No se han encontrado autos estacionados en el sistema.\n");
              printf("\n");
            }
            break;
        case 2:
            fLimpiar();
            int flag=0;
            for(i=0; i<tamA; i++)
            {
                for(j=0; j<tamD; j++)
                {
                    if(listaAuto[i].estadoAuto!=0 && listaAuto[i].idDuenio==lista[j].idDuenio && listaAuto[i].marca==3)
                    {
                        printf("+---------------------------------------------------------------------------------------------------------------------+\n");
                        printf("NOMBRE: %s\tMARCA: AUDI\t\tHORA DE ENTRADA: %d\tPATENTE: %s\n",lista[j].nombreApellido,listaAuto[i].horaEntrada,listaAuto[i].patente);
                        flag=1;
                    }
                }
            }
            if(flag==1)
            printf("+---------------------------------------------------------------------------------------------------------------------+\n");
            else
            {
              printf("No se han encontrado autos de marca AUDI en el sistema.\n");
              printf("\n");
            }
            break;
        case 3:
            fLimpiar();
            float calculo;
            float acum_alpha=0,acum_ferrari=0,acum_audi=0,acum_otro=0;
            for(j=0; j<tamA; j++)
            {
                if(listaAuto[j].estadoAuto==0)
                {
                    switch(listaAuto[j].marca)
                    {
                    case 1:
                        calculo=((listaAuto[j].horaSalida - listaAuto[j].horaEntrada)*(ALPHA_ROMERO));
                        acum_alpha=acum_alpha+calculo;
                        break;
                    case 2:
                        calculo=((listaAuto[j].horaSalida - listaAuto[j].horaEntrada)*(FERRARI));
                        acum_ferrari=acum_ferrari+calculo;
                        break;
                    case 3:
                        calculo=((listaAuto[j].horaSalida - listaAuto[j].horaEntrada)*(AUDI));
                        acum_audi=acum_audi+calculo;
                        break;
                    case 4:
                        calculo=((listaAuto[j].horaSalida - listaAuto[j].horaEntrada)*(OTRO));
                        acum_otro=acum_otro+calculo;
                        break;
                    }
                }
            }

            printf("+--------------------------+\n");
            printf("| \tGANANCIAS:         |\n");
            printf("+--------------------------+\n");
            printf("\tALPHA: %.2f\n",acum_alpha);
            printf("\tFERRARI: %.2f\n",acum_ferrari);
            printf("\tAUDI: %.2f\n",acum_audi);
            printf("\tOTRO: %.2f\n",acum_otro);
            printf("+--------------------------+\n");
            break;
        case 4:
            fLimpiar();
            float calculo1;
            float acum_alpha1=0,acum_ferrari1=0,acum_audi1=0,acum_otro1=0;
            for(j=0; j<tamA; j++)
            {
                if(listaAuto[j].estadoAuto==0)
                {
                    switch(listaAuto[j].marca)
                    {
                    case 1:
                        calculo1=((listaAuto[j].horaSalida - listaAuto[j].horaEntrada)*(ALPHA_ROMERO));
                        acum_alpha1=acum_alpha1+calculo1;
                        break;
                    case 2:
                        calculo1=((listaAuto[j].horaSalida - listaAuto[j].horaEntrada)*(FERRARI));
                        acum_ferrari1=acum_ferrari1+calculo1;
                        break;
                    case 3:
                        calculo1=((listaAuto[j].horaSalida - listaAuto[j].horaEntrada)*(AUDI));
                        acum_audi1=acum_audi1+calculo1;
                        break;
                    case 4:
                        calculo1=((listaAuto[j].horaSalida - listaAuto[j].horaEntrada)*(OTRO));
                        acum_otro1=acum_otro1+calculo1;
                        break;
                    }
                }
            }

            float gantotal=(acum_alpha1+acum_ferrari1+acum_audi1+acum_otro1);
            printf("+--------------------------+\n");
            printf("|   GANANCIAS TOTALES:     |\n");
            printf("+--------------------------+\n");
            printf("\t %.2f\n",gantotal);
            printf("+--------------------------+\n");
            break;

        case 5:
            fLimpiar();
            continuar='n';
            break;

        default:
            fLimpiar();
            printf("Error, introduzca una opcion correcta\n");
            break;
        }
    }
}
void ordenar(eAuto listaAuto[], int tamA)
{
    int i,j;
    /*int x;
    for(x=0;x<tamA;x++)
    printf("HORA: %d,PATENTE: %s\n",listaAuto[x].horaEntrada,listaAuto[x].patente);
    printf("----------------------------------------------\n");*/
    eAuto aux;
    for(i=0; i<tamA-1; i++)
    {
        for(j=i+1; j<tamA; j++)
        {
            if(listaAuto[i].horaEntrada>listaAuto[j].horaEntrada)
            {
                aux=listaAuto[i];
                listaAuto[i]=listaAuto[j];
                listaAuto[j]=aux;
            }
            if(listaAuto[i].horaEntrada==listaAuto[j].horaEntrada)
            {
                if(strcmp(listaAuto[i].patente,listaAuto[j].patente)>0)
                {
                    aux=listaAuto[i];
                    listaAuto[i]=listaAuto[j];
                    listaAuto[j]=aux;
                }
            }
        }
    }

    /*for(x=0;x<tamA;x++)
    printf("HORA: %d,PATENTE: %s\n",listaAuto[x].horaEntrada,listaAuto[x].patente);*/
}
