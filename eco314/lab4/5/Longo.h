#ifndef LONGO
#define LONGO
#include <iostream>

using namespace std;

class Longo{

protected:
	int num[30];

public:
	Longo();
	Longo(char*);
	~Longo(){};

	Longo operator+(Longo &);
	Longo operator-(Longo &);

	bool operator>(Longo &);
	bool operator<(Longo &);
	bool operator>=(Longo &);
	bool operator<=(Longo &);
	bool operator==(Longo &);
	bool operator!=(Longo &);

	friend ostream& operator<<(ostream &, Longo);
	friend istream& operator>>(istream &, Longo &);
};

#endif
