// 3)Desarrolle una función que agregue una posición, a un vector de structs.
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

void agregarNuevo(Valor unosValores[], int &tamanio){
    cout << "Ingrese nuevo valor: ";
    cin >> unosValores[tamanio].valor;
    tamanio++;
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
    agregarNuevo(vector, tamanio);
    cout << "Vector actualizado: " << endl;
    imprimirStruct(vector, tamanio);   

    return 0;
}