/* 2)Abrir un archivo de texto, escribir la palabra “algoritmos” por consola. 
Luego cerrarlo, volverlo a abrir e imprimir lo que se haya escrito. 
(Fijarse de como hacer para que la consola deje de pedir letras)
*/
#include <iostream>
#include <stdio.h>

using namespace std;

void escribirArchivo(FILE* f, char texto[], int tam){
    for(int i = 0; i < tam; i++) fputc(texto[i], f);
    fclose(f);
}

void imprimirArchivo(FILE* f){
    char letra;
    while(!feof(f)){
        letra = fgetc(f);
        cout << letra;
    }
}

int main(){
    char palabra[10];
    FILE* fw = fopen("ejercicio2.txt", "w");

    cout << "Ingrese una palabra: " << endl;
    cin.getline(palabra, 10);

    escribirArchivo(fw, palabra, 10);

    cout << endl;

    FILE* fr = fopen("ejercicio2.txt", "r");
    cout << "Contenido del archivo: " << endl;
    imprimirArchivo(fr);
    cout << endl;

    return 0;
}
