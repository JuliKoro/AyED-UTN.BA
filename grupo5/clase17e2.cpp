//Observacion: esta muy bien, les agregue un return 0; en el case 0: porque no terminaba de pedir la opcion

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
		if (peliculas[u].codigo ==  cod) {
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
	for (int i=0; i<tamLogico;i++) {
		if (peliculas[i].fechaDeEstreno != 0){
			cout << peliculas[i].titulo << ": " << peliculas[i].espectadores << endl; 
		}
	}
}

void listarMovie(Pelicula peliculas[10], int tamLogico) {
	for (int i=0; i<tamLogico;i++) {
		cout << peliculas[i].titulo << endl; 
	}
}

void save(Pelicula peliculas[], int tamLogico) {
	FILE* f = fopen("peliculas.dat","w+b");
	for(int i=0;i<tamLogico;i++){	
		fwrite(&peliculas[i],sizeof(Pelicula),1,f);
	}
    fclose(f);
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
}


void aCsv (Pelicula peliculas[], int tamLogico){
	FILE*F;
	F=fopen("peliculas.csv","w");
	for (int i = 0; i<tamLogico; i++){
		fprintf(F, "%d, %s, %s, %d, %8d\r", peliculas[i].codigo, peliculas[i].titulo, peliculas[i].director, peliculas[i].espectadores, peliculas[i].fechaDeEstreno);
	}
	fclose(F);
}

void aJson(){
	FILE*F=fopen("peliculas.dat","r");
	FILE*G=fopen("pelculas.json", "w");
	Pelicula p;
	fread(&p, sizeof(Pelicula), 1, F);
	fprintf(G,"{\r \"peliculas\":[\r");
	while(!feof(F)){
		fprintf(G,"{\r\t\"codigo\": \" %d \" \r, \t\"titulo\": \" %s \" \r, \t\"director\": \" %s \" \r , \t\"espectadores\": \" %d \" \r \t\"fecha-de-estreno\": \" %d \" \r", p.codigo, p.titulo, p.director, p.espectadores, p.fechaDeEstreno);
		fread(&p, sizeof(Pelicula), 1, F);
	}
    fclose(F);
    fclose(G);
	
}

template <typename T>
void ordenar(T arr[], int tamLogico, int (*criterio)(T,T)){
	bool ordenado = false;
	while (!ordenado){
		ordenado = true;
		for (int i = 0; i < tamLogico-1; i++){
			if (criterio (arr[i], arr[i+1]) > 0 ){
				T aux = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = aux;
				ordenado = false;
			}
		}
	}
}

int criterio09(Pelicula p1, Pelicula p2){
	return p1.codigo - p2.codigo;
}

int criterioAz(Pelicula p1, Pelicula p2){
	string titulo1 = p1.titulo;
	string titulo2 = p2.titulo;
	return titulo1>titulo2?1:titulo1<titulo2?-1:0;
}

template <typename T> 
void mostrar(T arr[], int tamLogico, void (*mostrarFila)(T)){
	for(int i = 0; i < tamLogico ; i++){
		mostrarFila(arr[i]);
	}
}

void mostrarPelicula (Pelicula p) {
		cout <<"codigo: "<<p.codigo<<endl<<"titulo: "<<p.titulo<<endl; 
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

template <typename T, typename K> 
int busquedaBinaria(FILE*f,K v,int(*criterio)(T,K)){
	int i= 0;
	int j= fileSize<T>(f)-1;//te dice la cantidad de archivos
	int k= (i+j)/2; 
	seek<T>(f,k); //ubica el puntero en el medio 
	T r= read<T>(f); //lee el archivo en el que esta parado 
	while (i<=j && criterio(r,v)!=0){ // mientras i sea menor que j (total del archiuvo) 
		if(criterio(r,v)>0){
			j=k-1;
		}
		else{
			if(criterio(r,v)<0){
				i=k+1;
			}
		}
		k=(i+j)/2;
		seek<T>(f,k);
		r= read<T>(f);
	}
	return i<=j?k:-1;
}

int main(){
	int menu = 0; 
	Pelicula peliculas[10];
	int tamLogico = 0;
	while(menu != 7) {
        cout << "Elija la accion que desee realizar: " << endl;
        cout << "1. Agregar una pelicula." << endl;
        cout << "2. Eliminar una pelicula." << endl;
        cout << "3. Listar todas las peliculas. " << endl;
        cout << "4. Listar las estrenadas." << endl;
        cout << "5. Guardar (sobreescribe el archivo si ya existe)." << endl;
        cout << "6. Cargar." << endl;
        cout << "7. CSV." << endl;
        cout << "8. Json." << endl;
        cout << "9. Ordenar ascendentemente por Codigo" << endl;
        cout << "10. Ordenar ascendentemente por Titulo" << endl;
        cout << "11. Buscar pelicula por Codigo" << endl;
		cout << "12. Buscar pelicula por Titulo" << endl;        
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
            case 9:
				ordenar<Pelicula>(peliculas, tamLogico, criterio09);
				mostrar<Pelicula>(peliculas, tamLogico, mostrarPelicula);
				break;
			case 10:
				ordenar<Pelicula>(peliculas, tamLogico, criterioAz);
				mostrar<Pelicula>(peliculas, tamLogico, mostrarPelicula);
				break;
			case 11:
				ordenar<Pelicula>(peliculas, tamLogico, criterio09);
				cout << "Ingrese el codigo de la pelicula que quiere buscar "<<endl;
				{
				int codtemp;
				cin >> codtemp;
				FILE* f = fopen("peliculas.dat","r");
				Pelicula obj;
				obj.codigo = codtemp;
				busquedaBinaria<Pelicula>(f,obj,criterio09);
				if (busquedaBinaria<Pelicula>(f,obj,criterio09)==-1){
					cout<<"El codigo ingresado no existe"<<endl;
				}
				if (busquedaBinaria<Pelicula>(f,obj,criterio09)!=-1){
					cout<<"La pelicula es: "<<peliculas[busquedaBinaria<Pelicula>(f,obj,criterio09)].titulo<<endl;
					cout<<"El director es: "<<peliculas[busquedaBinaria<Pelicula>(f,obj,criterio09)].director<<endl;
					cout<<"La cantidad de escpectadores es: "<<peliculas[busquedaBinaria<Pelicula>(f,obj,criterio09)].espectadores<<endl;
					cout<<"La fecha de estreno es: "<<peliculas[busquedaBinaria<Pelicula>(f,obj,criterio09)].fechaDeEstreno<<endl;
				}
			    fclose(f);
				}
				break;
			case 12:
				ordenar<Pelicula>(peliculas, tamLogico, criterio09);
				cout<<"Ingrese el titulo de la pelicula que desea buscar: "<<endl;
				{
				char temptit[25];
				cin>>temptit;
				Pelicula objetivotitulo;
				strcpy (objetivotitulo.titulo,temptit);
				FILE* f = fopen("peliculas.dat","r");
				busquedaBinaria<Pelicula>(f,objetivotitulo,criterioAz);
				if (busquedaBinaria<Pelicula>(f,objetivotitulo,criterioAz)==-1){
					cout<<"El titulo ingresado no existe"<<endl;
				}
				if (busquedaBinaria<Pelicula>(f,objetivotitulo,criterioAz)!=-1){
					cout<<"El codigo de la pelicula es: "<<peliculas[busquedaBinaria<Pelicula>(f,objetivotitulo,criterioAz)].codigo<<endl;
					cout<<"El director es: "<<peliculas[busquedaBinaria<Pelicula>(f,objetivotitulo,criterioAz)].director<<endl;
					cout<<"La cantidad de escpectadores es: "<<peliculas[busquedaBinaria<Pelicula>(f,objetivotitulo,criterioAz)].espectadores<<endl;
					cout<<"La fecha de estreno es: "<<peliculas[busquedaBinaria<Pelicula>(f,objetivotitulo,criterioAz)].fechaDeEstreno<<endl;
				}
				fclose(f);
				}
				break;
			case 0:
			    return 0;
            	break;
			default:
                cout << "Ingrese uno de los valores numericos del menu." << endl;
        }
	}
	return 0;
}
