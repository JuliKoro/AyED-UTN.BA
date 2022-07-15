//Polimorfismo

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Persona{
	protected: 
		string nombre;
		int edad;
	public:
		Persona(string,int);
		virtual void mostrar(); //funcion de polimorfismo. Solo va en la clase Padre.
};

class Alumno : public Persona{
	private:
		float notaFinal;
	public:
		Alumno(string,int,float);
		void mostrar();
};

class Profesor : public Persona{
	private:
		string materia;
	public:
		Profesor(string,int,string);
		void mostrar();
};

Persona::Persona(string _nombre, int _edad){
	nombre = _nombre;
	edad = _edad;
}

Alumno::Alumno(string _nombre,int _edad,float _notaFinal) : Persona(_nombre,_edad){
	notaFinal = _notaFinal;
}

Profesor::Profesor(string _nombre, int _edad, string _materia) : Persona(_nombre,_edad){
	materia = _materia;
}

void Persona::mostrar(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}

void Alumno::mostrar(){
	cout<<"-Alumno-"<<endl;
	Persona::mostrar();
	cout<<"Nota final: "<<notaFinal<<endl;
}

void Profesor::mostrar(){
	cout<<"-Profesor-"<<endl;
	Persona::mostrar();
	cout<<"Materia: "<<materia<<endl;
}

int main(){
	Persona *vector[3];
	
	vector[0] = new Alumno ("Julian",19,8.6);
	vector[0]->mostrar();
	cout<<"\n";
	vector[1] = new Alumno ("Maria", 20, 10);
	vector[1]->mostrar();
	cout<<"\n";
	vector[2] = new Profesor ("Mario",57,"Arquitectura de Computadores");
	vector[2]->mostrar();
	system("pause");
	return 0;
}
