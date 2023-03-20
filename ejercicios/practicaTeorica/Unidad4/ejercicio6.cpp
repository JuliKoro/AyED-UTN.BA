/* 6)Hacer un programa en el que puedas ingresar tu nombre, 
letra por letra y luego lo imprima por pantalla. Máximo, 10 letras. 
*¿Que pasaria si tengo un int v[3] y quiero imprimir v[4] ?*
*Tener en cuenta de desarrollar una función que “limpie” el vector para que no contenga basura, 
en un vector de char*

*/
#include <iostream>
using namespace std;

void imprimirVector(char unVector[], int tamanio){
    for(int i = 0; i < tamanio; i++) cout << unVector[i] << " ";
    cout << endl;
}

void ingresarNombre(char nombre[], int tamanio){
    int i = 0;
    char letra = '1';
    while(letra != '.' && i < tamanio){
        cin >> letra;
        nombre[i] = letra;
        i++;
    }
}

void limpiarVector(char unVector[], int tamanio){
    for(int i = 0; i < tamanio; i++) unVector[i] = ' ';
}

int main(){
    char nombre[10];
    limpiarVector(nombre, 10);
    cout << "Ingrese su nombre letra por letra, '.' para finalizar:" << endl;
    ingresarNombre(nombre, 10);

    cout << "Usted ingreso: ";
    imprimirVector(nombre, 10);
    cout << endl;

    return 0;
}