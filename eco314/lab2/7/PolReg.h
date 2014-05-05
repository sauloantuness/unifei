#ifndef ID_POLREG
#define ID_POLREG

class PolReg{
	int lados;
	int comprimento;

public:

	PolReg(int l, int c): lados(l), comprimento(c) {};

	int area();
	int perimetro();
	void nome();
};

#endif
