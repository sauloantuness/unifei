#include "Pilha.h"
#include <iostream>

#define TAM 10

using namespace std;

CPilha::CPilha(){
	m_tamanho = TAM;
	m_dados = new int[m_tamanho];
	m_ponteirodaPilha = -1;
}

CPilha::CPilha(int t){
	m_tamanho = t;
	m_dados = new int[m_tamanho];
	m_ponteirodaPilha = -1;
}

int CPilha::pop(){
	if(m_ponteirodaPilha == -1)
		throw pilhaVaziaException();
	return m_dados[m_ponteirodaPilha--];
}

void CPilha::push(int dado){
	if(m_ponteirodaPilha == m_tamanho -1)
		throw pilhaCheiaException();
	m_dados[++m_ponteirodaPilha] = dado;
	return;
}

istream& operator>>(istream &in, CPilha &p){
	int e;
	cin >> e;
	p.push(e);
	return in; 
}

ostream& operator<<(ostream &out, const CPilha &p){
	for(int i = p.m_ponteirodaPilha; i > -1; i--)
		cout << p.m_dados[i] << endl;
	return out;
}