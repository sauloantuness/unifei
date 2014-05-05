#include <iostream>
#include "FormasGeometricas.h"

#define TAM 3 // Define o número de objetos a serem criados

using namespace std;

// Agora será feito a resolução dinâmica de métodos.

int main(){

	Ponto **ptrPonto = new Ponto*[TAM];
	int op,raio,altura;

	for(int i=0; i<TAM; i++){

		cout << endl;
		cout << ":: Escolha o tipo a ser criado: " << endl;
		cout << " 1 - Ponto " << endl;
		cout << " 2 - Circulo " << endl;
		cout << " 3 - Cilindro " << endl;
		cin >> op;

		// Não estou tratando o valor de op que o usuário digita porque não é o objetivo do exercício.

		if(op == 1){
			ptrPonto[i] = new Ponto();	
			continue;
		}

		cout << "Raio: ";
		cin >> raio;

		if(op == 2){
			ptrPonto[i] = new Circulo(raio);
			continue;
		}

		cout << "Altura: ";
		cin >> altura;

		if(op == 3){
			ptrPonto[i] = new Cilindro(raio,altura);
			continue;
		}
	}

	cout << endl << endl;
	cout << "  Objetos criados " << endl << endl;

	for(int i=0; i<TAM; i++){
		cout << "     :: " << ptrPonto[i]->getTipo() << endl; // Criei este atributo apenas para identicar o objeto na hora da impressão
		cout << "  Area: " << ptrPonto[i]->area()    << endl;
		cout << "Volume: " << ptrPonto[i]->volume()  << endl;
		cout << endl;
	}
}	

