#include <fstream>
#include <string>
using namespace std;

struct Libro{
	fstream arc;
};

void cerrarLibro(Libro &arch);
bool abrirLibro(Libro &arch, char modo,bool binario, string nombre);
char leerCaracterLibro(Libro &arch);
void LeerPalabraLibro(Libro &arch, char cad[]);
bool finArchivo(Libro &arch);
	
