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
	virtual void Imprime() = 0;

};

class Presidente : public Politico{
protected:
	string pais;	
public:
	Presidente(string, string, string);
	~Presidente(){};
	virtual void Imprime();
};

class Governador : public Presidente{
protected:
	string estado;
public:
	Governador(string, string, string, string);
	~Governador(){};
	virtual void Imprime();
};

class Prefeito : public Governador{
protected:
	string cidade;
public:
	Prefeito(string, string, string, string, string);
	~Prefeito(){};
	virtual void Imprime();
};

#endif
