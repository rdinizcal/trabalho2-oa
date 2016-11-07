#include "../lib/RegFixo.h"

/**************************CONSTRUTOR**************************/
RegFixo::RegFixo(){

	std::cout<<"Objeto de RegFixo criado."<<std::endl;
}

/**************************DESTRUTOR**************************/
RegFixo::~RegFixo(){

	std::cout<<"Objeto de RegFixo destruido."<<std::endl;
}


/**************************METODOS PUBLICOS**************************/
void RegFixo::insertReg(){
}

void RegFixo::selectReg(){
}


/**************************SETTERS & GETTERS**************************/
void RegFixo::setChavePrimaria(int chavePrimaria){
	this.chavePrimaria = chavePrimaria;
}

int RegFixo::getChavePrimaria(){
	return this.chavePrimaria;
}

void RegFixo::setCampo1(std::string campo1){
	this.campo1 = campo1;
}

std::string RegFixo::getCampo1(){
	return this.campo1;
}

void RegFixo::setCampo2(std::string campo2){
	this.campo2 = campo2;
}

std::string RegFixo::getCampo2(){
	return this.campo2;
}

void RegFixo::setCampo3(std::string campo3){
	this.campo3 = campo3;
}

std::string RegFixo::getCampo3(){
	return this.campo3;
}

