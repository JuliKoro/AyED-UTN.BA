#include <iostream>

using namespace std;

template <typename T> struct Nodo {
    T info;
    Nodo<T>* sig;
};

template <typename T> void push(Nodo<T>* &p, T v){
    Nodo<T>* aux = new Nodo<T>();
    aux->info = v;
    aux->sig = p;
    p = aux;
    return;
}

template <typename T> T pop(Nodo<T>* &p){
    T x;
    Nodo<T>* aux = p;
    x = aux->info;
    p = aux->sig;
    delete aux;
    return x;
}

template <typename T> int size(Nodo<T>* p){
	int t = 0;
	while(p!=NULL){
        p=p->sig;
		t++;
	}
	return t;
}

template <typename T> bool empty(Nodo<T>* p){
	return p==NULL?true:false;
}

int main(){
    Nodo<char>* p = NULL;
    push(p,'a');
    push(p,'b');
    push(p,'c');
    cout<<"Cantidad de elementos en la pila: "<<size(p)<<endl;
    while( p!=NULL ){
        cout << pop(p) << endl;
    }
    cout<<"Esta vacia la pila?: "<<empty(p)<<endl;
    return 0;
}
