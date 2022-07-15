#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Pelicula{
    int codigo;
    string titulo;
    string director;
    int espectadores;
    int fechaDeEstreno;
    };

const int cant = 5;

void addMovie(Pelicula);
void aCsv(Pelicula);

void addMovie(Pelicula peliculas[cant]){
    Pelicula p;
    for(int c=0; c<cant; c++){
        cout<<"Pelicula Nro. "<<c+1<<":"<<endl;
        cout<<"Codigo: ";
        cin>>p.codigo;
        cin.ignore(); //Limpia el buffer para poder ingresar string;
        cout<<"Titulo: ";
        getline(cin, p.titulo);
        cout<<"Director: ";
        getline(cin, p.director);
        cout<<"Numero de espectadores: ";
        cin>>p.espectadores;
        cout<<"Fecha de estreno (aaaammdd): ";
        cin>>p.fechaDeEstreno;
        peliculas[c]=p;
    }
}

void aCsv(Pelicula peliculas[]){
    FILE *f1;
    f1 = fopen("peliculas.csv", "w");
    for(int c=0; c<cant; c++){
        fprintf(f1,"%d,%s,%s,%d,%d\n",peliculas[c].codigo,peliculas[c].titulo,peliculas[c].director,peliculas[c].espectadores,peliculas[c].fechaDeEstreno);
    }
    fclose(f1);
    cout<<"Datos transferidos a peliculas.csv con exito"<<endl;
}

int main()
{
    Pelicula peliculas[cant];
    addMovie(peliculas);
    aCsv(peliculas);
    cout<<endl<<"Archivo de texto creado."<<endl;
    return 0;
}

