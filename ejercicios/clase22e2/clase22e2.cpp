#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    int contador;
    Nodo *izq;
    Nodo *der;
};

void insertarNodo(Nodo *&nodo, int v) {
    if(nodo==NULL) {
        nodo = new Nodo();
        if(nodo!=NULL) {
            nodo->dato = v;
            nodo->contador = 1;
            nodo->izq=NULL;
            nodo->der=NULL;
        }
    } else if(v < nodo->dato) {
        insertarNodo(nodo->izq,v);
    } else if(v > nodo->dato) {
        insertarNodo(nodo->der,v);
    } else {
        nodo->contador++;
    }
}

void preOrden(Nodo* nodo) {
    if(nodo!=NULL) {
        cout << nodo->dato << "(" << nodo->contador << ")" << endl;
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }
}

void inOrden(Nodo* nodo){
    if(nodo!=NULL){
        inOrden(nodo->izq);
        cout << nodo->dato << "(" << nodo->contador << ")" << endl;
        inOrden(nodo->der);
    }
}

void postOrden(Nodo* nodo){
    if(nodo!=NULL){
        postOrden(nodo->izq);
        postOrden(nodo->der);
        cout << nodo->dato << "(" << nodo->contador << ")" << endl;
    }
}

int main(int argc, char** argv) {
    Nodo *raiz = NULL;
    int datos[] = {7,8,0,6,14,1,0,13,0,7};
    for(int i = 0; i<sizeof(datos)/sizeof(datos[0]); i++) {
        insertarNodo(raiz,datos[i]);
    }
    cout<<"Arbol inOrden: "<<endl;
    inOrden(raiz);
    cout<<"Arbol postOrden: "<<endl;
    postOrden(raiz);
    cout<<"Arbol preOrden: "<<endl;
    preOrden(raiz);
    return 0;
}
