// 1)Inicializar un vector de 4 posiciones con los de valores numéricos del 0 al 3. Imprimirlo por pantalla.
#include <iostream>
using namespace std;

void imprimirVector(int unVector[], int tamanio){
    for(int i = 0; i < tamanio; i++) cout << unVector[i] << " ";
    cout << endl;
}

int main(){
    int numeros[4] = {0, 1, 2, 3};

    imprimirVector(numeros, 4);

    return 0;
}