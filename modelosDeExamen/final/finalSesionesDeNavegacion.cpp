//Sesiones de navegacion - FINAL
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

struct Pagina{
	string url;
	long fechaHora;
};

struct Historial{
	Pagina info;
	Historial* sig;
};

struct Sesion{
	int id, codNav;
	long fechaHoraInicio, fechaHoraFin;
	Historial* hist;
};

struct Nodo{
	Sesion info;
	Nodo* sig;
};

struct Informe{
	string fechaInforme;
	int cantSes, cantPagNav, cantSesXCodNav[5];
	long durProSes; 
};

void agregar(Nodo* &p, Sesion s){
	Nodo* nuevo = new Nodo();
	nuevo->info = s;
	nuevo->sig = NULL;
	if(p == NULL) p = nuevo;
	else{
		Nodo* aux = p;
		while(aux->sig != NULL) aux = aux->sig;
		aux->sig = nuevo;
	}
}

Nodo* buscar(Nodo* p, int v){
	Nodo* aux = p;
	while(aux != NULL && aux->info.id != v) aux = aux->sig;
	return aux;
}

int tamanio(Nodo* &p){
	Nodo* aux = p;
	int cant = 0;
	while(aux != NULL){
		cant++;
		aux = aux->sig;
	}
	return cant;
}

void push(Historial* &p, Pagina v){
	Historial* nuevo = new Historial();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
}

Pagina pop(Historial* &p){
	Historial* aux = p;
	Pagina x = aux->info;
	p = aux->sig;
	delete aux;
	return x;
}

int tamPila(Historial* p){
	Historial* aux = p;
	int cant = 0;
	while(aux != NULL){
		cant++;
		aux = aux->sig;
	}
	return cant;
}

long ahora(){
	return time(NULL);
}

string fecha(time_t t){
  struct tm *tm;
  char hoy[100];
  tm=localtime(&t);
  strftime(hoy, 100, "%d%m%Y", tm);
  string fecha(hoy);
  return fecha;
}

long diferencia(long inicio, long final){
	return final-inicio;
}

void agregarPagina(Nodo* &p, int idSes, int codNav, string url){
	Nodo* aux = buscar(p, idSes);
	if(aux == NULL) {
		Sesion nueva;
		nueva.id = idSes;
		nueva.codNav = codNav;
		nueva.fechaHoraInicio = ahora();
		agregar(p,nueva);
		aux = p;
		cout<<"Sesion creada."<<endl;
	}
	Pagina web;
	web.fechaHora = ahora();
	web.url = url;
	Historial* hist = aux->info.hist;
	push(hist,web);
	aux->info.fechaHoraFin = ahora();
	cout<<"Pagina agregada."<<endl;
}

string obtenerUltimaPagina(Nodo* &p, int idSes){
	Nodo* aux = buscar(p, idSes);
	if(aux != NULL){
		Pagina elim = pop(aux->info.hist);
		aux->info.fechaHoraFin = ahora();
		return elim.url;
	}else cout<<"ID de sesion no encontrada."<<endl;
}

long promSes(Nodo* p){
	Nodo* aux = p;
	long inicio = 0, final = 0, dif, prom;
	while(aux != NULL){
		inicio = aux->info.fechaHoraInicio + inicio;
		final = aux->info.fechaHoraFin + final;
		aux = aux->sig; 
	}
	dif = diferencia(inicio, final);
	prom = dif / tamanio(p);
	return prom;
}

int cantPag(Nodo* p){
	Nodo* aux = p;
	int pags = 0;
	while(aux != NULL){
		pags = pags + tamPila(aux->info.hist);
		aux = aux->sig;
	}
	return pags;
}

int cantSesXNav(Nodo* p, int v){
	Nodo* aux = p;
	int cant = 0;
	while(aux != NULL && aux->info.codNav == v){
		cant++;
		aux = aux->sig;
	}
	return cant;
}

void crearInforme(Nodo* p, FILE* f){
	Informe i;
	time_t t = ahora();
	i.fechaInforme = fecha(t);
	i.cantSes = tamanio(p);
	i.durProSes = promSes(p);
	i.cantPagNav = cantPag(p);
	for(int c=0; c<5; c++) i.cantSesXCodNav[c] = cantSesXNav(p,c);
	fwrite(&i, sizeof(Informe),1,f);
	fclose(f);
	cout<<"Informe creado."<<endl;
}

int main(){
	Nodo* p = NULL;
	int m = 5, idS, codNav;
	string url;
	while(m != 0){
		cout<<"Elija que desee hacer: "<<endl;
		cout<<"1. Agregar una pagina."<<endl;
		cout<<"2. Obtener ultima pagina."<<endl;
		cout<<"3. Crear informe."<<endl;
		cout<<"0. Salir."<<endl;
		cin>>m;
		switch(m){
			case 1: 
				cout<<"Ingrese ID de sesion: ";
				cin>>idS;
				cout<<"Ingrese el codigo de navegador: "<<endl;
				cout<<" 0 - Chrome \n 1 - Firefox \n 2 - Safari \n 3 - IE/Edge \n 4 - Otro \n Codigo: ";
				cin>>codNav;
				cout<<"Ingrese la URL de la pagina web: "<<endl;
				cin>>url;
				agregarPagina(p,idS,codNav,url);
				break;
			case 2:
				cout<<"Ingrese ID de sesion: ";
				cin>>idS;
				cout<<"Ultima pagina visitada: "<<obtenerUltimaPagina(p,idS);
				break;
			case 3:{
				FILE* f = fopen("Informe.dat", "wb+");
				crearInforme(p,f);
				break;
			}
			case 0:
				cout<<"Hasta la proxima!"<<endl;
				break;
			default:
				cout<<"Ingrese un valor correcto."<<endl;
		}
	}
	system("pause");
	return 0;
}
