#ifndef PONTO_H
#define PONTO_H

#include <iostream>
using namespace std;

class Ponto{
protected:
	int x;
	int y;
public:
	Ponto(int X, int Y) : x(X), y(Y) {};
	~Ponto(){};

	Ponto operator++();    // pre
	Ponto operator++(int); // pos
	Ponto operator--();    // pre
	Ponto operator--(int); // pos

	friend ostream& operator<<(ostream &out, const Ponto P);
};

#endif