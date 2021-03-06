/*
 * validaciones.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Jony
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */
/// @fn char confirmarSalir()
/// @brief  Confirma si se desea salir del programa o no.Pide un char y convierte en minuscula
///
/// @return el caracter que el usuario ingresa
char confirmarSalir();
/// @fn int capitalizar(char[])
/// @brief recibe una cadena de string y pone el primer caracter en mayuscula luego el resto en minuscula
///
/// @param varString- cadena a convertir
/// @return devuelve 1 si todo salio bien, 0 si algo salio mal (validacion del puntero)
int capitalizar(char varString[]);
/// @fn int validarCargarStr(char[], char[], int)
/// @brief 	esta fucion pide al usuario ingresar una cadena de caracteres, luego evalua si se trata de de solamente
/// 		texto, si se ingresa un caracater no valido vuelve a pedir una nueva cadena. una vez validado se carga el valor
/// 		del mismo a al array pasado por parametro. Ademas no deja que desborde nuestra variable.
///
/// @param mensaje: este mensaje se muestra para pedir lo que querramos que el usuario ingrese
/// @param string:	aca se guarda la cadena una vez que este validado.
/// @param lenString: parametro que usamos para evitar el desbordamiento.
/// @return devuelve: 0 si algo la validacion de puntero sale mal, 1 si todo salio bin, 2 si se cargo pero hubo un desbordamiento.
int validarCargarStr(char mensaje[],char string[],int lenString);
/// @fn int validarCargarEntero(char[], int*)
/// @brief 	pide numeros enteros, valida que se traten solamente de numeros, evita que se exceda el maximo pormitido por (int)
/// 		al final una vez validado guarda el valor numerico dentro de nustra variable pasado por paramentro (puntero)
///
/// @param mensaje: mesaje para especificar que dato queremos recibir
/// @param varNumero: (puntero) aca guardamos los numeros luego de validar
/// @return 0 sale mal la validacion paramentros, 1 todo salio bien
int validarCargarEntero(char mensaje[], int* varNumero);
/// @fn int validarCargarDecimal(char[], float*)
/// @brief pide ingresar un numero flotante hasta que un ingrese un flotante, admite numeros y un punto. Una vez validado
/// 		carga el valor del flotante en nuestro puntero float
///
/// @param mensaje: mensaje para especificar que dato queremos recibir
/// @param varNumero (puntero) aca guardamos los numeros (flotante) luego de validar
/// @return 0 sale mal la validacion paramentros, 1 todo salio bien
int validarCargarDecimal(char mensaje[], float* varNumero);
/// @fn int validarCargarLetra(char[], char*)
/// @brief nos permite cargar y validar un char (un solo carcter), una vez validado carga el valor a nustro puntero char
///
/// @param mensaje: mensaje para especificar que dato queremos recibir
/// @param varLetra: se guarda en este puntero una vez validado, si hay mas de un caracter se guarda solo el primero.
/// @return: 0: salio mal la validacion de paramentros, 1 no hubo ningun problema, 2  informa que se tomo solo el primer caracter ya que se ingreso mas de un caracter.
int validarCargarLetra(char mensaje[],char* varLetra);
/// @fn int validarDosChar(char[], char*, char, char)
/// @brief pide un char y compara si son igual  a los dos parametros(letra), vuelve a pedir un char si se carga un valor distinto
/// 		al final guardamos el valor validado en nuestra variable principal
///
/// @param mensaje: mensaje para especificar que dato queremos recibir
/// @param varChar (puntero) char, variable donde guardamos la letra
/// @param letra1: valor a comparar
/// @param letra2: valor a comparar
/// @return retorna 1 si todo sale bien, 0 si la validacion de parametros sale mal
int validarDosChar(char mensaje[],char* varChar, char letra1, char letra2);
/// @fn int validarCargarFecha(char[], int*, int*, int*)
/// @brief permite perdir una fecha con un determiando estilo, valida que se hayan usado los caracteres correstos y guarda el dia
/// 		mes y anio en distintas variables que le pasamos por parametro.
///
/// @param mensaje: mensaje para especificar que dato queremos recibir
/// @param dia (putero) se guardara el dia
/// @param mes (putero) se guardara el mes
/// @param anio (putero) se guardara el anio
/// @return 0 si algo salio mal, 1 si todo salio bien
int validarCargarFecha(char mensaje[], int* dia, int* mes, int* anio);
