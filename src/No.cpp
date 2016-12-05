#include "../lib/No.h"

int No::objectCounter = 0;

/**************************CONSTRUTOR**************************/
No::No(){

	nivel = 0;
	pagina = objectCounter++;
	contador = 0;


	for(int i = 0; i < 5; i++){
		chave[i] = "";
		prr[0] = 0;
		filho[i] = NULL;
	}
	filho[5] = NULL;
	pai = NULL;

	//std::cout<<"Objeto de No "<<pagina<<" criado."<<std::endl;
}

/**************************DESTRUTOR**************************/
No::~No(){

	//std::cout<<"Objeto de No "<<pagina<<" destruido."<<std::endl;
}


/**************************METODOS PUBLICOS**************************/
int No::insert(std::string chaveAInserir, int posNoDisco){

	bool troca = false;
	
	std::string tempS;
	int tempI;

	std::cout<<"Inserindo chave "<<chaveAInserir<<" no No "<<pagina<<" ..."<<std::endl;
	//Insere a chave em um espaco vazio
	chave[contador] = chaveAInserir;
	prr[contador] = posNoDisco;

	//E organiza as strings em ordem cresncente 
	for(int i = 0; i < contador; i++){
		troca = false;
		for(int j = 0; j < contador; j++){
			if(chave[j].compare(chave[j+1])>0){
				troca = true;

				tempS = chave[j+1];
				chave[j+1] = chave[j];
				chave[j] = tempS;

				tempI = prr[j+1];
				prr[j+1] = prr[j];
				prr[j] = tempI;
			}
		}
		if(!troca) break;
	}

	contador++;
	
	for(int i = 0; i < contador; i++){
		if(chave[i] == chaveAInserir) return i;
	}

	return -1;
}

void No::erase(std::string chaveAApagar){
	
	for(int i = 0; i < contador; i++){
		if(chave[i] == chaveAApagar) {
			for(int j = i; j < contador; j++){
				if(j+1<contador){
					chave[j] = chave[j+1];
					prr[j] = prr[j+1];
					filho[j] = filho[j+1];
				}else{
					prr[j] = 0;
					filho[j] = NULL;
				}

			}
			break;
		}
	}

	contador--;

}
/**************************METODOS PRIVADOS**************************/

/**************************SETTERS & GETTERS**************************/
void No::setNivel(int n){
	nivel = n;
}

int No::getNivel(){
	return nivel;
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

std::string No::getChave(int i){
	return chave[i];
}

int No::getPrr(int i){
	return prr[i];
}

void No::setFilho(No* node, int i){
	filho[i] = node;
}

No* No::getFilho(int i){
	return filho[i];
}

void No::setPai(No* node){
	pai = node;
}

No* No::getPai(){
	return pai;
}
