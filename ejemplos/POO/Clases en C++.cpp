//Clases en C++
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Persona{ //Creacion de la Clase
	private: //Atributos (Caracteristicas). El private es para encapsular los atributos. Los unicos que pueden modificarlo son los metodos de la misma clase
		int edad;
		string nombre;
	public: //Metodos (Acciones)
		Persona (int, string); //Constructor
		void leer();
		void correr();
};

Persona::Persona(int _edad, string _nombre){ //Constructor: Inizializa los atributos
	edad = _edad;
	nombre = _nombre;
}

void Persona::leer(){
	cout<<"Soy "<<nombre<<" y estoy leyendo un libro."<<endl;
}

void Persona::correr(){
	cout<<"Soy "<<nombre<<" y estoy corriendo una maraton y tengo "<<edad<<" anos."<<endl;
}

int main(){
	Persona p1 = Persona(19,"Julian"); //Creo un objeto
	Persona p2(21, "Tamara"); //Creo otro objeto
	Persona p3(18, "Thiago");
	
	p1.leer();
	p2.correr();
	p3.leer();
	p3.correr();
	
	
	system("pause");
	return 0;
}
