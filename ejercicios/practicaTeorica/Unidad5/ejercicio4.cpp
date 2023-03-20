// 4)Desarrollar una función que quite la última posición de un vector de structs
#include <iostream>
using namespace std;

struct Valor{
    int valor;
};

void imprimirStruct(Valor unosValores[], int tamanio){
    for(int i = 0; i < tamanio; i++){
        cout << unosValores[i].valor << " ";
    }
    cout << endl;
}

void eliminarUltimo(Valor unosValores[], int &tamanio){
    tamanio--;
}

int main(){
    int tamanio = 3;
    Valor vector[tamanio];
    vector[0].valor = 4;
    vector[1].valor = 9;
    vector[2].valor = 14;

    cout << "Vector cargado: " << endl;
    imprimirStruct(vector, tamanio);
    cout << endl;
    eliminarUltimo(vector, tamanio);
    cout << "Vector actualizado: " << endl;
    imprimirStruct(vector, tamanio);   

    return 0;
}
