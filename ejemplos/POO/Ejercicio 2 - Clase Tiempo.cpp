//Ejercicio 2

#include <iostream>
#include <stdlib.h>

using namespace std;

class Tiempo{
	private:
		int horas, minutos, segundos;
	public:
		Tiempo(int,int,int);
		Tiempo(long);
		void mostrarTiempo();
};

Tiempo::Tiempo(int _horas, int _minutos, int _segundos){
	horas = _horas;
	minutos = _minutos;
	segundos = _segundos;
}

Tiempo::Tiempo(long seg){
	horas = int(seg/3600);
	minutos = int((seg/60)-(horas*60));
	segundos = int(seg-(horas*3600)-(minutos*60));
}

void Tiempo::mostrarTiempo(){
	cout<< "El tiempo es: "<<horas<<":"<<minutos<<":"<<segundos<<endl;
}

int main(){
	Tiempo ahora(21,9,00);
	Tiempo now(76140);
	
	ahora.mostrarTiempo();
	now.mostrarTiempo();
	
	system("pause");
	return 0;
}
