#include <iostream>
#include "Polinomio.h"

using namespace std;

int main(){
	Polinomio p1(2);

	cout << "Polinomio 1" << endl;
	cin >> p1;

	cout << "P1: " << p1 << endl;
	cout << "P1': " << p1.derivada() << endl;
	cout << "R: " << p1.raiz(999,20) << endl;
					// raiz(Xo, iterações)


}
