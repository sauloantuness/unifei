#include "Politico.h"
#include <iostream>
#include <typeinfo>

#define TAM 3

// No lab anterior já havia sido implementado a função imprimir como virtual e usado do Polimorfismo para imprimir os objetos.
// Aqui, apenas retirei o virtual  e a funcao Imprime da classe politico nao imprime nada. Pois a classe politico era abstrata;
// Como não imprime nada, no final do programa serão impressos apenas MAX linhas em branco.

using namespace std;

int main(){
	Politico **ptrPolitico = new Politico*[TAM];
	int op;
	string nome, partido, pais, estado, cidade;

	for(int i=0; i<TAM; i++){

		cout << endl;
		cout << ":: Escolha o tipo a ser criado: " << endl;
		cout << " 1 - Presidente " << endl;
		cout << " 2 - Governador " << endl;
		cout << " 3 - Prefeito " << endl;
		cin >> op;

		cout << "Nome: ";
		cin >> nome;
		cout << "Partido: ";
		cin >> partido;
		cout << "Pais: ";
		cin >> pais;

		// Não estou tratando o valor de op que o usuário digita porque não é o objetivo do exercício.

		if(op == 1){
			ptrPolitico[i] = new Presidente(nome, partido, pais);				
			continue;
		}

		cout << "Estado: ";
		cin >> estado;

		if(op == 2){
			ptrPolitico[i] = new Governador(nome, partido, pais, estado);
			continue;
		}

		cout << "Cidade: ";
		cin >> cidade;

		if(op == 3){
			ptrPolitico[i] = new Prefeito(nome, partido, pais, estado, cidade);		
			continue;
		}
	}

	cout << endl << endl;
	cout << "  Objetos criados " << endl << endl;

	for(int i=0; i<TAM; i++){
		ptrPolitico[i]->Imprime();
		cout << endl;
	}	
}