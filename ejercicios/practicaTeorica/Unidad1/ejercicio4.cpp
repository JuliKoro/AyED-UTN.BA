/*
4)Hacer un programa que reciba un número, le sume 230, e imprima por pantalla.
*/

#include <iostream>

using namespace std;

int main(){
    int unNumero;

    cout << "Ingrese un numero: ";
    cin >> unNumero;

    int suma = unNumero + 230;

    cout << "Resultado sumandole 230: " << suma << endl;

    return 0;
}