/* 2)a)Genere un programa que dado un vector de structs(el que quieras) de 5 posiciones, 
se pueda ir ingresando los valores, uno por uno. El struct solamente contiene el campo “valor”(entero).
b)Imprima desde el comienzo del vector, ambos valores del struct.
*/
#include <iostream>
using namespace std;

const int tamanio = 5;

struct Valor{
    int valor;
}valores[tamanio];

void imprimirStruct(Valor unosValores[]){
    for(int i = 0; i < tamanio; i++){
        cout << unosValores[i].valor << " ";
    }
    cout << endl;
}

void ingresarValores(Valor unosValores[]){
    for(int i = 0; i < tamanio; i++) {
        cout << "Ingrese un valor: ";
        cin >> valores[i].valor;
    }
}

int main(){
    ingresarValores(valores);
    cout << endl << "Usted ingreso: " << endl;
    imprimirStruct(valores);

    return 0;
}