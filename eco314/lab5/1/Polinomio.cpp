#include <iostream>
#include "Polinomio.h"

using namespace std;

Polinomio::Polinomio(int n){
	grau = n;
	p = new int[n+1];
	for (int i = 0; i <= n; i++)
		p[i] = 0;
}

Polinomio::Polinomio(const Polinomio &P){
	grau = P.grau;
	p = new int[grau + 1];
	for (int i = 0; i <= grau; i++)
		p[i] = P.p[i];
}

Polinomio Polinomio::operator+(const Polinomio &P){
	int n;
	if(grau > P.grau)
		n = grau;
	else
		n = P.grau;

	Polinomio temp(n);

	for (int i = 0; i <= n; ++i){
		if(i <= grau)
			temp.p[i] +=  p[i];
		if(i <= P.grau)
			temp.p[i] +=  P.p[i];
	}

	for (int i = n; i >= 0; i--){
		if(temp.p[i] == 0){
			temp.grau--;
		}
		break;
	}

	return temp;
}

Polinomio Polinomio::operator-(const Polinomio P){

	for (int i = 0; i <= P.grau; ++i)
		P.p[i] *= -1;

	return (*this)+P;
}

ostream& operator<<(ostream &out, const Polinomio &P){
	for (int i = P.grau; i > 0; i--){
		if(P.p[i] == 0)
			continue;

		if(P.p[i] > 0) 
			cout << "+";
		cout << P.p[i] << "x^" << i << " ";
	}
	
	if(P.p[0] == 0)
		return out;

	if(P.p[0] > 0)
		cout << "+";
	cout << P.p[0] ;

	return out;
}

istream& operator>>(istream &in, Polinomio &P){
	for (int i = P.grau; i >= 0; i--){
		cout << "x^" << i << ": ";
		cin >> P.p[i];
	}

	return in;
}
