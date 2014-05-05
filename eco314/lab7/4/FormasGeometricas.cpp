#include <iostream>
#include <string>
#include "FormasGeometricas.h"

using namespace std;

Ponto::Ponto(){
	raio = 0;
	altura = 0;
	tipo = "Ponto";
}

Circulo::Circulo(int r){
	raio = r;
	tipo = "Circulo";
}

Cilindro::Cilindro(int r, int h){
	raio = r;
	altura = h;
	tipo = "Cilindro";
}

float Ponto::area() const{
	return 0;
}

float Circulo::area() const{
	return 3.1415 * raio * raio;
}

float Cilindro::area() const{
	return 3.1415 * raio * raio;
}

float Ponto::volume() const{
	return 0;
}

float Circulo::volume() const{
	return 0;
}

float Cilindro::volume() const{
	return area() * altura;
}