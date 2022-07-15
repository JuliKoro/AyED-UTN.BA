#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
const char NOMBRE_ARCHIVO[] = "mediciones.csv";
const int CANT_CARACTERES = 14;
const int EN_ID = 0, EN_HORA = 1;

struct Medicion
{
	int id;
	int hora;
	float medicion;
	Medicion* siguiente;
};

struct Nodo
{
    int hora;
    Medicion* sublista;
    Nodo* siguiente;
};

void mostrar(Medicion* &muestra);
void leerMediciones();
Nodo* insertSortedIncreasingOrderList(Nodo* &primero, int hora, Medicion* &muestra);
Nodo* findAndInsertSortedIncreasingOrderList(Nodo* &primero, int hora, Medicion* &muestra);
Nodo* findList(Nodo* &primero, const int &hora);

void mostrar(Nodo* &primero)
{
    Nodo* aux = primero;
    cout<<endl<<endl;
    while(aux != NULL)
    {
        Medicion* muestra = aux->sublista;
        cout << "<Hora: " << muestra->hora << ">";
        while(muestra != NULL)
        {
            cout << "<ID: " << muestra->id <<"><Medicion: " << muestra->medicion << ">";
            if(muestra->siguiente != NULL) cout<<",";
            muestra = muestra->siguiente;
        }
        cout<<endl<<endl;
        aux = aux->siguiente;
    }
}

void leerMediciones()
{
	FILE *f;
	Nodo* lista = NULL;
	char cadena[CANT_CARACTERES];
	f = fopen(NOMBRE_ARCHIVO, "r");
	char* token;
	int i = 0, contador = 0;
	fgets(cadena, CANT_CARACTERES, f);
	while (!feof(f))
    {
        Medicion* muestra = new Medicion();
		cout << "Procesando linea [" << contador++ << "]" << " " << cadena;
		token = strtok(cadena, ",");
		while (token != NULL)
		{
			if(i==EN_ID) muestra->id = atoi(token);
			else if (i == EN_HORA)
            {
				string hhmm = string(token);
				string hh = hhmm.substr(0, hhmm.find(":"));
				muestra->hora = atoi(hh.c_str());
			}
			else muestra->medicion = atof(token);

			i++;
			token =strtok(NULL, ",");
		}

		muestra->siguiente = NULL;
		findAndInsertSortedIncreasingOrderList(lista,muestra->hora,muestra);
		i = 0;
		fgets(cadena, CANT_CARACTERES,f);
	}
	fclose(f);
    mostrar(lista);
}

Nodo* insertSortedIncreasingOrderList(Nodo* &primero, int hora, Medicion* &muestra)
{
    Nodo* nuevo = new Nodo();
    nuevo->hora = hora;
    nuevo->sublista = muestra;
    nuevo->siguiente = NULL;

    Nodo* anterior = NULL;
    Nodo* aux = primero;

    while((aux != NULL) && (aux->hora <= hora))
    {
        anterior = aux;
        aux = aux->siguiente;
    }

    if(anterior == NULL) primero = nuevo;
    else anterior->siguiente = nuevo;

    nuevo->siguiente=aux;

    return nuevo;
}

Nodo* findAndInsertSortedIncreasingOrderList(Nodo* &primero, int hora, Medicion* &muestra)
{
    bool encontrado;
    Nodo* nuevaLista = findList(primero,hora);
    encontrado = (nuevaLista != NULL);
    if(!encontrado) nuevaLista = insertSortedIncreasingOrderList(primero,hora,muestra);
    else
    {
        nuevaLista->sublista->siguiente = muestra;
    }
    return nuevaLista;
}

Nodo* findList(Nodo* &primero, const int &hora)
{
    Nodo* aux = primero;

    while ((aux != NULL) && (aux->hora != hora)) aux = aux->siguiente;

    return aux;
}


int main(int argc, char** argv) {

	leerMediciones();

	return 0;
}
