#include <iostream>
#include <algorithm>
#include "TrianguloRetangulo.h"

using namespace std;

TrianguloRetangulo::TrianguloRetangulo(int l1, int l2, int l3){
	int v[] = {l1,l2,l3};
	sort(v, v+3);

	cat1 = v[0];
	cat2 = v[1];
	hip = v[2];

	if(!ehTriangulo())
		cout << "OS VALORES (" << cat1 << ", " << cat2 << ", " << hip << ") NAO FORMAM UM TRIANGULO" << endl << endl;
}

void TrianguloRetangulo::imprime(char modo){
	char c1 = '*';	// Caso deseja mudar o preenchimento
	char c2 = ' ';  

	switch(modo){
		case 'a':	
			for (int i = 1; i <= cat1; i++) {
				int j = i;
				int k = cat1 - j;
				while(j--)
					cout << c1;
				while(k--)
					cout << c2;
				cout << endl;
			} break;

		case 'b':
			for (int i = 0; i < cat1; i++) {
				int j = cat1 - i;
				int k = cat1 - j;
				while(j--)
					cout << c1;
				while(k--)
					cout << c2;
				cout << endl;
			} break;

		case 'c':
			for (int i = 0; i < cat1; i++) {
				int j = i;
				int k = cat1 - j;
				while(j--)
					cout << c2;
				while(k--)
					cout << c1;
				cout << endl;
			} break;

		case 'd':
			for (int i = 1; i <= cat1; i++) {
				int j = cat1 - i;
				int k = cat1 - j;
				while(j--)
					cout << c2;
				while(k--)
					cout << c1;
				cout << endl;
			} break;
		}
}

bool TrianguloRetangulo::ehRetangulo(){
	if(cat1*cat1 + cat2*cat2 == hip*hip)
		return true;
	else
		return false;
}

bool TrianguloRetangulo::ehTriangulo(){
	if(cat1 - cat2 < hip && hip < cat1 + cat2)
		return true;
	else
		return false;
}

void TrianguloRetangulo::Quinhentos(){
	for (int i = 1; i < 500; i++) {
		for (int j = 1; j < 500; j++){
			for (int k = 1; k < 500; k++) {
				if(k*k == j*j + i*i)
					cout << i << " " << j << " " << k << endl;
			}
		}
	}
}
