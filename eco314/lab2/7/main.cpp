#include <iostream>
#include "polReg.h"

using namespace std;


int main(){
	PolReg p(4,2);
	p.nome();
	cout << endl;
	cout << "Area: " << p.area() << endl;
	cout << "Perimetro: " << p.perimetro() << endl;
	
}
