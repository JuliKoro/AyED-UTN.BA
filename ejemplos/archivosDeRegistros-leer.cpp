#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Persona {
 int dni;
 char nombre[25];
 double altura;
};

int main() {
 FILE* f = fopen("PERSONAS.DAT","rb+");
 Persona p; // leo el primer registro
 fread(&p,sizeof(Persona),1,f);
 while( !feof(f) ) {
 cout << p.dni << ", " << p.nombre <<"," << p.altura << endl;
 fread(&p,sizeof(Persona),1,f);
 }
 fclose(f);
 system("pause");
 return 0;
}
