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
	float area() const;
	float volume() const;
};

class Circulo : public Ponto{
public:
	Circulo(){};
	Circulo(int);
	~Circulo(){}
	float area() const;
	float volume() const;
};

class Cilindro : public Circulo{
public:
	Cilindro(){};
	Cilindro(int, int);
	~Cilindro(){}
	float area() const;
	float volume() const;
};

#endif