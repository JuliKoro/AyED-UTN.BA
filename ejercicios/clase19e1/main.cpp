#include <iostream>

using namespace std;

template <typename T> struct Nodo {
    T info;
    Nodo<T>* sig;
};

template <typename T> void agregar(Nodo<T>*& p, Nodo<T>*& q, T v) {
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->info = v;
    nuevo->sig = NULL;
    if( p==NULL ) p = nuevo;
    else q->sig = nuevo;
    q = nuevo;
}

template <typename T> T suprimir(Nodo<T>*& p, Nodo<T>*& q) {
    T ret = p->info;
    Nodo<T>* aux = p;
    p = p->sig;
    if( p == NULL) q = NULL;
    delete aux;
    return ret;
}

template <typename T> T frente(Nodo<T>* p){
    return p->info;
}

template <typename T> int tamanio(Nodo<T>* p){
    int cant = 0;
    while(p!=NULL){
        p=p->sig;
        cant++;
    }
    return cant;
}

template <typename T> bool vacia (Nodo<T>* p){
    return p==NULL?true:false;
}

int main(){
    Nodo<int>*p = NULL; //frente
    Nodo<int>*q = NULL; //fin
    agregar(p,q,1);
    agregar(p,q,2);
    agregar(p,q,3);
    cout<<"Cantidad de elemntos en la cola: "<<tamanio(p)<<endl;
    while(p!=NULL){
        cout<<suprimir(p,q)<<endl;
    }
    cout<<"La cola esta vacia? "<<endl;
    if (vacia(p)==1) cout<<"Si"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
