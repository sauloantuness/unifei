#include <iostream>
#include "Retangulo.h"

using namespace std;

int main(){
	Retangulo vetor[5];

	for(int i=0; i<5; i++){
		cout << "Retangulo # " << i+1 << endl;
		vetor[i].usuario();
	}

	for(int i=0; i<5; i++){
		vetor[i].imprime();
		cout << endl;
	}

}
