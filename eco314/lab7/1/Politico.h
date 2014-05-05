#ifndef POLITICO_H
#define POLITICO_H
#include <string>
#include <iostream>

using namespace std;

class Politico{
protected:
	string nome;
	string partido;
public:
	Politico(){};
	~Politico(){};	
	void Imprime(){}
};

class Presidente : public Politico{
protected:
	string pais;	
public:
	Presidente(string, string, string);
	~Presidente(){};
	void Imprime();
};

class Governador : public Presidente{
protected:
	string estado;
public:
	Governador(string, string, string, string);
	~Governador(){};
	void Imprime();
};

class Prefeito : public Governador{
protected:
	string cidade;
public:
	Prefeito(string, string, string, string, string);
	~Prefeito(){};
	void Imprime();
};

#endif
