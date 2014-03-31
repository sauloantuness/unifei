#include <iostream>
#include "Complexo.h"

using namespace std;

int main(){

	cout << "Objetos: " << Complexo::getContador() << endl;
	Complexo c1(2,3);
	Complexo c2(5,-1);
	Complexo c3;

	cout << "c1: ";
	c1.Print();
	cout << "c2: ";
	c2.Print();
	cout << "c3: ";
	c3.Print();

	cout << "Objetos: " << Complexo::getContador() << endl;

	cout << "(2 + 3i) + (5 - 1i) = ";
	c3 = c1.Somar(c2);
	c3.Print();

	cout << "(2 + 3i) - (5 - 1i) = ";
	c3 = c1.Subtrair(c2);
	c3.Print();

	cout << "(2 + 3i) * (5 - 1i) = ";
	c3 = c1.Multiplicar(c2);
	c3.Print();

	cout << "(2 + 3i) / (5 - 1i) = ";
	c3 = c1.Dividir(c2);
	c3.Print();

	cout << "Modulo: " << c3.Modulo() << endl;
	cout << "Objetos: " << Complexo::getContador() << endl;
}
