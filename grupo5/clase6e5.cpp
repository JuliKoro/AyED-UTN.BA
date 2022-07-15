/*Observaciones:
    Esta bien el programa, en si cumple con lo que deberia hacer, pero lo que se buscaba era pasar por parametro la
    cantidad de canales HD y en el de comercial solicitar las conexiones en la funcion calculClienteC.
    Lean bien las consignas y cuando no entiendan algo pregunten que para eso estamos.
    La idea de este tp semanal era la de implementar las funciones y los prototipos de las mismas, para la proxima
    utilicen los prototipos y escriban el desarrollo de cada funcion abajo del main.
    Cualquier duda o cosa que no entiendan de pq les pongo esta observación diganme.
    Atte. Matias
    
    Lo que se pedía era un programa que desde el main solicitara el num de cliente, el tipo de cliente y la cantidad
    de canales HD (lo hace) para entonces llamar a:
        (para r o R) calculoClienteR(float) y devolver el valor de la factura para imprimirlo desde el main (lo hace)
        (para c o C) calculoClienteC(float) y solicitar desde la funcion que se ingrese la cantidad de conexiones, determinar
            que cuenta realizar (para >10 una cosa y para <=10 otra) y devolver el valor de la factura para q sea impresa
            desde el main (mal)
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int precioCanalesHD = 5;
const int conexAdicionales = 5;

int conexiones, hd, numeroCliente;
float envFactura, servBasico, importe;
char tipoCliente;

float calculoClienteR () {
	importe = envFactura + servBasico + hd*precioCanalesHD;
	return importe;
}

float calculoClienteC (){
	if (conexiones>10){
		importe = envFactura + servBasico + ((conexiones-10)*5) + (hd*precioCanalesHD);
	} else {
		importe = envFactura + servBasico + (hd*precioCanalesHD);
	}
	return importe;
}

int main () {
	while (numeroCliente>=0){
		cout<<"Ingrese numero de cliente: ";
		cin>>numeroCliente;
        if (numeroCliente>=0){
            cout<<"Ingrese tipo de cliente residente (R o r) o comercial (C o c): ";
            cin>>tipoCliente;
            cout<<"Ingrese cantidad de canales HD: ";
            cin>>hd;
            switch(tipoCliente){
                case 'R': case'r':
                    envFactura = 4.50;
                    servBasico = 20.50;
                    importe = calculoClienteR();
                    break;
                case 'C': case'c':
                    cout<<"Ingrese cantidad de conexiones: ";
                    cin>>conexiones;
                    envFactura = 15;
                    servBasico = 75;
                    importe = calculoClienteC();
                    break;
            }
            cout<<setprecision(2);
            cout<<fixed<<showpoint;
            cout<<"Numero de cliente: "<<numeroCliente<<endl;
            cout<<"Importe total: $ "<<importe<<endl;
            cout<<"Para salir ingrese un numero negativo de cliente. "<<endl;
        }
    }
	return 0;
}
