/*
 * validaciones.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Jony
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
char confirmarSalir(){
		char aux;
		printf("Esta saliendo del programa. Confirme con una (s): ");
		fflush(stdin);
		scanf("%c", &aux);
		if(aux>65 && aux<91){
			aux=aux+32;
		}
	return aux;
}

int validarCargarLetra(char mensaje[],char* varLetra){
	char auxString[50];
	int i;
	int todoOk=0;
	if(mensaje!=NULL && varLetra!=NULL){
		do{//pedimos que ingrese una cadena hasta que cumpla con el requisito de: unicamente letras exclusivamente
			todoOk=1;
			printf("%s: ", mensaje);
			fflush(stdin);
			gets(auxString);
			if(auxString[0]=='\0'){
				printf("El texto esta vacio. ");
				todoOk=0;
			}
			else{
				i=0;
				while(auxString[i]!='\0'){
					if((auxString[i]<'a' || auxString[i]>'z') && (auxString[i]<'A' || auxString[i]>'Z')){
						printf("Caracteres no validos. ");
						todoOk=0;
						break;
					}
					i++;
				}
			}
		}while(!todoOk);
		*varLetra=auxString[0];
		if(strlen(auxString)>1){
			todoOk=2;
		}
	}
	return todoOk;
}

int validarCargarDecimal(char mensaje[], float* varNumero){
	int todoOk=0;
		int i;
		char auxString[50];
		if(mensaje!= NULL && varNumero!=NULL){
			todoOk=1;
			do{
				todoOk=1;
				printf("%s: ", mensaje);
				fflush(stdin);
				gets(auxString);
				if(auxString[0]=='\0'){
					printf("No ingreso nada aun. ");
					todoOk=0;
				}
				else{
					i=0;
					if(auxString[0]=='-'){
						i=1;
						if(auxString[1]=='\0'){
							printf("No ingreso nada aun. ");
							todoOk=0;
						}
					}
					while(auxString[i]!='\0' && todoOk==1){
						if(auxString[i]=='.'){
							i++;
							continue;

						}
						if(auxString[i]<'0' || auxString[i]>'9'){
							printf("Caracteres no validos. ");
							todoOk=0;
							break;
						}
						i++;
					}
				}
			}while(!todoOk);
			*varNumero=atof(auxString);
		}
		return todoOk;
}
int validarCargarEntero(char mensaje[], int* varNumero){
	int todoOk=0;
	int i;
	char auxString[50];
	int maximoPermitido=10;
	if(mensaje!= NULL && varNumero!=NULL){
		todoOk=1;
		do{
			todoOk=1;
			printf("%s: ", mensaje);
			fflush(stdin);
			gets(auxString);
			if(auxString[0]=='\0'){
				printf("No ingreso nada aun. ");
				todoOk=0;
			}
			else{
				i=0;
				if(auxString[0]=='-'){
					i=1;
					maximoPermitido=11;
					if(auxString[1]=='\0'){
						printf("No ingreso nada aun. ");
						todoOk=0;
					}
				}
				while(auxString[i]!='\0' && todoOk==1){
					if(auxString[i]<'0' || auxString[i]>'9'){
						printf("Caracteres no validos. ");
						todoOk=0;
						break;
					}
					i++;
				}
				if((strlen(auxString))>maximoPermitido && todoOk==1){
					printf("El numero es muy alto. ");
					todoOk=0;
				}

			}
		}while(!todoOk);
		*varNumero=atoi(auxString);
	}
	return todoOk;
}
int capitalizar(char varString[]){
	int todoOk=0;
	if (varString!=NULL){
		strlwr(varString);
		varString[0]=varString[0]-32;
		todoOk=1;
	}
	return todoOk;
}
int validarCargarStr(char mensaje[],char string[],int lenString){
	char auxString[50];
	int i;
	int todoOk=0;
	if(mensaje!=NULL && string!=NULL && lenString>0){
		do{//pedimos que ingrese una cadena hasta que cumpla con el requisito de: unicamente letras exclusivamente
			todoOk=1;
			printf("%s: ", mensaje);
			fflush(stdin);
			gets(auxString);
			if(auxString[0]=='\0'){
				printf("El texto esta vacio. ");
				todoOk=0;
			}
			else{
				i=0;
				while(auxString[i]!='\0'){
					if((auxString[i]<'a' || auxString[i]>'z') && (auxString[i]<'A' || auxString[i]>'Z')){
						printf("Caracteres no validos. ");
						todoOk=0;
						break;
					}
					i++;
				}
			}
		}while(!todoOk);
		//Verifica si la cadena no desborda nuestra varible principal antes de copiar
		if(strlen(auxString)<=lenString){
			strcpy(string, auxString);
			todoOk=1;
		}
		else{
			todoOk=2;
			for(int i=0; i<lenString;i++){
				string[i]=auxString[i];
			}
			string[lenString]='\0';
		}
	}
	return todoOk;
}
int validarDosChar(char mensaje[],char* varChar, char letra1, char letra2){
	int todoOk=0;
	if(mensaje!=NULL&&varChar!=NULL){
		char aux;
		printf("%s: ", mensaje);
		fflush(stdin);
		scanf("%c", &aux);
		if(aux>65 && aux<91){
			aux=aux+32;
		}
		while(aux!= letra1 && aux!=letra2){
			 printf("Vuelva a intentar .%s: ",mensaje);
			 fflush(stdin);
			 scanf("%c", &aux);
			 if(aux>65 && aux<91){
				aux=aux+32;
			}
		}
		*varChar=aux;
		todoOk=1;
	}
	return todoOk;
}

int validarCargarFecha(char mensaje[], int* dia, int* mes, int* anio){
	int todoOk=0;
	if(mensaje!=NULL && dia !=NULL && mes !=NULL && anio!=NULL){
		char auxString[30];
		int i=0;
		char auxDMA[4];
		do{
			todoOk=1;
			printf("%s: ", mensaje);
			fflush(stdin);
			gets(auxString);
			if(auxString[0]=='\0'){
				printf("No ingreso nada aun. ");
				todoOk=0;
			}
			else if(strlen(auxString)>10){
				printf("Por favor respete el formato (dd/mm/aaaa)\n");
				todoOk=0;
			}
			else{
				i=0;
				while(auxString[i]!='\0'){
					if(i==2 || i==5){
						if(auxString[i]!='/'){
							printf("Por favor respete el formato (dd/mm/aaaa)\n");
							todoOk=0;
							break;
						}
					}
					else{
						if(auxString[i]<'0' || auxString[i]>'9'){
							printf("Por favor respete el formato (dd/mm/aaaa)\n");
							todoOk=0;
							break;
						}
					}
					i++;
				}

			}
		}while(!todoOk);

		auxDMA[0]=auxString[0];
		auxDMA[1]=auxString[1];
		auxDMA[2]='\0';
		*dia=atoi(auxDMA);
		auxDMA[0]=auxString[3];
		auxDMA[1]=auxString[4];
		auxDMA[2]='\0';
		*mes=atoi(auxDMA);
		auxDMA[0]=auxString[6];
		auxDMA[1]=auxString[7];
		auxDMA[2]=auxString[8];
		auxDMA[3]=auxString[9];
		auxDMA[4]='\0';
		*anio=atoi(auxDMA);

		todoOk=1;

	}
	return todoOk;
}
