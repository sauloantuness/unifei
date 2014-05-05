#include <iostream>
#include "Retangulo.h"

using namespace std;


Retangulo::Retangulo(){
	setLargura(1);
	setComprimento(1);
	//cout << "Passei pelo construtor" << endl;
}

Retangulo::Retangulo(int t){
	setLargura(t);
	setComprimento(t);
}

Retangulo::Retangulo(int l, int c){
	setLargura(l);
	setComprimento(c);
}

Retangulo::~Retangulo(){
	//cout << "Passei pelo destrutor" << endl;
}

int Retangulo::getLargura(){
	return	largura;
}

int Retangulo::getComprimento(){
	return comprimento;
}

void Retangulo::setLargura(int h){
	if(h < 0)
		h = 0;
	if (h > 20)
		h = 20;
	
	largura = h;
}

void Retangulo::setComprimento(int c){
	if(c < 0)
		c = 0;

	if (c > 20)
		c = 20;

	comprimento = c;
}

bool Retangulo::eQuadrado(){
	if (getComprimento() == getLargura())
		return true;
	else
		return false;
}

void Retangulo::imprime(){
	imprime('x','.');
}

void Retangulo::imprime(char borda, char preenchimento){
	for(int i=0; i<largura; i++){
		for(int j=0; j<comprimento; j++){
			if(j == 0 || j == comprimento-1 || i == 0 || i == largura - 1)
				cout << borda;
			else
				cout << preenchimento;			
		}
		cout << endl;
	}		
}

void Retangulo::usuario(){
	int aux;
	cout << "Informe a largura: ";
	cin >> aux;
	setLargura(aux);
	cout << "Informe o comprimento: ";
	cin >> aux;
	setComprimento(aux);
}

