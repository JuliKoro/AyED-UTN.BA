//Observacion: Esta excelente

#include <iostream>
#include <math.h>
using namespace std;


struct Paquete {
	int dato;
	bool ap;
};

template <typename T> 
struct Nodo {
	T info;
	Nodo<T>* sig;	
};

template <typename T> 
void agregar (Nodo<T>*&p, Nodo<T>*&q, T v){
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo -> info = v;
	nuevo -> sig = NULL;
	if (p==NULL){
		p = nuevo;
	} else {
		q ->sig = nuevo;
	}
	q = nuevo;
}

template <typename T> 
T suprimir (Nodo<T>*&p, Nodo<T>*&q){
	T ret = p -> info;
	Nodo<T>* aux = p;
	p= aux -> sig;
	if( p==NULL){
		q=NULL;
	}
	delete aux;
	return ret;
}

template <typename T> 
void push (Nodo<T>*&p, T v){
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo -> info = v;
	nuevo -> sig = p;
	p = nuevo;
}

template <typename T, typename K>
void procesar (Nodo<T>* &p, Nodo<T>* &q, Nodo<K>* &t, Nodo<K>* &s, Nodo<K>* &r){
	while (p!=NULL){
		Paquete paque = suprimir<T>(p,q);
		paque.dato = abs(paque.dato);
		if (paque.ap == true){
			push<K>(r, paque.dato);
		} else {
			agregar<K>(s, t, paque.dato);
		}
	}
}

Paquete crearPaquete(int dato, bool ap){
	Paquete p;
	p.dato = dato;
	p.ap = ap;
	return p;
}

template <typename T>
T pop(Nodo<T>* &p){
	T x;
	Nodo<T>* aux = p;
	x = aux->info;
	p = aux->sig;
	delete aux;
	return x;
}

int main(){
	Nodo<Paquete>* p=NULL;
	Nodo<Paquete>* q=NULL;
	Nodo<int>* t=NULL;
	Nodo<int>* s=NULL;
	Nodo<int>*  r=NULL;
	
	agregar(p,q,crearPaquete(1555,0));
	agregar(p,q,crearPaquete(146,1));
	agregar(p,q,crearPaquete(552,0));
	agregar(p,q,crearPaquete(244,1));
	agregar(p,q,crearPaquete(-30,0));
	agregar(p,q,crearPaquete(15,1));
	agregar(p,q,crearPaquete(256,0));
	
	procesar<Paquete,int>(p, q, t, s, r);
	
	cout << "Alta prioridad: " << endl;
	while (r != NULL) {
		cout << pop<int>(r) << endl;
	}
	cout << "Buffer FIFO de salida: " << endl;
	while (t != NULL && s != NULL) {
	    cout << suprimir(s, t) << endl;
	} 
}
