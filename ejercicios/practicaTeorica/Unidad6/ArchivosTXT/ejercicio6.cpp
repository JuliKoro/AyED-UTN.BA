/* 6)Haga un programa que permita escribir un string de 10 caracteres en un archivo, y luego leerlo. 
No es necesario cerrarlo.
*/
#include <iostream>
#include <stdio.h>

using namespace std;

void escribir(FILE* f, int tam){
    char cadena[tam];
    cout << "Ingrese una palabra:" << endl;
    cin.getline(cadena, tam);
    fputs(cadena, f);
    cout << "Palabra guardada." << endl;
}

void leer(FILE* f, int tam){
    char cadena[tam];
    fgets(cadena, tam, f);
    cout << "Contenido del archivo:" << endl;
    for(int i = 0; i < tam; i++) cout << cadena[i];
    cout << endl;
}

int main(){
    int tamanio = 10;
    FILE* f = fopen("ejercicio6.txt", "w+");

    escribir(f, tamanio);
    fseek(f, 0, SEEK_SET);
    leer(f, tamanio);
    fclose(f);
    return 0;
}