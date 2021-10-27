/*
 * hardC.c
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

void hardCAutos(eAuto autos[],int* id, int* flagA){
	int idMarca[5]={1000,1000,1004,1004,1002};
	int idCliente[5]={30001,30001,30002,30003,30000};
	int idColor[5]={5000,5000,5004,5004,5002};
	char caja[5]={'a','m','a','m','a'};
	for(int i=0; i<5;i++){
		autos[i].id=*id;
		(*id)++;
		autos[i].idCliente=idCliente[i];
		autos[i].idMarca=idMarca[i];
		autos[i].idColor=idColor[i];
		autos[i].caja=caja[i];
		autos[i].isEmpty=0;
		(*flagA)++;
	}

}
void hardCTrabajos(eTrabajo trabajos[],int* id, int* flagT){
	int patente[5]={10001,10001,10004,10005,10002};
	int idServicio[5]={20000,20003,20002,20001,20001};
	int dia[5]={12,6,1,29,13};
	int mes[5]={1,3,4,5,6};
	int anio[5]={2001,2001,2002,2002,2003};
	for(int i=0; i<5;i++){
		trabajos[i].id=*id;
		(*id)++;
		trabajos[i].patente=patente[i];
		trabajos[i].idServicio=idServicio[i];
		trabajos[i].fecha.dia=dia[i];
		trabajos[i].fecha.mes=mes[i];
		trabajos[i].fecha.anio=anio[i];
		trabajos[i].isEmpty=0;
	}
	printf("hola");
	*flagT=1;
}

