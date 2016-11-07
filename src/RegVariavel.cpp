#include "../lib/RegVariavel.h"

/**************************CONSTRUTOR**************************/
RegVariavel::RegVariavel(){

	std::cout<<"Objeto de RegVariavel criado."<<std::endl;
}

/**************************DESTRUTOR**************************/
RegVariavel::~RegVariavel(){

	std::cout<<"Objeto de RegVariavel destruido."<<std::endl;
}


/**************************METODOS PUBLICOS**************************/
void RegVariavel::insertReg(){
}

void RegVariavel::selectReg(){
}


/**************************SETTERS & GETTERS**************************/
void RegVariavel::setChavePrimaria(int chavePrimaria){
	this.chavePrimaria = chavePrimaria;
}

int RegVariavel::getChavePrimaria(){
	return this.chavePrimaria;
}

void RegVariavel::setNome(std::string nome){
	this.nome = nome;
}

std::string RegVariavel::getNome(){
	return this.nome;
}

void RegVariavel::setSobrenome(std::string sobrenome){
	this.sobrenome = sobrenome;
}

std::string RegVariavel::getSobrenome(){
	return this.sobrenome;
}

void RegVariavel::setEmpresa(std::string empresa){
	this.empresa = empresa;
}

std::string RegVariavel::getEmpresa(){
	return this.empresa;
}

void RegVariavel::setEndereco(std::string endereco){
	this.endereco = endereco;
}

std::string RegVariavel::getEndereco(){
	return this.endereco;
}

void RegVariavel::setCidade(std::string cidade){
	this.cidade = cidade;
}

std::string RegVariavel::getCidade(){
	return this.cidade;
}

void RegVariavel::setEstado(std::string estado){
	this.estado = estado;
}

std::string RegVariavel::getEstado(){
	return this.estado;
}

void RegVariavel::setCEP(std::string cep){
	this.cep = cep;
}

std::string RegVariavel::getCEP(){
	return this.cep;
}

void RegVariavel::setPhone1(std::string phone1){
	this.phone1 = phone1;
}

std::string RegVariavel::getPhone1(){
	return this.phone1;
}

void RegVariavel::setPhone2(std::string phone2){
	this.phone2 = phone2;
}

std::string RegVariavel::getPhone2(){
	return this.phone2;
}