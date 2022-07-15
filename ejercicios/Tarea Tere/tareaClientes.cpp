#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Cliente{
	int usuarioId;
	int fechaCracion;
	bool activo;
	float totalImporte;
	char email;
};

const int CANT = 1000;

int main(){
	Cliente clientes[CANT];
	int n = 0;
	int cont = 0;
	while(n!=4){
		cout<<"Eliga una opcion: "<<endl<<"1. Levantar clientes."<<endl<<"2. Cargar nuevo cliente."<<endl<<"3. Eliminar un cliente."<<endl<<"4. Salir."<<endl;
		cin>>n;
		switch(n){
			case 1: 
				FILE* f=fopen("Clientes.bin","rb+");
			 	while (!feof(f)) {
			 		fread(&clientes[cont], sizeof(Cliente),1,f);
			 		cont++;
				 }
				fclose(f);
				break;
			case 2:
				int act;
				FILE* f=fopen("Clientes.bin","wb");
				cout<<"Ingrese Usuario ID: ";
				cin>>clientes[cont].usuarioId;
				cout<<"Ingrese Fecha de Creacion (AAAAMMDD): ";
				cin>>clientes[cont].fechaCracion;
				cin>>"Es Activo? 1. Si, 2. No: ";
				if (act == 1) clientes[cont].activo = true;
				else clientes[cont].activo = false;
				cout<<"Ingrese Total imporete de Compras: $";
				cin>>clientes[cont].totalImporte;
				cout<<"Ingrese e-mail: ";
				//cin.ignore();
				cin.getline(clientes[cont].email,25);
				fseek(f,0,SEEK_END);
				fwrite(&clientes[cont],sizeof(Cliente),1,f);
				cont++;
				fclose(f);
				break;
			case 3:
				
				
		}
	}
}

