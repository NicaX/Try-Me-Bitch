#include <stdio.h>
#include <stdlib.h>
#include "peliculas.c"
#include "peliculas.h"
#include "directores.c"
#include "validaciones.h"



int main()
{
    ePelicula peliculasMain[MAX_PELICULAS];
    eDirector directoresMain[MAX_DIRECTORES];

    inicializarArray(peliculasMain,MAX_PELICULAS);
    inicializarDirectores(directoresMain,MAX_DIRECTORES);

    int opcion;
    int banderaP=0;
    int banderaD=0;
    char auxNombreDirector[51];

    do
    {
        system("cls");
        menuPrincipal();
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                if(cargarPeliculas(peliculasMain,MAX_PELICULAS)==0)
                {
                    banderaP=1;
                }
                else
                {
                    banderaP=-1;
                }
                break;
            case 2:
                if(banderaP==1)
                {
                    modificarPelicula(peliculasMain,MAX_PELICULAS);
                }
                else
                {
                    printf("\nError!! Aun no se cargo ninguna pelicula!");
                }
                break;
            case 3:
                if(banderaP==1)
                {
                    borrarPelicula(peliculasMain,MAX_PELICULAS);
                }
                else
                {
                    printf("\nError!! Aun no se cargo ninguna pelicula!");
                }
                break;
            case 4:
                if(altaDirector(directoresMain,MAX_DIRECTORES)==0)
                {
                    banderaD=1;
                }

                break;
            case 5:
                if(banderaD==1)
                {
                    removerDirector(directoresMain,MAX_DIRECTORES,auxNombreDirector);
                }
                else
                {
                    printf("Aun no se cargaron los datos de ningun director!!\n");
                }
                break;
            case 6:
                if(banderaP==1 && banderaD==1)
                {
                    opcionesInformar(peliculasMain, MAX_PELICULAS,directoresMain, MAX_DIRECTORES);
                }
                else
                {
                    printf("Falta cargar algun dato (pelicula/director)\n");
                }
                break;
            case 7:
                printf("Saliendo....Que tenga buen dia!!!");
                break;
            default:
                break;
        }
        system("pause");
        system("cls");

    }
    while(opcion!=7);





    return 0;
}
