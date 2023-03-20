/* 4)Dado un vector con los siguientes valores {53,22,18,34,1}, ordenar de menor a mayor, 
e imprimir sus valores por pantalla, ordenados.
*/
#include <iostream>
using namespace std;

void imprimirVector(int unVector[], int tamanio){
    for(int i = 0; i < tamanio; i++) cout << unVector[i] << " ";
    cout << endl;
}

void ordenarMenorAMayor(int unVector[], int tamanio){
    for(int j=0; j<tamanio; j++){
        for(int i=0; i<tamanio; i++){
            if(unVector[i] > unVector[i+1]){
                int aux = unVector[i];
                unVector[i] = unVector[i+1];
                unVector[i+1] = aux;
            }
        }
    }
}

int main(){
    int numeros[5] = {53,22,18,34,1};

    cout << "Vector de numeros:" << endl;
    imprimirVector(numeros, 5);

    ordenarMenorAMayor(numeros, 5);
    cout << "Vector ordenado de menor a mayor:" << endl;
    imprimirVector(numeros, 5);

    return 0;
}