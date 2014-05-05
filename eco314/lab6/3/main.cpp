#include <iostream>
#include "FormasGeometricas.h"

using namespace std;

int main(){
	// Foi definido como 0 aqueles parametros que um objeto não tem. Como a altura em um círculo. (Sugestão dada em laboratório)

	Ponto ponto;
	Circulo circulo;
	Cilindro cilindro;

	cout << ":: Circulo ::" << endl;
	cin >> circulo;

	cout << endl;
	
	cout << ":: Cilindro ::" << endl;
	cin >> cilindro;

	cout << endl << endl;

	cout << ":: Ponto ::"  << endl << ponto << endl;
	cout << ":: Circulo ::"  << endl << circulo << endl;
	cout << ":: Cilindro ::" << endl << cilindro << endl;
}