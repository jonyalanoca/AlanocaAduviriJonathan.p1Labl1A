/*
 * funciones.c
 *
 *  Created on: 27 oct. 2021
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "funciones.h"
int altaAuto(eAuto autos[],int lenAuto, int* idAuto,eMarca marcas[],int lenMarcaColor, eColor colores[],eCliente clientes[], int lenCliente){
	int todoOk=0;{
	if(autos!=NULL &&lenAuto>0){
		int auxId;
		int auxIdCliente;
		int auxIdMarca;
		int auxIdColor;
		char auxCaja;
		int libre;
		printf("--------Alta de autos--------\n\n");
		libre=buscarLibreAuto(autos,lenAuto);
		if(libre!=-1){
			auxId=*idAuto;
			(*idAuto)++;
			mostrarClientes(clientes, lenCliente);
			do{
				validarCargarEntero("Ingrese el id del cliente", &auxIdCliente);
			}while(buscarIdCliente(auxIdCliente, clientes, lenCliente)==-1);
			mostrarMarcas(marcas, lenMarcaColor);
			do{
				validarCargarEntero("Ingrese el id de la marca", &auxIdMarca);
			}while(buscarIdMarca(auxIdMarca, marcas, lenMarcaColor)==-1);
			mostrarColores(colores,lenMarcaColor);
			do{
				validarCargarEntero("Ingrese el id del color", &auxIdColor);
			}while(buscarIdColor(auxIdColor, colores, lenMarcaColor)==-1);
			if(!validarDosChar("Ingrese el tipo de caja de auto Manual (m) - Automatica (a)", &auxCaja, 'm','a')){
				printf("Fallo. No se pudo cargar");
			}
			autos[libre].id=auxId;
			autos[libre].idCliente=auxIdCliente;
			autos[libre].idMarca=auxIdMarca;
			autos[libre].idColor=auxIdColor;
			autos[libre].caja=auxCaja;
			autos[libre].isEmpty=0;
			todoOk=1;
			}
		}
		else{
			printf("No espacio disponible");
		}
	}
	return todoOk;
}
void mostrarAuto(eAuto autos, char marca[], char color[], char cliente[]){
	printf("%d%10s%10s%7s%10c\n", autos.id, cliente, marca,color, autos.caja);
}

int buscarIdCliente(int id, eCliente clientes[], int lenCliente){
	int todoOk=-1;
	if(clientes!=NULL && lenCliente>0){
		for(int i=0; i<lenCliente;i++){
			if(id==clientes[i].id){
				todoOk=i;
				break;
			}
		}

	}
	return todoOk;
}
int mostrarAutos(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eCliente clientes[], int lenCliente){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0 && marcas!=NULL && colores!=NULL &&lenMarcaColor>0){

			printf("--------Lista de Autos--------\n\n");
			printf("ID	CLIENTE 	MARCA	  COLOR	   T-CAJA\n");
			for(int i=0;i<lenAuto;+i++){
				if(autos[i].isEmpty==0){
					mostrarAuto(autos[i],
						marcas[buscarIdMarca(autos[i].idMarca,marcas,lenMarcaColor)].descripcion
						,colores[buscarIdColor(autos[i].idColor,colores,lenMarcaColor)].nombreColor,
						clientes[buscarIdCliente(autos[i].idCliente, clientes, lenCliente)].nombre);
				}

			}
			todoOk=1;

	}
	return todoOk;
}
int ordenarAutos(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor){
	int todoOk=0;
	eAuto aux;
	if(autos!=NULL && lenAuto>0){
		for(int i=0;i<lenAuto-1;i++){
			for(int j=i+1;j<lenAuto;j++){
				if(strcmp(marcas[buscarIdMarca(autos[i].idMarca,marcas, lenMarcaColor)].descripcion,marcas[buscarIdMarca(autos[j].idMarca,marcas, lenMarcaColor)].descripcion )>0){
					aux=autos[i];
					autos[i]=autos[j];
					autos[j]=aux;
				}

			}
		}
	}
	return todoOk;
}
int iniciarAutos(eAuto autos[],int lenAuto){
	int todoOk=0;
	if(autos!=NULL &&lenAuto>0){
		for(int i =0; i<lenAuto; i++){
			autos[i].isEmpty=1;
		}
		todoOk=1;
	}
	return todoOk;
}
int buscarLibreAuto(eAuto autos[],int lenAuto){
	int todoOk=-1;
	if(autos!=NULL &&lenAuto>0){
		for(int i =0; i<lenAuto; i++){
			if(autos[i].isEmpty==1){
				todoOk=i;
				break;
			}
		}
	}
	return todoOk;
}
int buscarAuto(eAuto autos[],int lenAuto,int idAuto){
	int todoOk=0;
	if(autos!=NULL &&lenAuto>0){
		for(int i =0; i<lenAuto; i++){
			if(autos[i].isEmpty==0 && idAuto==autos[i].id){
				todoOk=1;
				break;
			}
		}
	}
	return todoOk;
}
int buscarIdAuto(eAuto autos[],int lenAuto,int idAuto){
	int todoOk=-1;
	if(autos!=NULL &&lenAuto>0){
		for(int i =0; i<lenAuto; i++){
			if(autos[i].isEmpty==0 && idAuto==autos[i].id){
				todoOk=i;
				break;
			}
		}
	}
	return todoOk;
}
int buscarIdColor(int id,eColor colores[],int lenColor){
	int todoOk=-1;
	if(colores!=NULL && lenColor>0){
		for(int i=0; i<lenColor;i++){
			if(id==colores[i].id){
				todoOk=i;
				break;
			}
		}

	}
	return todoOk;
}
int buscarIdMarca(int id,eMarca marcas[],int lenMarca){
	int todoOk=-1;
	if(marcas!=NULL && lenMarca>0){
		for(int i=0; i<lenMarca;i++){
			if(id==marcas[i].id){
				todoOk=i;
				break;
			}
		}

	}
	return todoOk;
}

void mostrarServicio(eServicio servicios){
	printf("%d	%10s	 %.2f\n", servicios.id, servicios.descripcion, servicios.precio);
}
int mostrarServicios(eServicio servicios[],int lenServicio){
	int todoOk=0;{
		if(servicios!=NULL&&lenServicio>0){
			printf("--------Lista de Servicios--------\n\n");
			printf("ID	  SERVICIO       PRECIO\n");
			for(int i=0;i<lenServicio;+i++){
				mostrarServicio(servicios[i]);
			}
			todoOk=1;
		}
	}
	return todoOk;
}

void mostrarCliente(eCliente clientes){
	printf("%d	%s	%c\n", clientes.id, clientes.nombre, clientes.sexo);
}
int mostrarClientes(eCliente clientes[],int lenCliente){
	int todoOk=0;{
		if(clientes!=NULL&&lenCliente>0){
			printf("--------Lista de clientes--------\n\n");
			printf("ID	CLIENTE	SEXO\n");
			for(int i=0;i<lenCliente;+i++){
				mostrarCliente(clientes[i]);
			}
			todoOk=1;
		}
	}
	return todoOk;
}



void mostrarMarca(eMarca marcas){
	printf("%d	%s\n", marcas.id, marcas.descripcion);
}
int mostrarMarcas(eMarca marcas[],int lenMarca){
	int todoOk=0;{
		if(marcas!=NULL&&lenMarca>0){
			printf("--------Lista de Marcas--------\n\n");
			printf("ID	MARCA\n");
			for(int i=0;i<lenMarca;+i++){
				mostrarMarca(marcas[i]);
			}
			todoOk=1;
		}
	}
	return todoOk;
}

void mostrarColor(eColor colores){
	printf("%d	%s\n", colores.id, colores.nombreColor);
}

int mostrarColores(eColor colores[],int lenColor){
	int todoOk=0;{
		if(colores!=NULL&&lenColor>0){
			printf("--------Lista de Colores--------\n\n");
			printf("ID	COLOR\n");
			for(int i=0;i<lenColor;+i++){
				mostrarColor(colores[i]);
			}
			todoOk=1;
		}
	}
	return todoOk;
}

int menu(){
	int opcion;
	printf("\t=-=-=-=-AUTO-SEVICIO-=-=-=-=-=\n");
	printf("\t_______________Menu_________________\n\n");
	printf("\t1-ALTA AUTO\n");
	printf("\t2-MODIFICAR AUTO\n");
	printf("\t3-BAJA AUTO\n");
	printf("\t4-LISTAR AUTOS\n");
	printf("\t5-LISTAR MARCAS\n");
	printf("\t6-LISTAR COLORES\n");
	printf("\t7-LISTAR SERVICIOS\n");
	printf("\t8-ALTA TRABAJO\n");
	printf("\t9-LISTAR TRABAJOS\n");
	printf("\t10-INFORMES\n");
	printf("\t11-SALIR\n");
	printf("\t____________________________________\n\n");
	printf("\tIngrese una opcion: ");
	fflush(stdin);
	scanf("%d",&opcion);
	fflush(stdin);
	system("cls");
	return opcion;
}

int modificarAuto(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eCliente clientes[], int lenCliente){
	int todoOk=0;
	if(autos!=NULL && marcas!=NULL && colores != NULL && lenAuto >0 && lenMarcaColor>0){
		int auxIdColor;
		int auxIdMarca;
		int idAuto;
		int indexAuto;
		printf("-----------------MODIFICAR AUTOS--------------\n");
		mostrarAutos(autos, lenAuto,marcas,lenMarcaColor, colores, clientes, lenCliente);
		printf("-----------------------------------------------\n");
		do{
			validarCargarEntero("Ingrese el id del autos a moidicar:", &idAuto);
		}while(!buscarAuto(autos,lenAuto, idAuto));
		if(buscarIdAuto(autos, lenAuto, idAuto)!=-1){
			indexAuto=buscarIdAuto(autos, lenAuto, idAuto);
		}

		switch(subMenu()){
		case 1:
			if(!mostrarColores(colores,lenMarcaColor)){
				printf("No se puedo motrar.\n");
			}
			printf("-------------------------------\n");
			do{
				validarCargarEntero("Ingrese el id del color", &auxIdColor);
			}while(buscarIdColor(auxIdColor, colores, lenMarcaColor)==-1);
			autos[indexAuto].idColor=auxIdColor;

			break;
		case 2:
			if(!mostrarMarcas(marcas,lenMarcaColor)){
				printf("No se puedo motrar.\n");
			}
			do{
				validarCargarEntero("Ingrese el id de la marca", &auxIdMarca);
			}while(buscarIdMarca(auxIdMarca, marcas, lenMarcaColor)==-1);
			break;
			autos[indexAuto].idMarca=auxIdMarca;
			break;
		case 3:
			break;
		default:
			printf("Opcion incorrecta. elija una opcion valida");
			break;
		}
		todoOk=1;
	}
	return todoOk;
}
int subMenu(){
	int opcion;
	printf("\t=-=-=-=-MODIFICAR AUTO-=-=-=-=-=\n");
	printf("\t_______________Menu_________________\n\n");
	printf("\t1-MODIFICAR COLOR\n");
	printf("\t2-MODIFICAR MODELO\n");
	printf("\t3-SALIR\n");
	printf("\t____________________________________\n\n");
	printf("\tIngrese una opcion: ");
	fflush(stdin);
	scanf("%d",&opcion);
	fflush(stdin);
	system("cls");
	return opcion;
}

int borrarAuto(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eCliente clientes[],int lenCliente){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0){
		int idAuto;
		char confirm='n';
		int indexAuto;
		printf("-----------------BORRAR AUTOS--------------\n");
		mostrarAutos(autos, lenAuto,marcas,lenMarcaColor, colores, clientes, lenCliente);
		printf("-----------------------------------------------\n");
		do{
			validarCargarEntero("Ingrese el id del autos que desea borrar", &idAuto);

		}while(!buscarAuto(autos,lenAuto, idAuto));
		if(buscarIdAuto(autos, lenAuto, idAuto)!=-1){
			indexAuto=buscarIdAuto(autos, lenAuto, idAuto);
		}

		printf("Seguro que desea borrar el siguiente regitro.\n");
		mostrarAuto(
				autos[indexAuto],

				marcas[buscarIdMarca(autos[indexAuto].idMarca,marcas,lenMarcaColor)].descripcion,
				colores[buscarIdColor(autos[indexAuto].idColor,colores,lenMarcaColor)].nombreColor,
				clientes[buscarIdCliente(autos[indexAuto].idCliente,clientes,lenCliente)].nombre
				);

		printf("Confirmar con una (s): ");
		fflush(stdin);
		scanf("%c", &confirm);
		if (confirm=='s'){
			autos[indexAuto].isEmpty=1;
		}
		todoOk=1;
	}
	return todoOk;
}
int buscarLibreTrabajo(eTrabajo trabajos[],int lenTrabajo){
	int todoOk=-1;
	if(trabajos!=NULL &&lenTrabajo>0){
		for(int i =0; i<lenTrabajo; i++){
			if(trabajos[i].isEmpty==1){
				todoOk=i;
				break;
			}
		}
	}
	return todoOk;
}
int iniciarTrabajos(eTrabajo trabajos[],int lenTrabajo){
	int todoOk=0;
	if(trabajos!=NULL &&lenTrabajo>0){
		for(int i =0; i<lenTrabajo; i++){
			trabajos[i].isEmpty=1;
		}
		todoOk=1;
	}
	return todoOk;
}
int buscarIdServicio(int id,eServicio servicios[],int lenServicio){
	int todoOk=-1;
	if(servicios!=NULL && lenServicio>0){
		for(int i=0; i<lenServicio;i++){
			if(id==servicios[i].id){
				todoOk=i;
				break;
			}
		}
	}
	return todoOk;
}
int altaTrabajo(eTrabajo trabajos[],int lenTrabajo, int* idTrabajo,eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[], eServicio servicios[],int lenServicio, eCliente clientes[],int lenCliente ){
	int todoOk=0;
	if(trabajos!=NULL &&autos!=NULL &&servicios!=NULL && lenTrabajo>0 && lenAuto>0 && lenServicio>0){
		int auxId;
		int libre;
		int auxIdAuto;
		int auxIdServicio;
		int auxDia;
		int auxMes;
		int auxAnio;
		printf("--------Alta de autos--------\n\n");
		libre=buscarLibreTrabajo(trabajos,lenTrabajo);
		if(libre!=-1){
			auxId=*idTrabajo;

			(*idTrabajo)++;

			mostrarAutos(autos, lenAuto,marcas,lenMarcaColor, colores, clientes, lenCliente);
			do{
				validarCargarEntero("Ingrese el id del auto", &auxIdAuto);
			}while(buscarIdAuto(autos, lenAuto,auxIdAuto)==-1);


			mostrarServicios(servicios,lenServicio);
			do{
				validarCargarEntero("Ingrese el id del servicio", &auxIdServicio);
			}while(buscarIdServicio(auxIdServicio, servicios, lenServicio)==-1);
			if(!validarCargarFecha("Ingrese la fecha con el formato (dd/mm/aaaa): ", &auxDia,&auxMes,&auxAnio)){
				printf("No se pudo cargar la fecha\n");
			}

			trabajos[libre].id=auxId;
			trabajos[libre].patente=auxIdAuto;
			trabajos[libre].idServicio=auxIdServicio;
			trabajos[libre].fecha.dia=auxDia;
			trabajos[libre].fecha.mes=auxMes;
			trabajos[libre].fecha.anio=auxAnio;
			trabajos[libre].isEmpty=0;
			todoOk=1;
		}
		else{
			printf("No espacio disponible");
		}

		todoOk=1;
	}
	return todoOk;
}

void mostrarTrabajo(eTrabajo trabajos,int lenTrabajo, char servicio[]){
	printf("%d	%d	  %s	   %d/%d/%d\n", trabajos.id, trabajos.patente, servicio, trabajos.fecha.dia,trabajos.fecha.mes,trabajos.fecha.anio);
}
int mostrarTrabajos(eTrabajo trabajos[],int lenTrabajo, eServicio servicios[],int lenServicio ){
	int todoOk=0;{
		if(trabajos!=NULL && servicios!=NULL&& lenTrabajo>0 && lenServicio>0){
			printf("--------Lista de Trabajos--------\n\n");
			printf("ID	PATENTE	  SERVICIO	FECHA\n");
			for(int i=0;i<lenTrabajo;+i++){
				if(trabajos[i].isEmpty==0){
				mostrarTrabajo(
						trabajos[i],
						lenTrabajo,
						servicios[buscarIdServicio(trabajos[i].idServicio, servicios, lenServicio)].descripcion
						);
				}
			}
			todoOk=1;
		}
	}
	return todoOk;
}

