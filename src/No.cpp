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
int No::insert(std::string chaveAInserir, int posNoDisco, No* noFilho){

	bool troca = false;
	
	std::string tempS;
	int tempI;
	No* tempF;


	//Shift de todo mundo pra direita e add o novo no comeco
	filho[contador+1] = filho[contador];
	for(int i = contador; i > 0; i--){
		chave[i] = chave[i-1];
		prr[i] = prr[i-1];
		filho[i] = filho[i-1];
	}

	//Insere a chave em um espaco vazio
	chave[0] = chaveAInserir;
	prr[0] = posNoDisco;
	filho[0] = noFilho;

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

				tempF = filho[j+1];
				filho[j+1] = filho[j];
				filho[j] = tempF; 				
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
					filho[j+1] = NULL;
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
