#ifndef DATA_H
#define DATA_H
#include <iostream>
using namespace std;

class Data{
protected:
	int dia;
	int mes;
	int ano;
	void validaData();

public:
	Data(int d=1,int m=1,int a=2000) : 
		dia(d), mes(m), ano(a) {
			validaData();
	};

	~Data(){};


	Data operator++();
	Data operator++(int);
	Data operator--();
	Data operator--(int);

	friend ostream& operator<<(ostream &, const Data &);
	friend istream& operator>>(istream &, Data &);

};

#endif