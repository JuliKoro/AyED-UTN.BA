/*
1)Hacer un programa que reciba 2 números e indique cuál es el mayor.
*/
#include <iostream>
using namespace std;

int main(){
    int unNumero, otroNumero;

    cout << "Ingrese un numero: ";
    cin >> unNumero;
    cout << "Ingrese otro numero: ";
    cin >> otroNumero;

    if (unNumero > otroNumero) cout << unNumero << " es mayor que " << otroNumero << endl;
    else cout << otroNumero << " es mayor que " << unNumero << endl;

    return 0;
}
