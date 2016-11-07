#ifndef REGFIXO_H
#define REGFIXO_H

#include <string>
#include <iostream>

class RegFixo{
private:
	int chavePrimaria;
	std::string campo1;
	std::string campo2;
	std::string campo3;
	
public:
	RegFixo();
	~RegFixo();

	void RegFixo::setChavePrimaria(int chavePrimaria);
	int RegFixo::getChavePrimaria();

	void RegFixo::setCampo1(std::string campo1);
	std::string RegFixo::getCampo1();

	void RegFixo::setCampo2(std::string campo2);
	std::string RegFixo::getCampo2();

	void RegFixo::setCampo3(std::string campo3);
	std::string RegFixo::getCampo3();
};

#endif