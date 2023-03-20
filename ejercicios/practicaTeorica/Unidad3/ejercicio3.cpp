/* 3)Hacer un programa que reciba dos números y sume 6 veces el valor de la segunda variable a la primera.
Imprimir el resultado de la primera variable. Usar un while() o un for(). 
Ej: a+b+b+b+b+b+b
*/
#include <iostream>
using namespace std;

int main(){
    int numero1, numero2;

    cout << "Ingrese un numero: ";
    cin >> numero1;
    cout << "Ingrese otro numero: ";
    cin >> numero2;

    for(int i=0; i<6; i++) numero1 += numero2;

    cout << "Resultado de A + 6B: " << numero1 << endl;
    return 0;
}