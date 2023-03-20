/* 9)Dado el siguiente vector {“somtirogla”} (cadena de caracteres), 
imprimirla de atrás para adelante. (Tiene que imprimir “algoritmos”)
*/
#include <iostream>
using namespace std;

void imprimirVector(char unVector[], int tamanio){
    for(int i = 0; i < tamanio; i++) cout << unVector[i] << " ";
    cout << endl;
}

void imprimirRotcev(char unVector[], int tamanio){
    for(int i = tamanio-1; i >= 0; i--) cout << unVector[i] << " ";
    cout << endl;
}

int main(){
    char vesre[10] = {'s','o','m','t','i','r','o','g','l','a'};

    cout << "Palabra orginal: " << endl;
    imprimirVector(vesre, 10);

    cout << "Palabra al reves: " << endl;
    imprimirRotcev(vesre, 10);

    return 0;
}