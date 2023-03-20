/*
9)Hacer un programa que reciba cinco números (a,b,c,d,e),
sume ‘a’ con ‘b’, multiplique ‘d’ con ‘e’, y le sume 100 a ‘c’. 
Luego, imprima sus valores en ese momento(osea del resultado de la suma entre (a + b), (d * e) y (c+100). 
*/
#include <iostream>

using namespace std;

int main(){
    int numeroA, numeroB, numeroC, numeroD, numeroE;

    cout << "Ingrese numero A: ";
    cin >> numeroA;
    cout << "Ingrese numero B: ";
    cin >> numeroB;
    cout << "Ingrese numero C: ";
    cin >> numeroC;
    cout << "Ingrese numero D: ";
    cin >> numeroD;
    cout << "Ingrese numero E: ";
    cin >> numeroE;

    int resultado = (numeroA + numeroB) + (numeroD * numeroE) + (numeroC + 100);

    cout << "Resultado de (A + B) + (D * E) + (C + 100): " << resultado << endl;

    return 0;
}