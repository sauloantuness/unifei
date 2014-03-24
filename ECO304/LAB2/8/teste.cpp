#include <iostream>
#include "CFracao.h"

using namespace std;

int main(){

	// Criacao do objeto sem parametros
	CFracao f1;

	// Criacao do objeto com parametros
	CFracao f2(2,4);
	
	// Construtor de cópia
	CFracao f3 = f2;

	cout << "f1: ";
	f1.Print();
	cout << endl;

	cout << "f2: ";
	f2.Print();
	cout << endl;

	// Get
	cout << "Get   numerador f2: " << f3.getNumerador() << endl;
	cout << "Get denominador f2: " << f3.getDenominador() << endl;


	// Somar
	f3 = f1.Somar(f2);
	cout << "Somar f1 + f2 =  ";
	f3.Print();
	cout << endl;


	//Subtrair
	f3 = f1.Subtrair(f2);
	cout << "Subtrair f1 - f2 =  ";
	f3.Print();
	cout << endl;

	// Multiplicar
	f3 = f1.Multiplicar(f2);
	cout << "Subtrair f1 * f2 =  ";
	f3.Print();
	cout << endl;

	// Dividir
	f3 = f1.Dividir(f2);
	cout << "Subtrair f1 / f2 =  ";
	f3.Print();
	cout << endl;

	// Maior que
	if(f1.MaiorQue(f2))
		cout << "f1 > f2" << endl;

	// Menor que
	if(f1.MenorQue(f2))
		cout << "f1 < f2" << endl;
	
	// Maior que
	if(f1.Igual(f2))
		cout << "f1 = f2" << endl;
	
	// Como float
	cout << "f1 como float: " << f1.ComoFloat() << endl;
	cout << "f2 como float: " << f2.ComoFloat() << endl;

}
