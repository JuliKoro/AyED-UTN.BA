/* 4)Hacer un programa que abra un archivo de texto, y que teniendo dos vectores “abcdefghi” y “jdogkakd”, 
escribalos en el archivo, y desde este, indique las cantidad de letras ‘a’ que contenga el archivo. 
(2 en este caso)
*/
#include <iostream>
#include <stdio.h>

using namespace std;

void escribir(FILE* f, char texto[], int tam){
    for(int i = 0; i < tam; i++) fputc(texto[i], f);
}

int contarLetra(FILE* f, char letra){
    char c = fgetc(f);
    int cont = 0;
    while(!feof(f)){
        if(c == 'a') cont++;
        c = fgetc(f);
    }
    return cont;
}

int main(){
    char cadena1[] = "abcdefghi";
    char cadena2[] = "jdogkakd";
    FILE* f = fopen("ejercicio4.txt", "w+");

    escribir(f, cadena1, sizeof(cadena1)/sizeof(char));
    escribir(f, cadena2, sizeof(cadena2)/sizeof(char));
    cout << "Archivo escrito." << endl;
    fseek(f, 0, SEEK_SET);
    int cantA = contarLetra(f, 'a');
    cout << "El archivo contiene " << cantA << " veces la letra " << 'a' << endl;

    return 0;
}