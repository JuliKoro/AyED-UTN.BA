/* 5)Hacer un programa que reciba una cantidad de letras(letra por letra, por consola),
las escriba en un archivo y que al final escriba “FinalDelArchivo”.
*/
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int tamanio = 5;
    char data;
    char fin[] = "FinalDelArchivo";
    FILE* f = fopen("ejercicio5.txt", "w");

    for(int i = 0; i < tamanio; i++){
        cout << "Ingrese una letra: ";
        cin >> data;
        fputc(data, f);
    }
    fprintf(f, "\r");
    for(int c = 0; c < (sizeof(fin)/sizeof(char)); c++) fputc(fin[c], f);
    cout << "Archivo creado/escrito." << endl;

    fclose(f);

    return 0;
}