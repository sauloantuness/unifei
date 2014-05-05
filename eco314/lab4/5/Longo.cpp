#include <iostream>
#include "Longo.h"

using namespace std;

Longo::Longo(){
	for(int i=0; i<30; i++)
		num[i] = 0;
}

Longo::Longo(char *str){
	int i=0, j=29;

	while(str[i] != '\0')
		i++;

	while(i--)
		num[j--] = str[i] - 48;

	while(j >= 0)
		num[j--] = 0;
}


Longo Longo::operator+(Longo &L){
	Longo temp;
	int aux = 0;
	int i=30;
	while(i--){
		temp.num[i] += (num[i] + L.num[i] + aux) % 10;
		aux = (num[i] + L.num[i]) / 10;
	}

	return temp;	
}

Longo Longo::operator-(Longo &L){
	Longo temp, menor, maior;

	if((*this) > L){
		maior = *this;
		menor = L;
	}
	else{
		maior = L;
		menor = *this;
	}

	int aux = 0;
	int i=30;

	while(i--){
		if(maior.num[i] < menor.num[i]){
			maior.num[i-1]--;
			maior.num[i] += 10;
		}

		temp.num[i] = (maior.num[i] - menor.num[i]);
	}

	return temp;
}

bool Longo::operator>(Longo &L){
	for (int i = 0; i < 30; i++) {
		if(num[i] == L.num[i])
			continue;

		if(num[i] > L.num[i])
			return	true;
		else
			return false;
	}
	return false;
}

bool Longo::operator<(Longo &L){
	for (int i = 0; i < 30; i++) {
		if(num[i] == L.num[i])
			continue;

		if(num[i] < L.num[i])
			return	true;
		else
			return false;
	}
	return false;
}

bool Longo::operator>=(Longo &L){
	for (int i = 0; i < 30; i++) {
		if(num[i] == L.num[i])
			continue;

		if(num[i] > L.num[i])
			return	true;
		else
			return false;
	}
	return true;
}

bool Longo::operator<=(Longo &L){
	for (int i = 0; i < 30; i++) {
		if(num[i] == L.num[i])
			continue;

		if(num[i] < L.num[i])
			return	true;
		else
			return false;
	}
	return true;
}

bool Longo::operator==(Longo &L){
	for (int i = 0; i < 30; i++) {
		if(num[i] != L.num[i])
			return	false;
	}
	return true;
}


bool Longo::operator!=(Longo &L){
	for (int i = 0; i < 30; i++) {
		if(num[i] != L.num[i])
			return	true;
	}
	return false;
}

ostream& operator<<(ostream &output, Longo L){
	int i=0;
	for (i = 0; i < 29; i++){
		if(L.num[i] != 0)
			break;
	}
	while(i < 30)
		output << L.num[i++];

	return output;
}

istream& operator>>(istream &input, Longo &L){
	char str[31];

	cout << "Numero: ";
	input >> str;

	int i=0, j=29;

	while(str[i] != '\0')
		i++;

	while(i--)
		L.num[j--] = str[i] - 48;

	while(j >= 0)
		L.num[j--] = 0;

	return input;
}