#include <iostream>
#include <stdlib.h>

using namespace std;

void pedirDatos();
void ordenar(float *, int);
void mostrar(float *, int);

float *elemento;
int nElementos;

int main(){
	pedirDatos();
	ordenar(elemento, nElementos);
	mostrar(elemento, nElementos);
	
	delete[] elemento;
	
	system ("pause");
	return 0;
}

void pedirDatos(){
	cout<<"Intoduzca el numero de elementos que quiere ordenar: "<<endl;
	cin>>nElementos;
	elemento = new float[nElementos];
	cout<<"Ahora introduzca "<<nElementos<<" elementos que quiera ordenar:"<<endl;
	for(int i=0; i<nElementos; i++){
		cin>>elemento[i];
	}
}

void ordenar(float *elemento, int nElementos){
	float aux;
	for(int i=0; i<nElementos; i++){
		for(int c=i+1; c<nElementos; c++){
			if(elemento[i]>elemento[c]){
				aux = elemento[c];
				elemento[c] = elemento[i];
				elemento[i] = aux;
			}
		}
	}
}

void mostrar (float *elemento, int nElementos){
	cout<<"Elementos ordenados de forma ascendente:"<<endl<<endl;
	for(int i=0; i<nElementos; i++){
		cout<<elemento[i]<<" ";
	}
	cout<<endl;
}


