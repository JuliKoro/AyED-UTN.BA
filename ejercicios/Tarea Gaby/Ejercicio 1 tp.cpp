#include <iostream>
#include <stdlib.h>
#include <stdio.h>
/*1))Generar el archivo “Repartidores.dat” con un registro por cada repartidor que se presentó para el
trabajo, estos datos se ingresan por teclado. Cada registro del archivo debe tener el dni, el nombre y
apellido y la zona de trabajo (del 1 al 6)

2)Informar cantidad de repartidores inscriptos para trabajar en cada una de las 6 zonas en que se
divide la ciudad.

3)Informar, si hubo, las zonas en las que no se postularon repartidores.
*/
using namespace std;

struct repartidores{
	unsigned dni;
	char NomApe[30];
	unsigned zona;
	unsigned cant[100];
};
	void zona(int);
int main()
{
    repartidores r;
	FILE * ArchRe= fopen("Repartidores.dat","wb");
	int i=0, cont1=0, cont2=0,cont3=0,cont4=0,cont5=0,cont6=0;
	if(ArchRe==NULL){
		cout<<"error"<<endl;
		}
		else{
			//ingreso de datos
			cout<<"ingrese el numero de DNI del repartidor"<<endl;
			cin>>r.dni;
			while(r.dni!=0){
				cin.ignore();
				cout<<"ingrese el nombre y de apellido del repartidor"<<endl;
				cin.getline(r.NomApe,30);
				cout<<"ingrese el nimero de zona(1: boedo, 2: Parque Patricios, 3: Barracas, 4: Caballito, 5: Chacarita, 6: Balbanera)"<<endl;
				cin>>r.zona;
				zona(r.zona);
				r.cant[i]=r.zona;
				fwrite(&r, sizeof(repartidores),1,ArchRe);
				i++;
				cout<<"ingrese el numero de DNI del repartidor"<<endl;
		 		cin>>r.dni;
		 		
			}
			for(int f=0;f< i;f++ ){
				if(r.cant[f]==1){
					cont1++;
				}
				if(r.cant[f]==2){
					cont2++;
				}
				if(r.cant[f]==3){
					cont3++;
				}
				if(r.cant[f]==4){
					cont4++;
				}
				if(r.cant[f]==5){
					cont5++;
				}
				if(r.cant[f]==6){
					cont6++;
				}
			 }

			cout<<"cantidad de repartidores inscriptos en boedo: "<<cont1<<endl;
			cout<<"cantidad de repartidores inscriptos en Parque Patricios: "<<cont2<<endl;
			cout<<"cantidad de repartidores inscriptos en Barracas: "<<cont3<<endl;
			cout<<"cantidad de repartidores inscriptos en Caballito: "<<cont4<<endl;
			cout<<"cantidad de repartidores inscriptos en Chacarita: "<<cont5<<endl;
			cout<<"cantidad de repartidores inscriptos en Balbanera: "<<cont6<<endl;
			fclose(ArchRe);
		}
	system("pause");
   return 0;
}

void zona(int z){
string zona;
	switch(z){
		case 1:
			cout<<"zona Boedo"<<endl;
			break;
		case 2:
			cout<<"zona Parque Patricios"<<endl;
			break;
        case 3:
			cout<<"zona Barracas"<<endl;
			break;
		case 4:
            cout<<"zona Caballito"<<endl;
            break;
		case 5:
            cout<<"zona Chacarita"<<endl;
            break;
		case 6:
            cout<<"zona Balvanera"<<endl;
            break;
		default:
			cout<<"el numero ingreseado no pertenece a ninguna zona"<<endl;
			break;
		}
		
}
