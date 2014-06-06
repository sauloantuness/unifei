#ifndef PILHA_H
#define PILHA_H
#include <iostream>
using namespace std;


class CPilha{
private:
	int *m_dados;
	int m_ponteirodaPilha;
	int m_tamanho;
public:
	CPilha();
	CPilha(int);
	~CPilha(){}

	int pop();
	void push(int);

	friend istream& operator>>(istream &, CPilha &);
	friend ostream& operator<<(ostream &, const CPilha &);
};

class pilhaVaziaException{
private:
	const char* info;
public:
	pilhaVaziaException() : info("Pilha vazia!") {}
	const char* message() const { return info; }
};


class pilhaCheiaException{
private:
	const char* info;
public:
	pilhaCheiaException() : info("Pilha cheia!") {}
	const char* message() const { return info; }
};
#endif