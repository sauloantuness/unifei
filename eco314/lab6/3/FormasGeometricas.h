#ifndef FORMAS_GEOMETRICAS_H
#define FORMAS_GEOMETRICAS_H

#include <iostream>
using namespace std;

class Ponto{
protected:
	int raio;
	int altura;
public:
	Ponto();
	~Ponto(){};
	float area() const;
	float volume() const;
	friend ostream& operator<<(ostream &, const Ponto &);
};

class Circulo : public Ponto{
public:
	Circulo(){};
	Circulo(int);
	~Circulo(){}
	friend istream& operator>>(istream &, Circulo &);
};


class Cilindro : public Circulo{
public:
	Cilindro(){};
	Cilindro(int, int);
	~Cilindro(){}
	friend istream& operator>>(istream &, Cilindro &);
};

#endif