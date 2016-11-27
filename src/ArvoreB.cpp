#include "../lib/ArvoreB.h"

/**************************CONSTRUTOR**************************/
ArvoreB::ArvoreB(){

	height = 0;

	//std::cout<<"Objeto de ArvoreB criado."<<std::endl;
}

/**************************DESTRUTOR**************************/
ArvoreB::~ArvoreB(){

	//std::cout<<"Objeto de ArvoreB destruido."<<std::endl;
}


/**************************METODOS PUBLICOS**************************/
bool ArvoreB::insert(std::string chaveAInserir, int posNoDisco){

	std::cout<<"Altura da Arvore: "<<height<<std::endl;
	std::cout<<"noMap> ";
	for(int i = 0; i<(int)noMap.size();i++){
		std::cout<<noMap[i]->getPagina()<<"|";
	}
	std::cout<<std::endl;

	if(noMap.size()>0){
		for(int i = 0; i < (int)noMap.size(); i++){
			if(noMap[i]->getNivel() == height){
				return inserirNo(buscaPosInsercao(noMap[i], chaveAInserir), chaveAInserir, posNoDisco, NULL, NULL);
			}
		}
	}
	
	No* raiz = new No;
	noMap[raiz->getPagina()] = raiz;
	
	return inserirNo(buscaPosInsercao(noMap[0], chaveAInserir), chaveAInserir, posNoDisco, NULL, NULL);
}

void ArvoreB::print(){

	Utils util;		
	util.clear();

	for(int i = height; i >= 0; i--){
		std::cout<<"N"<<i<<":\n";
		bool primeiroAImprimir = true;
		for(int j = 0; j < (int)noMap.size(); j++){
			
			if(noMap[j]->getNivel() == i){
				if(!primeiroAImprimir) std::cout<<"\n";
				primeiroAImprimir = false;
				std::cout<<"P"<<noMap[j]->getPagina()<<":\t";

				if(noMap[j]->getPai() != NULL) std::cout<<"PAI("<<noMap[j]->getPai()->getPagina()<<")\t";

				for(int k = 0; k < noMap[j]->getContador(); k++){
					std::cout<<noMap[j]->getChave(k);
					if(k+1 < noMap[j]->getContador()) std::cout<<"|";
				}

				std::cout<<" ";

				bool firstToPrint = true;
				for(int k = 0; k < 6; k++){
					if(noMap[j]->getFilho(k) != NULL){
						if(!firstToPrint) std::cout<<"|";
						firstToPrint = false;
						std::cout<<noMap[j]->getFilho(k)->getPagina();
					}

				}

				if(firstToPrint) std::cout<<"-|-";
			}
		}
		std::cout<<std::endl;
		std::cout<<"\n";
	}

}

void ArvoreB::seek(){
std::cout<<"\nBuscando...\n";
}
/**************************METODOS PRIVADOS***************************/
No* ArvoreB::buscaPosInsercao(No* noAtual, std::string chaveAInserir){

	//std::cout<<std::endl<<"Buscando posicao de insercao..."<<std::endl;
	for(int i = 0; i < 5; i++){
		//std::cout<<"Chave a Inserir: "<<chaveAInserir<<" Chave do No: "<<noAtual->getChave(i)<<std::endl;
		if(!noAtual->getChave(i).empty()){
			//std::cout<<"Chave do no nao e vazia.."<<std::endl;
			if(chaveAInserir.compare(noAtual->getChave(i))<0){
				//std::cout<<"Chave a inserir e menor que a do no.."<<std::endl;
				if(noAtual->getFilho(i) == NULL){
					return noAtual;
				}else{
					return buscaPosInsercao(noAtual->getFilho(i), chaveAInserir);
				}
			}
		}else{
			//std::cout<<"Chave do no e vazia.."<<std::endl;
			if(noAtual->getFilho(i) == NULL){
				//std::cout<<"Nao tem filho..."<<std::endl;
				return noAtual;
			}else{
				//std::cout<<"Tem filho.."<<std::endl;
				return buscaPosInsercao(noAtual->getFilho(i), chaveAInserir);
			}
		}
	}

	return noAtual;
}

bool ArvoreB::inserirNo(No* noAtual, std::string chaveAInserir, int posNoDisco, No* noFilho, No* noIrmao){
	
	bool success = true;
	int posInsercao = noAtual->insert(chaveAInserir, posNoDisco);
	std::cout<<"No: "<<noAtual->getPagina()<<" -> "<<"Chave "<<chaveAInserir<<" inserida na posicao "<<posInsercao<<std::endl;

	if(noAtual == NULL)
		return false;

	if(noFilho != NULL){
		noAtual->setFilho(noFilho, posInsercao);
		if(noIrmao != NULL) noAtual->setFilho(noIrmao, posInsercao+1);
	}

	if(noAtual->getContador()>4){
		if(noAtual->getPai()==NULL){
			std::cout<<"Cria No pai->"<<std::endl;
			No* pai = new No;
			pai->setNivel(noAtual->getNivel()+1);
			height = pai->getNivel();
			noAtual->setPai(pai);
			noMap[pai->getPagina()] = pai;

		}
		std::cout<<"Cria No irmao"<<std::endl;
		No* irmao = new No;
		irmao->setPai(noAtual->getPai());
		irmao->setNivel(noAtual->getNivel());
		noMap[irmao->getPagina()] = irmao;

		std::cout<<"Inserir chave[2] no pai"<<std::endl;
		success = inserirNo(noAtual->getPai(), noAtual->getChave(2), noAtual->getPrr(2), noAtual, irmao);

		std::cout<<"Inserir chave[3] no irmao"<<std::endl;
		inserirNo(irmao, noAtual->getChave(3), noAtual->getPrr(3), noAtual->getFilho(3), NULL);
		std::cout<<"Inserir chave[4] no irmao"<<std::endl;
		inserirNo(irmao, noAtual->getChave(4), noAtual->getPrr(4), noAtual->getFilho(4), noAtual->getFilho(5));

		for(int j = 4; j > 1; j--){

			std::cout<<"Apagando "<<noAtual->getChave(j)<<" do No "<<noAtual->getPagina()<<std::endl;
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

/*void ArvoreB::setNoVector(std::vector<No> nVec){
	noVector = nVec;
}

std::vector<No> ArvoreB::getNoVector(){
	return noVector;
}*/
