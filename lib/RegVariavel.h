#ifndef REGVARIAVEL_H
#define REGVARIAVEL_H

#include <string>
#include <iostream>

class RegVariavel{
private:
	int chavePrimaria;
	std::string nome;
	std::string sobrenome;
	std::string empresa;
	std::string endereco;
	std::string cidade;
	std::string estado;
	std::string cep;
	std::string phone1;
	std::string phone2;


	
public:
	RegVariavel();
	~RegVariavel();

	void RegVariavel::setChavePrimaria(int chavePrimaria);
	int RegVariavel::getChavePrimaria();

	void RegVariavel::setNome(std::string nome);
	std::string RegVariavel::getNome();

	void RegVariavel::setSobrenome(std::string sobrenome);
	std::string RegVariavel::getSobrenome();

	void RegVariavel::setEmpresa(std::string empresa);
	std::string RegVariavel::getEmpresa();

	void RegVariavel::setEndereco(std::string endereco);
	std::string RegVariavel::getEndereco();

	void RegVariavel::setCidade(std::string cidade);
	std::string RegVariavel::getCidade();

	void RegVariavel::setEstado(std::string estado);
	std::string RegVariavel::getEstado();

	void RegVariavel::setCEP(std::string cep);
	std::string RegVariavel::getCEP();

	void RegVariavel::setPhone1(std::string phone1);
	std::string RegVariavel::getPhone1();

	void RegVariavel::setPhone2(std::string phone2);
	std::string RegVariavel::getPhone2();

	
};

#endif