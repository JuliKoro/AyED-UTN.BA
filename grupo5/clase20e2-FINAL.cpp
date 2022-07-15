//Observacion: Excelente

#include<iostream>
#include <string>

using namespace std;
using std::string;

struct Canal {
    int id;
    string url;
    int vel;
};

struct Nodo {
    Canal info;
    Nodo * sig;
};


void eliminar(Nodo * & p, int v) {
    Nodo * aux = p;
    Nodo * ant = NULL;
    while (aux != NULL && aux -> info.vel >= v) {
        ant = aux;
        aux = aux -> sig;
    }
    if (ant != NULL) {
        ant -> sig = aux -> sig;
    } else {
        p = aux -> sig;
    }
    delete aux;
}

Nodo * insertarOrdenado(Nodo * & p, Canal v) {
    Nodo * nuevo = new Nodo();
    nuevo -> info = v;
    nuevo -> sig = NULL;
    Nodo * ant = NULL;
    Nodo * aux = p;
    while (aux != NULL && aux -> info.id <= v.id) {
        ant = aux;
        aux = aux -> sig;
    }

    if (ant == NULL) {
        p = nuevo;
    } else {
        ant -> sig = nuevo;
    }

    nuevo -> sig = aux;
    return nuevo;
}

Canal eliminarPrimerNodo(Nodo * & p) {
    Canal ret = p -> info;
    Nodo * aux = p;
    p = p -> sig;
    delete aux;
    return ret;
}

Nodo * ordenar(Nodo * & p) {
    Nodo * q = NULL;
    while (p != NULL) {
        Canal v = eliminarPrimerNodo(p);
        insertarOrdenado(q, v);
    }
    p = q;
    return p;
}

int canalesInferiores(Nodo* p){
	int f = 0;
	while(p != NULL){
		if(p -> info.vel < 5){
			f++;
		}
		p = p -> sig;
	}
	return f;
}

void eliminarCalidad(Nodo * & p) {
	int f = canalesInferiores(p);
	for(int i = 0; i<f; i++){
		eliminar(p, 5);
	}
	cout<<"Canales eliminados.\n"<<endl;
}

Nodo * buscarID(Nodo * & p, int v) {
    Nodo * aux = p;
    while (aux != NULL && aux -> info.id != v) {
        aux = aux -> sig;
    }
    return aux;
}

void mostrar(Nodo * & p) {
    Nodo * aux = p;
    while (aux != NULL) {
        cout << aux -> info.id << " ";
        cout << aux -> info.url << " ";
        cout << aux -> info.vel << endl;
        aux = aux -> sig;
    }
}

Canal crearCanal(int id, string url, int vel) {
    Canal c;
    c.id = id;
    c.url = url;
    c.vel = vel;
    return c;
}

void agregarCanal(Nodo * & p, Canal x) {
    Nodo * nuevo = new Nodo();
    nuevo -> info = x;
    nuevo -> sig = NULL;
    if (p == NULL) {
      p = nuevo;
    } else {
      Nodo * aux = p;
      while (aux -> sig != NULL) {
        aux = aux -> sig;
      }
      aux -> sig = nuevo;
    }
}

Nodo * importarFuentes(Nodo * & p, Nodo * & q) {
	Nodo * fusion = NULL;
	while (p != NULL && q != NULL) {
		if (p -> info.id <= q -> info.id) {
			agregarCanal(fusion, p -> info);
			p = p -> sig;
		} else {
			agregarCanal(fusion, q -> info);
			q = q -> sig;
		}	
	}
	while (p != NULL) {
		agregarCanal(fusion, p -> info);
		p = p -> sig;
	}
	while (q != NULL) {
		agregarCanal(fusion, q -> info);
		q = q -> sig;
	}
	return fusion;
}

int main() {
    int menu = 5;
    Nodo * p = NULL; //lista A
    Nodo * q = NULL;  // Lista D
    Nodo * nodito = NULL;  // para b�squeda
    Nodo * fusion = NULL;
    int id;
    while (menu != 0) {
        cout << "Elija la opcion que desee: " << endl;
        cout << "1. Agregar canales ordenados por ID." << endl;
        cout << "2. Eliminar canales cuya velocidad sea inferior a 5." << endl;
        cout << "3. Buscar un canal por ID ." << endl;
        cout << "4. Listar todos los canales de la lista." << endl;
        cout << "5. Importar lista complementaria" << endl;
        cout << "0. Salir." << endl;
        cin >> menu;
        switch (menu) {
        case 1:
            agregarCanal(p, crearCanal(22, "http://youtv.com/channel22", 15));
            agregarCanal(p, crearCanal(12, "http://vivideo.tv/canal12", 67));
            agregarCanal(p, crearCanal(77, "https://localtv.us/stream/news", 4));
            agregarCanal(p, crearCanal(4, "http://movies.tv/drama", 0));
            agregarCanal(p, crearCanal(87, "https://news.tv/rumania", 127));
            ordenar(p);
            break;
        case 2:
            eliminarCalidad(p);
            break;
        case 3:
            cin >> id;
            nodito = buscarID(p, id);
            cout << nodito -> info.url << endl;
            cout << nodito -> info.vel << endl;
            break;
        case 4:
            mostrar(p);
            break;
        case 5:
			agregarCanal(q, crearCanal(28, "http://noticiasdelmundo.tv/canal28", 55));
			agregarCanal(q, crearCanal(8, "https://livetv.com/channel8", 23));
			agregarCanal(q, crearCanal(51, "http://sports.tv/football", 89));
			agregarCanal(q, crearCanal(112, "https://livenews.tv/newzeland", 3));
			agregarCanal(q, crearCanal(54, "http://maspelis.com/comedia", 0));
			agregarCanal(q, crearCanal(99, "https://technews.tv/mobileworld", 56));
	    	eliminarCalidad(p);
        	eliminarCalidad(q);
        	fusion = importarFuentes(p,q);
			ordenar(fusion);
			mostrar(fusion);
        }
    }
}
