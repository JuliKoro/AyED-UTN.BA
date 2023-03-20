/* 7)Dado el siguiente vector {‘j','a’,'i','k','s’} 
hacer un programa que indique si una letra, ingresada por el usuario, pertenece al vector.
*/
#include <iostream>
using namespace std;

void imprimirVector(char unVector[], int tamanio){
    for(int i = 0; i < tamanio; i++) cout << unVector[i] << " ";
    cout << endl;
}

bool pertenece(char letra, char letras[], int tamanio){
    for(int i = 0; i < tamanio; i++){
        if(letras[i] == letra) return true;
    }
    return false;
}

int main(){
    char letras[5] = {'j','a','i','k','s'}, letra;

    cout << "Ingrese una letra: ";
    cin >> letra;

    cout << "¿Pertenece esa letra al conjunto?" << endl;
    if(pertenece(letra, letras, 5)) cout << "Si." << endl;
    else cout << "No." << endl;

    return 0;
}