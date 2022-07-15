#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Repartidor{
	unsigned dni;
	char NomApe[25];
	unsigned zona;
};

int main(){
	Repartidor r;
	int contZonas[6] {};
	FILE* f=fopen("Repartidores.dat","wb");
	cout<<"Ingrese DNI del repartidor: ";
	cin>>r.dni;
	while(r.dni > 0){
		cout<<"Ingrese el nombre y de apellido del repartidor: "<<endl;
		cin.ignore();
		cin.getline(r.NomApe,25);
		cout<<"Ingrese el numero de zona(1: boedo, 2: Parque Patricios, 3: Barracas, 4: Caballito, 5: Chacarita, 6: Balbanera)"<<endl;
		cin>>r.zona;
		switch(r.zona){
			case 1: contZonas[0] = contZonas[0] + 1;
					break;
			case 2: contZonas[1] = contZonas[1] + 1;
					break;
			case 3: contZonas[2] = contZonas[2] + 1;
					break;
			case 4: contZonas[3] = contZonas[3] + 1;
					break;
			case 5: contZonas[4] = contZonas[4] + 1;
					break;
			case 6: contZonas[5] = contZonas[5] + 1;
					break;
			default: cout<<"Numero de zona incorrecto."<<endl;
		}
		fwrite(&r, sizeof(Repartidor),1,f);
		cout<<"Ingrese DNI del repartidor: ";
		cin>>r.dni;
	}
	fclose(f);
	cout<<"Cantidad de repartidores en..."<<endl;
	for(int c = 0; c < 6; c++){
		if (contZonas[c] > 0){
			switch(c){
				case 0: cout<<"1. Boedo: "<<contZonas[0]<<endl;
						break;
				case 1:  cout<<"2. Parque Patricios: "<<contZonas[1]<<endl;
						break;
				case 2: cout<<"3. Barracas: "<<contZonas[2]<<endl;
						break;
				case 3: cout<<"4. Caballito: "<<contZonas[3]<<endl;
						break;
				case 4: cout<<"5. Chacarita: "<<contZonas[4]<<endl;
						break;
				case 5: cout<<"6. Balbanera: "<<contZonas[5]<<endl;
						break;
			}
		} else {
			switch (c){
				case 0: cout<<"No hubo repartidores en Boedo."<<endl;
						break;
				case 1: cout<<"No hubo repartidores en Parque Patricios."<<endl;
						break;
				case 2: cout<<"No hubo repartidores en Barracas."<<endl;
						break;
				case 3: cout<<"No hubo repartidores en Caballito."<<endl;
						break;
				case 4: cout<<"No hubo repartidores en Chacarita."<<endl;
						break;
				case 5: cout<<"No hubo repartidores en Balbanera."<<endl;
						break;
			}
		}
	}
	return 0;
}
