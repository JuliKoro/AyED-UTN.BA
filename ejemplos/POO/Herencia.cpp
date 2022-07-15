//Herencia

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Persona{ //Clase Padre
	protected: //Atributos / Son manipulables solo por la clase y su herencia.
		string nombre;
		int edad;
	public: //Metodos
		Persona(string,int); //Contructor
		void mostrarPersona();
};

class Alumno : public Persona{
	private: //Atributos
		string codAlumno;
		float notaFinal;
	public: //Metodos
		Alumno(string,int,string,float); //Contructorde clase Alumno (Clase Hija)
		void mostrarAlumno();
};

Persona::Persona(string _nombre, int _edad){ //Constructor de la clase Persona (Clase Padre)
	nombre = _nombre;
	edad = _edad;
}

Alumno::Alumno(string _nombre, int _edad, string _codAlumno, float _notaFinal) : Persona(_nombre,_edad){
	codAlumno = _codAlumno;
	notaFinal = _notaFinal;
}

void Persona::mostrarPersona(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}

void Alumno::mostrarAlumno(){
	mostrarPersona();
	cout<<"Codigo de Alumno: "<<codAlumno<<endl;
	cout<<"Nota final: "<<notaFinal<<endl;
}

int main(){
	Alumno alumno1("Julian",19,"HJ25",8.5);
	alumno1.mostrarAlumno();
	
	
	system("pause");
	return 0;
}
