#include <iostream>
#include <math.h>

using namespace std;

struct Paquete {
	int dato;
	bool ap;
};

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

Paquete crearPaquete(int dato, bool ap){
    Paquete p;
    p.dato = dato;
    p.ap = ap;
    return p;
}

template <typename T, typename K> void procesar (Nodo<T>* &p, Nodo<T>* &q, Nodo<K>* &s, Nodo<K>* &t, Nodo<K>* &r){
    while(p!=NULL){
        Paquete paque = suprimir<T>(p,q); //el frente de la cola paquete lo guardo en paque
        paque.dato = abs(paque.dato); //calcula valor absoluto
        if(paque.ap == true) push<K>(r, paque.dato); //guardo en la pila
        else agregar<K>(s,t,paque.dato); //guardo en la cola
    }
}

int main(){
    Nodo<Paquete>* p = NULL; //frente del paquete
    Nodo<Paquete>* q = NULL; //fin del paquete
    Nodo<int>* s=NULL; //frente cola (Buffer FIFO de salida)
	Nodo<int>* t=NULL; //fin cola (Buffer FIFO de salida)
	Nodo<int>*  r=NULL; //pila (Alta prioridad)

    agregar(p,q,crearPaquete(1555,0));
	agregar(p,q,crearPaquete(146,1));
	agregar(p,q,crearPaquete(552,0));
	agregar(p,q,crearPaquete(244,1));
	agregar(p,q,crearPaquete(-30,0));
	agregar(p,q,crearPaquete(15,1));
	agregar(p,q,crearPaquete(256,0));

	procesar<Paquete,int>(p,q,s,t,r);

	cout<<"Alta prioridad: "<<endl;
	while(r!=NULL){
        cout<<pop<int>(r)<<endl;
	}
	cout<<"Buffer de salida: "<<endl;
	while(s!=NULL && t!=NULL){
        cout<<suprimir<int>(s,t)<<endl;
	}

    return 0;
}
