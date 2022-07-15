#include <iostream>
#include <string>

using namespace std;

const int CANT = 10;

struct Pelicula{
    int codigo;
    string titulo;
    string director;
    int espectadores;
    int fechaDeEstreno;
    };

void cargarPeliculas(Pelicula, int&);
void listarEnCartel(Pelicula, int&);

void cargarPeliculas(Pelicula peliculas[CANT], int& tamLogico){
    cout<<"A continuacion debe cargar los datos de las peliculas: "<< endl;
    while (tamLogico<=CANT){
            cout<<"Pelicula Nro. "<<tamLogico+1<<":"<<endl;
            cout<<"Codigo: ";
            cin>>peliculas[tamLogico].codigo;
            cin.ignore(); //Limpia el buffer para poder ingresar string;
            cout<<"Titulo: ";
            getline(cin, peliculas[tamLogico].titulo);
            cout<<"Director: ";
            getline(cin, peliculas[tamLogico].director);
            cout<<"Numero de espectadores: ";
            cin>>peliculas[tamLogico].espectadores;
            cout<<"Fecha de estreno (aaaammdd): ";
            cin>>peliculas[tamLogico].fechaDeEstreno;
            tamLogico++;
    }
    tamLogico = 0;
    }

void listarEnCartel(Pelicula peliculas[CANT], int& tamLogico){
    cout<<"Peliculas estrenadas en cartelera: "<<endl;
    while (tamLogico<=CANT){
        if (peliculas[tamLogico].fechaDeEstreno!=0){
            cout<<"Titulo"<<peliculas[tamLogico].titulo<<endl;
            cout<<"Cant. de espectadores: "<<peliculas[tamLogico].espectadores<<endl<<endl;
        }
        tamLogico++;
    }
}

int main()
{
    int tamLogico = 0;
    Pelicula peliculas[CANT];
    cargarPeliculas(peliculas, tamLogico);
    listarEnCartel(peliculas, tamLogico);
    return 0;
}
