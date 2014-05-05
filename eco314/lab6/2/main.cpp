#include "Politico.h"
#include <iostream>

using namespace std;

int main(){
	Politico *PtrPolitico;

	cout << ":: PRESIDENTE ::" << endl;
	Presidente presidente("Dilma","PT","Brasil");
	PtrPolitico = &presidente;
	PtrPolitico->Imprime();
	cout << endl;
	
	cout << ":: GOVERNADOR ::" << endl;
	Governador governador("Alberto","PP","Brasil","Minas Gerais");
	PtrPolitico = &governador;
	PtrPolitico->Imprime();
	cout << endl;

	cout << ":: PREFEITO ::" << endl;
	Prefeito   prefeito  ("Rodigo","PMDB","Brasil","Minas Gerais","Itajuba");
	PtrPolitico = &prefeito;
	PtrPolitico->Imprime();
}