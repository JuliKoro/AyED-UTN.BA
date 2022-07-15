#include <iostream>

using namespace std;

struct Elem {
    int dato;
};

struct Nodo {
    Elem elem;
    Nodo* ant;
    Nodo* sig;
};

void agregar(Nodo* ultimo, Elem e) {
    Nodo* nuevo = new Nodo;
    nuevo->elem = e;
    nuevo->sig = ultimo;
    nuevo->ant = ultimo->ant;
    Nodo* ant = ultimo->ant;
    ultimo->ant = nuevo;
    ant->sig = nuevo;
}

void eliminar(Nodo* objetivo) {
    Nodo* pre = objetivo->ant;
    Nodo* pro = objetivo->sig;
    pre->sig = pro;
    pro->ant = pre;
    delete objetivo;
}

void mostrar (Nodo* cabecera){
    while(cabecera->sig != NULL){
        cout<<cabecera->elem.dato<<endl;
        cabecera = cabecera->sig;
    }
}

bool vacia (Nodo* cabecera){
    if(cabecera->sig == NULL) return true;
    else return false;
}

int frente (Nodo* cabecera){
    return cabecera->sig->elem.dato;
}

void insertar (Nodo* cabecera, Elem e){
    Nodo* nuevo = new Nodo();
    nuevo->elem = e;
    while(cabecera->sig != NULL && cabecera->elem.dato <= e.dato){
        nuevo->sig = cabecera->sig;
        cabecera = cabecera->sig;
    }
    cabecera->ant = nuevo;
    nuevo->sig = cabecera;
    cabecera->ant->sig = nuevo;
    nuevo->ant = cabecera->ant;
}

int main()
{
//Inicializacion
    Nodo* primero = new Nodo; //cabecera
    primero -> ant = NULL;
    Nodo* ultimo = new Nodo;
    ultimo -> sig = NULL;
    primero->sig = ultimo;
    ultimo->ant = primero;
//Agregar elementos
    Elem e;
    Nodo* obj = new Nodo;
    e.dato = 1;
    agregar(ultimo,e);
    Elem e2;
    e2.dato = 2;
    agregar(ultimo,e2);
    Elem e3;
    e3.dato = 3;
    agregar(ultimo,e3);
    cout<<"Elementos agregados."<<endl<<endl;
    cout<<"Frente de la lista doble: "<<frente(primero)<<endl<<endl;
    cout<<"Ingrese nro. que elemento eliminar: ";
    cin>>obj->elem.dato;
    eliminar(obj);
    cout<<"Elemento eliminado."<<endl<<endl;
    cout<<"Mostrando todos los elementos: "<<endl;
    mostrar(primero);
    cout<<endl;
    cout<<"La lista doble esta vacia? ";
    if (vacia(primero) == true) cout<<"Si."<<endl<<endl;
    else cout<<"No."<<endl<<endl;
    cout<<"Ingrese 3 numeros para insertar de forma ordenada: "<<endl;
    cin>>e.dato;
    insertar(primero, e);
    cin>>e2.dato;
    insertar(primero, e2);
    cin>>e3.dato;
    insertar(primero, e3);
    cout<<endl<<"Mostrando datos: "<<endl;
    mostrar(primero);
    return 0;
}
