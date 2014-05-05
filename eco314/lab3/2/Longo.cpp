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

void Longo::setNum(){
	char str[31];

	cout << "Informe o numero: ";
	cin >> str;

	int i=0, j=29;

	while(str[i] != '\0')
		i++;

	while(i--)
		num[j--] = str[i] - 48;

	while(j >= 0)
		num[j--] = 0;
}

char* Longo::getNum(){
	char* str = new char[31];
	for(int i=0; i<30; i++)
		str[i] = num[i] + 48;

	return str;
}

Longo Longo::Somar(Longo l1){
	Longo l2;
	int aux = 0;
	int i=30;
	while(i--){
		l2.num[i] += (num[i] + l1.num[i] + aux) % 10;
		aux = (num[i] + l1.num[i]) / 10;
	}

	return l2;
}

Longo Longo::Subtrair(Longo l1){
	Longo l2;
	int aux = 0;
	int i=30;
	while(i--){
		if(num[i] < l1.num[i]){
			num[i] + 10;
			num[i-1]--;
		}

		l2.num[i] = (num[i] - l1.num[i]);
	}

	return l2;
}
