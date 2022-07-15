#include <iostream>

using namespace std;

template <typename T> struct Nodo {
	T info;
	Nodo<T>* sig;
};

template <typename T> void liberar(Nodo<T>*& p) { // Libera la memoria que ocupa la lista
	Nodo<T>* aux;
		while( p!=NULL ) {
			aux = p;
			p = p->sig;
			delete aux;
		}
}

template <typename T> Nodo<T>* insertarOrdenado(Nodo<T>*& l, T v, int (*criterio)(T,T) ) { //Inserta un Nodo manteniendo el orden
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo->info = v;
	nuevo->sig = NULL;
	Nodo<T>* aux = l;
	Nodo<T>* ant = NULL;
	while( aux!=NULL && criterio(aux->info,v)<=0 ) {
		ant = aux;
		aux = aux->sig;
	}
	if( ant==NULL ) {
		l = nuevo;
	} else {
		ant->sig = nuevo;
	}
	nuevo->sig = aux;
	return nuevo;
}

struct Alumno {
	int leg;
	string nom;
};

Alumno crearAlumno(int leg, string nom) {
	Alumno a;
	a.leg = leg;
	a.nom = nom;
	return a;
}

int criLeg(Alumno a1, Alumno a2) { //Criterio09
	return a1.leg-a2.leg;
}

int criNom(Alumno a1, Alumno a2) { //CriterioAZ
	return a1.nom<a2.nom?-1:a1.nom>a2.nom?1:0;
}

template <typename T> Nodo<T>* buscarEnLista(Nodo<T>*l, T v, int(*criterio)(T,T)) { 
	Nodo<T>* aux = l;
	while(aux!=NULL&&criterio(aux->info,v)!=0) {
		aux = aux -> sig;
	}
	return aux;
}

int main() { // programa principal
	Alumno a, b, c;
	Nodo<Alumno>* p = NULL;

	a = crearAlumno(40,"Ariel");
	b = crearAlumno(30,"Juan");
	c = crearAlumno(35,"Pablo");

	insertarOrdenado<Alumno>(p,a,criLeg); // inserto ordenado por legajo
	insertarOrdenado<Alumno>(p,b,criLeg);
	insertarOrdenado<Alumno>(p,c,criLeg);
	int a = NULL;
	Nodo<Alumno>* aux = p;

	cout << "Lista ordenada por numero de legajo:" << endl;
	while( aux!=NULL ) {
		cout << aux->info.leg << ", " << aux->info.nom << endl;
		aux=aux->sig;
	}
	/*
		liberar<Alumno>(p);

		p = NULL;
		a = crearAlumno(30,"Juan");
		b = crearAlumno(40,"Ariel");
		c = crearAlumno(50,"Pedro");
		insertarOrdenado<Alumno>(p,a,criNom); // ahora inserta ordenado por nombre
		insertarOrdenado<Alumno>(p,b,criNom);

		aux = p;
		cout << "Lista ordenada por nombre:" << endl;
		while( aux!=NULL ) {
			cout << aux->info.leg << ", " << aux->info.nom << endl;
			aux=aux->sig;
		}
		*/
	Nodo<Alumno>* res = buscarEnLista<Alumno>(p,b,criNom);

	if(res!=NULL) {
		cout<<"Encontrado!";
	}

	liberar<Alumno>(p);

	return 0;
}
