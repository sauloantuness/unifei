#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "Pilha.h"
using namespace std;

int main(){
	ifstream entrada("entrada.txt", ios::in);
	CPilha<int> pilha(10);
	entrada >> pilha;

	ofstream saida("saida.txt", ios::out);
	saida << pilha;
}