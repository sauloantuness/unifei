#include <iostream>

using namespace std;

class Retangulo{
	int largura;
	int comprimento;

public:

	Retangulo(){
		setLargura(1);
		setComprimento(1);
		cout << "Passei pelo construtor padrao!" << endl;
	}

	Retangulo(int t){
		setLargura(t);
		setComprimento(t);
		cout << "Passei pelo construtor com um parametro!" << endl;
	}

	Retangulo(int l, int c){
		setLargura(l);
		setComprimento(c);
		cout << "Passei pelo construtor com dois parametros!" << endl;
	}

	~Retangulo(){
		cout << "Passei pelo destrutor!" << endl;	
	}

	int getLargura(){
		return	largura;
	}

	int getComprimento(){
		return comprimento;
	}

	void setLargura(int l){
		if(l < 0)
			l = 0;

		if (l > 20)
			l = 20;
		
		largura = l;
	}

	void setComprimento(int c){
		if(c < 0)
			c = 0;

		if (c > 20)
			c = 20;

		comprimento = c;
	}

	bool eQuadrado(){
		if (getComprimento() == getLargura())
			return true;
		else
			return false;
	}

	int area(){
		return largura*comprimento;
	}

	int perimetro(){
		return (largura*2 + comprimento*2);
	}

	void imprime(){
		char borda = 'x';
		char preenchimento = '.';

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

};