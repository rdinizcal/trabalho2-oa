#ifndef REGVARIAVEL_H
#define REGVARIAVEL_H

#include <string>
#include <iostream>

class RegVariavel{

private:
	std::string chavePrimaria;
	int prr;
	std::string nome;
	std::string sobrenome;
	std::string empresa;
	std::string endereco;
	std::string cidade;
	std::string condado;
	std::string estado;
	std::string cep;
	std::string phone1;
	std::string phone2;

public:
	static int objectCounter;

	RegVariavel();
	~RegVariavel();

	void setChavePrimaria(std::string chavePrimaria);
	std::string getChavePrimaria();

	void setPrr(int prr);
	int getPrr();

	void setNome(std::string nome);
	std::string getNome();

	void setSobrenome(std::string sobrenome);
	std::string getSobrenome();

	void setEmpresa(std::string empresa);
	std::string getEmpresa();

	void setEndereco(std::string endereco);
	std::string getEndereco();

	void setCidade(std::string cidade);
	std::string getCidade();

	void setCondado(std::string condado);
	std::string getCondado();

	void setEstado(std::string estado);
	std::string getEstado();

	void setCEP(std::string cep);
	std::string getCEP();

	void setPhone1(std::string phone1);
	std::string getPhone1();

	void setPhone2(std::string phone2);
	std::string getPhone2();
};

#endif