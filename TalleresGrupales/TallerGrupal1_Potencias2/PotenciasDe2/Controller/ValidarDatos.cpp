#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "../Model/ValidarDatos.h"


int ValidarDatos::validarNumeros(char msj[20]){
	char c;
	int valor,i=0;
	char dato[10];
	printf("\nTEVS: %s",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			dato[i++]=c;
			printf("%c",c);
		}
	}
	dato[i]='\0';
	valor=atoi(dato);
	printf("\n");
	return valor;
}

bool ValidarDatos::validarAnioBisiesto(int anio){
	if(anio%4!=0){
		return false;}
	else if(anio%100!=0){
		return true;}
	else if(anio%400!=0){
		return false;}
	else{
		return true;}
}

//Regresa el numero de dias del mes
int ValidarDatos::validarMes (int mes, int anio){
	if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
		return 31;}
	else if(mes==4 || mes==6 || mes==9 || mes==11){
		return 30;}
	else if(mes==2){
			if(validarAnioBisiesto(anio)==true){
				return 29;}
			else{
				return 28;}
		}
}

bool ValidarDatos::validarDia(int dia,int diasDelMes){
	if (dia<1 || dia>diasDelMes){
		return false;}
	else
		return true;
}




