#include "Politico.h"
#include <iostream>
#include <string>

using namespace std;

Presidente::Presidente(string Nome, string Partido, string Pais){
	nome = Nome;
	partido = Partido;
	pais = Pais;

}

Governador::Governador(string Nome, string Partido, string Pais, string Estado) :
	Presidente::Presidente(Nome, Partido, Pais)
{
	estado = Estado;

}

Prefeito::Prefeito(string Nome, string Partido, string Pais, string Estado, string Cidade) :
	Governador::Governador(Nome, Partido, Pais, Estado)
{
	cidade = Cidade;

}

void Presidente::Imprime(){
	cout << "Nome: " << nome << endl;
	cout << "Partido: " << partido << endl;
	cout << "Pais: " << pais << endl;
}

void Governador::Imprime(){
	Presidente::Imprime();
	cout << "Estado: " << estado << endl;
}

void Prefeito::Imprime(){
	Governador::Imprime();
	cout << "Cidade: " << cidade << endl;
}
