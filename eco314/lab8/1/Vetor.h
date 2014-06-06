#ifndef VETOR_H
#define VETOR_H

#include <iostream>
#include <algorithm>

template <class T> 
class Vetor{
protected:
	T *dado;
	int tam;
public:
	Vetor(int);
	~Vetor();
	void Ordena();
	int size();
	T& operator[](int const pos){
		if(pos < 0 || pos > tam - 1)
			throw pos;
		return dado[pos];
	}
};

template <class T>
Vetor<T>::Vetor(int t) : tam(t){
	dado = new T[tam];
}

template <class T>
Vetor<T>::~Vetor(){
	free(dado);
}

template <class T>
void Vetor<T>::Ordena(){
	sort(dado, dado+tam);
}

template <class T>
int Vetor<T>::size(){
	return tam;
}

#endif