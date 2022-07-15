#include <iostream>

using namespace std;

int factorial(int);

int main(){
	int n;
	cout << "Ingrese un numero que desee saber su factorial: ";
	cin >> n;
	cout << "Factorial de " << n << " es " << factorial(n) << endl;
	return 0;
}

int factorial (int n){
	if (n == 0) n = 1; //Caso base
	else n = n * factorial(n-1); //Caso general
	return n;
}
