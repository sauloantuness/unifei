#include <iostream>
#include <cstdlib>
#include "Vetor.h"

using namespace std;

// O tipo do vetor deve possuir o operador < sobrecarregado para ser ordenado
// Por exemplo, se for uma struct. Dentro dela deve ser sobrecarregado um operator
// bool operator<(const &NomeDaStruct) const;

struct Elefante{
	int peso;
	Elefante(){}
	Elefante(int peso) : peso(peso) {}

	bool operator<(const Elefante& e) const {
		return peso < e.peso;
	}

	friend ostream& operator<<(ostream& out, const Elefante& e){
		out << "E_" << e.peso;
		return out;
	}
};

int main(){
	Vetor<int> vet(10);

	cout << "Vetor de int" << endl;
	for (int i = 0; i < vet.size(); ++i){
		vet[i] = rand()%10;
		cout << vet[i] << " ";
	}

	vet.Ordena();
	cout << endl;

	for (int i = 0; i < vet.size(); ++i)
		cout << vet[i] << " ";
	cout << endl << endl;
	
	Vetor<Elefante> evet(10);

	cout << "Vetor de Elefante" << endl;
	for (int i = 0; i < evet.size(); ++i){
		evet[i] = Elefante(rand()%10);
		cout << evet[i] << " ";
	}

	evet.Ordena();
	cout << endl;

	for (int i = 0; i < evet.size(); ++i)
		cout << evet[i] << " ";
	cout << endl << endl;


// Acessando posição inválida
	try{
		evet[10];
	}
	catch(int e){
		cout << "A posicao " << e << " eh invalida" << endl;
	}
}