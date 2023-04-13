#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>

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
void aCsv(Pelicula);
void aJson();

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

void aCsv(Pelicula peliculas[]){
    FILE *f1;
    f1 = fopen("peliculas.csv", "w");
    for(int c=0; c<cant; c++){
        char title[peliculas[c].titulo.size()+1], dire[peliculas[c].director.size()+1];
        strcpy(title, peliculas[c].titulo.c_str());
        strcpy(dire, peliculas[c].director.c_str());
        fprintf(f1,"%d,%s,%s,%d,%d\n",peliculas[c].codigo,title,dire,peliculas[c].espectadores,peliculas[c].fechaDeEstreno);
    }
    fclose(f1);
    cout<<"Datos transferidos a peliculas.csv con exito"<<endl;
}

void aJson(){
    FILE *b = fopen("peliculas.dat","rb+");
    FILE *j = fopen("peliculas.json", "w");
    Pelicula p[cant];
    int c = 0;
    fread(&p[c], sizeof(Pelicula),1,b);
    fprintf(j,"{\r \"peliculas\":[\r");
    while(!feof(b)){
        char title[p[c].titulo.size()+1], dire[p[c].director.size()+1];
        strcpy(title, p[c].titulo.c_str());
        strcpy(dire, p[c].director.c_str());
        cout<<"Imprimiendo!:"<<endl;
        fprintf(j,"{\r\t\"codigo\": \" %d \" \r, \t\"titulo\": \" %s \" \r, \t\"director\": \" %s \" \r , \t\"espectadores\": \" %d \" \r \t\"fecha-de-estreno\": \" %d \", \r \"},", p[c].codigo, title, dire, p[c].espectadores, p[c].fechaDeEstreno);
        c++;
        fread(&p[c], sizeof(Pelicula),1,b);
    }
    fprintf(j,"]\r}\r");
    fclose(b);
    fclose(j);
    cout<<"Datos transferidos a .json exitosamente!"<<endl;
}

int main()
{
    Pelicula peliculas[cant];
    int menu = 0, tamLogico = 0;
    while(menu != 9){
        cout<<"Eliga una opcion: "<<endl;
        cout<<"1. Agregar una pelicula."<<endl;
        cout<<"2. Eliminar una pelicula."<<endl;
        cout<<"3. Listar todas las peliculas."<<endl;
        cout<<"4. Listar peliculas estrenadas."<<endl;
        cout<<"5. Guardar peliculas."<<endl;
        cout<<"6. Cargar peliculas."<<endl;
        cout<<"7. Guardar en un archivo de texto."<<endl;
        cout<<"8. Transferir a un archivo .json."<<endl;
        cout<<"9. Salir."<<endl<<endl;
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
            case 7:
                aCsv(peliculas);
                break;
            case 8:
                aJson();
                break;
            case 9:
            default:
                cout<<"Ingrese una opcion correcta por favor."<<endl;
            }
    }
    cout<<"Adios!"<<endl;
    return 0;
}
