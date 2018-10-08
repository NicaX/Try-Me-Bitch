#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id;
    char titulo[51];
    int anio;
    char nacionalidad[51];
    char nombreDirector[51]; //Unir con los directores
    int isEmpty;
}ePelicula;

/** \brief Inicializa el array de empleados poniendolos como vacios
 *
 * \param arrayPeliculas[] ePelicula   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void inicializarArray(ePelicula arrayPeliculas[],int cantidad);

/** \brief una funcion que muestra el menú principal
 *
 * \return void
 *
 */
void menuPrincipal();

/** \brief Da de alta un empleado si encuentra espacio
 *
 * \param arrayPeliculas[] ePelicula   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return int  -1 en caso de error y 0 en caso de exito
 *
 */
int cargarPeliculas(ePelicula arrayPeliculas[],int cantidad, eDirector arrayDirectores[], int cantidadDirectores);

/** \brief Toma los datos de un empleado para darlo de alta
 *
 * \param arrayPeliculas[] ePelicula   Array de empleados
 * \param vacio int Indice del primer espacio vacio del array
 * \param cantidad int  Cantidad de empleados del array
 * \return int  Devuelve -1 en caso de error y 0 si se logra completar
 *
 */
int cargarUnaPelicula(ePelicula arrayPeliculas[],int vacio,int cantidad, eDirector arrayDirectores[],int cantidadDirectores);

/** \brief Busca el primer espacio vacio en el array
 *
 * \param arrayPeliculas[] ePelicula   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return int Devuelve el indice del espacio vacio
 *
 */
int buscarLibre(ePelicula arrayPeliculas[],int cantidad);

/** \brief  Busca empleados por id y permite modificar el resto de los parametros de la estructura
 *
 * \param arrayPeliculas[] ePelicula   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
int modificarPelicula(ePelicula arrayPeliculas[],int cantidad);

/** \brief  Busca el indice de un empleado mediante su id
 *
 * \param arrayPeliculas[] ePelicula   Array de empleados
 * \param cantidad int  Cantiadad de empleados del array
 * \param id int    Id del empleado a buscar
 * \return int  Retorna -1 en caso de error y el indice correspondiente al id en caso exitoso
 *
 */
int buscarPeliculaPorId(ePelicula arrayPeliculas[],int cantidad,int id);

/** \brief  Toma el array de empleados y lo imprime por pantalla
 *
 * \param arrayPeliculas[] ePelicula   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
int mostrarPeliculas(ePelicula arrayPeliculas[],int cantidad);

/** \brief  Muestra la lista de empleados y mediande el id se permite la baja
 *
 * \param arrayPeliculas[] ePelicula   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return int
 *
 */
int borrarPelicula(ePelicula arrayPeliculas[],int cantidad);

void pelisHardcode(ePelicula arrayPeliculas[]);

int opcionesInformar(ePelicula arrayPeliculas[],int cantidadPeliculas, int flagP, eDirector arrayDirectores[], int cantidadDirectores, int flagD);

void mostrarPeliculasConDirector(ePelicula arrayPeliculas[], int cantidadPeliculas, eDirector arrayDirectores[], int cantidadDirectores);


#endif // PELICULAS_H_INCLUDED
