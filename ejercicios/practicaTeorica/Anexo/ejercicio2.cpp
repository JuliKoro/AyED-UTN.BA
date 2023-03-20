/* 2)Declarar una variable a, asignarle un valor por consola,
declarar un puntero a entero y hacer lo necesario para que, utilizando el puntero 
*/
#include <iostream>
using namespace std;

int main(){
    int a, *puntero;

    cout << "Ingrese un numero: ";
    cin >> a;

    puntero = &a;
    cout << "Numero apuntando: " << *puntero << endl;
    cout << "Direccion de memoria apuntando: " << &puntero << endl;

    return 0;
}