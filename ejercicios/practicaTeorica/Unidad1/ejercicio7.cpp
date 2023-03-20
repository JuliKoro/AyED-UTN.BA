/*
7)Hacer un programa que reciba 3 números,(a,b,c) sume los primeros 2(a+b), 
al resultado de esto le multiplique el tercer número((a+b)*c) y que a este resultado total, 
se lo asigne a la tercera variable(c). 
Imprimir el valor de c
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

    int sumaAB = numeroA + numeroB;
    numeroC = sumaAB * numeroC;

    cout << "Resultado de (A + B) * C: " << numeroC << endl;

    return 0;
}