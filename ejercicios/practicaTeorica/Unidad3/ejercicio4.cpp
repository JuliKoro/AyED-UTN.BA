/* 4)Dado un flag(Bool) que empieza en True, imprimir la frase “Este número no es 44”,
mientras el numero ingresado por el usuario sea distinto a 44.
*/
#include <iostream>
using namespace std;

int main(){
    int unNumero = 0;
    while (unNumero != 44){
        cout << "Ingrese un numero: ";
        cin >> unNumero;
        if (unNumero != 44) cout << "Este número no es 44" << endl;
    }
    return 0;
}