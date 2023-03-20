/* 1)Desarrollar push().
2)Desarrollar pop().
/*Teniendo definimos ya push() y pop(), desarrollar lo que sigue*/
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int info;
    Nodo* sig;
};

void push(Nodo* &p, int val){
    Nodo* aux = new Nodo();
    aux -> info = val;
    aux -> sig = p;
    p = aux;
    return;
}

int pop(Nodo* &p){
    int val = p -> info;
    Nodo* aux = p;
    p = aux -> sig;
    delete aux;
    return val;
}

int main(){
    Nodo* p = NULL; // Creo una pila
    push(p, 1);
    push(p, 2);
    push(p, 3);
    while(p != NULL) cout << pop(p) << endl;
    cout << "La pila esta vacia." << endl;
    return 0;
}