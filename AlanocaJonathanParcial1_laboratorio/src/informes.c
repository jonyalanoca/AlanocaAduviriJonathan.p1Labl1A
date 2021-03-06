/*
 * informes.c
 *
 *  Created on: 27 oct. 2021
 *      Author: Jony
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "funciones.h"
#include "hardC.h"
#include "informes.h"

int informes(eTrabajo trabajos[],int lenTrabajo,eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eServicio servicios[],int lenServicio, eCliente clientes[], int lenCliente){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0 && marcas!=NULL && colores!=NULL &&lenMarcaColor>0){
		printf("-----------------INFORMES--------------\n");
		switch(menuInformes()){
			case 1:
				if(!mostrarAutoDeUnColor(autos, lenAuto, marcas, lenMarcaColor,colores, clientes, lenCliente)){
					printf("Error. No se puede mostrar\n");
				}
				break;
			case 2:
				if(!mostrarAutoDeUnaMarca(autos, lenAuto, marcas, lenMarcaColor,colores,clientes, lenCliente)){
					printf("Error. No se puede mostrar\n");
				}
				break;
			case 3:
				if(!cantidadAutosPorColorYMarca(autos, lenAuto, marcas, lenMarcaColor,colores)){
				printf("Error. No se puede mostrar\n");
				}
				break;
			case 4:
				if(!marcaMasElegida(autos, lenAuto, marcas, lenMarcaColor,colores)){
				printf("Error. No se puede mostrar\n");
				}
				break;
			case 5:
				if(!mostrarTrabajosDeUnAuto(trabajos, lenTrabajo,autos, lenAuto,marcas,lenMarcaColor, colores, servicios, lenServicio,clientes, lenCliente)){
				printf("Error. No se puede mostrar\n");
				}
				break;
			case 6:
				if(!mostrarSumaTrabajosDeUnAuto(trabajos, lenTrabajo,autos, lenAuto,marcas,lenMarcaColor, colores, servicios, lenServicio, clientes, lenCliente)){
				printf("Error. No se puede mostrar\n");
				}
				break;
			case 7:
				if(!mostrarAutosQueRealizaronServicio(trabajos, lenTrabajo,autos, lenAuto,marcas,lenMarcaColor, colores, servicios, lenServicio)){
				printf("Error. No se puede mostrar\n");
				}
				break;
			case 8:
				if(!promedioAutosManualAuto(autos, lenAuto)){
				printf("Error. No se puede mostrar\n");
				}
				break;
			case 9:
				if(!mostrarPorFecha(trabajos, lenTrabajo,autos, lenAuto,marcas,lenMarcaColor, colores, servicios, lenServicio, clientes, lenCliente)){
				printf("Error. No se puede mostrar\n");
				}
				break;
			default:
				printf("Ingreso una opcion incorecta. Porfavor vuelva a intentarlo.\n");
				break;
		}
	}
	return todoOk;

}
int menuInformes(){
	int opcion;
	printf("\t=-=-=-=-MENU INFOMES-=-=-=-=-=\n");
	printf("\t_______________Menu_________________\n\n");
	printf("\t1-MOSTRAR DE UN COLOR SELECCIONADO\n");
	printf("\t2-MOSTRAR DE UNA MARCA SELECCIONADA\n");
	printf("\t3-CANTIDAD DE AUTOS POR UNA MARCA Y COLOR SELECCIONADA\n");
	printf("\t4-LA MARCA MAS ELEGIDA\n");
	printf("\t5-LISTA DE SERVICIOS REALIZADOS A UN AUTO\n");
	printf("\t6-LISTA TRABAJOS REALIZADOS EN UN COCHE \n");
	printf("\t7-LISTA DE AUTOS QUE REALIZARON UN SERVICIO  \n");
	printf("\t8-PRMEDIO DE AUTOS CON CAJA MANUAL Y AUTOMATICA  \n");
	printf("\t9-LISTAR TRABAJOS POR FECHA\n");
	printf("\t____________________________________\n\n");
	printf("\tIngrese una opcion: ");
	fflush(stdin);
	scanf("%d",&opcion);
	fflush(stdin);
	system("cls");
	return opcion;
}

int mostrarAutoDeUnColor(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eCliente clientes[], int lenCliente){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0 && marcas!=NULL && colores!=NULL &&lenMarcaColor>0){
		int auxIdColor;
		mostrarColores(colores,lenMarcaColor);
		do{
			validarCargarEntero("Ingrese el id del color", &auxIdColor);
		}while(buscarIdColor(auxIdColor, colores, lenMarcaColor)==-1);
		printf("--------Lista de Autos--------\n\n");
		printf("ID	CLIENTE	   MARCA	  COLOR	   T-CAJA\n");
		for(int i=0;i<lenAuto;+i++){
			if(autos[i].isEmpty==0 && auxIdColor==autos[i].idColor){
				mostrarAuto(autos[i],
					marcas[buscarIdMarca(autos[i].idMarca,marcas,lenMarcaColor)].descripcion
					,colores[buscarIdColor(autos[i].idColor,colores,lenMarcaColor)].nombreColor
					,clientes[buscarIdCliente(autos[i].idCliente,clientes,lenCliente)].nombre

				);
			}

		}
		todoOk=1;

	}
	return todoOk;
}

int mostrarAutoDeUnaMarca(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eCliente clientes[],int lenCliente){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0 && marcas!=NULL && colores!=NULL &&lenMarcaColor>0){
		int auxIdMarca;
		mostrarMarcas(marcas, lenMarcaColor);
		do{
			validarCargarEntero("Ingrese el id de la marca", &auxIdMarca);
		}while(buscarIdMarca(auxIdMarca, marcas, lenMarcaColor)==-1);
		printf("--------Lista de Autos--------\n\n");
		printf("ID	CLIENTE	MARCA	  COLOR	   T-CAJA\n");
		for(int i=0;i<lenAuto;+i++){
			if(autos[i].isEmpty==0 && auxIdMarca==autos[i].idMarca){
				mostrarAuto(autos[i],
					marcas[buscarIdMarca(autos[i].idMarca,marcas,lenMarcaColor)].descripcion
					,colores[buscarIdColor(autos[i].idColor,colores,lenMarcaColor)].nombreColor
					,clientes[buscarIdCliente(autos[i].idCliente,clientes,lenCliente)].nombre
				);
			}

		}
		todoOk=1;

	}
	return todoOk;
}
int cantidadAutosPorColorYMarca(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[]){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0 && marcas!=NULL && colores!=NULL &&lenMarcaColor>0){
		int auxIdMarca;
		int auxIdColor;
		int cantidad=0;
		mostrarMarcas(marcas, lenMarcaColor);
		do{
			validarCargarEntero("Ingrese el id de la marca", &auxIdMarca);
		}while(buscarIdMarca(auxIdMarca, marcas, lenMarcaColor)==-1);
		mostrarColores(colores,lenMarcaColor);
		do{
			validarCargarEntero("Ingrese el id del color", &auxIdColor);
		}while(buscarIdColor(auxIdColor, colores, lenMarcaColor)==-1);

		for(int i=0;i<lenAuto;+i++){
			if(autos[i].isEmpty==0 && auxIdMarca==autos[i].idMarca && auxIdColor==autos[i].idColor){
				cantidad++;
			}
		}
		printf("La cantidad de autos que cumplen la condicion es: %d\n", cantidad);
		todoOk=1;

	}
	return todoOk;
}

int marcaMasElegida(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[]){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0 && marcas!=NULL && colores!=NULL &&lenMarcaColor>0){
		int maxMarcas[5]={0,0,0,0,0};
		int flag=0;
		int maximo;
		printf("--------MARCAS MAS USADAS--------\n\n");

		for(int i=0;i<lenAuto;+i++){
			if(autos[i].isEmpty==0){
				maxMarcas[buscarIdMarca(autos[i].idMarca, marcas, lenMarcaColor)]++;
			}
		}
		for(int i=0;i<5;+i++){
			 if(!flag){
				 flag=1;
				 maximo=maxMarcas[i];
			 }
			 else if(maxMarcas[i]>maximo){
				 maximo=maxMarcas[i];
			 }
		}
		printf("La marcas mas usadas son: ");
		for(int i=0;i<5;+i++){
			if(maximo==maxMarcas[i]){
				printf("%s ", marcas[i].descripcion);
			}
		}

		todoOk=1;

	}
	return todoOk;
}
int mostrarTrabajosDeUnAuto(eTrabajo trabajos[],int lenTrabajo,eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eServicio servicios[],int lenServicio, eCliente clientes[], int lenCliente){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0 && marcas!=NULL && colores!=NULL &&lenMarcaColor>0){
		int auxIdAuto;
		mostrarAutos(autos, lenAuto,marcas,lenMarcaColor, colores, clientes,lenCliente);
		do{
			validarCargarEntero("Ingrese el id de la marca", &auxIdAuto);
		}while(buscarIdAuto(autos, lenAuto, auxIdAuto)==-1);

		printf("--------TRABAJOS HECHOS A UN AUTO--------\n\n");
		printf("ID	PATENTE	  SERVICIO	FECHA\n");
		for(int i=0;i<lenTrabajo;i++){
			if(trabajos[i].isEmpty==0 && trabajos[i].patente==auxIdAuto){
			mostrarTrabajo(
					trabajos[i],
					lenTrabajo,
					servicios[buscarIdServicio(trabajos[i].idServicio, servicios, lenServicio)].descripcion
					);
			}
		}
		todoOk=1;
	}
	return todoOk;
}
int mostrarSumaTrabajosDeUnAuto(eTrabajo trabajos[],int lenTrabajo,eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eServicio servicios[],int lenServicio,eCliente clientes[], int lenCliente){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0 && marcas!=NULL && colores!=NULL &&lenMarcaColor>0){
		int auxIdAuto;
		float suma=0;
		mostrarAutos(autos, lenAuto,marcas,lenMarcaColor, colores,clientes, lenCliente);
		do{
			validarCargarEntero("Ingrese el id de la marca", &auxIdAuto);
		}while(buscarIdAuto(autos, lenAuto, auxIdAuto)==-1);

		printf("--------TRABAJOS HECHOS A UN AUTO--------\n\n");
		for(int i=0;i<lenTrabajo;i++){
			if(trabajos[i].isEmpty==0 && trabajos[i].patente==auxIdAuto){
				suma+=servicios[buscarIdServicio(trabajos[i].idServicio,servicios,lenServicio)].precio;
			}
		}
		printf("La suma de los trabajos realizados en ese choche es: %.2f\n",suma );
		todoOk=1;
	}
	return todoOk;
}

int mostrarAutosQueRealizaronServicio(eTrabajo trabajos[],int lenTrabajo,eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eServicio servicios[],int lenServicio){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0 && marcas!=NULL && colores!=NULL &&lenMarcaColor>0){
		int auxIdServicio;
		mostrarServicios(servicios,lenServicio);
		do{
			validarCargarEntero("Ingrese el id del servicio", &auxIdServicio);
		}while(buscarIdServicio(auxIdServicio, servicios, lenServicio)==-1);

		printf("--------TRABAJOS HECHOS A UN AUTO--------\n\n");
		printf("ID	PATENTE	  SERVICIO	FECHA\n");
		for(int i=0;i<lenTrabajo;i++){
			if(trabajos[i].isEmpty==0 && trabajos[i].idServicio==auxIdServicio){
			mostrarTrabajo(
					trabajos[i],
					lenTrabajo,
					servicios[buscarIdServicio(trabajos[i].idServicio, servicios, lenServicio)].descripcion
					);
			}
		}
		todoOk=1;
	}
	return todoOk;
}


int promedioAutosManualAuto(eAuto autos[],int lenAuto){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0){
		int contManual=0;
		int contAuto=0;
		int contador=0;
		printf("----PROMEDIO DE AUTOS CON MANUAL Y AUTO-----\n\n");

		for(int i=0;i<lenAuto;+i++){
			if(autos[i].caja=='m'){
				contManual++;
				contador++;
			}
			else if(autos[i].caja=='a'){
				contAuto++;
				contador++;
			}
		}
		printf("El promedio de autos con caja manual es: %.3f\n", (float)contManual/contador);
		printf("El promedio de autos con caja automatica es: %.3f\n", (float)contAuto/contador);
		todoOk=1;

	}
	return todoOk;
}


int mostrarPorFecha(eTrabajo trabajos[],int lenTrabajo,eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eServicio servicios[],int lenServicio, eCliente clientes[], int lenCliente){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0 && marcas!=NULL && colores!=NULL &&lenMarcaColor>0 && clientes!=NULL && lenCliente>0 && servicios!=NULL && lenServicio>0){
		int auxDia;
		int auxMes;
		int auxAnio;
		int existe=0;
		if(!validarCargarFecha("Ingrese la fecha con el formato (dd/mm/aaaa): ", &auxDia,&auxMes,&auxAnio)){
			printf("No se pudo cargar la fecha\n");
		}


		printf("--------TRABAJOS POR FECHA--------\n\n");
		printf("ID	PATENTE	  SERVICIO	FECHA\n");
		for(int i=0;i<lenTrabajo;i++){
			if(trabajos[i].isEmpty==0 && trabajos[i].fecha.dia==auxDia &&trabajos[i].fecha.mes==auxMes &&trabajos[i].fecha.anio==auxAnio){
				mostrarTrabajo(
					trabajos[i],
					lenTrabajo,
					servicios[buscarIdServicio(trabajos[i].idServicio, servicios, lenServicio)].descripcion
					);
				existe=1;
			}
		}
		if(!existe){
			printf("No se han encontrado ningun regitro con esa fecha.\n");
		}
		todoOk=1;
	}
	return todoOk;
}
