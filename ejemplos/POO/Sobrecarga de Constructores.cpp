//Sobrecarga de Constructores

#include <iostream>
#include <stdlib.h>

using namespace std;

class Fecha{
	private: //Atributos
		int dia, mes, anio;
	public: //Metodos
		Fecha(int,int,int); //Constructor1
		Fecha(long); //Constructor2
		void mostrarFecha();
};

Fecha::Fecha (int _dia, int _mes,int _anio){ //Constructor1
	anio = _anio;
	mes = _mes;
	dia = _dia;
}

Fecha::Fecha(long fecha){
	anio = int(fecha/10000); //Extraer anio
	mes = int((fecha-anio*10000)/100); //Extraer mes
	dia = int(fecha-anio*10000-mes*100); //Extraer dia
}

void Fecha::mostrarFecha(){
	cout<<"La fecha es: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

int main(){
	Fecha hoy(5,2,2020); //Creo objeto hoy de la clase Fecha
	Fecha ayer(20200402);
	hoy.mostrarFecha();
	ayer.mostrarFecha();
	system("pause");
	return 0;
}
