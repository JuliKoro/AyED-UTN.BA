// 5)Desarrollar una función que quite una posición, ingresada por el usuario, de un vector de structs.
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

void eliminarPosicion(Valor unosValores[], int &tamanio, int pos){
    for(int i = pos; i < tamanio; i++){
        unosValores[i] = unosValores[i+1];
    }
    tamanio--;
}

int main(){
    int tamanio = 3, posicion;
    Valor vector[tamanio];
    vector[0].valor = 4;
    vector[1].valor = 9;
    vector[2].valor = 14;

    cout << "Vector cargado: " << endl;
    imprimirStruct(vector, tamanio);
    cout << endl;
    cout << "Ingrese una posicion a eliminar: ";
    cin >> posicion;
    eliminarPosicion(vector, tamanio, posicion);
    cout << "Vector actualizado: " << endl;
    imprimirStruct(vector, tamanio);   

    return 0;
}