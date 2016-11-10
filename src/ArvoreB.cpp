#include "../lib/ArvoreB.h"

/**************************CONSTRUTOR**************************/
ArvoreB::ArvoreB(){

	height = 0;

	std::cout<<"Objeto de ArvoreB criado."<<std::endl;
}

/**************************DESTRUTOR**************************/
ArvoreB::~ArvoreB(){

	std::cout<<"Objeto de ArvoreB destruido."<<std::endl;
}


/**************************METODOS PUBLICOS**************************/
bool ArvoreB::insert(std::string key, int pos){

	return true;
}

/**************************SETTERS & GETTERS**************************/
void ArvoreB::setHeight(int h){
	height = h;
}

int ArvoreB::getHeight(){
	return height;
}

void ArvoreB::setMapNo(std::map<int, No> map){
	mapNo = map;
}

std::map<int, No> ArvoreB::getMapNo(){
	return mapNo;
}

