#ifndef TRIANGULORETANGULO
#define TRIANGULORETANGULO

class TrianguloRetangulo{

protected:
	int hip;
	int cat1;
	int cat2;

public:
	TrianguloRetangulo(void){
		cat1 = 3;
		cat2 = 4;
		hip = 5;
	}

	TrianguloRetangulo(int, int, int);
	~TrianguloRetangulo(){};

	bool ehTriangulo();
	bool ehRetangulo();
	void imprime(char);
	void Quinhentos();
};

#endif



