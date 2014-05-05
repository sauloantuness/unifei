#ifndef COMPLEXO
#define COMPLEXO
#include <iostream>

using namespace std;

class Complexo {

protected:
	double real;
	double imaginaria;
	static int contador;

public:
	Complexo(){
		real = 0;
		imaginaria = 0;
		contador++;		
	}

	Complexo(int r){
		real = r;
		imaginaria = 0;
		contador++;
	}

	Complexo(int r, int i): real(r), imaginaria(i) {
		contador++;	
	};

	Complexo(const Complexo &c){
		real = c.real;
		imaginaria = c.imaginaria;
		contador++;
	}

	~Complexo(){
		contador--;
	}

	static int getContador(){ return contador;}

	double Modulo();

	Complexo operator+(Complexo &);
	Complexo operator-(Complexo &);
	Complexo operator*(Complexo &);
	Complexo operator/(Complexo &);

	bool operator<(Complexo &);
	bool operator>(Complexo &);
	bool operator<=(Complexo &);
	bool operator>=(Complexo &);
	bool operator==(Complexo &);
	bool operator!=(Complexo &);

	friend ostream& operator<<(ostream &, Complexo);
	friend istream& operator>>(istream &, Complexo &);
};

#endif
