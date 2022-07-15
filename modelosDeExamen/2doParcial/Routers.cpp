#include<iostream>
using namespace std;
struct comando{
	int id;
	int sec;
	char router[25];
};
struct Nodo{
	comando info;
	Nodo* sig;
};

void configurar(Nodo*&, FILE*, comando);
void mostrar(Nodo*&);
Nodo* insertaOrdenado(Nodo*& , comando);
Nodo* array[10]={NULL};//No se si declarar antes del int main ,o dentro del mismo.
int i=0;//Tampoco se bien dónde declarar el i.

int main(){
	int id;
	Nodo* array[10]={NULL};
	Nodo* p=NULL;
	int i=0;

	FILE* f=fopen("comandos.dat", "rb");
	comando c;
	fread(&c, sizeof(c), 1,f);
	configurar(array[i], f, c);
	p=array[0];//No puedo lograr mostrar el ejercicio por pantalla.
	mostrar(p);//
	return 0;
}

void configurar (Nodo*& p, FILE* f, comando c){
	while(!feof){
		insertaOrdenado(array[c.id], c);
	}
	fread(&c, sizeof(c), 1,f);
}

Nodo* insertaOrdenado(Nodo*& p, comando v){
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig=NULL;
	Nodo* aux=p;
	Nodo*ant=NULL;
	while(aux!=NULL && aux->info.sec<=v.sec){
		ant=aux;
		aux=aux->sig;
	}
	if (ant==NULL){
		p=nuevo;
	}else{
		ant->sig=nuevo;
	}
	nuevo->sig=aux;
	return nuevo;
}

void mostrar(Nodo* p){//Función para mostrar el ejercicio por pantalla.
	comando com;
	for(int i=0;i<10;i++){
		p = array[i];
		com=array[i]->info;
		cout<<"id Router"<< i <<endl;
		while (p->sig!=NULL){
			cout<<"comando"<<com.router<<endl;
			cout<<"Secuencia"<< com.sec<<endl;
		p=p->sig;
		}
	}
}
