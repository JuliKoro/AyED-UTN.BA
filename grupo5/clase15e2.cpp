//Observacion: esta bien pero revisen la linea en la que les puse un comentario

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
using std::string;

struct pelicula{
	int codigo;
	string titulo;
	string director;
	int espectadores;
	int fechaDeEstreno;
};

void addMovie (int &tamaniologico, pelicula peliculas[10]) {
	pelicula p;
	cout << "introduzca el codigo de la pelicula" << endl;
	cin >> p.codigo;
	cout << "Introduzca el titulo" << endl;
	cin >> p.titulo;
	cout << "Introduzca el director" << endl;
	cin >> p.director;
	cout << "Introduzca la cantidad de espectadores" << endl;
	cin >> p.espectadores;
	cout << "Introduzca la fecha de estreno" << endl;
	cin >> p.fechaDeEstreno;
	peliculas[tamaniologico] = p;
	tamaniologico++;
}

void removeMovie (int cod, pelicula peliculas[10], int& tamaniologico) {
	int pos = -1;
	for (int u=0; u<tamaniologico-1;u++) { //el -1 hace que no revise el ultimo valor de la lista, por ende si existieran 4 peliculas solo buscara entre las 3 primeras [0;2]
		if (peliculas[u].codigo ==  cod) {
			pos = u;
		}
	}
	if (pos == -1) {
		cout << "No se encuentra una pelicula con ese codigo" << endl;		
	} else {
		for (int i=pos; i<tamaniologico-1;i++) {
			peliculas[i]=peliculas[i+1];
		}
	}
	
	tamaniologico--;
}

void listarEstrenadas(pelicula peliculas[10], int tamaniologico) {
	for (int i=0; i<tamaniologico-1;i++) {
		if (peliculas[i].fechaDeEstreno != 0){
			cout << peliculas[i].titulo << ": " << peliculas[i].espectadores << endl; 
		}
	}
}

void listarMovie(pelicula peliculas[10], int tamaniologico) {
	for (int i=0; i<10-1;i++) {
		cout << peliculas[i].titulo << endl; 
	}
}

void save(pelicula peliculas[]) {
	FILE* f = fopen("peliculas.dat","w+b");
    fwrite(&peliculas, sizeof(peliculas), 1, f);
    fclose(f);
}

void cargar(pelicula peliculas[]) {
	FILE* f = fopen("peliculas.dat","rb+");
	fread(&peliculas, sizeof(peliculas), 1, f);
    fclose(f);
}

int main(){
	int menu = 0; 
	pelicula peliculas[10];
	int tamaniologico = 0;
	while(menu != 7) {
        cout << "Elija la accion que desee realizar: " << endl;
        cout << "1. Agregar una pel�cula." << endl;
        cout << "2. Eliminar una pel�cula." << endl;
        cout << "3. Listar todas las pel�culas. " << endl;
        cout << "4. Listar las estrenadas." << endl;
        cout << "5. Guardar (sobreescribe el archivo si ya existe)." << endl;
        cout << "6. Cargar." << endl;
        cout << "7. Salir." << endl;
        cin >> menu;
        switch(menu){
            case 1:
				addMovie(tamaniologico, peliculas);
                break;
            case 2:
            	int codremove;
            	cout << "ingrese el codigo de la pelicula a eliminar "<< endl;
            	cin >> codremove;
				removeMovie(codremove, peliculas, tamaniologico);
                break;
            case 3:
               	listarMovie(peliculas, tamaniologico);
                break;
            case 4:
                listarEstrenadas(peliculas, tamaniologico);
                break;
            case 5:
            	save(peliculas);
            case 6:
				cargar(peliculas);
				break;
            case 7:
            	break;
			default:
                cout << "Ingrese uno de los valores numericos del menu." << endl;
        }
	}
	return 0;
}
