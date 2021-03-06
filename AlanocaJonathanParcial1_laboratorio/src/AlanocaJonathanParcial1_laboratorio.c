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
#include "funciones.h"
#include "hardC.h"
#include "informes.h"
#define TAM_AUTO 10
#define TAM_TRAB 10
#define TAM_MARCA_COLOR 5
#define TAM_SERVICIO 4
#define TAM_CLIENTE 5

int main(void) {
	setbuf(stdout,NULL);
	char seguir='n';
	int flagAuto=0;
	int flagTrabajo=0;
	int idAuto=10000;
	eAuto autos[TAM_AUTO];
	int idTrabajo=20000;
	eTrabajo trabajos[TAM_TRAB];
	eCliente clientes[TAM_CLIENTE]={
			{30000,"Jose",'m'},
			{30001,"Ana",'f'},
			{30002,"Rodrigo",'m'},
			{30003,"Esther",'f'},
			{30004,"Carlor",'m'},

	};
	eMarca marcas[TAM_MARCA_COLOR]={
			{1000,"Renault"},
			{1001,"Ford"},
			{1002,"Fiat"},
			{1003,"Chevrolet"},
			{1004,"Peugeot"}
	};
	eColor colores[TAM_MARCA_COLOR]={
			{5000,"N"},
			{5001,"Blanco"},
			{5002,"Rojo"},
			{5003,"Gris"},
			{5004,"Azul"}
	};
	eServicio servicios[TAM_SERVICIO]={
		{20000,"Lavado",450},
		{20001,"Pulid",500},
		{20002,"Encerado",600},
		{20003,"Completo",900}
	};

	if(!iniciarAutos(autos,TAM_AUTO)){
		printf("Error al inicializar altos.\n");
	}
	if(!iniciarTrabajos(trabajos,TAM_TRAB)){
		printf("Error al inicializar trabajos.\n");
	}
	hardCAutos(autos, &idAuto,&flagAuto);
	hardCTrabajos(trabajos,&idTrabajo,&flagTrabajo);
	do{
	    system("cls");
	    switch(menu()){
	        case 1:
	        	if(!altaAuto(autos, TAM_AUTO,&idAuto,marcas,TAM_MARCA_COLOR, colores, clientes,TAM_CLIENTE)){
	        		printf("No se puedo cargar los datos\n");
	        	}
	        	else{
	        		flagAuto++;
	        	}
	            break;
	        case 2:
	        	if (flagAuto>0){
					if(!modificarAuto(autos, TAM_AUTO,marcas,TAM_MARCA_COLOR, colores, clientes, TAM_CLIENTE)){
						printf("No se puedo cargar los datos\n");
					}
	        	}
	        	else{
	        		printf("Primero tenemos que dar de alta un auto.\n");
	        	}
	            break;
	        case 3:
	        	if(flagAuto>0){
	        		if(!borrarAuto(autos, TAM_AUTO,marcas,TAM_MARCA_COLOR, colores, clientes,TAM_CLIENTE)){
						printf("No se puedo cargar los datos\n");
					}
	        		flagAuto--;
	        	}
	        	else{
					printf("Primero tenemos que dar de alta un auto.\n");
				}

	            break;
	        case 4:
	        	if(flagAuto>0){
					ordenarAutos(autos ,TAM_AUTO,marcas,TAM_MARCA_COLOR);
					mostrarAutos(autos, TAM_AUTO,marcas,TAM_MARCA_COLOR, colores, clientes, TAM_CLIENTE);
	        	}
	        	else{
					printf("Primero tenemos que dar de alta un auto.\n");
				}
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
	        	if(flagAuto>0){
					if(!altaTrabajo(trabajos, TAM_TRAB, &idTrabajo,autos, TAM_AUTO,marcas,TAM_MARCA_COLOR, colores, servicios, TAM_SERVICIO, clientes,TAM_CLIENTE )){
						printf("No se puedo cargar los datos.\n");
					}
					else{
						flagTrabajo=1;
					}
	        	}
	        	else{
	        		printf("Primero tenemos que dar de alta un auto.\n");
	        	}
				break;
	        case 9:
	        	if (flagTrabajo){
					if(!mostrarTrabajos(trabajos, TAM_TRAB, servicios, TAM_SERVICIO)){
						printf("No se puedo motrar.\n");
					}
	        	}
	        	else{
	        		printf("Primero debemos hacer algun trabajo\n");
	        	}
	            break;
	        case 10:
	        	informes(trabajos, TAM_TRAB,autos, TAM_AUTO,marcas,TAM_MARCA_COLOR, colores, servicios, TAM_SERVICIO, clientes, TAM_CLIENTE);
	        	break;
	        case 11:
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


