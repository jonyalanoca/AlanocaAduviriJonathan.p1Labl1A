/*
 ============================================================================
 Name        : AlanocaJonathanParcial1_laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#define TAM_AUTO 10
#define TAM_MARCA_COLOR 5
#define TAM_SERVICIO 4

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
}eTrabajo;
int altaAuto(eAuto autos[],int lenAuto, int* idAuto,eMarca marcas[],int lenMarcaColor, eColor colores[]);
int iniciarAutos(eAuto autos[],int lenAuto);
int buscarLibreAuto(eAuto autos[],int lenAuto);
int buscarIdColor(int id,eColor colores[],int lenColor);
int buscarIdMarca(int id,eMarca marcas[],int lenMarca);
void mostrarAuto(eAuto autos, char marca[], char color[]);
int mostrarAutos(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[]);
void mostrarServicio(eServicio servicios);
int mostrarServicios(eServicio servicios[],int lenServicio);
void mostrarMarca(eMarca marcas);
int mostrarMarcas(eMarca marcas[],int lenMarca);
void mostrarColor(eColor colores);
int mostrarColores(eColor colores[],int lenColor);
int menu();

int main(void) {
	setbuf(stdout,NULL);
	char seguir='n';
	int idAuto=10000;
	eAuto autos[TAM_AUTO];
	eMarca marcas[5]={
			{1000,"Renault"},
			{1001,"Ford"},
			{1002,"Fiat"},
			{1003,"Chevrolet"},
			{1004,"Peugeot"}
	};
	eColor colores[5]={
			{5000,"N"},
			{5001,"Blanco"},
			{5002,"Rojo"},
			{5003,"Gris"},
			{5004,"Azul"}
	};
	eServicio servicios[4]={
		{20000,"Lavado",450},
		{20001,"Pulid",500},
		{20002,"Encerado",600},
		{20003,"Completo",900}
	};

	if(!iniciarAutos(autos,TAM_AUTO)){
		printf("Error al inicializar altos.\n");
	}
	do{
	    system("cls");
	    switch(menu()){
	        case 1:
	        	if(!altaAuto(autos, TAM_AUTO,&idAuto,marcas,TAM_MARCA_COLOR, colores)){
	        		printf("No se puedo cargar los datos\n");
	        	}
	        	mostrarAutos(autos, TAM_AUTO,marcas,TAM_MARCA_COLOR, colores);

	            break;
	        case 2:

	            break;
	        case 3:

	            break;
	        case 4:

				break;
	        case 5:
	        	if(!mostrarMarcas(marcas,TAM_MARCA_COLOR)){
					printf("No se puedo motrar.\n");
				}
				break;
	        case 6:
	        	if(!mostrarColores(colores,TAM_MARCA_COLOR)){
	        		printf("No se puedo motrar.\n");
	        	}
				break;
	        case 7:
	        	if(!mostrarServicios(servicios,TAM_SERVICIO)){
					printf("No se puedo motrar.\n");
				}
				break;
	        case 8:

				break;
	        case 9:

	            break;
	        case 10:
	        	seguir=confirmarSalir();
	            break;
	        default:
	            printf("Porfavor Ingrese una opcion valida.\n");
	            break;
	    }
	    system("pause");
	}while(seguir!='s');
	return EXIT_SUCCESS;
}

int altaAuto(eAuto autos[],int lenAuto, int* idAuto,eMarca marcas[],int lenMarcaColor, eColor colores[]){
	int todoOk=0;{
	if(autos!=NULL &&lenAuto>0){
		int auxId;
		int auxIdMarca;
		int auxIdColor;
		char auxCaja;
		int libre;
		printf("--------Alta de autos--------\n\n");
		libre=buscarLibreAuto(autos,lenAuto);
		if(libre!=-1){
			auxId=*idAuto;
			(*idAuto)++;
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
void mostrarAuto(eAuto autos, char marca[], char color[]){
	printf("%d	%s	%s	%c", autos.id, marca,color, autos.caja);
}
int mostrarAutos(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor,eColor colores[]){
	int todoOk=0;
	if(autos!=NULL && lenAuto>0){

			printf("--------Lista de Autos--------\n\n");
			printf("ID		MARCA		COLOR	T-CAJA\n");
			for(int i=0;i<lenAuto;+i++){

				mostrarAuto(autos[i],
						marcas[buscarIdMarca(autos[i].idMarca,marcas,lenMarcaColor)].descripcion
						,colores[buscarIdColor(autos[i].idColor,colores,lenMarcaColor)].nombreColor);
			}
			todoOk=1;

	}
	return todoOk;
}
/*int ordenarAutos(eAuto autos[],int lenAuto,eMarca marcas[],int lenMarcaColor){
	int todoOk=0;
	int aux;
	if(autos!=NULL && lenAuto>0){
		for(int i=0;i<lenAuto-1;i++){
			for(int j=i+1;j<lenAuto;j++){
				if(autos[i].)

			}
		}
	}
	return todoOk;
}*/
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
	printf("\t9- LISTAR TRABAJOS\n");
	printf("\t10-SALIR\n");
	printf("\t____________________________________\n\n");
	printf("\tIngrese una opcion: ");
	fflush(stdin);
	scanf("%d",&opcion);
	fflush(stdin);
	system("cls");
	return opcion;
}
