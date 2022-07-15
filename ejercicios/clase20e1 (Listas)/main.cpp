#include <iostream>
#include <string>

using namespace std;

struct Canal {
    int id;
    string url;
    int mbps;
};

struct Nodo {
    Canal info;
    Nodo* sig;
};

Canal crearCanal(int id, string url, int mbps){
    Canal c;
    c.id = id;
    c.url = url;
    c.mbps = mbps;
    return c;
    }

void agregarNodo(Nodo* &p, Canal x) {
    Nodo* nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sig = NULL;
    if( p==NULL ) {
        p = nuevo;
    } else {
        Nodo* aux = p;
        while(aux->sig!=NULL ) {
            aux = aux->sig;
        }
    aux->sig = nuevo;
    }
}

void eliminar(Nodo*& p, int v) {
    Nodo* aux = p;
    Nodo* ant = NULL;
    while( aux != NULL && aux->info.mbps >= v ) {
        ant = aux;
        aux = aux->sig;
    }
    if( ant!=NULL ) {
        ant->sig = aux->sig;
    } else {
        p = aux->sig;
    }
    delete aux;
}

Nodo* buscar(Nodo*& p, int v) {
    Nodo* aux = p;
    while( aux != NULL && aux->info.id != v ) {
        aux=aux->sig;
    }
    return aux;
}

Canal eliminarPrimerNodo(Nodo*& p) {
    Canal ret = p->info;
    Nodo* aux = p;
    p = p->sig;
    delete aux;
    return ret;
}

Nodo* insertarOrdenado(Nodo*& p, Canal v) {
    Nodo* nuevo = new Nodo();
    nuevo->info = v;
    nuevo->sig = NULL;
    Nodo* ant = NULL;
    Nodo* aux = p;
    while(aux!=NULL && aux->info.id<=v.id) {
        ant = aux;
        aux = aux->sig;
    }
    if(ant==NULL) {
        p = nuevo;
    } else {
        ant->sig = nuevo;
    }
    nuevo->sig = aux;
    return nuevo;
}

Nodo* ordenar(Nodo*& p) {
    Nodo* q = NULL;
    while(p!=NULL) {
        Canal v = eliminarPrimerNodo(p);
        insertarOrdenado(q,v);
    }
    p = q;
    return p;
}

void mostrar(Nodo*& p) {
    Nodo* aux = p;
    while( aux!=NULL ) {
        cout << "ID: " << aux->info.id << endl;
        cout << "URL: " << aux->info.url << endl;
        cout << "Velocidad: " << aux->info.mbps << " Mbps" << endl << endl;
        aux = aux->sig;
    }
}

int canalesInferiores(Nodo* p){ //No paso la lista por referencia
    int f = 0;
    while(p != NULL){
        if(p->info.mbps < 5){
            f++;
        }
        p = p->sig;
    }
    return f;
}

void eliminarCanales(Nodo* &p){
    int f = canalesInferiores(p);
    for (int i = 0; i < f; i++){
        eliminar(p, 5);
    }
}

int main(){
    Nodo* p = NULL; //Creo Lista
    Nodo* nodito = NULL;
    int menu = -1, idBusq;
    while(menu != 0){
        cout<<"Elija la opcion que desee realizar:"<<endl;
        cout<<"1. Agregar canales ordenados por ID."<<endl;
        cout<<"2. Eliminar canales cuya velocidad sea inferior a 5."<<endl;
        cout<<"3. Buscar un canal por ID."<<endl;
        cout<<"4. Listar todos los canales de la lista."<<endl;
        cout<<"0. Salir."<<endl;
        cin>>menu;
        switch(menu){
            case 1:
                agregarNodo(p, crearCanal(22,"http://youtv.com/channel22",15));
                agregarNodo(p, crearCanal(12,"http://vivideo.tv/canal12",67));
                agregarNodo(p, crearCanal(77,"https://localtv.us/stream/news",4));
                agregarNodo(p, crearCanal(4,"http://movies.tv/drama",0));
                agregarNodo(p, crearCanal(87,"https://news.tv/rumania",127));
                ordenar(p);
                break;
            case 2:
                eliminarCanales(p);
                cout<<"Canales eliminados."<<endl<<endl;
                break;
            case 3:
                cout<< "Ingrese ID que desea buscar: ";
                cin>>idBusq;
                nodito = buscar(p, idBusq);
                if (nodito != NULL){
                    cout<<"URL: "<<nodito->info.url<<endl;
                    cout<<"Velocidad: "<<nodito->info.mbps<<" Mbps"<<endl;
                }else{
                    cout<<"Canal no encontrado."<<endl;
                }
                break;
            case 4:
                mostrar(p);
                break;
            case 0:
                break;
            default:
                cout<<"Ingrese una opcion correcta, por favor."<<endl;
        }
    }
    cout<<endl<<"Adios!"<<endl;
    return 0;
}
