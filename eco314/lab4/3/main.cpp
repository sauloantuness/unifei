#include <iostream>
#include "Complexo.h"

using namespace std;

int main(){

	Complexo c1,c2;

	cout << "C1\n";
	cin >> c1;
	cout << endl;

	cout << "C2\n";
	cin >> c2;
	cout << endl;

	cout << "C1 = " << c1;
	cout << "C2 = " << c2 << endl;


	cout << "Operator+" << endl;
	cout << "C1 + C2 =  " << c1 + c2 << endl;

	cout << "Operator-" << endl;
	cout << "C1 - C2 =  " << c1 - c2 << endl;

	cout << "Operator*" << endl;
	cout << "C1 * C2 =  " << c1 * c2 << endl;

	cout << "Operator/" << endl;
	cout << "C1 / C2 =  " << c1 / c2 << endl;

	cout << "Operator>" << endl;
	cout << "C1 > C2 :";
	c1 > c2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator>=" << endl;
	cout << "C1 >= C2 :";
	c1 >= c2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator<" << endl;
	cout << "C1 < C2 :";
	c1 < c2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator<=" << endl;
	cout << "C1 <= C2 :";
	c1 <= c2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator==" << endl;
	cout << "C1 == C2 :";
	c1 == c2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator!=" << endl;
	cout << "C1 != C2 :";
	c1 != c2 ? cout << "sim\n\n" : cout << "nao\n\n";
}
