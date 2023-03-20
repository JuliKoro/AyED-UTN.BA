/* 6)a)Desarrolle una función que genere un vector de structs (El struct posee el campo “índice”,
siendo un int). 
El valor del entero índice del primer struct va a ser cero, el del segundo struct, uno, el del tercero, 
dos y así hasta 20.
b)Imprima el vector una vez terminado de generarlo.
*/
#include <iostream>
using namespace std;

const int tamanio = 20;

struct Valor{
    int indice;
};

void imprimirStruct(Valor unosValores[], int tamanio){
    for(int i = 0; i < tamanio; i++){
        cout << unosValores[i].indice << " ";
    }
    cout << endl;
}

void generarIndices(Valor unVector[]){
    for(int i = 0; i < tamanio; i++) unVector[i].indice = i + 1;
}

int main(){
    Valor indices[tamanio];
    generarIndices(indices);
    cout << "Vector generado:" << endl;
    imprimirStruct(indices, tamanio);
    return 0;
}