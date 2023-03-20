/* Ejercicio Unidad 2: Acciones y Funciones
Entonces, hagamos un programa que use todo lo que dijimos. 
Vamos a hacer un programa, que multiplique 2 valores cualesquiera, le cambie el valor a uno de estos valores a 20 y luego imprima a todos los valores.
Entonces, si lo  pensamos modularmente, tendríamos que tener:
una función que multiplique valores y retorne su resultado.
una acción que cambie el valor de un número a 20, porque no me interesa qué devuelva; ya se que la variable va a salir valiendo 20.
una acción que imprima valores
*/
#include <iostream>

using namespace std;

int multiplicar(int unNumero, int otroNumero){
    return unNumero * otroNumero;
}

void cambiarValor(int &unNumero){
    unNumero = 20;
}

void imprimirValor(int unValor){
    cout << "El valor es: " << unValor << endl;
}

int main(){
    int valor1 = 14, valor2 = 9;
    int resultado = multiplicar(valor1, valor2);
    cambiarValor(valor1);

    imprimirValor(valor1);
    imprimirValor(valor2);
    imprimirValor(resultado);
    return 0;
}