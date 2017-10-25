#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define ALPHA_ROMERO 150
#define FERRARI 175
#define AUDI 200
#define OTRO 250

typedef struct{

    int idDuenio;
    char nombreApellido[200];
    int tarjetaDeCredito;
    char direccion[200];
    int estado;

}eDuenio;

typedef struct{

    int idDuenio;
    char patente[200];
    int marca;
    char marcaString[200];
    int horaEntrada;
    int horaSalida;
    int estadoAuto;

}eAuto;

/** \brief Limpia pantalla.
 */
void fLimpiar();
/** \brief Pide el ingreso y verifica que sea un entero.
 *
 * \param Mensaje a mostrar.
 * \param Mensaje a mostrar si hay un error.
 * \param Numero minimo que se puede ingresar.
 * \param Numero maximo que se puede ingresar.
 * \param Largo maximo que puede llegar a tener el entero ingresado previamente.
 * \return Numero ingresado.
 *
 */
int getInt(char mensajeamostrar[],char erroramostrar[],int minimo,int maximo,int largoentero);
/** \brief Verifica que lo que se ingrese sea un numero.
 *
 * \param Dato a validar.
 * \param Largo del dato a validar.
 * \return Devuelve 1 si el dato es un numero, y 0 si no lo es.
 *
 */
int validaNumero(char datoAValidar[],int largoDato);
/** \brief Pide el ingreso y verfica sea de tipo char (sin numeros).
 *
 * \param Ingreso (dato a validar).
 * \param Mensaje a mostrar.
 * \param Mensaje a mostrar si hay un error.
 * \param Largo maximo que puede llegar a tener el char (sin numeros) ingresado previamente.
 *
 */
void getChar(char ingreso[],char mensajeamostrar[],char erroramostrar[],int largoChar);
/** \brief Verifica que lo que se ingrese sea una letra.
 *
 * \param Dato a validar
 * \param Largo del dato a validar.
 * \return Devuelve 1 si el dato es una letra, y 0 si no lo es.
 *
 */
int validaLetra(char datoAValidar[],int largoDato);
/** \brief Inicializa los estados de la estructura Duenio.
 *
 * \param Array de la estructura a pasar.
 * \param Tamaño del Array de la estructura.
 *
 */
void inicializarDuenio(eDuenio lista[], int tam);
/** \brief Inicializa los estados de la estructura Auto.
 *
 * \param Array de la estructura a pasar.
 * \param Tamaño del Array de la estructura.
 *
 */
void inicializarAuto(eAuto listaAuto[], int tam);
/** \brief Obtiene el primer indice libre del vector (array).
 *
 * \param lista (Array que se pasa como parametro).
 * \return Devuelve el indice.
 * \return  Devuelve -1 si no hay mas espacio.
 *
 */
int buscarEspacioLibreDuenio(eDuenio lista[], int tam);
/** \brief Obtiene el primer indice libre del vector (array).
 *
 * \param listaAuto (Array que se pasa como parametro).
 * \return Devuelve el indice.
 * \return  Devuelve -1 si no hay mas espacio.
 *
 */
 int buscarEspacioLibreAuto(eAuto listaAuto[], int tam);
 /** \brief Busca el ID en el array de la estructura Duenio.
  *
  * \param ID a buscar en el array de la estructura.
  * \param lista (Array que se pasa como parametro).
  * \param Tamaño del array (lista).
  * \return Devuelve -1 si no encuentra el ID y devuelve el indice si lo encuentra (!=-1).
  *
  */
 int buscarID(int id, eDuenio lista[], int tam);
 /** \brief Busca la Patente del auto en el array de la estructura Auto.
  *
  * \param Patente a buscar en el array de la estructura.
  * \param listaAuto (Array de la estructura que se pasa como parametro).
  * \param Tamaño del array (listaAuto).
  * \return Devuelve -1 si no encuentra la Patente y devuelve el indice si lo encuentra (!=-1).
  *
  */
int buscarPatenteAuto(char patente[], eAuto listaAuto[], int tam);
  /** \brief Da de alta al dueño.
  *
  * \param Array de la estructura duenio.
  * \param Tamaño del array de la estructura duenio.
  *
  */
 void altaDuenio(eDuenio lista[],int tam);
  /** \brief Modifica la tarjeta de credito del dueño.
  *
  * \param Array de la estructura duenio.
  * \param Tamaño del array de la estructura duenio.
  *
  */
 void modifDuenio(eDuenio lista[],int tam);
  /** \brief Da de baja al auto.
  *
  * \param Array de la estructura auto.
  * \param Tamaño del array de la estructura auto.
  * \param Array de la estructura duenio.
  * \param Tamaño del array de la estructura duenio.
  *
  */
 void bajaAuto(eAuto listaAuto[], int tamA, eDuenio lista[], int tamD);
  /** \brief Informa datos de las estructuras duenio y auto.
  *
  * \param Array de la estructura duenio.
  * \param Tamaño del array de la estructura duenio.
  * \param Array de la estructura auto.
  * \param Tamaño del array de la estructura auto.
  *
  */
 void informar(eDuenio lista[], int tamD, eAuto listaAuto[], int tamA);
 /** \brief Ordena las patentes y el horario de entrada.
  *
  * \param Array de la estructura auto.
  * \param Tamaño del array de la estructura auto.
  *
  */
 void ordenar(eAuto listaAuto[], int tamA);
#endif // FUNCIONES_H_INCLUDED
