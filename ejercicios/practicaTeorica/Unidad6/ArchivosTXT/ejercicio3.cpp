/* 3)Hacer un programa que teniendo el siguiente vector {‘C’,‘a’,‘l’,‘c’,‘u’,‘l’,‘o’},
lo escriba en un archivo de texto, y luego sin cerrarlo, lea ese archivo e imprima por pantalla su contenido.
*/
#include <iostream>
#include <stdio.h>

using namespace std;

void escribir(FILE* f, char texto[], int tam){
    for(int i = 0; i < tam; i++) fputc(texto[i], f);
}

void imprimir(FILE* f){
    fseek(f, 0, SEEK_SET);
    char c = fgetc(f);
    while(!feof(f)){
        cout << c;
        c = fgetc(f);
    }
}

int main(){
    char vector[] = {'C', 'a', 'l', 'c', 'u', 'l', 'o'};
    FILE* f = fopen("ejercicio3.txt", "w+");
    escribir(f, vector, sizeof(vector)/sizeof(char));
    cout << "Archivo creado/guardado." << endl;
    cout << "Contenido del archivo: " << endl;
    imprimir(f);
    cout << endl;
    fclose(f);

    return 0;
}