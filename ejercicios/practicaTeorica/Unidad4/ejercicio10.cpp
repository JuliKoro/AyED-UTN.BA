/* 10)Dado un vector (int v[0]) desarrollar un programa que vaya agregando valores al vector, 
conforme el usuario vaya ingresando valores por consola. 
Formar, siendo vos el usuario que ingresa los valores, 
e imprimir un vector de 5 posiciones con los siguientes valores {0,4,6,2,9}.
*/
#include <iostream>
using namespace std;

void imprimirVector(int unVector[], int tamanio){
    for(int i = 0; i < tamanio; i++) cout << unVector[i] << " ";
    cout << endl;
}

void formarVector(int unVector[], int &indice){
    int ingreso;
    while(ingreso != -1){
        cin >> ingreso;
        if(ingreso != -1){
            unVector[indice] = ingreso;
            indice++;
        }
    }
}

int main(){
    int v[0], indice = 0;

    cout << "Ingrese numeros de auno, -1 para finalizar:" << endl;
    formarVector(v, indice);

    cout << "Usted formo el vector:" << endl;
    imprimirVector(v, indice);
}