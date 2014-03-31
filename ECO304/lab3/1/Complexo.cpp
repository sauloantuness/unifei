#include <iostream>
#include <cmath>
#include "Complexo.h"

using namespace std;

int Complexo::contador = 0;

Complexo Complexo::Somar(Complexo C){
	Complexo aux;
	aux.real       = real       + C.real;
	aux.imaginaria = imaginaria + C.imaginaria;	
	return aux;
}

Complexo Complexo::Subtrair(Complexo C){
	Complexo aux;
	aux.real       = real       - C.real;
	aux.imaginaria = imaginaria - C.imaginaria;	
	return aux;
}

Complexo Complexo::Multiplicar(Complexo C){
	Complexo aux;
	aux.real       = real * C.real - imaginaria * C.imaginaria;
	aux.imaginaria = imaginaria * C.real + real * C.imaginaria;
	return aux;
}

Complexo Complexo::Dividir(Complexo C){
	Complexo aux;
	aux.real       = (real * C.real + imaginaria * C.imaginaria) / (C.real * C.real + C.imaginaria * C.imaginaria);
	aux.imaginaria = (imaginaria * C.real - real * C.imaginaria) / (C.real * C.real + C.imaginaria * C.imaginaria);
	return aux;
}

double Complexo::Modulo(){
	double modulo;
	modulo = sqrt(real*real + imaginaria*imaginaria);
	return modulo;
}

void Complexo::Print(){
	cout << real << " + " << imaginaria << "i" << endl;
}
