#ifndef REGFIXO_H
#define REGFIXO_H

#include <string>
#include <iostream>

class RegFixo{
private:
	std::string chavePrimaria;
	int nrr;
	std::string campo1;
	std::string campo2;
	std::string campo3;
	
public:
	RegFixo();
	~RegFixo();

	void setChavePrimaria(std::string chavePrimaria);
	std::string getChavePrimaria();

	void setNrr(int nrr);
	int getNrr();

	void setCampo1(std::string campo1);
	std::string getCampo1();

	void setCampo2(std::string campo2);
	std::string getCampo2();

	void setCampo3(std::string campo3);
	std::string getCampo3();
};

#endif