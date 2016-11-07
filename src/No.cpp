#include "../lib/No.h"

/**************************CONSTRUTOR**************************/
No::No(){

	std::cout<<"Objeto de No criado."<<std::endl;
}

/**************************DESTRUTOR**************************/
No::~No(){

	std::cout<<"Objeto de No destruido."<<std::endl;
}


/**************************METODOS PUBLICOS**************************/
void No::insertNode(){

}

void No::selectNode(){

}


/**************************SETTERS & GETTERS**************************/
void No::setContador(int contador){
	this.contador = contador;
}

void No::setContador(int contador){
	return this.contador;
}

void No::setChave(vector<int>  chave){
	this.chave = chave;
}

vector<int>  No::getChave(){
	return this.chave;
}

void No::setPrr(vector<int> prr){
	this.prr = prr;
}

vector<int>  No::getPrr(){
	return this.prr;
}

void No::setFilho(vector<int> filho){
	this.filho = filho;
}

vector<int> No::getFilho(){
	return this.filho;
}

