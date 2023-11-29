#include "TDALIBRO_H"
#include <iostream>
#include <string>
using namespace std;

Libro crearLibro(){
	Libro arch;
	return arch;
}

bool confirmarLibro(Libro arch){//confirma si se abrió correctamente
	return arch.arc.is_open;
}
	
bool abrirLibro(Libro arch, char modo, string nombre){//abre el archivo para leer o escribir según el modo elegido

	switch(modo){
	case 'l'://leer
		arch.arc.open(nombre,ios::in);
		break;
	case 'e'://escribir
		arch.arc.open(nombre,ios::out);
		break;
	case 'b'://binario
		arch.arc.open(nombre,ios::binary);
		break;
	}
	
	return confirmarLibro(arch);
}

void cerrarLibro(Libro.arch){
	arch.arc.close();
}

char leerCaracterLibro(Libro arch){
	char c;
	arch.arc.get(c);
	return c;
}

void LeerPalabraLibro(Libro arch, char cad[], int tl=20){
	arch.arc.getline(cad, tl,' ');
}
