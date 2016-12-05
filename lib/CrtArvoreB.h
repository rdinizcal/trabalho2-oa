#ifndef CRTARVOREB_H
#define CRTARVOREB_H

#include "../lib/ArvoreB.h"
#include "../lib/No.h"
#include "../lib/RegVariavel.h"
#include "../lib/RegFixo.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class CrtArvoreB{
private:
	ArvoreB arvoreB;

public:
	CrtArvoreB();
	~CrtArvoreB();

	bool setUp(std::string, std::string);
	bool inserir(std::string);
	void buscar(std::string, std::string);
	void mostrar();

private:
	std::vector<RegFixo> parseFixedReg(std::fstream&);
	std::vector<RegVariavel> parseVariableReg(std::fstream&);

};

#endif