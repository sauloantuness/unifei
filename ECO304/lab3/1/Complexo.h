#ifndef COMPLEXO
#define COMPLEXO

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
	Complexo Somar(Complexo);
	Complexo Subtrair(Complexo);
	Complexo Multiplicar(Complexo);
	Complexo Dividir(Complexo);
	double Modulo();
	void Print();
};

#endif
