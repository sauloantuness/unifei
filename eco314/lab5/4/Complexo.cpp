#include <iostream>
#include <cmath>
#include "Complexo.h"

using namespace std;

int Complexo::contador = 0;

double Complexo::Modulo(){
	double modulo;
	modulo = sqrt(real*real + imaginaria*imaginaria);
	return modulo;
}

Complexo Complexo::operator+(Complexo &C){
	Complexo aux;
	aux.real       = real       + C.real;
	aux.imaginaria = imaginaria + C.imaginaria;	
	return aux;
}

Complexo Complexo::operator-(Complexo &C){
	Complexo aux;
	aux.real       = real       - C.real;
	aux.imaginaria = imaginaria - C.imaginaria;	
	return aux;	
}

Complexo Complexo::operator*(Complexo &C){
	Complexo aux;
	aux.real       = real * C.real - imaginaria * C.imaginaria;
	aux.imaginaria = imaginaria * C.real + real * C.imaginaria;
	return aux;	
}

Complexo Complexo::operator/(Complexo &C){
	Complexo aux;
	aux.real       = (real * C.real + imaginaria * C.imaginaria) / (C.real * C.real + C.imaginaria * C.imaginaria);
	aux.imaginaria = (imaginaria * C.real - real * C.imaginaria) / (C.real * C.real + C.imaginaria * C.imaginaria);
	return aux;	
}


// Para comparar dois números complexos foi usado seu módulo. 

bool Complexo::operator>(Complexo &C){
	return Modulo() > C.Modulo();
}

bool Complexo::operator<(Complexo &C){
	return Modulo() < C.Modulo();
}

bool Complexo::operator>=(Complexo &C){
	return Modulo() >= C.Modulo();
}

bool Complexo::operator<=(Complexo &C){
	return Modulo() <= C.Modulo();
}

bool Complexo::operator==(Complexo &C){
	return Modulo() == C.Modulo();
}

bool Complexo::operator!=(Complexo &C){
	return Modulo() != C.Modulo();
}

Complexo::operator float(){
	return (float)Modulo();
}

Complexo::operator int(){
	return (int)Modulo();
}

Complexo::operator double(){
	return Modulo();
}

ostream& operator<<(ostream &output, Complexo C){
	output << C.real << " + " << C.imaginaria << "i";
	return output;
}

istream& operator>>(istream &input, Complexo &C){
	cout << "Real: ";
	input >> C.real;
	cout << "Imaginaria: ";
	input >> C.imaginaria;
	return input;
}