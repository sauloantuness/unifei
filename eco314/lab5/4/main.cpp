#include <iostream>
#include "Complexo.h"
#include "CFracao.h"

using namespace std;

int main(){

	Complexo c1;

	cout << "Complexo C1" << endl;
	cin >> c1;
	cout << endl;

	cout << "         C1  = " << c1 << endl;
	cout << "(double)|C1| = " << (double)c1 << endl;
	cout << " (float)|C1| = " << (float)c1 << endl;
	cout << "   (int)|C1| = " << (int)c1 << endl << endl;


	CFracao f1;

	cout << "Fracao F1" << endl;
	cin >> f1;
	cout << endl;

	cout << "        F1 = " << f1 << endl;
	cout << "(double)F1 = " << (double)f1 << endl;
	cout << " (float)F1 = " << (float)f1 << endl;
	cout << "   (int)F1 = " << (int)f1 << endl;

}
