#include <iostream>
#include "Pilha.h"
using namespace std;

int main(){
	CPilha p(4);

	cout << "Leitura" << endl;	
	for(int i = 0; i < 4; i++)
		cin >> p;
	
	cout << "Impressao" << endl;
	cout << p ;
}