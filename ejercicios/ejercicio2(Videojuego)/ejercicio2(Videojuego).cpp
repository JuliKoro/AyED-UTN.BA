#include <iostream>
#include <string>

using namespace std;

struct Auto{
    string nom;
    string rutaIm;
    int vel;
    float ac;
    float peso;
    float cofAd;
};

struct Nodo{
    Auto info;
    Nodo* ant;
    Nodo* sig;
};

void agregar(Nodo* u, Auto a){
    Nodo* nuevo = new Nodo();
    nuevo->info = a;
    nuevo->sig = u;
    Nodo* ant = u->ant;
    ant->sig =  nuevo;
}

void crearAuto(Nodo* &u, string nom, string ruta, int vel, float ac, float peso, float cofAd){
    Auto a;
    a.nom = nom;
    a.rutaIm = ruta;
    a.vel = vel;
    a.ac = ac;
    a.peso = peso;
    a.cofAd = cofAd;
    agregar(u,a);
}

bool mostrarIzqDer(Nodo* cabecera){
    if (cabecera->ant == NULL) return true;
    else return false;
}

bool mostrarDerIzq(Nodo* trailer){
    if (trailer->sig == NULL) return true;
    else return false;
}

void mostrar(Nodo* cabecera, Nodo* trailer, Nodo* (*sentido)(Nodo*)){
    if(sentido(cabecera))

    while(cabecera->sig != NULL){
        cout<<"Auto: "<<cabecera->info.nom<<endl;
        cout<<"Imagen: "<<cabecera->info.rutaIm<<endl;
        cout<<"Velocidad: "<<cabecera->info.vel<<" Km/h"<<endl;
        cout<<"Aceleracion: "<<cabecera->info.ac<<" m/s2"<<endl;
        cout<<"Peso: "<<cabecera->info.peso<<" Kg."<<endl;
        cout<<"Coeficiente aerodinamico: "<<cabecera->info.cofAd<<endl;
        cabecera = cabecera->sig;
    }
}

void insertar(Nodo* cabecera, Auto a){
    Nodo* nuevo = new Nodo();
    nuevo->info = a;
    while (nuevo->sig!=NULL){
        nuevo = cabecera->sig;
        cabecera = cabecera->sig;
    }
    cabecera->ant = nuevo;
    nuevo->sig = cabecera;
    cabecera->ant->sig = nuevo;
    nuevo->ant = cabecera->ant;
}

Nodo* irA(Nodo* &p, string nom){
    Nodo* aux = p;
    while(aux!=NULL && aux->info.nom!=nom){
        aux=aux->sig;
    }
    return aux;
}

int main()
{
    Nodo* p = new Nodo();
    p->ant=NULL;
    Nodo* u = new Nodo();
    u->sig = NULL;
    p->sig = u;
    u->ant = p; //Inicializacion

    crearAuto(u,"Pagani","img.png",350,150.56,780.5,2.3);
    crearAuto(u,"Zonda","img1.png",400,182.76,980.5,3.3);
    crearAuto(u,"Fiat","img2.png",200,105.95,560.5,1.3);

    Auto nuevo;
    cout<<"Crear nuevo auto:"<<endl;
    cout<<"Nombre: ";
    cin>>nuevo.nom;
    cout<<"Ruta de imagen:";
    cin>>nuevo.rutaIm;
    cout<<"Velocidad:";
    cin>>nuevo.vel;
    cout<<"Aceleracion:";
    cin>>nuevo.ac;
    cout<<"Peso:";
    cin>>nuevo.peso;
    cout<<"Coeficiente aerodinamico:";
    cin>>nuevo.cofAd;
    insertar(p,nuevo);
    cout<<"Auto nuevo creado y agregado a la lista!\n"<<endl;

    Nodo* busq;
    string busqNom;
    cout<<"Busqueda de auto:";
    cin>>busqNom;
    busq = irA(p,busqNom);
    cout<<"Imagen: "<<busq->info.rutaIm<<endl;
    cout<<"Velocidad: "<<busq->info.vel<<" Km/h"<<endl;
    cout<<"Aceleracion: "<<busq->info.ac<<" m/s2"<<endl;
    cout<<"Peso: "<<busq->info.peso<<" Kg."<<endl;
    cout<<"Coeficiente aerodinamico: "<<busq->info.cofAd<<endl;

    return 0;
}
