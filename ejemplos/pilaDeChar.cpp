#include <iostream>

using namespace std;

struct Nodo {
 char info;
 Nodo* sig;
};

void push(Nodo* &p, char v){
 Nodo* aux = new Nodo();
 aux->info = v;
 aux->sig = p;
 p = aux;
 return;
}

char pop(Nodo* &p){
 char x;
 Nodo* aux = p;
 x = aux->info;
 p = aux->sig;
 delete aux;
 return x;
}

int size(Nodo* p){
	int t = 0;
	while(p!=NULL){
	p=p->sig;
		t++;
	}
	return t;
}

bool empty(Nodo* p){
	return p==NULL?true:false;
}

int main(){
Nodo* p = NULL;
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

