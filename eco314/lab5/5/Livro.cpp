#include <iostream>
#include <iomanip>
#include <string>
#include "Livro.h"

using namespace std;

istream& operator>>(istream &in, LivroB &L){
	cout << "Titulo: ";
	in >> L.titulo; 
	cout << "Autor: ";
	in >> L.autor; 
	cout << "Genero: ";
	in >> L.genero; 
	cout << "Edicao: ";
	in >> L.edicao;
	return in;
}

ostream& operator<<(ostream &out, const LivroB &L){
	out << L.titulo << ", " << L.autor << " - " << L.edicao << "a edicao (" << L.genero << ")";
	return out;
}

istream& operator>>(istream &in, LivroL &L){
	cout << "Titulo: ";
	in >> L.titulo; 
	cout << "Autor: ";
	in >> L.autor; 
	cout << "Genero: ";
	in >> L.genero; 
	cout << "Edicao: ";
	in >> L.edicao;
	cout << "Preco: ";
	in >> L.preco;
	return in;

}

ostream& operator<<(ostream &out, const LivroL &L){
	out << L.titulo << ", " << L.autor << " - " << L.edicao << "a edicao (" << L.genero << ") " << "R$ " << setprecision(2) << fixed << L.preco;
	return out;
}
