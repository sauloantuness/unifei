#include <iostream>

using namespace std;

// Usando linux, só aconteceu a exceção do segundo modo. 
// No windows, ambos os modos funcionaram.

int main(){
		try{
			double *v;
			while(1)
				v = new double[10000];
		}
		catch(bad_alloc e){
			cout << "Aconteceu uma excecao:  " << e.what() << endl;
		}
}

int main2(){
		try{
			double *v = new double[10000000000];
		}
		catch(bad_alloc e){
			cout << "Aconteceu uma excecao:  " << e.what() << endl;
		}
}