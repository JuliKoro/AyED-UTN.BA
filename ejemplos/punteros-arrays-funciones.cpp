#include <iostream>
#include <stdlib.h>

using namespace std;

int hallarMax(int *, int);


int main (){
	int numeros[] = {5,8,7,9,2};
	const int nElementos = 5;
	
	cout<<"El mayor elemento es: "<<hallarMax(numeros, nElementos)<<endl;
	
	system("pause");
	return 0;
}

int hallarMax(int *dir, int nElementos){
	int max=0;
	for (int i=0; i<nElementos; i++){
		if(*(dir+i)>max){
			max = *(dir+i);
		}
	}
	return max;
}

