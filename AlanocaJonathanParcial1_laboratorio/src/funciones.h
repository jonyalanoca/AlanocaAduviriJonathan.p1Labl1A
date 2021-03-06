/*
 * funciones.h
 *
 *  Created on: 27 oct. 2021
 *      Author: Jony
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
typedef struct{
	int id;
	char nombre[20];
	char sexo;
}eCliente;
typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;
typedef struct{
	int id;
	char descripcion[20];
}eMarca;
typedef struct{
	int id;
	char nombreColor[20];
}eColor;

typedef struct{
	int id;
	int idCliente;
	int idMarca;
	int idColor;
	char caja;
	int isEmpty;
}eAuto;
typedef struct{
	int id;
	char descripcion[20];
	float precio;
}eServicio;
typedef struct{
	int id;
	int patente;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

#endif /* FUNCIONES_H_ */
int menu();
int subMenu();
/// @fn int iniciarAutos(eAuto[], int)
/// @brief  pone los isEmpty en 1
///
/// @param autos
/// @param lenAuto
/// @return 0 si algo salio mal, 1 si todo salio bien
int iniciarAutos(eAuto autos[],int lenAuto);
/// @fn int iniciarTrabajos(eTrabajo[], int)
/// @brief pone los isEmpty en 1
///
/// @param trabajos
/// @param lenTrabajo
/// @return 0 si algo salio mal, 1 si todo salio bien
int iniciarTrabajos(eTrabajo trabajos[],int lenTrabajo);

/// @fn int altaAuto(eAuto[], int, int*, eMarca[], int, eColor[])
/// @brief funcion para dar  de alta los autos, pone le id automatico, pide y carga la marca, el color y tipo de caja
///
/// @param autos
/// @param lenAuto
/// @param idAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @return 0 si algo salio mal, 1 si todo salio bien
int altaAuto(eAuto autos[],int lenAuto, int* idAuto,eMarca marcas[],int lenMarcaColor, eColor colores[], eCliente clientes[],int lenCliente);
/// @fn int modificarAuto(eAuto[], int, eMarca[], int, eColor[])
/// @brief permite modificar los valores previamente carados de autos
///
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @return 0 si algo salio mal, 1 si todo salio bien
int modificarAuto(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eCliente clientes[], int lenCliente);

/// @fn int borrarAuto(eAuto[], int, eMarca[], int, eColor[])
/// @brief permite borrar logicamente un registro de  auto
///
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @return 0 si algo salio mal, 1 si todo salio bien
int borrarAuto(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eCliente clientes[],int lenCliente);

/// @fn int altaTrabajo(eTrabajo[], int, int*, eAuto[], int, eMarca[], int, eColor[], eServicio[], int)
/// @brief permite hacer un registro de un trabajo ralizado
///
/// @param trabajos
/// @param lenTrabajo
/// @param idTrabajo
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @param servicios
/// @param lenServicio
/// @return 0 si algo salio mal, 1 si todo salio bien
int altaTrabajo(eTrabajo trabajos[],int lenTrabajo, int* idTrabajo,eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eServicio servicios[],int lenServicio, eCliente clientes[],int lenCliente );
/// @fn int buscarLibreAuto(eAuto[], int)
/// @brief busca un isEmpty en 1 dentro de la estructura
///
/// @param autos
/// @param lenAuto
/// @return -1 si no existe lugar o el index del lugar disponible

int buscarLibreAuto(eAuto autos[],int lenAuto);
/// @fn int buscarLibreTrabajo(eTrabajo[], int)
/// @brief busca un isEmpty en 1 dentro de la estructura
///
/// @param trabajos
/// @param lenTrabajo
/// @return -1 si no existe lugar o el index del lugar disponible
int buscarLibreTrabajo(eTrabajo trabajos[],int lenTrabajo);
/// @fn int buscarAuto(eAuto[], int, int)
/// @brief busca si existe el id en la estructura autos
///
/// @param autos
/// @param lenAuto
/// @param idAuto
/// @return 1 si existe, 0 no existe
int buscarAuto(eAuto autos[],int lenAuto,int idAuto);
/// @fn int buscarIdAuto(eAuto[], int, int)
/// @brief busca el index del id que le pasamos por parametro
///
/// @param autos
/// @param lenAuto
/// @param idAuto
/// @return -1 no existe o el numero de index
int buscarIdAuto(eAuto autos[],int lenAuto,int idAuto);
/// @fn int buscarIdColor(int, eColor[], int)
/// @brief busca el index del id que le pasamos por parametro
///
/// @param id
/// @param colores
/// @param lenColor
/// @return -1 no existe o el numero de index
int buscarIdColor(int id,eColor colores[],int lenColor);
/// @fn int buscarIdMarca(int, eMarca[], int)
/// @brief busca el index del id que le pasamos por parametro
///
/// @param id
/// @param marcas
/// @param lenMarca
/// @return -1 no existe o el numero de index
int buscarIdMarca(int id,eMarca marcas[],int lenMarca);
/// @fn int buscarIdServicio(int, eServicio[], int)
/// @brief busca el index del id que le pasamos por parametro
///
/// @param id
/// @param servicios
/// @param lenServicio
/// @return -1 no existe o el numero de index
int buscarIdServicio(int id,eServicio servicios[],int lenServicio);


/// @fn int ordenarAutos(eAuto[], int, eMarca[], int)
/// @brief odena el la estructura autos primero po marca luego por patente
///
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @return 0 si algo salio mal, 1 si todo salio bien
int ordenarAutos(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor);
/// @fn void mostrarAuto(eAuto, char[], char[])
/// @brief muestra los valores de un registro
///
/// @param autos
/// @param marca
/// @param color
void mostrarAuto(eAuto autos, char marca[], char color[], char cliente[]);

/// @fn int mostrarAutos(eAuto[], int, eMarca[], int, eColor[])
/// @brief  muestra los valores de un conjuto de registro
///
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @return 0 si algo salio mal, 1 si todo salio bien
int mostrarAutos(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eCliente clientes[], int lenCliente);
/// @fn void mostrarTrabajo(eTrabajo, int, char[])
/// @brief  muestra los valores de un registro
///
/// @param trabajos
/// @param lenTrabajo
/// @param servicio
void mostrarTrabajo(eTrabajo trabajos,int lenTrabajo, char servicio[]);
/// @fn int mostrarTrabajos(eTrabajo[], int, eServicio[], int)
/// @brief muestra los valores de un conjuto de registro
///
/// @param trabajos
/// @param lenTrabajo
/// @param servicios
/// @param lenServicio
/// @return 0 si algo salio mal, 1 si todo salio bien
int mostrarTrabajos(eTrabajo trabajos[],int lenTrabajo, eServicio servicios[],int lenServicio );
/// @fn void mostrarServicio(eServicio)
/// @brief muestra los valores de un registro
///
/// @param servicios
void mostrarServicio(eServicio servicios);
/// @fn int mostrarServicios(eServicio[], int)
/// @brief muestra los valores de un conjuto de registro
///
/// @param servicios
/// @param lenServicio
/// @return  0 si algo salio mal, 1 si todo salio bien
int mostrarServicios(eServicio servicios[],int lenServicio);
/// @fn void mostrarMarca(eMarca)
/// @brief muestra los valores de un conjuto de registro
///
/// @param marcas
void mostrarMarca(eMarca marcas);
/// @fn int mostrarMarcas(eMarca[], int)
/// @brief muestra los valores de un conjuto de registro
///
/// @param marcas
/// @param lenMarca
/// @return 0 si algo salio mal, 1 si todo salio bien
int mostrarMarcas(eMarca marcas[],int lenMarca);
/// @fn void mostrarColor(eColor)
/// @brief muestra los valores de un  registro
///
/// @param colores
void mostrarColor(eColor colores);
/// @fn int mostrarColores(eColor[], int)
/// @brief muestra los valores de un conjuto de registro
///
/// @param colores
/// @param lenColor
/// @return 0 si algo salio mal, 1 si todo salio bien
int mostrarColores(eColor colores[],int lenColor);

int buscarIdCliente(int id, eCliente clientes[], int lenCliente);


void mostrarCliente(eCliente clientes);

int mostrarClientes(eCliente clientes[],int lenCliente);
