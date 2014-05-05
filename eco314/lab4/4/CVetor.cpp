#include <iostream>
#include "CVetor.h"

using namespace std;


CVetor::CVetor(){
	p = NULL;
	n = 0;
}
CVetor::CVetor(int tam){
	n = tam;
	p = new int[n];
	for (int i = 0; i < n; i++)
		p[i] = 0;
}

CVetor::CVetor(CVetor &v){
	n = v.n;
	p = new int[n];
	for (int i = 0; i < n; i++)
		p[i] = v.p[i];
}

int& CVetor::operator[](int i){
	return p[i];
}

ostream& operator<<(ostream &output, CVetor V){
	int i;
	for (i = 0; i < V.n-1; i++){
		if(V.p[i] != 0)
			break;
	}

	for (i; i < V.n; i++)	{
		output << V.p[i];
	}

	return output;
}

istream& operator>>(istream &input, CVetor &V){
	char str[V.n+1];

	cout << "Numero: ";
	input >> str;

	int i=0, j = V.n - 1;

	while(str[i] != '\0')
		i++;

	while(i--)
		V.p[j--] = str[i] - 48;

	while(j >= 0)
		V.p[j--] = 0;

	return input;
}
// v(5) = 123
// v[] = 00123
//n=5
//i=5
bool CVetor::operator>(CVetor &V){
	int casas1=1, casas2=1;
	int i,j;

	for (i = 0; i < n; i++)	{
		if(p[i] != 0){
			casas1 = n - i;
			break;
		}
	}

	// Caso o número for todo 0.
	if(i == n)
		i--;
	
	for (j = 0; j < V.n; j++){
		if(V.p[j] != 0){
			casas2 = V.n - j;
			break;
		}
	}

	// Caso o número for todo 0.
	if(j == V.n)
		j--;

	if(casas1 > casas2)
		return true;
	if(casas1 < casas2)
		return false;

	while(casas1--){
		if(p[i] > V.p[j])
			return true;
		if(p[i] < V.p[j])
			return false;
		i++;
		j++;
	}
	return false;
}

bool CVetor::operator==(CVetor &V){
	int casas1=1, casas2=1;
	int i,j;

	for (i = 0; i < n; i++)	{
		if(p[i] != 0){
			casas1 = n - i;
			break;
		}
	}

	// Caso o número for todo 0.
	if(i == n)
		i--;

	for (j = 0; j < V.n; j++)	{
		if(V.p[j] != 0){
			casas2 = V.n - j;
			break;
		}
	}
	
	// Caso o número for todo 0.
	if(j == V.n)
		j--;

	if(casas1 != casas2)
		return false;

	while(casas1--){
		if(p[i++] != V.p[j++])
			return false;
	}
	return true;
}

bool CVetor::operator!=(CVetor &V){
	return !(*this == V);
}

bool CVetor::operator>=(CVetor &V){
	if( *this > V || *this == V)
		return true;
	else
		return false;
}


bool CVetor::operator<(CVetor &V){
	if( *this > V || *this == V)
		return false;
	else
		return true;	
}


bool CVetor::operator<=(CVetor &V){
	if( *this > V)
		return false;
	else
		return true;
}

// v(5) = 123
// v[] = 00123