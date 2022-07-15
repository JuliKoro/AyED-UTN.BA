//Observacion: esta muy bien

#include <iostream>
using namespace std;
float suma= 0;
float avg;
const int tamanio=10;
void ingresoVentas(float Ventas[]){
	for (int i=0; i<tamanio; i++){
		cout<<"ingrese importe de venta "<<i+1<<endl;
		cin>>Ventas[i];
	}
}
void SumyAvg(float Ventas[]){
	for (int g=0; g<tamanio; g++){
		suma=suma+Ventas[g];
	}
	avg=(suma)/tamanio;
	cout<<"Valor total de ventas: "<<suma<<endl;
	cout<<"Valor promedio por venta: "<<avg<<endl;
}
float maximo (float Ventas[]){
	float max=0;
	for(int f=0; f<tamanio; f++){
		if(Ventas[f]>max){
			max=Ventas[f];
		}
	}
	return max;
}
int busquedaSec (const float Ventas[], float objetivo, float tolerancia){
	int indice;
	bool encontrado=false;
	indice=0;
	while (indice<tamanio && !encontrado){
		if (Ventas[indice]<=(objetivo+tolerancia) && Ventas[indice]>=(objetivo-tolerancia)){
			encontrado=true;
		} else{
			indice++;
		}
	}
	if (encontrado){
		return indice;
	} else{
		return -1;
	}
}

int main(){
	float Ventas[tamanio];
	float tolerancia;
	float objetivo;
	ingresoVentas(Ventas);
	SumyAvg(Ventas);
	float max = maximo(Ventas);
	cout<<"El importe mayor es: "<<max<<endl;
	cout<<"Ingrese el valor de venta que busca: "<<endl;
	cin>>objetivo;
	cout<<"Ingrese tolerancia de busqueda: "<<endl;
	cin>>tolerancia;
	int resultadoBusq=busquedaSec(Ventas, objetivo, tolerancia);
	cout<<"La posicion del valor buscado es "<<resultadoBusq+1<<endl;
}
