/*Los rubros de los negocios a los que presta servicio la empresa de delivery son Heladería, Pizzería, Bebidas,
Parrilla.
Se ingresan los datos de los negocios que quieren trabajar con la empresa.
Por cada negocio se ingresa: Nombre de comercio, rubro y código de zona en la que se encuentra.
Se admite un máximo de 10 comercios por rubro por cada zona.
Al momento de ingresar los datos del comercio rechazar su incorporación si ya se completó el cupo para el
rubro en esa zona.
La finalización del ingreso de datos de los comercios queda a criterio del grupo.
Se pide:
1) Generar los archivos “Heladerias.dat”, “Pizzeria.dat”, “Bebidas.dat” y “Parrilla.dat” con los comercios
incorporados por cada rubro. Cada registro de cada uno de los archivos debe tener: nombre del
comercio y código de zona en la que se encuentra. Estos archivos deben estar ordenados
alfabéticamente por nombre del comercio.
2) Informar por cada zona si hay comercios para todos los rubros.
3) Informar, si hubo, rubros en los que no se hayan incorporado comercios.
Para realizar los puntos 2 y 3 utilizar estructuras de datos en memoria (arrays), no hacerlo con los archivos
generados.*/

#include <iostream>
#include <stdio.h>
#include <string.h>


struct C{ //Comercios
char n[20]; //Nombre
int z;//Zona
};

using namespace std;

int Guardar(C v[60], int t, FILE* a);
int OrdenarAlfabeticamente(C v[60], int t);
int IniciarZonas(int v[6]);
int IniciarRubros(int v[4]);
int IniciarHCPZ(bool m[4][6]);
int MostrarSiHCPZ(bool m[4][6]);

int main(){
FILE *He;
FILE *Pzz;
FILE *Be;
FILE *Prr;
He=fopen("Heladerias.dat","wb");
Pzz=fopen("Pizzerias.dat","wb");
Be=fopen("Bebidas.dat","wb");
Prr=fopen("Parrillas.dat","wb");
int cn; //Cantidad de negocios
int t;
C h[60];//Heladerias
C pz[60];//Pizzerias
C b[60];//Bebidas
C pr[60];//Parrillas
int cz[6];//Cantidad ingresada por zona
int cr[4];//Cantidad ingresada por rubro
bool hcpz[4][6]; //Hay o no comercios de todo rubro por zona por zona
IniciarHCPZ(hcpz);
IniciarZonas(cz);
IniciarRubros(cr);
char n[20];
int r, z;
//Ingreso de datos
cout<<"Cantidad de negocios que desea ingresar:"<<endl;
cin>>cn;
for(int i=0;i<cn;i++){
cout<<endl<<"Ingrese nombre del comercio"<<endl;
cin.ignore();
cin.getline(n,20);
cout<<endl<<"Ingrese rubro (1 heladeria, 2 pizzeria, 3 bebidas, 4 parrilla)"<<endl;
cin>>r;
cout<<endl<<"Ingrese zona (1 a 6)"<<endl;
cin>>z;
while(cz[z]==10){
cout<<endl<<"Maximo de comercios en la zona alcanzado. Ingrese otra zona"<<endl;
cin>>z;
}
cz[z-1]+= 1;
hcpz[r-1][z-1]=true;
switch(r){
	case 1: strcpy(h[cr[0]].n,n);
    		h[cr[0]].z = z;
    		cr[0]+=1;
    		break;
    		
    case 2: strcpy(pz[cr[1]].n,n);
    		pz[cr[1]].z = z;
    		cr[1]+=1;
    		break;
    		
    case 3: strcpy(b[cr[2]].n,n);
    		b[cr[2]].z = z;
   			cr[2]+=1;
   			break;
   			
   	case 4: strcpy(pr[cr[3]].n,n);
    		pr[cr[3]].z = z;
    		cr[3]+=1;
    		break;
}
}
//Ordenado alfabetico y Guardado en Archivos
OrdenarAlfabeticamente(h, cr[0]);
Guardar(h, cr[0], He);
OrdenarAlfabeticamente(pz, cr[1]);
Guardar(pz, cr[1], Pzz);
OrdenarAlfabeticamente(b, cr[2]);
Guardar(b, cr[2], Be);
OrdenarAlfabeticamente(pr, cr[3]);
Guardar(pr, cr[3], Prr);
//Comercios para todos los rubros por zona
MostrarSiHCPZ(hcpz);
//Rubros sin comercios
cout<<endl;
if(cr[0]==0){
    cout<<"No hay comercios en heladerias"<<endl;
}
if(cr[1]==0){
    cout<<"No hay comercios en pizzerias"<<endl;
}
if(cr[2]==0){
    cout<<"No hay comercios en bebidas"<<endl;
}
if(cr[3]==0){
    cout<<"No hay comercios en parrillas"<<endl;
}
fclose(He);
fclose(Pzz);
fclose(Be);
fclose(Prr);
}

int IniciarZonas(int v[6]){
	for(int m=0; m<6; m++) v[m]=0;
}

int IniciarRubros(int v[4]){
	for(int j=0; j < 4; j++) v[j]=0;
}

int IniciarHCPZ(bool m[4][6]){
for(int i=0;i<4;i++){
    for(int j=0;j<6;j++){
        m[i][j] = false;
    }
}
}

int MostrarSiHCPZ(bool m[4][6]){
for(int j=0;j<6;j++){
    cout<<endl;
    bool f=false;//Falta algun comercio
    if(m[0][j]==false){
        cout<<"No hay heladerias en la zona "<<j+1<<endl;
        f=true;
    }
    if (m[1][j]==false){
        cout<<"No hay pizzerias en la zona "<<j+1<<endl;
        f=true;
    }
    if (m[2][j]==false){
        cout<<"No hay bebidas en la zona "<<j+1<<endl;
        f=true;
    }
    if (m[3][j]==false){
        cout<<"No hay parrillas en la zona "<<j+1<<endl;
        f=true;
    }
    if(f==false){
        cout<<"Hay comercios de todos los rubros en la zona "<<j+1<<endl;
    }
}
}

int OrdenarAlfabeticamente(C v[60], int t){
int i=1, j;
C aux;
bool cambio;
do{
    cambio=false;
    for(j=0;j<t-i;j++)
    {
        if(strcmp(v[j].n,v[j+1].n)>0){
            aux=v[j];
            v[j]=v[j+1];
            v[j+1]=aux;
            cambio = true;
        }
    }
    i++;
}while(i<t && cambio);
//test de ordenamiento
for(int k=0;k<t;k++){
  cout<<v[k].n<<endl;
}
}

int Guardar(C v[60], int t, FILE* a){
for(int i=0;i<t;i++){
     fwrite(&v[i],sizeof(C),1,a);
}
}

