#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "directores.h"



static int generarIdDirector()
{
    static int id=0;

    id ++;

    return id;
}
void inicializarDirectores(eDirector arrayDirectores[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        arrayDirectores[i].isEmpty = 1;
    }
}

int buscarDirectorLibre(eDirector arrayDirectores[],int cantidad)
{
    int i;
    int retorno = -1;
    for(i=0;i<cantidad;i++)
    {
        if(arrayDirectores[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int buscarDirectorPorNombre(eDirector arrayDirectores[], int cantidad, char nombre[])
{
    int i;
    int retorno=-1;
    if( arrayDirectores!= NULL)
    {
        for( i=0 ; i<cantidad ; i++)
        {
            if(strcmp(arrayDirectores[i].nombre,nombre)==0 && arrayDirectores[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int altaDirector(eDirector arrayDirectores[], int cantidad)
{
    eDirector auxiliarDirector;
    int lugarLibre = buscarDirectorLibre(arrayDirectores, cantidad);
    int retorno=-1;
    int comparacion;
    int auxId;
    //char auxNombre[51];
    //char auxNacionalidad[51];
    //int auxAnio;

    if(arrayDirectores !=  NULL)
    {
        if(lugarLibre== -1)
        {
            printf("No hay espacio libre para los directores!!!");
        }
        else
        {
            getValidString("Ingrese nombre del director: ", "Error, no valido.", auxiliarDirector.nombre);
            comparacion =buscarDirectorPorNombre(arrayDirectores, cantidad, auxiliarDirector.nombre);

            if(comparacion!=-1)
            {
                printf("Existe un autor con ese nombre");
            }
            else
            {

            auxId=generarIdDirector();
            auxiliarDirector.idDirector=auxId;
            getValidString("Ingrese pais de origen del director: ", "Error, no valido.", auxiliarDirector.paisOrigen);
            auxiliarDirector.nacimiento.dia = getValidInt("Ingrese dia: ","Error, dia no valido.", 1, 31);
            auxiliarDirector.nacimiento.mes = getValidInt("Ingrese mes: ","Error, mes no valido.", 1, 12);
            auxiliarDirector.nacimiento.anio = getValidInt("Ingrese anio: ","Error, anio no valido.", 1000, 2018);
            //auxiliarPelicula.id = generarNextId();
            auxiliarDirector.isEmpty =0;
            arrayDirectores[lugarLibre]=auxiliarDirector;

            }

            retorno=0;
        }
    }
    return retorno;
}

int removerDirector(eDirector arrayDirectores[], int cantidad, char nombre[])
{
    int index;
    int i;
    int retorno=-1;
    int opcion;

    if(arrayDirectores!=NULL)
    {
        mostrarTodosLosDirectores(arrayDirectores,cantidad);
        printf("Ingrese el nombre del director que desea eliminar: ");
        fflush(stdin);
        gets(nombre);
        index=buscarDirectorPorNombre(arrayDirectores, cantidad, nombre);

        if(arrayDirectores[index].isEmpty==0)
        {
            // printf("ID\t   TITULO\t   ANIO\t   NACIONALIDAD\n");
             mostrarUnDirector(arrayDirectores, index);
        }
        //Tendria que preguntar si quiere eliminar la pelicula
        for( i=0 ; i<cantidad ; i++)
        {
            if(index>=0)
            {
                printf("Seguro que quiere eliminar el director? (1.Si/2.No)");
                scanf("%d",&opcion);

                if(opcion==1)
                {
                    printf("El usuario fue eliminado!\n");
                    arrayDirectores[index].isEmpty=1;
                    break;
                }
                else
                {
                   printf("no se elimino el director");
                   break;
                }

            }
            else
            {
                printf("No existe ese nombre!! \n");
                break;
            }
            retorno=0;
        }
    }
    return retorno;
}

int mostrarUnDirector(eDirector arrayDirectores[], int indice)
{
    int retorno=-1;
    if( arrayDirectores!= NULL)
    {
        if(arrayDirectores[indice].isEmpty==0)
        {

           printf("%3d %15s %15s %8d/%2d/%2d\n",arrayDirectores[indice].idDirector,
                   arrayDirectores[indice].nombre, arrayDirectores[indice].paisOrigen,
                   arrayDirectores[indice].nacimiento.dia,
                   arrayDirectores[indice].nacimiento.mes,
                   arrayDirectores[indice].nacimiento.anio);
           retorno=0;
        }
    }
    return retorno;

}

int mostrarTodosLosDirectores(eDirector arrayDirectores[], int cantidad)
{
    int retorno=-1;
    int i;
    if(arrayDirectores!= NULL)
    {
        printf("\n%3s %15s %15s %17s\n","Id", "Nombre", "Pais Origen", "Nacimiento");
        for( i=0; i<cantidad ; i ++ )
        {
            if(arrayDirectores[i].isEmpty == 0)
            {
                mostrarUnDirector(arrayDirectores, i);
                retorno=0;
            }
        }
    }
    return retorno;
}


void directoresHardcode(eDirector arrayDirectores[], eFecha fecha[])
{
    int i;
    int id[3]={1,2,3};
    char nombre[][51]={"Julio","Steven","Julio"};
    int dia[]={1,20,1};
    int mes[]={9,12,9};
    int anio[]={1960,1980,1960};
    char paisOrigen[][51]={"mex", "eeuu", "mex"};

    for(i=0;i<3;i++)
    {
        arrayDirectores[i].idDirector=id[i];
        arrayDirectores[i].nacimiento.anio=anio[i];
        arrayDirectores[i].nacimiento.mes=mes[i];
        arrayDirectores[i].nacimiento.dia=dia[i];
        strcpy(arrayDirectores[i].nombre,nombre[i]);
        strcpy(arrayDirectores[i].paisOrigen,paisOrigen[i]);

    }

}
