#include "../lib/CrtArvoreB.h"

/**************************CONSTRUTOR**************************/
CrtArvoreB::CrtArvoreB(){

	std::cout<<"Objeto de CrtArvoreB criado."<<std::endl;
}

/**************************DESTRUTOR**************************/
CrtArvoreB::~CrtArvoreB(){

	std::cout<<"Objeto de CrtArvoreB destruido."<<std::endl;
}


/**************************METODOS PUBLICOS**************************/
bool CrtArvoreB::setUp(std::string fileType, std::string fileName){

	int success = false;

	std::string filePath;

	std::fstream file;

	std::vector<RegFixo> regFixoVector;
	std::vector<RegVariavel> regVariavelVector;
	
	filePath = "../";
	filePath.append(fileName);

	file.open(filePath, std::fstream::in);

	if(!file.is_open()){
		std::cout<<fileName<<" nao pode ser aberto."<<std::endl;
		return false;
	}

	//std::cout<<fileName<<" foi aberto."<<std::endl;

	if(fileType.compare("rfixo")){
		regFixoVector = parseFixedReg(file);

		for(int i = 0; i < (int)regFixoVector.size(); i++) {
    		success = arvoreB.insert(regFixoVector[i].getChavePrimaria(), regFixoVector[i].getNrr());
    		if(!success) return false;
		}

	}
	else if(fileType.compare("rvar")){
		regVariavelVector = parseVariableReg(file);

		for(int i = 0; i < (int)regVariavelVector.size(); i++) {
    		success = arvoreB.insert(regVariavelVector[i].getChavePrimaria(), regVariavelVector[i].getPrr());
    		if(!success) return false;
		}
	}
	else{
		return false;
	}

	file.close();

	return true;
}

void CrtArvoreB::inserir(){

}

void CrtArvoreB::buscar(){

}

void CrtArvoreB::mostrar(){

}

/**************************METODOS PRIVADOS**************************/
std::vector<RegFixo> CrtArvoreB::parseFixedReg(std::fstream &file){
	std::vector<RegFixo> regFixoVector;
	return regFixoVector;
}

std::vector<RegVariavel>  CrtArvoreB::parseVariableReg(std::fstream &file){
	std::vector<RegVariavel> regVariavelVector;
	return regVariavelVector;
}