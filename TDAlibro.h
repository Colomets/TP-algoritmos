#ifndef TDALIBRO_H
#define TDALIBRO_H
#include <fstream>
#include <string>
using namespace std;

struct Libro{
	ifstream arc;
	
};

void cerrarLibro(Libro arch);
bool abrirLibro(Libro arch,char modo, string nombre);
Libro crearLibro();
char leerCaracterLibro(Libro arch);
void LeerPalabraLibro(Libro arch, char cad[]);


	
#endif
