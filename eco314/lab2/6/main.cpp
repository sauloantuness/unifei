#include <iostream>
#include "Retangulo.h"

using namespace std;

int main(){
	Retangulo *r;
	r = new Retangulo(5);
	r->imprime(); // 	(*r).imprime();

	delete(r);
}
