/* 7)Teniendo el siguiente struct, generar un vector de structs de 5 persona (inicializándolos como guste) 
e indicar de cada una, si una persona es pobre y si es mayor de edad. 
(Preferentemente al estilo de “ *Nombre* es/o no es mayor de edad y es pobre/rico”)
(alguien es pobre si tiene menos de 1000 pesos)

struct Persona{
        char nombre[20];
        int edad;
        int dinero;
};
*/
#include <iostream>
using namespace std;

struct Persona{
        char nombre[20];
        int edad;
        int dinero;
};

bool esRico(Persona unaPersona){
    if (unaPersona.dinero >= 1000) return true;
    else return false;
}

void imprimirPersonas(Persona unasPersonas[], int tamanio){
    for(int i = 0; i < tamanio; i++){
        cout << "Nombre: " << unasPersonas[i].nombre << endl;
        cout << "Edad: " << unasPersonas[i].edad << " años" << endl;
        cout << "Dinero: $" << unasPersonas[i].dinero << endl;
        if (esRico(unasPersonas[i])) cout << "Es rico." << endl << endl;
        else cout << "Es pobre." << endl << endl;
    }
}

int main(){
    Persona poblacion[5] = {
        {"Julian", 22, 0},
        {"Pedro", 23, 4000},
        {"Tamara", 24, 500},
        {"Federico", 22, 999},
        {"Ignacio", 23, 1000}
    };

    imprimirPersonas(poblacion, 5);

    return 0;
}