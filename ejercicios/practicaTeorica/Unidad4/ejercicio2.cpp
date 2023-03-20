/* 2)a)Hacer un programa que reciba 10 números y se lo asigne a un vector de 10 posiciones.
b)Imprimirlos en el orden ingresado.
*/
#include <iostream>
using namespace std;

void ingresarValores(int vector[], int tamanio){
    int unValor;
    for(int i = 0; i < tamanio; i++){
        cout << "Ingrese valor: ";
        cin >> unValor;
        vector[i] = unValor;
    }
}

void imprimirVector(int unVector[], int tamanio){
    for(int i = 0; i < tamanio; i++) cout << unVector[i] << " ";
    cout << endl;
}

int main(){
    int tamanio = 10, numeros[tamanio];

    ingresarValores(numeros, tamanio);
    imprimirVector(numeros, tamanio);

    return 0;
}