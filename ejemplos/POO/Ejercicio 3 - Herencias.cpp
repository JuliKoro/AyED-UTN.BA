//Ejercicio 3: Herencia
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Persona{
	protected:
		string nombre, apellido;
		int edad;
	public:
		Persona(string,string,int);
		void mostrarPersona();
};

class Estudiante : public Persona{
	protected:
		string codEst;
		float notaFinal;
	public:
		Estudiante(string,string,int,string,float);
		void mostrarEstudiante();
};

class Universitario : public Estudiante{
	private:
		string carrera;
		int anio;
	public:
		Universitario(string,string,int,string,float,string,int);
		void mostrarUniversitario();
};

class Empleado : public Persona{
	private:
		string puesto;
		int antiguedad;
	public:
		Empleado(string,string,int,string,int);
		void mostrarEmpleado();	
};

Persona::Persona(string _nombre, string _apellido, int _edad){
	nombre = _nombre;
	apellido = _apellido;
	edad = _edad;
}

Estudiante::Estudiante(string _nombre, string _apellido, int _edad, string _codEst, float _notaFinal) : Persona(_nombre,_apellido,_edad){
	codEst = _codEst;
	notaFinal = _notaFinal;
}

Universitario::Universitario(string _nombre, string _apellido, int _edad, string _codEst, float _notaFinal, string _carrera, int _anio) : Estudiante(_nombre,_apellido,_edad,_codEst,_notaFinal){
	carrera = _carrera;
	anio = _anio;
}

Empleado::Empleado(string _nombre, string _apellido, int _edad, string _puesto, int _antiguedad) : Persona(_nombre,_apellido,_edad){
	puesto = _puesto;
	antiguedad = _antiguedad;
}

void Persona::mostrarPersona(){
	cout<<"Nombre completo: "<<nombre<<" "<<apellido<<endl;
	cout<<"Edad: "<<edad<<endl;
}

void Estudiante::mostrarEstudiante(){
	mostrarPersona();
	cout<<"Codigo de estudiante: "<<codEst<<endl;
	cout<<"Nota final: "<<notaFinal<<endl;
}

void Universitario::mostrarUniversitario(){
	cout<<"-Universitario-"<<endl;
	mostrarEstudiante();
	cout<<"Carrera: "<<carrera<<endl;
	cout<<"Anio cursando: "<<anio<<endl;
}

void Empleado::mostrarEmpleado(){
	cout<<"-Empleado-"<<endl;
	mostrarPersona();
	cout<<"Puesto de trabajo: "<<puesto<<endl;
	cout<<"Anios de antiguedad: "<<antiguedad<<endl;
}

int main(){
	Universitario alumno1("Julian","Koroluk",19,"1789797-3",8.5,"Ing. en Sistemas",2);
	Empleado empleado1("Mac","Jak",21,"Programador Senior",2);
	alumno1.mostrarUniversitario();
	cout<<"\n";
	empleado1.mostrarEmpleado();
	system("pause");
	return 0;
}
