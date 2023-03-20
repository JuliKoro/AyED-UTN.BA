// 1)Abrir un archivo binario en modo solo lectura y luego cerrarlo.
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    FILE* f = fopen("ejercicio1.dat", "rb");
    cout << "Archivo abierto en modo lectura." << endl;
    fclose(f);
    cout << "Archivo cerrado." << endl;

    return 0;
}