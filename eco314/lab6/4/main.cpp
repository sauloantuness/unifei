#include <iostream>
#include <set>
#include "PhoneNumber.h"
using namespace std;

int main(){
   PhoneNumber phone; 

   // DDDs 11(SP) e 29(RJ) serão lidos 9 digitos
   cout << "Entre com o numero de telefone no formato (12) X3456-7890:" << endl;

   cin >> phone;

   cout << "O numero do telefone eh: ";
   cout << phone << endl;
}