#include <iostream>
#include "EqSegundoGrau.h"

using namespace std;

EqSegundoGrau::EqSegundoGrau(int A, int B, int C){
	a = A;
	b = B;
	c = C;
	delta = b*b - 4*a*c;
}

void EqSegundoGrau::tipoRaiz(){
	if(delta == 0)
		cout << "Raiz real unica" << endl;
	if(delta < 0)
		cout << "Raizes complexas" << endl;
	if(delta > 0)
		cout << "Raizes reais e distintas" << endl;
}

ostream& operator<<(ostream &saida, EqSegundoGrau &e){
	saida << e.a << "x^2 ";

	if(e.b > 0)
		saida << "+";
	saida << e.b << "x ";

	if(e.c > 0)
		saida << "+";
	saida << e.c;
	
	return saida;;
}