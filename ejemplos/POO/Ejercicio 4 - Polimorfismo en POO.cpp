//Ejercicio 4: Polimorfismo
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Animal{
	protected:
		string name;
	public:
		Animal(string);
		virtual void eat();
};

class Human : public Animal{
	private:
		int age;
	public:
		Human(string,int);
		void eat();
};

class Dog : public Animal{
	private:
		string race;
	public:
		Dog(string,string);
		void eat();
};

Animal::Animal(string _name){
	name = _name;
}

Human::Human(string _name, int _age) : Animal(_name){
	age = _age;
}

Dog::Dog(string _name, string _race) : Animal(_name){
	race = _race;
}

void Animal::eat(){
	cout<<"comiendo";
}

void Human::eat(){
	cout<<"Hola! Soy "<<name<<", tengo "<<age<<" y estoy ";
	Animal::eat();
	cout<<" con cubiertos sobre una mesa"<<endl;
}

void Dog::eat(){
	cout<<"Uau! Soy "<<name<<", soy un "<<race<<" y estoy ";
	Animal::eat();
	cout<<" con mi oscico en el suelo."<<endl;
}

int main(){
	Animal *vector[3];
	vector[0] = new Human("Julian",19);
	vector[0]->eat();
	cout<<"\n";
	vector[1] = new Dog("Linda","Callejero");
	vector[1]->eat();
	cout<<"\n";
	vector[2] = new Dog("Fito", "Ovejero aleman");
	vector[2]->eat();
	system("pause");
	return 0;
}
