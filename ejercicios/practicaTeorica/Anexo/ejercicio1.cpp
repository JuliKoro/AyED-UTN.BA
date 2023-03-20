// 1)Declarar un puntero a entero, imprimir el valor del puntero.
#include <iostream>
using namespace std;
 int main(){
    int num = 20;
    int *entero;

    entero = &num;

    cout << "Numero apuntando: " << *entero << endl;
    cout << "Direccion de memoria apuntando: " << &entero << endl;

    return 0;
 }