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
int criterioAZ(string, string);
int criterio09(int, int);
template <typename T> void ordenar(T, int, int);
template <typename T> void mostrarFila(T);
template <typename T> void mostrar(T, int);
template <typename T> void prevCondition(T, int, int);
template <typename T> long fileSize(FILE*);
template <typename T> void seek (FILE*, int);
template <typename T> T read (FILE*);
template <typename T, typename K> int busquedaBinaria(FILE*, K, int);

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

template <typename T> int criterioAZ(T e1, T e2) {
    return e1.titulo>e2.titulo?1:e1.titulo<e2.titulo?-1:0;
}

template <typename T> int criterio09(T e1, T e2){
    return e1.codigo-e2.codigo;
}

template <typename T> void ordenar(T arr[], int len, int (*criterio)(T,T)) {
    bool ordenado=false;
    while(!ordenado){
        ordenado=true;
        for(int i=0; i<len-1; i++){
            if( criterio(arr[i],arr[i+1])>0 ){
                T aux = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = aux;
                ordenado = false;
            }
        }
    }
}

template <typename T> void mostrarFila(T a){
    cout<<a.titulo<<", ";
}

template <typename T> void mostrar(T arr[], int len, void (*mostrarCriterio)(T)) {
    for(int i=0; i<len; i++){
        mostrarCriterio(arr[i]);
    }
}

template <typename T> void prevCondition(T arr[], int len, int numCriterio){
    if(numCriterio == 11) ordenar<Pelicula>(arr, len, criterio09);
    else ordenar<Pelicula>(arr, len, criterioAZ);
    save(arr);
}

//lo siguiente es necesario para busqueda binaria
template <typename T>
long fileSize(FILE*f){
	long curr= ftell(f);
	fseek (f,0,SEEK_END);
	long ultimo=ftell(f);
	fseek (f,curr,SEEK_SET);
	return ultimo/sizeof(T);
}

template <typename T>
void seek (FILE* arch, int n){
	fseek (arch, n*sizeof(T),SEEK_SET);
}

template <typename T>
T read (FILE* f){
	T buff;
	fread(&buff,sizeof(T),1,f);
	return buff;
}

template <typename T, typename K> int busquedaBinaria(FILE* f, K v, int (*criterio)(T,K)) {
    int i = 0;
    int j = fileSize<T>(f)-1; //te dice la cantidad de archivos
    int k = (i+j)/2;
    seek<T>(f,k); //ubica el puntero en el medio
    T r = read<T>(f); //lee el archivo en el que esta parado
    while( i<=j && criterio(r,v)!=0 ) { // mientras i sea menor que j (total del archiuvo)
        if( criterio(r,v)>0 ) {
            j = k-1;
        } else {
        if( criterio(r,v)<0 ) {
            i=k+1;
        }
        }
        k = (i+j)/2;
        seek<T>(f,k);
        r = read<T>(f);
    }
    return i<=j?k:-1;
}

int main()
{
    Pelicula peliculas[cant];
    int menu = -1, tamLogico = 0;
    while(menu != 0){
        cout<<"Eliga una opcion: "<<endl;
        cout<<"1. Agregar una pelicula."<<endl;
        cout<<"2. Eliminar una pelicula."<<endl;
        cout<<"3. Listar todas las peliculas."<<endl;
        cout<<"4. Listar peliculas estrenadas."<<endl;
        cout<<"5. Guardar peliculas."<<endl;
        cout<<"6. Cargar peliculas."<<endl;
        cout<<"7. Guardar en un archivo de texto."<<endl;
        cout<<"8. Transferir a un archivo .json."<<endl;
        cout<<"9. Ordenar ascendentemente por codigo."<<endl;
        cout<<"10. Ordenar ascendentemente por titulo."<<endl;
        cout<<"11. Buscar por codigo."<<endl;
        cout<<"12. Buscar por titulo."<<endl;
        cout<<"0. Salir."<<endl<<endl;
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
                ordenar<Pelicula>(peliculas, tamLogico, criterio09);
                mostrar<Pelicula>(peliculas, tamLogico, mostrarFila);
                break;
            case 10:
                ordenar<Pelicula>(peliculas, tamLogico, criterioAZ);
                mostrar<Pelicula>(peliculas, tamLogico, mostrarFila);
                break;
            case 11:
                {
                prevCondition(peliculas, tamLogico, menu);
                int codBuscar, searchResult;
                cout << "Ingrese el codigo de la pelicula que quiera buscar: ";
                cin >> codBuscar;
                Pelicula obj; //objetivo
                obj.codigo = codBuscar;
                FILE* f = fopen("movies.dat", "rb+");
                searchResult = busquedaBinaria<Pelicula>(f,obj,criterio09);
                fclose(f);
                if (searchResult==-1){
					cout<<"El codigo ingresado no existe."<<endl;
				} else {
                    cout<<"La pelicula es: "<<peliculas[searchResult].titulo<<endl;
					cout<<"El director es: "<<peliculas[searchResult].director<<endl;
					cout<<"La cantidad de escpectadores es: "<<peliculas[searchResult].espectadores<<endl;
					cout<<"La fecha de estreno es: "<<peliculas[searchResult].fechaDeEstreno<<endl;
                }
                }
                break;
            case 12:
                {
                prevCondition(peliculas, tamLogico, menu);
                string titleBuscar;
                int searchResult;
                cout << "Ingrese el titulo de la pelicula que quiera buscar: ";
                getline(cin, titleBuscar);
                Pelicula obj; //objetivo
                obj.titulo = titleBuscar;
                FILE* f = fopen("movies.dat", "rb+");
                searchResult = busquedaBinaria<Pelicula>(f,obj,criterio09);
                fclose(f);
                if (searchResult==-1){
					cout<<"El titulo ingresado no existe."<<endl;
				} else {
                    cout<<"El codigo es: "<<peliculas[searchResult].codigo<<endl;
					cout<<"El director es: "<<peliculas[searchResult].director<<endl;
					cout<<"La cantidad de escpectadores es: "<<peliculas[searchResult].espectadores<<endl;
					cout<<"La fecha de estreno es: "<<peliculas[searchResult].fechaDeEstreno<<endl;
                }
                }
                break;
            case 0:
                return 0; //para q termine de pedir la opcion
            	break;
            default:
                cout<<"Ingrese una opcion correcta por favor."<<endl;
            }
    }
    cout<<"Adios!"<<endl;
    return 0;
}
