/*
2) Teniendo 2 enteros, 23 y 45 asignados a dos variables distintas, intercambiar sus valores.
Imprimir ambos valores.
*/

#include <iostream>

using namespace std;

int main(){
    int numero1 = 23, numero2 = 45, aux;

    cout << "Valor numero 1: " << numero1 << endl;
    cout << "Valor numero 2: " << numero2 << endl;

    cout << "Intercambio de variables..." << endl;

    aux = numero1;
    numero1 = numero2;
    numero2 = aux;

    cout << "Nuevo valor numero 1: " << numero1 << endl;
    cout << "Nuevo valor numero 2: " << numero2 << endl;

    return 0;
}