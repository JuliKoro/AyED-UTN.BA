/* 3)Hacer un programa, que genere una lista con los siguientes valores: 30, 55, 24 y los imprima por pantalla. 
El struct posee solamente un campo entero llamado valor.
*/
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Data{
    int valor;
};

struct Nodo{
    Data info;
    Nodo* sig;
};

void agregar(Nodo* &p, Data val){
    Nodo* nuevo = new Nodo();
    nuevo -> info = val;
    nuevo -> sig = NULL;
    if(p == NULL) p = nuevo;
    else {
        Nodo* aux = p;
        while(aux -> sig != NULL) aux = aux -> sig;
        aux -> sig = nuevo;
    }
}

void mostrar(Nodo* p){
    //Nodo* aux = p;
    while(p != NULL){
        cout << p -> info.valor << " ";
        p = p -> sig;
    }
}

int main(){
    Data num1, num2, num3;
    Nodo* p = NULL;

    num1.valor = 30;
    num2.valor = 55;
    num3.valor = 24;

    agregar(p, num1);
    agregar(p, num2);
    agregar(p, num3);

    cout << "Lista en el programa:" << endl;
    mostrar(p);
    cout << endl;

    return 0;
}