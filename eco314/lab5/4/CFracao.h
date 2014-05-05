#ifndef ID_CFRACAO
#define ID_CFRACAO

#include <iostream>
using namespace std;

class CFracao{

protected:
	int m_numerador;
	int m_denominador;

	// responde ao receptor com o mínimo denominador comum
	CFracao Reduzida(void);	

public:
	// Construtor sem parametros inline
	CFracao(void){
		m_numerador = 1;
		m_denominador = 1;
	}

	CFracao(int Num, int Denom) : m_numerador(Num), m_denominador(Denom) { };
	
	CFracao( const CFracao& f) // Construtor de copia
	{
		m_numerador = f.m_numerador;
		m_denominador = f.m_denominador;
	}

	~CFracao(void){ };		// Destrutor

	int getNumerador(void) { return m_numerador; }
	int getDenominador(void) { return m_denominador; }

	operator double();
	operator float();
	operator int();

	CFracao operator+(CFracao &);
	CFracao operator-(CFracao &);
	CFracao operator*(CFracao &);
	CFracao operator/(CFracao &);

	bool operator<(CFracao &);
	bool operator>(CFracao &);
	bool operator<=(CFracao &);
	bool operator>=(CFracao &);
	bool operator==(CFracao &);
	bool operator!=(CFracao &);

	friend ostream& operator<<(ostream &, CFracao);
	friend istream& operator>>(istream &, CFracao &);

};

#endif // ID_CFRACAO



