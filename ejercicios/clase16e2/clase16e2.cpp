#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Pelicula{
    int codigo;
    char titulo[25];
    char director[25];
    int espectadores;
    int fechaDeEstreno;
    };

void aJson();

void aJson(){
    FILE *b = fopen("peliculas.dat","rb+");
    FILE *j = fopen("peliculas.json", "w");
    Pelicula p[5];
    int c = 0;
    fread(&p[c], sizeof(Pelicula),1,b);
    fprintf(j,"{\r \"peliculas\":[\r");
    while(!feof(b)){
        cout<<"Imprimiendo!:"<<endl;
        fprintf(j,"{\r\t\"codigo\": \" %d \" \r, \t\"titulo\": \" %s \" \r, \t\"director\": \" %s \" \r , \t\"espectadores\": \" %d \" \r \t\"fecha-de-estreno\": \" %d \", \r \"},", p[c].codigo, p[c].titulo, p[c].director, p[c].espectadores, p[c].fechaDeEstreno);
        c++;
        fread(&p[c], sizeof(Pelicula),1,b);
    }
    fprintf(j,"]\r}\r");
    fclose(b);
    fclose(j);
    cout<<"Datos transferidos a .json exitosamente!"<<endl;
}

int main()
{
    aJson();
    return 0;
}
