//Observacion: aprobado

# include <iostream>
using namespace std;
	
int main() {
	int negativo = 0 ;
	float saldo;
	
	for (int i = 1; i <= 12; i++) {
		cout << "Ingrese el saldo por mes"<< endl;
		cout << "Saldo del mes " << i << ": $";
		cin >> saldo;
		if (saldo <=0) negativo++;
	}
	
	if (negativo == 0) {
    	cout << "Confianza alta."<< endl; 
	} else if (negativo>0 && negativo<=2) {
		cout << "Confianza media." << endl;
	} else {
           cout << "Confianza baja." << endl;	
	}
	return 0;
}

