/* 1)a)Defina un struct Alumno con los siguientes campos: 
nombre(vector de caracteres), edad(entero), promedio(decimal).
b)Haga un programa que permita ingresar el nombre, la edad y el promedio y a estos los asigne al struct Alumno.
c) Imprima el nombre, edad y promedio de un Alumno.

*/
#include <iostream>
using namespace std;

struct Alumno{
    char nombre[10];
    int edad;
    float promedio;
};

void ingresarAlumno(Alumno &unAlumno){
    cout << "Ingrese los datos del Alumno." << endl;
    cout << "Nombre: ";
    cin >> unAlumno.nombre;
    cout << "Edad: ";
    cin >> unAlumno.edad;
    cout << "Promedio: ";
    cin >> unAlumno.promedio;
    cout << endl <<"Alumno registrado." << endl << endl;
}

void imprimirAlumno(Alumno unAlumno){
    cout << "Datos de alumno: " << endl;
    cout << "Nombre: " << unAlumno.nombre << endl;
    cout << "Edad: " << unAlumno.edad << " años" << endl;
    cout << "Promedio: : " << unAlumno.promedio << endl;
}

int main(){
    Alumno alumno1;
    ingresarAlumno(alumno1);
    imprimirAlumno(alumno1);
    return 0;
}