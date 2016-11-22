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
bool ArvoreB::insert(No* novoNo, std::string chaveAInserir, int posNoDisco){

	No raiz;

	if(noVector.size()>0){
		for(int i = 0; i < (int)noVector.size(); i++){
			if(noVector[i].getNivel() == height){
				raiz = noVector[i];
				break;
			}
		}
	}else{
		noVector.push_back(raiz);
	}

	novoNo = buscaPosInsercao(&raiz, chaveAInserir);
	return inserirNo(novoNo, chaveAInserir, posNoDisco, NULL, NULL);
}

/**************************METODOS PRIVADOS***************************/
No* ArvoreB::buscaPosInsercao(No* noAtual, std::string chaveAInserir){

	for(int i = 0; i < noAtual->getContador(); i++){
		if(noAtual->getChave(i) != ""){
			if(chaveAInserir.compare(noAtual->getChave(i))<0){
				if(noAtual->getFilho(i) == NULL){
					return noAtual;
				}else{
					return buscaPosInsercao(noAtual->getFilho(i), chaveAInserir);
				}
			}else{
				return noAtual;
			}
		}
	}

	return noAtual;
}

bool ArvoreB::inserirNo(No* noAtual, std::string chaveAInserir, int posNoDisco, No* noFilho, No* noIrmao){
	
	bool success = true;
	int posInsercao = noAtual->insert(chaveAInserir, posNoDisco);
	std::cout<<"Posicao para insercao dentro do no: "<<posInsercao<<std::endl;

	if(noFilho != NULL && noIrmao != NULL){
		noAtual->setFilho(noFilho, posInsercao);
		noAtual->setFilho(noIrmao, posInsercao+1);
	}

	if(noAtual->getContador()>4){
		if(noAtual->getPai()==NULL){
			No pai;
			pai.setNivel(noAtual->getNivel()+1);
			height = pai.getNivel();
			noAtual->setPai(&pai);
			noVector.push_back(pai);
		}
		No irmao;
		irmao.setPai(noAtual->getPai());
		irmao.setNivel(noAtual->getNivel());
		noVector.push_back(irmao);

		success = inserirNo(noAtual->getPai(), noAtual->getChave(2), noAtual->getPrr(2), noAtual, &irmao);

		inserirNo(&irmao, noAtual->getChave(3), noAtual->getPrr(3), NULL, NULL);
		inserirNo(&irmao, noAtual->getChave(4), noAtual->getPrr(4), NULL, NULL);

		for(int j = 4; j > 1; j++){
			noAtual->erase(noAtual->getChave(j));
		}

	}

	return success;
}

/**************************SETTERS & GETTERS**************************/
void ArvoreB::setHeight(int h){
	height = h;
}

int ArvoreB::getHeight(){
	return height;
}

void ArvoreB::setNoVector(std::vector<No> nVec){
	noVector = nVec;
}

std::vector<No> ArvoreB::getNoVector(){
	return noVector;
}

