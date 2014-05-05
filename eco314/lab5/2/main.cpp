#include <iostream>
#include "Ponto.h"

using namespace std;

int main(){
	Ponto p(1,2);

	cout << "  P: " << p << endl;
	cout << "P++: " << p++ << endl;
	cout << "  P: " << p << endl;
	cout << "++P: " << ++p << endl;
	cout << "  P: " << p << endl << endl;

	cout << "  P: " << p << endl;
	cout << "P--: " << p-- << endl;
	cout << "  P: " << p << endl;
	cout << "--P: " << --p << endl;
	cout << "  P: " << p << endl;
}