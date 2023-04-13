#include <iostream>

using namespace std;

template <typename T> struct Nodo {
    T info;
    Nodo<T>* sig;
};

/*template <typename T> Nodo<T>* buscarEnLista(Nodo<T>*,T);
template <typename T> void agregarNodo(Nodo<T>*, T);
template <typename T> void mostrar(Nodo<T>*);*/

template <typename T> Nodo<T>* buscarEnLista(Nodo<T>*l, T v){
    Nodo<T>* aux = l;
    while(aux != NULL && aux->info != v){
        aux=aux->sig;
    }
    return aux;
}

template <typename T> void agregarNodo(Nodo<T>* &p, T x) {
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->info = x;
    nuevo->sig = NULL;
    if( p==NULL ) {
        p = nuevo;
    } else {
        Nodo<T>* aux = p;
        while(aux->sig!=NULL ) {
            aux = aux->sig;
        }
    aux->sig = nuevo;
    }
}

template <typename T> void mostrar(Nodo<T>*& p) {
    Nodo<T>* aux = p;
    while( aux!=NULL ) {
        cout << aux->info << "-";
        aux = aux->sig;
    }
}

int main()
{
    Nodo<int>* p = NULL; //Creo Lista
    agregarNodo(p, 1);
    agregarNodo(p, 4);
    agregarNodo(p, 8);
    mostrar(p);
    p = buscarEnLista(p,4);
    cout<<endl<< "Objetivo encontrado: "<<p->info<<endl;
    return 0;
}


