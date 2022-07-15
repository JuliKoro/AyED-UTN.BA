//Observacion: bien

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
using std::string;


struct Firma{
	int id;
	string nombre;
	string firma;
};

struct Nodo {
    Firma info;
    Nodo * sig;
};

int critFirmaNom(Firma f1, Firma f2){
	return f1.nombre<f2.nombre?-1:f1.nombre>f2.nombre?1:0;
}

template <typename T> Nodo* insertarOrdenado(Nodo*& l, Firma v, int (*criterio)(T,T) ) {
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	Nodo* aux = l;
	Nodo* ant = NULL;
	while( aux!=NULL && criterio(aux->info,v)<=0 ) {
		ant = aux;
		aux = aux->sig;
	}
	if( ant==NULL ) {
		l = nuevo;
	} else {
		ant->sig = nuevo;
	}
	nuevo->sig = aux;
	return nuevo;
}

void importar(FILE* f, Nodo* & p) {
	Firma c;
	f = fopen("firmas.dat","rb+");
	fread(&c,sizeof(c),1,f);
	insertarOrdenado(p,c,critFirmaNom);	
	while( !feof(f) ) {
		fread(&p,sizeof(f),1,f);
		insertarOrdenado(p,c,critFirmaNom);
		
	}
	fclose(f);
}

void exportar (Nodo*& p, char lugar[]){
	FILE* f = fopen(lugar,"wb+");
	Nodo* aux=p;
	Firma g;
	while(aux!=NULL){
		g=aux->info;
		fwrite(&p,sizeof(Firma),1,f);
		aux=aux->sig;
	}
	fclose (f);
}

bool analizar (string array[], Nodo*& p){
	while (p!=NULL){
		string datoComp = string (p->info.firma);
		for (int i=0;i<5;i++){
			if (datoComp.compare(array[i])== -1){
				return false;
			}
		}
	p = p->sig;
	}
	return true;
}


int main(){
	Nodo * p = NULL;
	FILE* f;
	importar(f,p);
	
	string primerLote [5] {"fasdfafafaeeww", "2jhg3jf2hjf4h23hgj234j", "32kljh34kl2h3lk4g23", "213kjh4k23g4g23io", "2o34y2332nsnjhsaghkj"};

	string segundoLote [5] {"afasklfalksfuiyiy", "opteqljhweqljkhrefadslfd", "up32ljh324kjhl234kj", "ln32kljh432klj4klhljk", "32uoi4kjhl234khg234jk"};

	string tercerLote [5] {"fasjkhfkljhfjkhah", "khjl32jkhl234jkgh43jhg", "kh324khj342khj243k", "kjh32kjhl43kjhl24jkh", "kljhfakjsjkhlsdahjksdl"};
		
	if (analizar(primerLote,p)==false){
		cout<<"El primer lote contiene un virus"<<endl;
	}else{
		cout<<"El primer lote No contiene un virus"<<endl;
	}
	if (analizar(segundoLote,p)==false){
		cout<<"El segundo lote contiene un virus"<<endl;
	}else{
		cout<<"El segundo lote No contiene un virus"<<endl;
	}
	if (analizar(tercerLote,p)==false){
		cout<<"El tercer lote contiene un virus"<<endl;
	}else{
		cout<<"El tercer lote No contiene un virus"<<endl;
	}
	
	cout<<"Ingrese el nombre del archivo para guardar los resultados"<<endl;
	char nombre [25];
	cin>>nombre;
	exportar (p,nombre);

}


