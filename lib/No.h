#ifndef NO_H
#define NO_H

#include <vector>
#include <iostream>

class No{

private:
	int nivel;
	int pagina;
	int contador;
	std::string chave[5];
	int prr[5];
	No* filho[6];
	No* pai;

public:
	static int objectCounter;

	No();
	~No();

	int insert(std::string, int, No*);
	void erase(std::string);

	void setNivel(int);
	int getNivel();

	int getPagina();

	void setContador(int);
	int getContador();

	std::string getChave(int);

	int getPrr(int);

	void setFilho(No*, int);
	No* getFilho(int);

	void setPai(No*);
	No* getPai();
};

#endif