/*2)Abrir un archivo binario, escribir un struct Alumno, 
que contiene una variable edad(ingresada por consola). 
Cerrarlo, abrirlo de nuevo e imprimir la edad sacada desde el archivo.
*/
#include <iostream>
#include <stdio.h>

using namespace std;

struct Alumno{
    char nombre[10];
    int edad;
};

int main(){
    Alumno alumno1;
    FILE* fw = fopen("ejercicio2.dat", "wb");

    cout << "Ingrese nombre: ";
    cin.getline(alumno1.nombre, 10);
    cout << "Ingrese edad: ";
    cin >> alumno1.edad;

    fwrite(&alumno1, sizeof(Alumno), 1, fw);
    cout << "Archivo guardado." << endl;

    fclose(fw);

    FILE* fr = fopen("ejercicio2.dat", "rb");

    Alumno a;
    fread(&a, sizeof(Alumno), 1, fr);
    
    fclose(fr);

    cout << "Contenido del archivo: " << endl;
    cout << "Nombre: " << a.nombre << endl;
    cout << "Edad: " << a.edad << " años" << endl;

    return 0;
}