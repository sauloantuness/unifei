#include <iostream>
#include "Data.h"

using namespace std;

void Data::validaData(){
	if(dia < 1){
		dia = 31;
		mes--;
		validaData();
	}

	if(dia > 31){
		dia = 1;
		mes++;
		validaData();
	}

	if(mes < 1){
		mes = 12;
		ano--;
		validaData();
	}

	if(mes > 12){
		mes = 1;
		ano++;
		validaData();
	}

	if(ano < 0)
		ano = 0;

	int bissexto = 0;

	if(ano % 4 == 0 && !(ano % 100 == 0 && ano % 400 != 0))
		bissexto = 1;
	

	if(mes == 2){
		if(dia > 28 + bissexto){
			dia = 1;
			mes++;
			validaData();
		}
	}

	if(mes == 1  || 
	   mes == 3  || 
	   mes == 5  || 
	   mes == 7  || 
	   mes == 8  || 
	   mes == 10 ||
	   mes == 12 ){
		if(dia > 31){
			dia = 1;
			mes++;
			validaData();
		}
	}

	if(mes == 4  || 
	   mes == 6  || 
	   mes == 9  || 
	   mes == 11 ){
		if(dia > 30){
			dia = 1;
			mes++;
			validaData();
		}
	}
}

ostream& operator<<(ostream &out, const Data &D){
	out << D.dia << " de ";
	switch(D.mes){
		case  1: out << "Janeiro de " ; 	break;
		case  2: out << "Fevereiro de " ; 	break;
		case  3: out << "Marco de " ; 		break;
		case  4: out << "Abril de " ; 		break;
		case  5: out << "Maio de " ; 		break;
		case  6: out << "Junho de " ; 		break;
		case  7: out << "Julho de " ; 		break;
		case  8: out << "Agosto de " ; 		break;
		case  9: out << "Setembro de " ; 	break;
		case 10: out << "Outubro de " ; 	break;
		case 11: out << "Novembro de " ; 	break;
		case 12: out << "Dezembro de " ; 	break;
	}

	out << D.ano;

	return out;
}

istream& operator>>(istream &in, Data &D){
	cout << "Dia: ";
	cin >> D.dia;
	cout << "Mes: ";
	cin >> D.mes;
	cout << "Ano: ";
	cin >> D.ano;
	D.validaData();

	return in;
}

Data Data::operator++(){
	dia++;
	validaData();
	return *this;
}

Data Data::operator++(int){
	Data temp = *this;
	dia++;
	validaData();
	return temp;
}
Data Data::operator--(){
	dia--;
	validaData();
	return *this;
}

Data Data::operator--(int){
	Data temp = *this;
	dia--;
	validaData();
	return temp;
}