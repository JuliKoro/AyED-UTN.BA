
#include <iostream>

using namespace std;

int main(){
	float n,CantAlumn,aprobados=0,desaprobados=0;
	float porcentajea,porcentajeb;
	string Alumn;
	cout<<"Ingrese cantidad de alumnos: ";
	cin>>CantAlumn;
	for (int i=1; i<=CantAlumn; i++){
	cout<<"Ingrese el nombre del alumno/a: ";
	cin>>Alumn;
	cout<<"Ingrese nota del examen: ";
	cin>>n;
	if(n>=6){
		cout<<"El/La alumno/a "<<Alumn<<" esta aprobado/a :)"<<endl;
		aprobados=aprobados+1;
	}
	else{
		cout<<"El/la alumno "<<Alumn<<" esta desaprobado/a :("<<endl;
		desaprobados=desaprobados+1;
	}
}
cout<<"Cant de alumnos: "<<CantAlumn<<endl;
cout<<"Cant de aprobados: "<<aprobados<<endl;
cout<<"Cant de desaprobados: "<<desaprobados<<endl;
porcentajea=(aprobados/CantAlumn)*100;
porcentajeb=(desaprobados/CantAlumn)*100;
cout<<"El porcentaje de alumnos aprobados es: "<<porcentajea<<"%"<<endl;
cout<<"El porcentaje de alumnos desaprobados es: "<<porcentajeb<<"%";
return 0;
}
