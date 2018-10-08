#ifndef DIRECTORES_H_INCLUDED
#define DIRECTORES_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int idDirector;
    char nombre[51];
    eFecha nacimiento;
    char paisOrigen[51];
    int isEmpty;

}eDirector;


/** \brief Inicializa el array de directores poniendolos como vacios
 *
 * \param arrayPeliculas[] eDirector   Array de directores
 * \param cantidad int  Cantidad de directores del array
 * \return void
 *
 */
void inicializarDirectores(eDirector arrayDirectores[],int cantidad);


int buscarDirectorLibre(eDirector arrayDirectores[],int cantidad);


int buscarDirectorPorNombre(eDirector arrayDirectores[], int cantidad, char nombre[]);

int altaDirector(eDirector arrayDirectores[], int cantidad);

int removerDirector(eDirector arrayDirectores[], int cantidad, char nombre[]);

int mostrarUnDirector(eDirector arrayDirectores[], int indice);

int mostrarTodosLosDirectores(eDirector arrayDirectores[], int cantidad);

void directoresHardcode(eDirector arrayDirectores[], eFecha fecha[]);
#endif // DIRECTORES_H_INCLUDED
