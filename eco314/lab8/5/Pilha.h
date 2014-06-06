#ifndef PILHA_H
#define PILHA_H
#include <iostream>
using namespace std;

#define TAM 10

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

template <class T>
class CPilha{
private:
	T *m_dados;
	int m_ponteirodaPilha;
	int m_tamanho;
public:
	CPilha();
	CPilha(int);
	~CPilha(){}

	T pop();
	void push(T);

	friend istream& operator>>(istream &in, CPilha<T> &p){
		T e;
		cin >> e;
		p.push(e);
		return in; 
	}

	friend ostream& operator<<(ostream &out, const CPilha<T> &p){
		for(int i = p.m_ponteirodaPilha; i > -1; i--)
			cout << p.m_dados[i] << endl;
		return out;
	}
};

template <class T>
CPilha<T>::CPilha(){
	m_tamanho = TAM;
	m_dados = new T[m_tamanho];
	m_ponteirodaPilha = -1;
}

template <class T>
CPilha<T>::CPilha(int t){
	m_tamanho = t;
	m_dados = new T[m_tamanho];
	m_ponteirodaPilha = -1;
}

template <class T>
T CPilha<T>::pop(){
	if(m_ponteirodaPilha == -1)
		throw pilhaVaziaException();
	return m_dados[m_ponteirodaPilha--];
}

template <class T>
void CPilha<T>::push(T dado){
	if(m_ponteirodaPilha == m_tamanho -1)
		throw pilhaCheiaException();
	m_dados[++m_ponteirodaPilha] = dado;
	return;
}

#endif