/* 3)Declarar una función que cambie el valor de una variable al número 300 y luego,
fuera de la función, imprima el valor modificado.
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

void cambiar(int** dir, int valor){
    *dir = new int[valor];
}

int main(){
    int a;
    int* dir_a;

    cout << "Ingrese un valor: ";
    cin >> a;

    dir_a = &a;

    cout << endl << "Usted ingreso el valor: " << *dir_a << endl;
    cout << "En la direccion de memoria: " << dir_a << endl;

    cambiar(&dir_a, 300); // No funciona

    cout << endl << "Valor cambiado: " << *dir_a << endl;
    cout << "En la direccion de memoria: " << dir_a << endl;

    return 0;
}