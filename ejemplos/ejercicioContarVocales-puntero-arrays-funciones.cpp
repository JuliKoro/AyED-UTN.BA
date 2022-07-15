#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void pedirDatos();
int contarVocales(char *);

const char vocales[] = {'a','e','i','o','u','A','E','I','O','U'};
const int cantVoc = 10;
const int tam = 30;

char nombre[tam];

int main(){
	pedirDatos();
	
	cout<<"Numero de vocales en su nombre: "<<contarVocales(nombre)<<endl;
	
	system ("pause");
	return 0;
}

void pedirDatos(){
	cout<<"Ingrese su nombre completo por favor: ";
	cin.getline(nombre,tam,'\n');
}

int contarVocales(char *dirNombre){
	int cont = 0;
	while(*dirNombre){
		for(int c=0; c<cantVoc; c++){
			if(*dirNombre == vocales[c]){
				cont++;
			}
		}
		dirNombre++;
	}
	return cont;
}
