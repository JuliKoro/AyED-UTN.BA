#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	FILE *f1;
	FILE *f2;
	int c;
	f1 = fopen("entrada.txt", "r");
	f2 = fopen("salida.txt","w");
	c = fgetc(f1);
	while (!feof(f1)) {
		fputc(c, f2);
		c = fgetc(f1);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
