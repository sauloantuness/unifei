#include <iostream>
#include "FormasGeometricas.h"

using namespace std;

Ponto::Ponto(){
	raio = 0;
	altura = 0;
}

Circulo::Circulo(int r){
	raio = r;
}

Cilindro::Cilindro(int r, int h){
	raio = r;
	altura = h;
}

float Ponto::area() const{
	return 3.1415 * raio * raio;
}

float Ponto::volume() const{
	return Ponto::area() * altura;
}

istream& operator>>(istream &in, Circulo &C){
	cout << "Raio: ";
	in >> C.raio;
	return in;
}

istream& operator>>(istream &in, Cilindro &C){
	in >> *(static_cast <Circulo*>(&C));
	cout << "Altura: ";
	in >> C.altura;
	return in;
}

ostream& operator<<(ostream &out, const Ponto &C){
	out << "  Raio: " << C.raio << endl;
	out << "Altura: " << C.altura << endl;
	out << "  Area: " << C.area() << endl;
	out << "Volume: " << C.volume() << endl;
	return out;
}
