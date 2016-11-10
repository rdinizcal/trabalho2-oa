#include "../lib/No.h"

/**************************CONSTRUTOR**************************/
/*No::No(){

	std::cout<<"Objeto de No criado."<<std::endl;
}*/

/**************************DESTRUTOR**************************/
No::~No(){

	std::cout<<"Objeto de No destruido."<<std::endl;
}


/**************************METODOS PUBLICOS**************************/


/**************************SETTERS & GETTERS**************************/
void No::setNivel(int n){
	nivel = n;
}

int No::getNivel(){
	return nivel;
}

void No::setPagina(int p){
	pagina = p;
}

int No::getPagina(){
	return pagina;
}

void No::setContador(int c){
	contador = c;
}

int No::getContador(){
	return contador;
}

void No::setChave(std::vector<int> c){
	chave = c;
}

std::vector<int>  No::getChave(){
	return chave;
}

void No::setPrr(std::vector<int> p){
	prr = p;
}

std::vector<int>  No::getPrr(){
	return prr;
}

void No::setFilho(std::vector<int> f){
	filho = f;
}

std::vector<int> No::getFilho(){
	return filho;
}

