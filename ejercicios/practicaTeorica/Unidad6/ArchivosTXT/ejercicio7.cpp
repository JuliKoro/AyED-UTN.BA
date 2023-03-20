/* 7)Hacer un programa en el cual se pueda ingresar letras a un archivo, 
guardando cada letra y luego corrobore si las siguientes letras se encuentran en el archivo
(no importa el orden, lo importante es que estén): a,b,d,g,h,z,e,t. 
En caso que la o no la encuentre, imprima, con una frase que sea expresiva, 
cual es la que no o si encuentra (Ej: “La letra que no se encuentra en el archivo es: h”)
*/
#include <iostream>
#include <stdio.h>

using namespace std;

void escribir(FILE* f){
    char letra;
    cout << "Ingrese una letra ('.' para salir): ";
    cin >> letra;
    while(letra != '.'){
        fputc(letra, f);
        cout << "Ingrese una letra ('.' para salir): ";
        cin >> letra;
    }
}

void imprimir(FILE* f){
    fseek(f, 0, SEEK_SET);
    char c = fgetc(f);
    while(!feof(f)){
        cout << c;
        c = fgetc(f);
    }
}

int pertenece(char c, char letras[]){
    for(int i = 0; i < (sizeof(letras)/sizeof(char)); i++){
        if(c == letras[i]) return i;
    }
    return -1;
}

int noPertenece(char c, char letras[]){
    for(int i = 0; i < (sizeof(letras)/sizeof(char)); i++){
        if(c != letras[i]) return i;
    }
    return -1;
}

void check(FILE* f){
    fseek(f, 0, SEEK_SET);
    char c;
    char letras[] = {'a', 'b', 'd', 'g', 'h', 'z', 'e', 't'};
    c = fgetc(f);
    while(!feof(f)){
        int si = pertenece(c, letras);
        int no = noPertenece(c, letras);
        if(si != -1) cout << "Se ha encontrado la letra " << letras[si] << endl;
        
        c = fgetc(f);
    }
    for(int c = 0; c < (sizeof(letras)/sizeof(char)); c++){
        int j = 0;
        while(letras[c] != l[j]) j++;
        if(letras[c] == l[j]) cout << "Se ha encontrado la letra " << letras[j] << endl;
        else cout << "NO se ha encontrado la letra " << letras[j] << endl;  
    }
}

int main(){
    FILE* f = fopen("ejercicio7.txt", "w+");

    escribir(f);
    cout << "Archivo guardado." << endl << endl;

    cout << "Contenido del archivo: " << endl;
    imprimir(f);

    cout << endl << endl << "Chequeo de letras:" << endl;
    check(f);

    fclose(f);

    return 0;
}
