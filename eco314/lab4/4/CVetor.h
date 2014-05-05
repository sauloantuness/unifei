#ifndef CVETOR_H
#define CVETOR_H

#include <iostream>
using namespace std;

class CVetor{
protected:
	int n;
	int *p;

public:
	CVetor();
	CVetor(int);
	CVetor(CVetor &);
	~CVetor(){};

	int size(){return n;};

	int& operator[](int);

	bool operator>(CVetor &);
	bool operator<(CVetor &);
	bool operator>=(CVetor &);
	bool operator<=(CVetor &);
	bool operator==(CVetor &);
	bool operator!=(CVetor &);

	friend ostream& operator<<(ostream &output, CVetor);
	friend istream& operator>>(istream &input, CVetor &);

};


#endif