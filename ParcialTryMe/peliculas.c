#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "validaciones.c"
#include "directores.h"
#include "peliculas.h"

void inicializarArray(ePelicula arrayPeliculas[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        arrayPeliculas[i].isEmpty = 1;
    }
}

void menuPrincipal()
{
    printf("\n*********Bienvenido**********\n\n-------------------------\n1.Dar de alta una pelicula.\n2."
           "Modificar datos de una pelicula.\n3.Dar de baja una pelicula.\n4.Nuevo director.\n5.Eliminar Director"
           "\n6.Listar.\n7.Salir.\n-------------------------\n\n"
           "Ingrese una opcion: ");
}

int cargarPeliculas(ePelicula arrayPeliculas[],int cantidad)//listo
{
    int retorno=0;
        system("cls");
        if(cargarUnaPelicula(arrayPeliculas,buscarLibre(arrayPeliculas,cantidad),cantidad) == -1)
        {

            retorno=-1;
        }
        fflush(stdin);
    return retorno;
}

static int generateNextId ()
{
    static int id=0;

    id ++;

    return id;
}

int cargarUnaPelicula(ePelicula arrayPeliculas[],int vacio,int cantidad)//listo
{
    int retorno = -1;
    int auxId;
    char auxTitulo[51];
    int auxAnio;
    char auxNacionalidad[51];
    char auxDirector[51];
    if(retorno==-1)
    {
        /*
        char titulo[51];
        int anio;
        char nacionalidad[51];
        char nombreDirector[51];
        */
        auxId=generateNextId();

        getValidString("\nIngrese titulo de la pelicula:\n", " Error, ingrese titulo de la pelicula nuevamente (solo letras):", auxTitulo);

        auxAnio=getValidInt("\nIngrese anio de la pelicula:\n"," Error, ingrese anio de la pelicula nuevamente (solo numero):\n", 1800, 2018);

        getValidString("\nIngrese nacionalidad de la pelicula:\n", " Error, ingrese nacionalidad de la pelicula nuevamente (solo letras):", auxNacionalidad);

        getValidString("\nIngrese nombre del director:\n", " Error, ingrese nombre del director nuevamente (solo letras):", auxDirector);


        arrayPeliculas[vacio].id=auxId;
        strcpy(arrayPeliculas[vacio].titulo, auxTitulo);
        arrayPeliculas[vacio].anio=auxAnio;
        strcpy(arrayPeliculas[vacio].nacionalidad, auxNacionalidad);
        strcpy(arrayPeliculas[vacio].nombreDirector, auxDirector);

        arrayPeliculas[vacio].isEmpty = 0;
        retorno = 0;
    }

    if(retorno==0)
    {
        printf("\nPelicula cargada con exito!\n");
    }


    return retorno;
}

int buscarLibre(ePelicula arrayPeliculas[],int cantidad)
{
    int i;
    int retorno = -1;
    for(i=0;i<cantidad;i++)
    {
        if(arrayPeliculas[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int modificarPelicula(ePelicula arrayPeliculas[],int cantidad)
{
    system("cls");
    int retorno=-1;
    int indice;
    int id;
    int opcion;
    char opcion2;
    char auxTitulo[51];
    int auxAnio;
    char auxNacionalidad[51];
    char auxDirector[51];

    mostrarPeliculas(arrayPeliculas,cantidad);
    printf("\n\nIngrese el id de la pelicula a modificar: \n");
    fflush(stdin);
    scanf("%d",&id);

    indice = buscarPeliculaPorId(arrayPeliculas,cantidad,id);

    if(arrayPeliculas != NULL)
    {
        if(indice>=0)
        {
            do{
                system("cls");
                mostrarPeliculas(arrayPeliculas, cantidad);

                printf("\nQue campo quiere modificar?\n");
                printf("\n1_Titulo: %s"
                       "\n2_Anio: %d"
                       "\n3_Nacionalidad: %s"
                       "\n4_Director: %s"
                       "\n\nElija una opcion :",arrayPeliculas[indice].titulo,
                arrayPeliculas[indice].anio,arrayPeliculas[indice].nacionalidad,arrayPeliculas[indice].nombreDirector);
                fflush(stdin);
                scanf("%d",&opcion);
                system("cls");

                switch(opcion)
                {
                    case 1:

                        getValidString(" Ingrese nuevo titulo: "," Error, ingrese nuevamente:", auxTitulo);
                        strcpy(arrayPeliculas[indice].titulo, auxTitulo);
                        break;
                    case 2:
                        auxAnio=getValidInt(" Ingrese nuevo anio: \n"," Error, el anio no es valido.\n", 1800, 2018);
                        arrayPeliculas[indice].anio=auxAnio;
                        ;
                        break;
                    case 3:
                        getValidString(" Ingrese nueva nacionalidad: "," Error, ingrese nuevamente:", auxNacionalidad);
                        strcpy(arrayPeliculas[indice].nacionalidad, auxNacionalidad);

                        break;
                    case 4:
                        getValidString(" Ingrese nuevo director: "," Error, ingrese nuevamente:", auxDirector);
                        strcpy(arrayPeliculas[indice].nombreDirector, auxDirector);
                        break;
                    default:
                        printf("\nError: opcion no valida, elija una opcion del 1 al 4.\n");
                        system("pause");
                        system("cls");
                        break;
                }
                printf("Desea continuar? s/n \n :");
                fflush(stdin);
                scanf("%c",&opcion2);
                system("pause");
                system("cls");
            }while(opcion2=='s' || opcion2=='S');
        }
        else if(indice<0)
        {
            printf("No existe ese id");
            system("pause");
        }
        retorno=0;
    }
    return retorno;
}

int buscarPeliculaPorId(ePelicula arrayPeliculas[],int cantidad,int id)
{
    int i,retorno=-1;
    for(i=0;i<cantidad;i++)
    {
        if(arrayPeliculas[i].isEmpty == 0 && arrayPeliculas[i].id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int mostrarPeliculas(ePelicula arrayPeliculas[],int cantidad)
{
    int i;
    int retorno=-1;
    if(arrayPeliculas!=NULL)
    {
        printf("\n%5s %20s %20s %6s %20s\n","Id" ,"Titulo","Nacionalidad","Anio","Director");
        for(i=0;i<cantidad;i++)
        {
            if(arrayPeliculas[i].isEmpty == 0)
            {
                printf ("%5d %20s %20s %6d %20s\n",arrayPeliculas[i].id,arrayPeliculas[i].titulo,arrayPeliculas[i].nacionalidad,
                        arrayPeliculas[i].anio,arrayPeliculas[i].nombreDirector);
                retorno=0;
            }
        }
    }
    return retorno;
}

int borrarPelicula(ePelicula arrayPeliculas[],int cantidad)//listo
{
    system("cls");
    int id;
    int indice;
    int retorno=-1;
    mostrarPeliculas(arrayPeliculas,cantidad);
    printf("\n\nIngrese el id de la pelicula que quiere dar de baja: ");
    fflush(stdin);
    scanf("%d",&id);
    indice = buscarPeliculaPorId(arrayPeliculas,cantidad,id);
    if(indice>=0)
    {
        arrayPeliculas[indice].isEmpty = 1;
        printf ("\nLa pelicula fue dada de baja con exito.\n");
        system ("pause");
        retorno=1;
    }
    else
    {
        printf("Error!. Ese id no existe.\n");
        system ("pause");
    }
    return retorno;
}

int opcionesInformar(ePelicula arrayPeliculas[],int cantidadPeliculas, eDirector arrayDirectores[], int cantidadDirectores)
{
    int retorno=-1;
    int elijaOpcion;
    if(arrayPeliculas!=NULL && arrayDirectores!=NULL)
    {
        printf("1. Mostrar peliculas\n");
        printf("2. Mostrar directores\n");
        printf("Elija la opcion: ");
        scanf("%d",&elijaOpcion);
    switch(elijaOpcion)
    {
    case 1:
        mostrarPeliculas(arrayPeliculas, cantidadPeliculas);
        break;
    case 2:
        mostrarTodosLosDirectores(arrayDirectores, cantidadDirectores);
        break;
    default:
        printf("Opcion incorrecta!\n");
    }
    retorno=0;
    }

    return retorno;

}
