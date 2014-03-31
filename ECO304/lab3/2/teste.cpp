#include <iostream>
#include "Longo.h"

using namespace std;

int main(){
	Longo l1("888888888888888888");
	Longo l2("111111111111111111");
	Longo l3;
	
	cout << "L1: " << l1.getNum() << endl;
	cout << "L2: " << l2.getNum() << endl;
	cout << "L3: " << l3.getNum() << endl;

	l3 = l1.Somar(l2);
	cout << "L1 + L2: " << l3.getNum() << endl;
	
	l3 = l1.Subtrair(l2);
	cout << "L1 - L2: " << l3.getNum() << endl;

	l3.setNum();
	cout << "L3: " << l3.getNum() << endl;
}
