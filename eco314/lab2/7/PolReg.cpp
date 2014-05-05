#include <iostream>
#include "polReg.h"
#include <cmath>


using namespace std;



int PolReg::area(){
	return	lados * comprimento * comprimento * cos(3.14159 / lados) / sin(3.14159 / lados) / 4;
}

int PolReg::perimetro(){
	return lados * comprimento;	
}

void PolReg::nome(){
	switch(lados){
		case 3: cout << "Triangulo"; break;
		case 4: cout << "Quadrado"; break;
		case 5: cout << "Pentagono"; break;
		case 6: cout << "Hexagono"; break;
		case 7: cout << "Heptagono"; break;
		case 8: cout << "Octogono"; break;
		case 9: cout << "Eneagono"; break;
		case 10: cout << "Decagono"; break;
	}
}
