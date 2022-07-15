/*
    Observacion: en la funcion aJson dentro del while el fread va luego de la impresion ya que del modo en el que lo escribieron 
                se estarian saltando el 1er registro del archivo, arreglen eso y el resto esta bien.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
using std::string;

struct Pelicula{
	int codigo;
	char titulo[25];
	char director[25];
	int espectadores;
	int fechaDeEstreno;
};

void addMovie (int &tamLogico, Pelicula peliculas[10]) {
	Pelicula p;
	string titulo, director;
	cout << "introduzca el codigo de la pelicula" << endl;
	cin >> p.codigo;
	cout << "Introduzca el titulo" << endl;
	cin >> titulo;
	cout << "Introduzca el director" << endl;
	cin >> director;
	cout << "Introduzca la cantidad de espectadores" << endl;
	cin >> p.espectadores;
	cout << "Introduzca la fecha de estreno" << endl;
	cin >> p.fechaDeEstreno;
	strcpy(p.titulo,titulo.c_str());
	strcpy(p.director,director.c_str());
	peliculas[tamLogico] = p;
	tamLogico++;
}

void removeMovie (int cod, Pelicula peliculas[10], int& tamLogico) {
	int pos = -1;
	for (int u=0; u<tamLogico;u++) {
		if (peliculas[u].codigo == cod) {
			pos = u;
		}
	}
	if (pos == -1) {
		cout << "No se encuentra una pelicula con ese codigo" << endl;		
	} else {
		for (int i=pos; i<tamLogico-1;i++) {
			peliculas[i]=peliculas[i+1];
		}
	}
	tamLogico--;
}

void listarEstrenadas(Pelicula peliculas[10], int tamLogico) {
	cout<<"Las peliculas estrenadas recientemente son: "<<endl;
	for (int i=0; i<tamLogico;i++) {
		if (peliculas[i].fechaDeEstreno != 0){
			cout <<"Titulo:"<<peliculas[i].titulo << " | Cantidad de espectadores: " << peliculas[i].espectadores << endl; 
		}
	}
}

void listarMovie(Pelicula peliculas[10], int tamLogico) {
	cout<<"Lista de todas las peliculas: "<<endl;
	for (int i=0; i<tamLogico;i++) {
		cout<<peliculas[i].titulo<<endl; 
	}
}

void save(Pelicula peliculas[], int tamLogico) {
	FILE* f = fopen("peliculas.dat","w+b");
	for(int i=0;i<tamLogico;i++){	
		fwrite(&peliculas[i],sizeof(Pelicula),1,f);
	}
    fclose(f);
    cout<<"Peliculas guardadas en Peliculas.dat"<<endl;
}

int filesize(FILE*f){
	Pelicula r;
	fseek (f,0,SEEK_END);
	return ftell(f)/sizeof (r);
}

void cargar(Pelicula peliculas[], int &tamLogico) {
	FILE* f = fopen("peliculas.dat","rb+");
	Pelicula p;
	fread(&p, sizeof(Pelicula), 1, f);
	while(!feof(f)){
		peliculas[tamLogico]=p;
		tamLogico++;
		fread(&p, sizeof(Pelicula), 1, f);
	}
    fclose(f);
    cout<<"Peliculas cargadas en Peliculas.dat exitosamente"<<endl;
}


void aCsv (Pelicula peliculas[], int tamLogico){
	FILE*F;
	F=fopen("peliculas.csv","w");
	for (int i = 0; i<tamLogico; i++){
		fprintf(F, "%d, %s, %s, %d, %8d\r", peliculas[i].codigo, peliculas[i].titulo, peliculas[i].director, peliculas[i].espectadores, peliculas[i].fechaDeEstreno);
	}
	fclose(F);
	cout<<"Datos transferidos a Peliculas.csv con exito"<<endl;
}

void aJson(){
	FILE*F=fopen("peliculas.dat","r");
	FILE*G=fopen("peliculas.json", "w");
	Pelicula p;
	fread(&p, sizeof(Pelicula), 1, F);
	fprintf(G,"{\r \"peliculas\":[\r");
	while(!feof(F)){
		fread(&p, sizeof(Pelicula), 1, F);
		fprintf(G,"{\r\t\"codigo\": \" %d \" \r, \t\"titulo\": \" %s \" \r, \t\"director\": \" %s \" \r , \t\"espectadores\": \" %d \" \r \t\"fecha-de-estreno\": \" %d \", \r }, \r { \r \t \"codigo\": \" %d \" \r, \t\"titulo\": \" %s \" \r, \t\"director\": \" %s \" \r , \t\"espectadores\": \" %d \" \r \t\"fecha-de-estreno\": \" %d \", \r }] \r }", p.codigo, p.titulo, p.director, p.espectadores, p.fechaDeEstreno);
	}
    fclose(F);
    fclose(G);
	cout<<"Datos transferidos a peliculas.json exitosamente"<<endl;
}

int main(){
	int menu = 9; 
	Pelicula peliculas[10];
	int tamLogico = 0;
	while(menu != 0){
        cout << "Elija la accion que desee realizar: " << endl;
        cout << "1. Agregar una pelicula." << endl;
        cout << "2. Eliminar una pelicula." << endl;
        cout << "3. Listar todas las peliculas. " << endl;
        cout << "4. Listar las estrenadas." << endl;
        cout << "5. Guardar (sobreescribe el archivo si ya existe)." << endl;
        cout << "6. Cargar." << endl;
        cout << "7. CSV." << endl;
        cout << "8. Json." << endl;
        cout << "0. Salir." << endl;
        cin >> menu;
        switch(menu){
            case 1:
				addMovie(tamLogico, peliculas);
                break;
            case 2:
            	int codremove;
            	cout << "ingrese el codigo de la pelicula a eliminar "<< endl;
            	cin >> codremove;
				removeMovie(codremove, peliculas, tamLogico);
                break;
            case 3:
               	listarMovie(peliculas, tamLogico);
                break;
            case 4:
                listarEstrenadas(peliculas, tamLogico);
                break;
            case 5:
            	save(peliculas, tamLogico);
            	break;
            case 6:
				cargar(peliculas, tamLogico);
				break;
            case 7:
				aCsv(peliculas, tamLogico);
				break;
            case 8:
				aJson();
				break;
            case 0:
            	break;
			default:
                cout << "Ingrese uno de los valores numericos del menu." << endl;
        }
	}
	return 0;
}



