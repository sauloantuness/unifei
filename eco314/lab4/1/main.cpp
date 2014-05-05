#include <iostream>
#include "EqSegundoGrau.h"

using namespace std;

int main(){
	EqSegundoGrau r(1,-5,6);
	cout << r << endl;
	r.tipoRaiz();
	cout << endl;
	
	EqSegundoGrau d(4,-4,1);
	cout << d << endl;
	d.tipoRaiz();
	cout << endl;
	
	EqSegundoGrau c(1,-4,5);
	cout << c << endl;
	c.tipoRaiz();
	cout << endl;
}