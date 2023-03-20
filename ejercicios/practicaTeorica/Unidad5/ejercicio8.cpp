/* 7)Teniendo un vector de structs, previamente inicializado (realizar una función que inicializa structs), 
ordenar el vector con respecto a v:

struct Nodo{
        Int v;
};
*/
#include <iostream>
using namespace std;

struct Nodo{
    int v;
};

const int tamanio = 5;

void imprimirStruct(Nodo unosValores[], int tamanio){
    for(int i = 0; i < tamanio; i++){
        cout << unosValores[i].v << " ";
    }
    cout << endl << endl;
}

void inicializar(Nodo unVector[], int len){
    for(int i = 0; i < len; i++){
        cout << "Ingrese un valor: ";
        cin >> unVector[i].v;
    }
}

void ordenar(Nodo unVector[], int len){
    for(int c = 1; c < len; c++){
        for(int i = 0; i < len - c; i++){
            if(unVector[i].v > unVector[i+1].v){
                int temp = unVector[i].v;
                unVector[i].v = unVector[i+1].v;
                unVector[i+1].v = temp;
            }
        }
    }
}

int main(){
    Nodo vector[tamanio];

    inicializar(vector, tamanio);
    cout << "Vector cargado: " << endl;
    imprimirStruct(vector, tamanio);
    ordenar(vector, tamanio);
    cout << "Vector ordenado: " << endl;
    imprimirStruct(vector, tamanio);

    return 0;
}