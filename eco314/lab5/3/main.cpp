#include <iostream>
#include "Data.h"

using namespace std;

int main(){
	Data d;
	cout << "Data" << endl;
	cin >> d;
	cout << "  Data: " << d << endl;
	cout << "Data++: " << d++ << endl;
	cout << "  Data: " << d << endl;
	cout << "++Data: " << ++d << endl;
	cout << "  Data: " << d << endl;
	cout << "Data--: " << d-- << endl;
	cout << "  Data: " << d << endl;
	cout << "--Data: " << --d << endl;
	cout << "  Data: " << d << endl;

}