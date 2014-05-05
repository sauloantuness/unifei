#ifndef FORMAS_GEOMETRICAS_H
#define FORMAS_GEOMETRICAS_H

#include <iostream>
#include <string>
using namespace std;

class Ponto{
protected:
	int raio;
	int altura;
	string tipo;
public:
	Ponto();
	~Ponto(){};
	string getTipo() const {return tipo;}
	virtual float area() const;
	virtual float volume() const;
};

class Circulo : public Ponto{
public:
	Circulo(){};
	Circulo(int);
	~Circulo(){}
	virtual float area() const;
	virtual float volume() const;
};

class Cilindro : public Circulo{
public:
	Cilindro(){};
	Cilindro(int, int);
	~Cilindro(){}
	virtual float area() const;
	virtual float volume() const;
};

#endif