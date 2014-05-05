#ifndef ID_RETANGULO
#define ID_RETANGULO

class Retangulo{
	int largura;
	int comprimento;

public:

	Retangulo();
	Retangulo(int);
	Retangulo(int, int);

	~Retangulo();

	int getLargura();
	int getComprimento();
	void setLargura(int);
	void setComprimento(int);

	bool eQuadrado();
	
	int area(){ 	  return largura*comprimento; };
	int perimetro() { return (largura*2 + comprimento*2); };

	void imprime();
	void imprime(char, char);

};

#endif
