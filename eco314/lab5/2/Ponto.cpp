#include <iostream>
#include "Ponto.h"

using namespace std;

ostream& operator<<(ostream &out, const Ponto P){
	out << "(" << P.x << ", " << P.y << ")" ;
	return out;
}

Ponto Ponto::operator++(){
	x++;
	y++;
	return (*this);
}

Ponto Ponto::operator++(int){
	Ponto temp = *this;
	x++;
	y++;
	return temp;
}

Ponto Ponto::operator--(){
	x--;
	y--;
	return (*this);
}

Ponto Ponto::operator--(int){
	Ponto temp = *this;
	x--;
	y--;
	return temp;
}