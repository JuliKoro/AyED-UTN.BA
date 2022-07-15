#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

const int cant = 10;

struct Pelicula{
    int codigo;
    string titulo;
    string director;
    int espectadores;
    int fechaDeEstreno;
    };

void addMovie(int, Pelicula);
void removeMovie(int, Pelicula);
void listMovies(int, Pelicula);
void listarEstrenadas(int, Pelicula);
void save(Pelicula);
void cargar(Pelicula);

void addMovie(int &tamLogico, Pelicula peliculas[cant]){
    Pelicula p;
    if(tamLogico<=cant){
        cout<<"Pelicula Nro. "<<tamLogico+1<<":"<<endl;
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
        peliculas[tamLogico]=p;
        tamLogico++;
    } else{
        cout<<"Ha superado el limite de peliculas en el registro."<<endl;
        }
}

void removeMovie(int &tamLogico, Pelicula peliculas[cant]){
    int cod, pos = -1;
    cout<<"Ingrese el codigo de la pelicula que desea eliminar: ";
    cin>>cod;
    for(int c=0; c<tamLogico; c++){
        if (cod==peliculas[c].codigo){
            pos = c;
        }
    }
    if (pos==-1){
        cout<<"No se encontro una pelicula con ese codigo."<<endl;
    }else{
        for(int i=pos; i<tamLogico-1; i++){
            peliculas[i]=peliculas[i+1];
        }
    }
    tamLogico--;
}

void listMovies(int tamLogico, Pelicula peliculas[cant]){
    for(int c=0; c<tamLogico; c++){
        cout<<"Titulo: "<<peliculas[c].titulo<<endl;
        }
}

void listarEstrenadas(int tamLogico, Pelicula peliculas[cant]){
    cout<<"\n Peliculas estrenadas:"<<endl;
    for(int i=0; i<tamLogico; i++){
        if(peliculas[i].fechaDeEstreno!=0){
            cout<<"Titulo: "<<peliculas[i].titulo<<endl;
            cout<<"Nro. de espectadores: "<<peliculas[i].espectadores<<endl<<endl;
        }
    }
}

void save(Pelicula peliculas[]){
    FILE* f = fopen("movies.dat", "w+b");
    fwrite(&peliculas, sizeof(Pelicula), 1, f);
    fclose(f);
    cout<<endl<<"Peliculas guardadas con exito!"<<endl;
}

void cargar(Pelicula peliculas[]){
    FILE* f = fopen("movies.dat", "rb+");
    fread(&peliculas, sizeof(Pelicula),1,f);
    fclose(f);
    cout<<endl<<"Peliculas cargadas con exito!"<<endl;
}

int main()
{
    Pelicula peliculas[cant];
    int menu = 0, tamLogico = 0;
    while(menu != 7){
        cout<<"Eliga una opcion: "<<endl;
        cout<<"1. Agregar una pelicula."<<endl;
        cout<<"2. Eliminar una pelicula."<<endl;
        cout<<"3. Listar todas las peliculas."<<endl;
        cout<<"4. Listar peliculas estrenadas."<<endl;
        cout<<"5. Guardar peliculas."<<endl;
        cout<<"6. Cargar peliculas."<<endl;
        cout<<"7. Salir."<<endl<<endl;
        cin>>menu;
        switch (menu){
            case 1:
                addMovie(tamLogico, peliculas);
                break;
            case 2:
                removeMovie(tamLogico, peliculas);
                break;
            case 3:
                listMovies(tamLogico, peliculas);
                break;
            case 4:
                listarEstrenadas(tamLogico, peliculas);
                break;
            case 5:
                save(peliculas);
                break;
            case 6:
                cargar(peliculas);
                break;
            default:
                cout<<"Ingrese una opcion correcta por favor."<<endl;
            }
    }
    cout<<"Adios!"<<endl;
    return 0;
}

