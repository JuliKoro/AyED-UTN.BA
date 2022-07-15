#include <iostream>
#include <stdlib.h>

using namespace std;

const int tam = 10;

struct Router{
    int id;
    int sec;
    char comando[25];
};

struct Nodo {
	Router info;
	Nodo* sig;
};

int criterio09(int e1, int e2){
    return e1-e2;
}

Nodo* insertarOrdenado(Nodo*& arr, Router v, int (*criterio)(int,int) ) { //Inserta un Nodo manteniendo el orden
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	Nodo* aux = arr;
	Nodo* ant = NULL;
	while( aux!=NULL && criterio(aux->info.sec,v.sec)<=0 ) {
		ant = aux;
		aux = aux->sig;
	}
	if( ant==NULL ) {
		arr = nuevo;
	} else {
		ant->sig = nuevo;
	}
	nuevo->sig = aux;
	return nuevo;
}

void configurar(Nodo* arr[tam]){
    Router a;
    FILE* f = fopen("comandos.dat","rb");
    fread(&a, sizeof(Router), 1, f);
    while(!feof(f)){
        insertarOrdenado(arr[a.id],a,criterio09);
        fread(&a, sizeof(Router), 1, f);
    }
    fclose(f);
}

int main()
{
    Nodo* routers[tam] = {NULL};
    configurar(routers);

    return 0;
}



