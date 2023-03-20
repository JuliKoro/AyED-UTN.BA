// 1)Abrir un archivo de texto en modo escritura y lectura, y luego cerrarlo.
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    FILE* f = fopen("ejercicio1.txt", "w+");
    cout << "El archivo ha sido creado/abierto." << endl;

    fclose(f);
    cout << "El archivo ha sido cerrado." << endl;

    return 0;
}