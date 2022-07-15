//Destructor

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Perro{
	private:
		string nombre, raza;
	public:
		Perro(string, string); //Constructor
		~Perro(); //Destructor
		void mostrarDatos();
		void jugar();
};

Perro::Perro(string _nombre, string _raza){ //Constructor
	nombre = _nombre;
	raza = _raza;
}

Perro::~Perro(){ //Destructor
}

void Perro::mostrarDatos(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Raza: "<<raza<<endl;
}

void Perro::jugar(){
	cout<<nombre<<" esta jugando!"<<endl;
}

int main(){
	Perro perro1("Linda","Callejero");
	perro1.mostrarDatos();
	perro1.jugar();
	perro1.~Perro();
	system("pause");
	return 0;
}
