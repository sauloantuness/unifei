#ifndef EQSEGUNDOGRAU_H
#define EQSEGUNDOGRAU_H

class EqSegundoGrau{
private:
	int a;
	int b;
	int c;
	int delta;

public:
	EqSegundoGrau(int,int,int);
	~EqSegundoGrau(){};
	void tipoRaiz();
	friend std::ostream&operator<<(std::ostream &saida, EqSegundoGrau &e);
};

#endif