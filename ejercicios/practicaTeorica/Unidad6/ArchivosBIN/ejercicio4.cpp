/* 4)Generar un programa, en el cual se pueda escribir cuantos structs Nodo se necesite 
(por consola se ingresan los datos) en un archivo binario, 
hasta que se ingrese un número 0 en la variable ‘int valor’, esa es la condición de corte.
Una vez ingresados los datos en, leer el archivo y solamente imprimir el valor de los structs que tengan 
el ‘bool imprimir’ en true.
struct Nodo{
	bool imprimir;
	int valor;
}
*/
#include <iostream>
#include <stdio.h>

using namespace std;

struct Nodo{
	bool imprimir;
	int valor;
};

void ingresar(FILE* f, Nodo info){
    char cond;
    while(info.valor != 0){
        cout << "Ingrese un valor (0 para salir): ";
        cin >> info.valor;
        if(info.valor != 0){
            cout << "¿Se puede imprimir? (Si/No): ";
            cin >> cond;
            if(cond == 'S' || cond == 's') info.imprimir = true;
            else info.imprimir = false;
            fwrite(&info, sizeof(Nodo), 1, f);
        }
        cin.ignore();
    }
    cout << "Archivo cargado con exito." << endl << endl;
}

void imprimir(Nodo info){
    if(info.imprimir) cout << info.valor << endl;
}

void leer(FILE* f){
    Nodo aux;
    fseek(f, 0, SEEK_SET);
    while(!feof(f)){
        fread(&aux, sizeof(Nodo), 1, f);
        imprimir(aux);
    }
}

int main(){
    Nodo info;
    FILE* f = fopen("ejercicio4.dat", "wb+");

    ingresar(f, info);

    cout << "Valores imprimibles: " << endl;
    leer(f);

    fclose(f);

    return 0;
}