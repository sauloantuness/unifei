#include <iostream>
#include "TrianguloRetangulo.h"

using namespace std;

int main(){
	
	TrianguloRetangulo NT(1,1,2);   // Triangulo invalido
	TrianguloRetangulo TR(8,6,10);

	cout << "Modo (a):" << endl;
	TR.imprime('a');
	cout << endl;

	cout << "Modo (b):" << endl;
	TR.imprime('b');
	cout << endl;
	
	cout << "Modo (c):" << endl;
	TR.imprime('c');
	cout << endl;
	
	cout << "Modo (d):" << endl;
	TR.imprime('d');
	cout << endl;

	if(TR.ehTriangulo())
		cout << "Eh Triangulo" << endl;
	else
		cout << "Nao eh Triangulo" << endl;

	if(TR.ehRetangulo())
		cout << "Eh Retangulo" << endl;
	else
		cout << "Nao eh Retangulo" << endl;

	TR.Quinhentos();

	return 0;
}
