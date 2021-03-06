/*
 * informes.h
 *
 *  Created on: 27 oct. 2021
 *      Author: Jony
 */

#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */
/// @fn int informes(eTrabajo[], int, eAuto[], int, eMarca[], int, eColor[], eServicio[], int, eCliente[], int)
/// @brief Esta funcion se encarga de dar los informes, contiene un submenu y redirecciona  a otras nuevas funciones
///
/// @param trabajos
/// @param lenTrabajo
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @param servicios
/// @param lenServicio
/// @param clientes
/// @param lenCliente
/// @return 0 is algo salio mal, 1 si todo salio bien
int informes(eTrabajo trabajos[],int lenTrabajo,eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eServicio servicios[],int lenServicio, eCliente clientes[], int lenCliente);
/// @fn int menuInformes()
/// @brief Muestra un submenu para dar informes
///
/// @return
int menuInformes();
/// @fn int mostrarAutoDeUnColor(eAuto[], int, eMarca[], int, eColor[], eCliente[], int)
/// @brief permite seleccionar el id de un color y mostrar solo los autos que tiene ese color
///
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @param clientes
/// @param lenCliente
/// @return 0 is algo salio mal, 1 si todo salio bien
int mostrarAutoDeUnColor(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eCliente clientes[], int lenCliente);
/// @fn int mostrarAutoDeUnaMarca(eAuto[], int, eMarca[], int, eColor[], eCliente[], int)
/// @brief permite seleccionar el id de una marca y mostrar solo los autos de esa marca
///
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @param clientes
/// @param lenCliente
/// @return 0 is algo salio mal, 1 si todo salio bien
int mostrarAutoDeUnaMarca(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[],eCliente clientes[],int lenCliente);
/// @fn int cantidadAutosPorColorYMarca(eAuto[], int, eMarca[], int, eColor[])
/// @brief pide al usuario que indiquen el color y la marca, para luego informar la cantidad de autos que hay con esas caracteristicas
///
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @return 0 is algo salio mal, 1 si todo salio bien
int cantidadAutosPorColorYMarca(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[]);
/// @fn int marcaMasElegida(eAuto[], int, eMarca[], int, eColor[])
/// @brief hace una comparacion que el listado de autos y muetra cual es el la marca que mas se elige
///
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @return 0 is algo salio mal, 1 si todo salio bien
int marcaMasElegida(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[]);
/// @fn int mostrarTrabajosDeUnAuto(eTrabajo[], int, eAuto[], int, eMarca[], int, eColor[], eServicio[], int, eCliente[], int)
/// @brief pide al usuario que ingrese el id de un trabajo y solo muetra autos que hicieron ese trabajo
///
/// @param trabajos
/// @param lenTrabajo
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @param servicios
/// @param lenServicio
/// @param clientes
/// @param lenCliente
/// @return 0 is algo salio mal, 1 si todo salio bien
int mostrarTrabajosDeUnAuto(eTrabajo trabajos[],int lenTrabajo,eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eServicio servicios[],int lenServicio, eCliente clientes[], int lenCliente);
/// @fn int mostrarSumaTrabajosDeUnAuto(eTrabajo[], int, eAuto[], int, eMarca[], int, eColor[], eServicio[], int, eCliente[], int)
/// @brief  permite seleccionar un auto, recolecta la informacion que que trabajos y servicios se hizo en el para informar la cantidad de dinero gato.
///
/// @param trabajos
/// @param lenTrabajo
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @param servicios
/// @param lenServicio
/// @param clientes
/// @param lenCliente
/// @return 0 is algo salio mal, 1 si todo salio bien
int mostrarSumaTrabajosDeUnAuto(eTrabajo trabajos[],int lenTrabajo,eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eServicio servicios[],int lenServicio, eCliente clientes[],int lenCliente);
/// @fn int mostrarAutosQueRealizaronServicio(eTrabajo[], int, eAuto[], int, eMarca[], int, eColor[], eServicio[], int)
/// @brief  permite seleccionar un servicio  por id y solo muestra los autos que se ralizaron ese servicio
///
/// @param trabajos
/// @param lenTrabajo
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @param servicios
/// @param lenServicio
/// @return 0 is algo salio mal, 1 si todo salio bien
int mostrarAutosQueRealizaronServicio(eTrabajo trabajos[],int lenTrabajo,eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eServicio servicios[],int lenServicio);
/// @fn int promedioAutosManualAuto(eAuto[], int)
/// @brief acumula la catidad de autos que hay con caja manual y con caja automatica, luego realiza un promedio de cada uno y lo informa.
///
/// @param autos
/// @param lenAuto
/// @return 0 is algo salio mal, 1 si todo salio bien
int promedioAutosManualAuto(eAuto autos[],int lenAuto);
/// @fn int mostrarPorFecha(eTrabajo[], int, eAuto[], int, eMarca[], int, eColor[], eServicio[], int, eCliente[], int)
/// @brief el usuario ingrese una fecha valida y solo muestra los trabajos que se realizaron es dicha fecha.
///
/// @param trabajos
/// @param lenTrabajo
/// @param autos
/// @param lenAuto
/// @param marcas
/// @param lenMarcaColor
/// @param colores
/// @param servicios
/// @param lenServicio
/// @param clientes
/// @param lenCliente
/// @return 0 is algo salio mal, 1 si todo salio bien
int mostrarPorFecha(eTrabajo trabajos[],int lenTrabajo,eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eServicio servicios[],int lenServicio, eCliente clientes[], int lenCliente);

