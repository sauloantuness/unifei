#ifndef LONGO
#define LONGO

class Longo{

protected:
	int num[30];

public:
	Longo();
	Longo(char*);
	~Longo(){};

	void setNum();
	char* getNum();

	Longo Somar(Longo);
	Longo Subtrair(Longo);
};

#endif
