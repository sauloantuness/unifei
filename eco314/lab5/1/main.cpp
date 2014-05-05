#include <iostream>
#include "Polinomio.h"

using namespace std;

int main(){
	Polinomio p1(3);
	Polinomio p2(4);

	cout << "Polinomio 1" << endl;
	cin >> p1;
	cout << "Polinomio 2" << endl;
	cin >> p2;
	cout << endl;

	cout << "P1: " << p1 << endl;
	cout << "P2: " << p2 << endl << endl;

	cout << "P1 + P2 = " << p1 + p2 << endl;
	cout << "P1 - P2 = " << p1 - p2 << endl;
}
