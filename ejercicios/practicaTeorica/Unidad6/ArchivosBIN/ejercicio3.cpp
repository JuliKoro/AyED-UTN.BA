/* 3)Abrir un archivo binario, escribir 3 struct Alumno, 
que contiene una variable edad (Ingresada por consola). 
Cerrarlo, abrirlo de nuevo e imprimir las edades sacadas desde el archivo.
*/
#include <iostream>
#include <stdio.h>

using namespace std;

struct Alumno{
    char nombre[10];
    int edad;
};

void escribir(FILE* f, int cant){
    for(int i = 0; i < cant; i++){
        Alumno alum;
        cout << "Ingrese nombre del alumno " << i+1 << ": ";
        cin.getline(alum.nombre, 10);
        cout << "Ingrese edad del alumno " << i+1 << ": ";
        cin >> alum.edad;
        cout << endl;
        fwrite(&alum, sizeof(Alumno), 1, f);
        cin.ignore();
    }
}

void leer(FILE* f){
    Alumno a;
    int i = 1;
    while(fread(&a, sizeof(Alumno), 1, f)){
        cout << "Alumno Nro. " << i << ":" << endl;
        cout << "Nombre: " << a.nombre << endl;
        cout <<"Edad: " << a.edad << " años" << endl << endl;
        i++;
    }
}

int main(){
    int cant = 3;

    FILE* fw = fopen("ejercicio3.dat", "wb");
    escribir(fw, cant);
    fclose(fw);

    FILE* fr = fopen("ejercicio3.dat", "rb");
    leer(fr);
    fclose(fr);

    return 0;
}