#include "CFracao.h"
#include <iostream>

using namespace std;

CFracao CFracao::Reduzida(void)
{
	int negativo = 1;
	if(m_numerador < 0)
		negativo = -1;
	m_numerador *= negativo;

	int gcd = 1;
	int minimo = m_numerador;
	if (m_numerador > m_denominador) 
		minimo = m_denominador;
	
	for(int i = 1; i <= minimo; i++)
	{
		if ((m_numerador%i == 0) && (m_denominador%i == 0))
			gcd = i;
	}
	
	m_numerador /= gcd;
	m_denominador /= gcd;

	m_numerador *= negativo;
	return (*this);
}

CFracao CFracao::operator+(CFracao &F){
	CFracao temp(m_numerador*F.m_denominador + m_denominador*F.m_numerador, m_denominador*F.m_denominador );
	return temp.Reduzida();
}

CFracao CFracao::operator-(CFracao &F){
	CFracao temp(m_numerador*F.m_denominador - m_denominador*F.m_numerador, m_denominador*F.m_denominador );
	return temp.Reduzida();
}

CFracao CFracao::operator*(CFracao &F){
	CFracao temp(m_numerador*F.m_numerador, m_denominador*F.m_denominador );
	return temp.Reduzida();
}

CFracao CFracao::operator/(CFracao &F){
	CFracao temp(m_numerador*F.m_denominador, m_denominador*F.m_numerador );
	return temp.Reduzida();
}

bool CFracao::operator<(CFracao &F){
	return (m_numerador*F.m_denominador < m_denominador*F.m_numerador );
}

bool CFracao::operator>(CFracao &F){
	return (m_numerador*F.m_denominador > m_denominador*F.m_numerador );
}

bool CFracao::operator<=(CFracao &F){
	return (m_numerador*F.m_denominador <= m_denominador*F.m_numerador );
}

bool CFracao::operator>=(CFracao &F){
	return (m_numerador*F.m_denominador >= m_denominador*F.m_numerador );
}

bool CFracao::operator==(CFracao &F){
	return (m_numerador*F.m_denominador == m_denominador*F.m_numerador );
}

bool CFracao::operator!=(CFracao &F){
	return (m_numerador*F.m_denominador != m_denominador*F.m_numerador );
}

ostream& operator<< (ostream& output, CFracao F){
	output << F.m_numerador << "/" << F.m_denominador;
	return output;
}

istream& operator>> (istream& input, CFracao &F){
	cout << "Numerador: " ;
	input >> F.m_numerador;
	cout << "Denominador: " ;
	input >> F.m_denominador;
	return input;
}

CFracao::operator int(){
	return (int)(m_numerador/m_denominador);
}

CFracao::operator float(){
	return (float)m_numerador/m_denominador;
}

CFracao::operator double(){
	return (double)m_numerador/m_denominador;
}