#include <iostream>
#include "CVetor.h"

using namespace std;


int main(){
	CVetor v1(30);
	CVetor v2(30);

	cout << "V1 \n";
	cin >> v1;

	cout << endl;

	cout << "V2 \n";
	cin >> v2;

	cout << endl;

	cout << "V1 = " << v1 << endl;
	cout << "V2 = " << v2 << endl << endl;

	// cout << "Operator+" << endl;
	// cout << "L1 + L2 =  " << l1 + l2 << endl << endl;

	// cout << "Operator-" << endl;
	// cout << "L1 - L2 =  " << l1 - l2 << endl << endl;

	cout << "Operator>" << endl;
	cout << "V1 > V2 :";
	v1 > v2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator>=" << endl;
	cout << "V1 >= V2 :";
	v1 >= v2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator<" << endl;
	cout << "V1 < V2 :";
	v1 < v2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator<=" << endl;
	cout << "V1 <= V2 :";
	v1 <= v2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator==" << endl;
	cout << "V1 == V2 :";
	v1 == v2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator!=" << endl;
	cout << "V1 != V2 :";
	v1 != v2 ? cout << "sim\n\n" : cout << "nao\n\n";
}