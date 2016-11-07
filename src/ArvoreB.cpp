#include "../lib/ArvoreB.h"

/**************************CONSTRUTOR**************************/
ArvoreB::ArvoreB(){

	std::cout<<"Objeto de ArvoreB criado."<<std::endl;
}

/**************************DESTRUTOR**************************/
ArvoreB::~ArvoreB(){

	std::cout<<"Objeto de ArvoreB destruido."<<std::endl;
}


/**************************METODOS PUBLICOS**************************/


/**************************SETTERS & GETTERS**************************/
void ArvoreB::setMapNo(int mapNo){
	this.mapNo = mapNo;
}

map<int, No> ArvoreB::getMapNo(){
	return this.mapNo;
}

