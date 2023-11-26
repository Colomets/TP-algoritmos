#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdio>
using namespace std;

//Funciones

bool validarContra(char [],char []);
void invertir(char [],char []);
bool ingresoCorrecto(const char x[]);
void leerContrasena(char password[], int tam);

//Funciones

bool login(){//Devuelve la validacion del ingreso
	bool valido=true;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Usamos para cambiar el color de la consola en alguna linea especifica
	system("cls");
	char legajo[100];
	char contra[100];
	fflush(stdin);
	do{
		cout<<"Ingrese su id de usuario: ";
		gets(legajo);
		if(!(ingresoCorrecto(legajo)) or (ingresoCorrecto(legajo) and (legajo[0]<'1' or legajo[0]>'8'))){
			system("cls");
			SetConsoleTextAttribute(hConsole, 4);//Muestra mensaje de error en rojo si el ingreso es invalido
			cout<<"Id incorrecto, ingrese su Nro de legajo."<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(!(ingresoCorrecto(legajo)) or (ingresoCorrecto(legajo) and (legajo[0]<'1' or legajo[0]>'8')));
	int intentos=0, contador=0;
	do{//Pide el ingreso de contrasenia hasta que sea valido o hasta que se alcancen los 3 intentos incorrectos
		if(contador==0){
			system("cls");
			cout<<"Ingrese su id de usuario: ";puts(legajo);
		}
		cout<<"Ingrese su contrase"<<(char)164<<"a: ";
		leerContrasena(contra,100);
		intentos++;
		if(intentos==3 and !(validarContra(contra,legajo))){
			system("cls");
			for(int i=0;i<15;i++) cout<<endl;
			for(int i=0;i<20;i++) cout<<" ";
			cout<<"Exediste el limite de intentos permitidos, vuelve mas tarde."<<endl;
			Sleep(2000);
			valido=false;//Si alcanza los 3 intentos incorrectos, no valida el ingreso a la app
		}
		else if(!(validarContra(contra,legajo))){
			system("cls");
			cout<<"Ingrese su id de usuario: ";puts(legajo);
			SetConsoleTextAttribute(hConsole, 4);
			cout<<"Contrase"<<(char)164<<"a incorrecta, intente nuevamente."<<endl;
			SetConsoleTextAttribute(hConsole, 11);
			contador++;
		}
	}while(!(validarContra(contra,legajo)) and intentos<3);
	
	return valido;
}
void leerContrasena(char password[], int tam){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char caracter;
	int i = 0;
	bool terminar=true;
	SetConsoleTextAttribute(hConsole, 15);//9,15,240
	/*lee caracteres individuales y los guarda en una cadena hasta que el usuario presione enter
	caracteres especiales en ascii:
	13---ENTER
	8---borrar/backspace*/
	do{
		caracter=getch();//oculta el caracter ingresado	
		if(i<tam){
			if(caracter==13){
				terminar=false;
			}else{
				if(caracter==8 and i>0){//preguntar como retroceder una posicion en la pantalla
					cout<<"\b \b";
					i--;
				}else if(i<tam and caracter>31 and caracter!=127){//condicion para escribir un caracter (menos caracteres que el tamaño físico y no debe se un caracter de control)
					password[i]=caracter;
					cout<<"*";
					i++;
				}
			}
		}
	}while(terminar);
	password[i]='\0';
	SetConsoleTextAttribute(hConsole, 11);
}
bool ingresoCorrecto(const char x[]){//valida que la cadena ingresada sea una de 5 números
	bool aprobado=true;
	if(strlen(x)!=5)aprobado=false;
	else {
		for(int i=0;i<5;i++) { 
			if(!(isdigit(x[i])))aprobado=false;
		}
	}
	return aprobado;
}
bool validarContra(char x[],char legajo[]){//Evalua si la contrasenia ingresada cumple con la regla establecida
	bool ok=true;
	int largoContra=strlen(x),largoDeLegajo=strlen(legajo);
	if(largoContra!=largoDeLegajo)ok=false;
	else{
		char contra[10];
		invertir(legajo,contra);
		char agregar[2];
		if(((legajo[0]-'0')+(legajo[largoDeLegajo-1]-'0'))>9)agregar[0]=(((legajo[0]-'0')+(legajo[largoDeLegajo-1]-'0')-10)+'0');
		else agregar[0]=((legajo[0]-'0')+(legajo[largoDeLegajo-1]-'0')+'0');
		agregar[1]='\0';
		strcat(contra,agregar);
		int largo=strlen(contra);
		int i=0;
		while(ok and i<largo){
			if(x[i]!=contra[i])ok=false;
			i++;
		}
	}
	return ok;
}

	
void invertir(char legajo[],char salida[]){//Invierte numero entero y lo convierte en una cadena de caracteres
	int i=0;
	int cantDig=strlen(legajo);
	cantDig-=1;
	while(cantDig>0){
		salida[i]=legajo[cantDig];
		cantDig--;
		i++;
	}
	salida[i]='\0';
	return;
}
	
