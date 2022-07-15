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
 FILE* f = fopen("PERSONAS.DAT","w+b");
 int dni;
 string nom;
 double altura;
 cout << "Ingrese dni, nombre, altura: ";
 cin >> dni;
 cin >> nom;
 cin >> altura;
 while( dni>0 ) {
 Persona p;
 p.dni = dni;
 strcpy(p.nombre,nom.c_str());
 p.altura = altura;
 fwrite(&p,sizeof(Persona),1,f);
 cout << "Ingrese dni, nombre, altura: ";
 cin >> dni;
 cin >> nom;
 cin >> altura;
 }
 fclose(f);
 return 0;
}


