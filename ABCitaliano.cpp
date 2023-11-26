#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include "func_aux.h"
using namespace std;

//Funciones

void bienvenida();
bool login();
int digitos(int);
bool validarContra(char [],int);
void invertir(int,char[]);
int primDig(int);
void menuPrincipal();
void salir(char opcion='x');
void menuAbecedarios();
void menuJuegos();
int potencia(int,int);
bool ABCingles();
void show(char[], int,int,int [],int);
void mayusculas (char[], int);
void minusculas (char[], int);
void showABC (char[], int);
bool ABCespaniol();
bool ABCfrances();
bool ABCitaliano();
bool ABCportugues();
bool esRepetido(char revisar[], char letra,int l);
void ahorcado();
bool descubrir(bool v[],int top);
void tituloAhorcado();
void mostrarLetrasIngresadas(const char escritas[],const int k);

//Funciones


bool ABCitaliano(){
	system("cls");//Limpia la consola
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Las usamos para operar los colores de la consola en una linea especifica
	char abc[21]={'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
	int vocales[]={133,138,130,141,161,140,149,162,151,163};//Definimos el abecedario y las letras acentuadas
	int tam=21,tl=10;//Definimos el tamanio del abecedario
	show(abc, tam,3,vocales,tl);//Llamamos la funcion show para mostrar todo
	
	string input;
	char eleccion[2]={'a','k'};
	bool salida;
	do{//Menu para decidir como continuar la ejecucion del programa
		cout<<"Ingrese (X) para volver al menu anterior: ";
		fflush(stdin);
		getline(cin,input);
		if(input=="X"||input=="x")
		{
			eleccion[0]='X';
			eleccion[1]='\0';
		}
		
		if(eleccion[0]!='X' or !(esUnDigito(eleccion))){
			system("cls");
			show(abc,tam,3,vocales,tl);//vuelve a mostrar toda la funcion para volver a elegir la opcion
			SetConsoleTextAttribute(hConsole, 4);//Cambiamos el color del texto
			cout<<"Opci"<<(char)162<<"n ingresada es inv"<<(char)160<<"lida. "<<endl;
			SetConsoleTextAttribute(hConsole, 11);
		}
	}while(eleccion[0]!='X' or !(esUnDigito(eleccion)));
	return true;
}
