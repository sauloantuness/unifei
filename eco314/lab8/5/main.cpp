#include <string>
#include "Pilha.h"
using namespace std;

int main(){

	// Pilha de int
	CPilha<int> pInt(3);
	pInt.push(1);
	pInt.push(2);
	pInt.push(3);

	cout << "Pilha de Int: " << endl;
	cout << pInt << endl;
	
	// Pilha de float
	CPilha<float> pFloat(3);
	pFloat.push(10.0);
	pFloat.push(20.0);
	pFloat.push(30.0);
	
	cout << "Pilha de Float: " << endl;
	cout << pFloat << endl;
	
	// Pilha de string
	CPilha<string> pString(3);
	pString.push("string 1");
	pString.push("string 2");
	pString.push("string 3");
	
	cout << "Pilha de String: " << endl;
	cout << pString << endl;

	// Pilha de CPilha<string>
	CPilha< CPilha<string> > pCPilha(3);

	CPilha<string> pString1(3);
	pString1.push("pString1 1");
	pString1.push("pString1 2");
	pString1.push("pString1 3");

	CPilha<string> pString2(3);
	pString2.push("pString2 1");
	pString2.push("pString2 2");
	pString2.push("pString2 3");

	CPilha<string> pString3(3);
	pString3.push("pString3 1");
	pString3.push("pString3 2");
	pString3.push("pString3 3");

	pCPilha.push(pString1);
	pCPilha.push(pString2);
	pCPilha.push(pString3);
	
	cout << "Pilha de CPilha<string>: " << endl;
	cout << pCPilha << endl;
}