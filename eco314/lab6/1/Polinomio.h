#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <iostream>

using namespace std;

class Polinomio{
protected:
	int grau;
	int* p;

public:
	Polinomio(int n);
	Polinomio(const Polinomio &);
	~Polinomio(){};

	Polinomio derivada();
	float raiz(float=999,int=40);
	float F(float);

	Polinomio operator+(const Polinomio &);
	Polinomio operator-(const Polinomio);

	friend ostream& operator<<(ostream &, const Polinomio &);
	friend istream& operator>>(istream &, Polinomio &);

};

#endif
