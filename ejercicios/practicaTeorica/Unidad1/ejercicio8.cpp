/*
8)Hacer un programa que reciba tres letras(variables a,b,c) e intercambie sus valores de la siguiente manera:
a va a valer c,
b va a valer a,
c va a valer b
*/
#include <iostream>

using namespace std;

int main(){
    char letraA, letraB, letraC, aux1, aux2;

    cout << "Ingrese letra a: ";
    cin >> letraA;
    cout << "Ingrese letra b: ";
    cin >> letraB;
    cout << "Ingrese letra c: ";
    cin >> letraC;

    cout << "Valor de la letra a: " << letraA << endl;
    cout << "Valor de la letra b: " << letraB << endl;
    cout << "Valor de la letra c: " << letraC << endl;

    cout << endl << "Intercambaindo variables..." << endl << endl;

    aux1 = letraA;
    letraA = letraC;
    aux2 = letraB;
    letraB = aux1;
    letraC = aux2;

    cout << "Nuevo valor de la letra a: " << letraA << endl;
    cout << "Nuevo valor de la letra b: " << letraB << endl;
    cout << "Nuevo valor de la letra c: " << letraC << endl;

    return 0;
}