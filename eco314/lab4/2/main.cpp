#include <iostream>
#include "CFracao.h"

using namespace std;

int main(){

	CFracao f1;
	CFracao f2;

	cout << "F1 \n";
	cin >> f1;

	cout << endl;

	cout << "F2 \n";
	cin >> f2;

	cout << endl;

	cout << "F1 = " << f1 << endl;
	cout << "F2 = " << f2 << endl << endl;

	cout << "Operator+" << endl;
	cout << "F1 + F2 =  " << f1 + f2 << endl << endl;

	cout << "Operator-" << endl;
	cout << "F1 - F2 =  " << f1 - f2 << endl << endl;

	cout << "Operator*" << endl;
	cout << "F1 * F2 =  " << f1 * f2 << endl << endl;

	cout << "Operator/" << endl;
	cout << "F1 / F2 =  " << f1 / f2 << endl << endl;

	cout << "Operator>" << endl;
	cout << "F1 > F2 :";
	f1 > f2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator>=" << endl;
	cout << "F1 >= F2 :";
	f1 >= f2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator<" << endl;
	cout << "F1 < F2 :";
	f1 < f2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator<=" << endl;
	cout << "F1 <= F2 :";
	f1 <= f2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator==" << endl;
	cout << "F1 == F2 :";
	f1 == f2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator!=" << endl;
	cout << "F1 != F2 :";
	f1 != f2 ? cout << "sim\n\n" : cout << "nao\n\n";

}