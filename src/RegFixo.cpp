#include "../lib/RegFixo.h"

/**************************CONSTRUTOR**************************/
RegFixo::RegFixo(){

	//std::cout<<"Objeto de RegFixo criado."<<std::endl;
}

/**************************DESTRUTOR**************************/
RegFixo::~RegFixo(){

	//std::cout<<"Objeto de RegFixo destruido."<<std::endl;
}


/**************************METODOS PUBLICOS**************************/


/**************************SETTERS & GETTERS**************************/
void RegFixo::setChavePrimaria(std::string c){
	chavePrimaria = c;
}

std::string RegFixo::getChavePrimaria(){
	return chavePrimaria;
}

void RegFixo::setNrr(int n){
	nrr = n;
}
	
int RegFixo::getNrr(){
	return nrr;
}

void RegFixo::setCampo1(std::string c1){
	campo1 = c1;
}

std::string RegFixo::getCampo1(){
	return campo1;
}

void RegFixo::setCampo2(std::string c2){
	campo2 = c2;
}

std::string RegFixo::getCampo2(){
	return campo2;
}

void RegFixo::setCampo3(std::string c3){
	campo3 = c3;
}

std::string RegFixo::getCampo3(){
	return campo3;
}

