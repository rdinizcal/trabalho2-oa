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


/**************************SETTERS & GETTERS**************************/
void RegVariavel::setChavePrimaria(int chave){
	chavePrimaria = chave;
}

int RegVariavel::getChavePrimaria(){
	return chavePrimaria;
}

void RegVariavel::setPrr(int p){
	prr = p;
}

int RegVariavel::getPrr(){
	return prr;
}

void RegVariavel::setNome(std::string n){
	nome = n;
}

std::string RegVariavel::getNome(){
	return nome;
}

void RegVariavel::setSobrenome(std::string sn){
	sobrenome = sn;
}

std::string RegVariavel::getSobrenome(){
	return sobrenome;
}

void RegVariavel::setEmpresa(std::string e){
	empresa = e;
}

std::string RegVariavel::getEmpresa(){
	return empresa;
}

void RegVariavel::setEndereco(std::string e){
	endereco = e;
}

std::string RegVariavel::getEndereco(){
	return endereco;
}

void RegVariavel::setCidade(std::string c){
	cidade = c;
}

std::string RegVariavel::getCidade(){
	return cidade;
}

void RegVariavel::setEstado(std::string e){
	estado = e;
}

std::string RegVariavel::getEstado(){
	return estado;
}

void RegVariavel::setCEP(std::string c){
	cep = c;
}

std::string RegVariavel::getCEP(){
	return cep;
}

void RegVariavel::setPhone1(std::string p1){
	phone1 = p1;
}

std::string RegVariavel::getPhone1(){
	return phone1;
}

void RegVariavel::setPhone2(std::string p2){
	phone2 = p2;
}

std::string RegVariavel::getPhone2(){
	return phone2;
}