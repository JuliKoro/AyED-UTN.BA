/* 3) Dado un vector con los siguientes valores {5,1,63,2}, en ese orden, 
indica el mayor y el menor por pantalla. 
Ayuda: usar while()/for().
*/

#include <iostream>
using namespace std;

void imprimirVector(int unVector[], int tamanio){
    for(int i = 0; i < tamanio; i++) cout << unVector[i] << " ";
    cout << endl;
}

int mayor(int numeros[], int tamanio){
    int max = numeros[0];
    for(int i = 0; i < tamanio; i++){
        if(max < numeros[i+1]) max = numeros[i+1];
    }
    return max;
}

int menor(int numeros[], int tamanio){
    int min = numeros[0];
    for(int i = 0; i < tamanio-1; i++){
        if(min > numeros[i+1]) min = numeros[i+1];
    }
    return min;
}

int main(){
    int numeros[4] = {5,1,63,2};

    cout << "Vector: ";
    imprimirVector(numeros, 4);
    cout << "El mayor es: " << mayor(numeros, 4) << endl;
    cout << "El menor es: " << menor(numeros, 4) << endl;

    return 0;
}