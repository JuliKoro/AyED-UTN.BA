/* 1)Hacer un programa que cargue un archivo binario con una pila de 10 Personas, que tiene nombre, edad y 
número de legajo (número entero), previamente inicializada por el usuario (en este caso, vos), 
y finalmente que imprima, sacando los datos desde el archivo, 
el nombre de las personas mayores de edad (mayor a 18 años).
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Persona{
    char nombre[10];
    int edad;
    int nro_legajo;
};

struct Nodo{
    Persona info;
    Nodo* sig;
};

void push(Nodo* &p, Persona info){
    Nodo* aux = new Nodo();
    aux -> info = info;
    aux -> sig = p;
    p = aux;
    return;
}

void ingresar(Nodo* &p, int cant){
    Persona alumno;
    for(int i = 0; i < cant; i++){
        cout << "Ingrese nombre: ";
        cin.getline(alumno.nombre, 10);
        cout << "Ingrese edad: ";
        cin >> alumno.edad;
        cout << "Ingrese nro legajo: ";
        cin >> alumno.nro_legajo;
        push(p, alumno);
        cin.ignore();
    }
}
Persona pop(Nodo* &p){
    Persona x;
    Nodo* aux = p;
    x = aux -> info;
    p = aux -> sig;
    delete aux;
    return x;
}

void guardar(FILE* f, Nodo* p){
    fwrite(&p, sizeof(Nodo), 1, f);
    cout << "Archivo guardado." << endl << endl;
}

void imprimir(FILE* f){
    Nodo* aux;
    Persona alumno;
    fseek(f, 0, SEEK_SET);
    fread(&aux, sizeof(Nodo), 1, f);
    cout << "Nombres de las personas mayores de edad:" << endl;
    while(aux != NULL){
        alumno = pop(aux);
        if(alumno.edad >= 18) cout << alumno.nombre << endl;
    }
}

int main(){
    Nodo* p = NULL;
    int cant = 10;
    FILE* f = fopen("personas.dat", "wb+");

    ingresar(p, cant);
    guardar(f, p);
    imprimir(f);

    fclose(f);

    return 0;
}