//Pilas de Contenedores - FINAL 03.10.18

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

const int N = 10;

struct Nodo{
	int info;
	Nodo* sig;
};

struct Ternas{
	int i, j, k;
};

Nodo* p[N] = {NULL};

void push(Nodo* &p, int v){
	Nodo* aux = new Nodo();
	aux->info = v;
	aux->sig = p;
	p = aux;
}

int pop(Nodo* &p){
	int x;
	Nodo* aux = p;
	x = aux->info;
	p = aux->sig;
	delete aux;
	return x;
}

/*void leerArchivo(Ternas &t[N]){
	FILE f* = fopen("Ternas.dat","rb");
	int cont = 0;
	fread(%terna[cont],sizeof(Ternas),1,f);
	while(!feof){
		cont++;
		fread(&terna[cont],sizeof(Terna),1,f);
	}
	fclose(f);
}*/

void ingresoTerna(Ternas &t){
	cout<<"Ingrese dato 'i': ";
	cin>>t.i;
	cout<<"Ingrese dato 'j': ";
	cin>>t.j;
	cout<<"Ingrese dato 'k': ";
	cin>>t.k;
}

void agregarElementoAPila(int i, int j){
	push(p[abs(i)],j);
	cout<<"Elemento '"<<j<<"' agregado a la Pila "<<abs(i)<<endl;
}

void eliminarElementoDePila(int i, int j){
	Nodo* aux;
	int elim = pop(p[abs(i)]);
	while (elim != j) {
		push(aux,elim);
		elim = pop(p[abs(i)]);
	}
	elim = pop(aux);
	while (aux->sig == NULL) push(p[abs(i)],elim);
	cout<<"Eliminado el elemento '"<<j<<"' de la Pila "<<abs(i)<<endl;
}

void eliminar(int i){
	while(p[abs(i)]->sig != NULL) {
		pop(p[abs(i)]);
		p[abs(i)] = p[abs(i)]->sig;
	}
	cout<<"Eliminados todos los nodos de la Pila "<<abs(i)<<endl;
}

int main(){
	//Ternas terna[N];
	//leerArchivo(terna);
	Ternas t;
	int m = 1;
	while(m!=0){
		ingresoTerna(t);
		if(t.k == 0){ //Elimina todos los nodos de la pila i
			eliminar(t.i);
		} else if(t.k == -1){
			if(t.i > 0) agregarElementoAPila(t.i,t.j); //Agrega el elemento j a la pila i
			else if(t.i < 0) eliminarElementoDePila(t.i,t.j); //Elimina el elemento j de la pila i
		}
		cout<<"Quiere ingresar otro conjunto de ternas?"<<endl;
		cout<<"1. Si."<<endl<<"0. No."<<endl;
		cin>>m;
}
	system("pause");
	return 0;
}
