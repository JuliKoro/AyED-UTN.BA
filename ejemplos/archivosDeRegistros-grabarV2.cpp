#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

struct Persona {
 int dni;
 char nombre[25];
 double altura;
};

int main() {
 Persona p;
 FILE* f = fopen("PERSONAS.DAT","w+b");
 while( p.dni>0 ) {
 fwrite(&p,sizeof(Persona),1,f);
 cout << "Ingrese dni, nombre, altura: ";
 cin >> p.dni;
 cin.getline(p.nombre, 25);
 cin >> p.altura;
 }
 fclose(f);
 system("pause");
 return 0;
}


