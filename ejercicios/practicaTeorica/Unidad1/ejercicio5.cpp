/*
5)Hacer un programa que reciba dos números, imprima sus valores, 
luego los intercambie e imprima el valor final de cada variable. (osea los valores intercambiados)
*/

#include <iostream>

using namespace std;

int main(){
    int numero1, numero2, aux;

    cout << "Ingrese un numero: ";
    cin >> numero1;
    cout << "Ingrese otro numero: ";
    cin >> numero2;

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