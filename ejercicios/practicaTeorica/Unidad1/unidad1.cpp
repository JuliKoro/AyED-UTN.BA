 
 /* Unidad 1: Variables y Tipos de Datos
  
  - Desarrollar un programa que, dado unos datos otorgados por un usuario,
 podamos imprimir por pantalla su Nombre, Apellido, Edad y haga la suma entre sus dos números favoritos.
 */
 
 #include <iostream>

 using namespace std;

 int main(){
    string nombre, apellido;
    int edad, unNumero, otroNumero;

    cout << "Ingrese su nombre: ";
    cin >> nombre;

    cout << "Ingrese su apellido: ";
    cin >> apellido;

    cout << "Ingrese su edad: ";
    cin >> edad;

    cout << "Ingrese su numero favorito: ";
    cin >> unNumero;

    cout << "Ingrese otro numero favorito: ";
    cin >> otroNumero;

    int suma = unNumero + otroNumero;

    cout << endl << "Tu nombre es: " << nombre << endl;
    cout << "Tu apellido es: " << apellido << endl;
    cout << "Tu edad es: " << apellido << endl;
    cout << "Suma de ambos numeros: " << suma << endl;

    return 0;
 }