/*
6)Hacer un programa que reciba 3 números, los multiplique entre ellos (a*b*c),
y al resultado, le reste el tercer número, e imprima el resultado por pantalla.
*/

#include <iostream>

using namespace std;

int main(){
    int numeroA, numeroB, numeroC;

    cout << "Ingrese numero A: ";
    cin >> numeroA;
    cout << "Ingrese numero B: ";
    cin >> numeroB;
    cout << "Ingrese numero C: ";
    cin >> numeroC;

    int resultado = (numeroA * numeroB * numeroC) - numeroC;

    cout << "Resultado de (A*B*C) - C: " << resultado << endl;

    return 0;
}