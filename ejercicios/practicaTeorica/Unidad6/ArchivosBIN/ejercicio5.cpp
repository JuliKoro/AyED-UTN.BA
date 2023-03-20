/* 5) Teniendo un struct de un remito, con los campos número de remito, 
número de producto y nombre del conductor, escriba 3 tipos de remitos distintos en un archivo binario. 
Luego ciérrelo, ábralo nuevamente e imprima lo más claro posible los datos del remito.
*/
#include <iostream>
#include <stdio.h>

using namespace std;

struct Remito{
    int numero;
    int nro_producto;
    char nom_conductor[20];
};

void ingresar(FILE* f, Remito remito){
    while(remito.numero != 0){
        cout << "Ingrese nro. del remito (0 para salir): ";
        cin >> remito.numero;
        if (remito.numero != 0){
            cout << "Ingrese nro. de producto: ";
            cin >> remito.nro_producto;
            cout << "Ingrese nombre del conductor: ";
            cin.ignore();
            cin.getline(remito.nom_conductor, 20);
            fwrite(&remito, sizeof(Remito), 1, f);
        }
    }
    cout << "Archivo guardado." << endl << endl;
}

void imprimir(FILE* f){
    Remito aux;
    while(!feof(f)){
        fread(&aux, sizeof(Remito), 1, f);
        cout << "Remito Nro.: " << aux.numero << endl;
        cout << "Producto Nro.: " << aux.nro_producto << endl;
        cout << "Conductor: " << aux.nom_conductor << endl << endl;
    }
}

int main(){
    Remito remito;
    FILE* fw = fopen("ejercicio5.dat", "wb");

    ingresar(fw, remito);
    fclose(fw);

    FILE* fr = fopen("ejercicio5.dat", "rb");

    imprimir(fr);
    fclose(fr);

    return 0;
}