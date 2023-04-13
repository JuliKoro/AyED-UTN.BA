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
    Nodo<string>* p = NULL;
    string url;
    int menu = -1;
    while(menu != 0){
        cout<<"Elija una de las opciones: "<<endl;
        cout<<"1- Nueva direccion."<<endl;
        cout<<"2- Atras."<<endl;
        cout<<"0- Salir."<<endl;
        cin>>menu;
        switch(menu){
            case 1:
                cin>>url;
                push(p, url);
                break;
            case 2:
                if(empty(p)==1) cout<<"Pila vacia."<<endl;
                else cout<<pop(p)<<endl;
                break;
            case 0:
                break;
            default:
                cout<<"Introduzca una de las opciones del menu, por favor."<<endl;
        }
    }
    cout<<"Adios!"<<endl;
    return 0;
}
