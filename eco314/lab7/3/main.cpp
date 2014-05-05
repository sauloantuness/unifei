#include <iostream>
#include "FormasGeometricas.h"

#define TAM 3 // Define o número de objetos a serem criados

using namespace std;

// Como não foi declarado os métodos area() e volume() como virtual, 
// não será feito a escolha dinâmica dos métodos quando chamado através ponteiro.
// O que resultará na chamada dos métodos da classe base Ponto, que retorna 0 tanto para area() quanto volume().

// Em relação ao lab anterior, a classe foi simplificada deixando apenas o que é necessário para a demonstração do exercício e também para facilitar a correção.

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