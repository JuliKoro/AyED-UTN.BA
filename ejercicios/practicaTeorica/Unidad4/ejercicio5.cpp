/* 5) Dado el siguiente vector {2,4,23,28,30} osea, de 5 posiciones, 
buscar la forma en que sumen solo las posiciones pares(0,2,4) Es decir 2+23+30. Usar while()/for().
*/
#include <iostream>
using namespace std;

void imprimirVector(int unVector[], int tamanio){
    for(int i = 0; i < tamanio; i++) cout << unVector[i] << " ";
    cout << endl;
}

int sumarPosicionesPares(int numeros[], int tamanio){
    int suma = 0;
    for(int i=0; i<tamanio; i++){
        if(i%2 == 0) suma += numeros[i];
    }
    return suma;
}

int main(){
    int numeros[5] = {2,4,23,28,30};

    cout << "Vector de numeros:" << endl;
    imprimirVector(numeros, 5);

    cout << "Resultado de la suma de las posciones pares: " << sumarPosicionesPares(numeros, 5) << endl;

    return 0;
}