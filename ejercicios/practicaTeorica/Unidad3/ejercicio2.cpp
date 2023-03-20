// 2) Dado un número ingresado por el usuario, indicar si es igual a 32.
#include <iostream>
using namespace std;

int main(){
    int unNumero;

    cout << "Ingrese un numero: ";
    cin >> unNumero;

    if (unNumero == 32) cout << "Su numero es 32" << endl;
    else cout << "Su numero NO es 32" << endl;

    return 0;
}