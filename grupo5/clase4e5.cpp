/*
Observaciones: esta muy bien!
Personalmente hubiera declarado los valores envFactura (de r y de c), servBasico
(de r y de c), precioCanalesHD y conexAdicionales como constantes antes de inciar el int main ,para así en el caso de tener que cambiar algún valor, no tener
que borrar todos los datos hardcodeados
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main () {
	char cliente; 
	int conexiones, hd, numero;
	float importe;
	cout<<"Ingrese numero de cliente: ";
	cin>>numero;
	cout<<"Ingrese tipo de cliente residente (R o r) o comercial (C o c): ";
	cin>>cliente;
	cout<<"Ingrese cantidad de canales HD: ";
	cin>>hd;
	switch(cliente){
		case 'R': case'r': importe=4.5+20.5+5*hd;
			break; 
		case 'C': case'c': 
			cout<<"Ingrese cantidad de conexiones: ";
			cin>>conexiones;
			if (conexiones>10){
				importe=15+75+(conexiones-10)*5+5*hd;
			} else {
				importe=15+75+5*hd;
			}
			break;
	}
	cout<<setprecision(2);
	cout<<fixed<<showpoint;
	cout<<"Numero de cliente: "<<numero<<endl;	
	cout<<"Importe total: $ "<<importe<<endl;
	system("pause");
	return 0;

}
