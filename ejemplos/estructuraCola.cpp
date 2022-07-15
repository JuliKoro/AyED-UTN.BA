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
	if( p==NULL ) {
 		p = nuevo;
	} else {
 		q->sig = nuevo;
	}
 	q = nuevo;
}

template <typename T> T suprimir(Nodo<T>*& p, Nodo<T>*& q) {
	T ret = p->info;
	Nodo<T>* aux = p;
	p = p->sig;
	if( p == NULL) {
		q = NULL;
	}
	delete aux;
	return ret;
}

template <typename T> T frente(Nodo<T>*p){
	return p->info;
}

int tamanio(Nodo<int>* p){
	int cant = 0;
	while(p!=NULL){
		p = p -> sig;
		cant++;
	}
	return cant;
}

bool vacia(Nodo<int> *p){
	return p==NULL?true:false;
}

int main(){
	Nodo<int>* p = NULL;
 	Nodo<int>* q = NULL;
 	agregar(p,q,1);
 	agregar(p,q,2);
 	agregar(p,q,3);
 	cout<<"Cantidad de elementos en la cola: "<<tamanio(p)<<endl;
 	cout << suprimir(p,q) << endl;
 	cout << suprimir(p,q) << endl;
 	agregar(p,q,4);
 	agregar(p,q,5);
 	cout<<"Elemento al frente de la cola: "<<frente(p)<<endl;
 	while( p!=NULL ){
 		cout << suprimir(p,q) << endl;
 	}
 	cout<<"La cola esta vacia?"<<endl;
 	if(vacia(p)==true) cout<<"Si."<<endl;
 	else cout<<"No."<<endl;
 	return 0;
}
