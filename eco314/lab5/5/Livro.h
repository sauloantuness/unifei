#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include <string>

using namespace std;

class LivroB{
protected:
	string titulo;
	string autor;
	string genero;
	int edicao;

public:
	LivroB(){};
	~LivroB(){};

	friend istream& operator>>(istream &, LivroB &);
	friend ostream& operator<<(ostream &, const LivroB &);

};

class LivroL{
protected:
	string titulo;
	string autor;
	string genero;
	int edicao;
	float preco;

public:
	LivroL(){};
	~LivroL(){};

	friend istream& operator>>(istream &, LivroL &);
	friend ostream& operator<<(ostream &, const LivroL &);

};


#endif
