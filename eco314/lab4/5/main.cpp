#include <iostream>
#include "Longo.h"

using namespace std;

// Foi corrigido a subtração do lab anterior.
// No lab anterior não tratei quando se tinha uma situação do tipo
// numero - numero_maior
// Agora é feito a subtração, porém não se armazena o sinal do número.


int main(){

	Longo l1;
	Longo l2;

	cout << "L1 \n";
	cin >> l1;

	cout << endl;

	cout << "L2 \n";
	cin >> l2;

	cout << endl;

	cout << "L1 = " << l1 << endl;
	cout << "L2 = " << l2 << endl << endl;

	cout << "Operator+" << endl;
	cout << "L1 + L2 =  " << l1 + l2 << endl << endl;

	cout << "Operator-" << endl;
	cout << "L1 - L2 =  " << l1 - l2 << endl << endl;


	cout << "Operator>" << endl;
	cout << "L1 > L2 :";
	l1 > l2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator>=" << endl;
	cout << "L1 >= L2 :";
	l1 >= l2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator<" << endl;
	cout << "L1 < L2 :";
	l1 < l2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator<=" << endl;
	cout << "L1 <= L2 :";
	l1 <= l2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator==" << endl;
	cout << "L1 == L2 :";
	l1 == l2 ? cout << "sim\n\n" : cout << "nao\n\n";

	cout << "Operator!=" << endl;
	cout << "L1 != L2 :";
	l1 != l2 ? cout << "sim\n\n" : cout << "nao\n\n";
}