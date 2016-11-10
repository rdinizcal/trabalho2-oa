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

	std::cout<<"fileType: "<<fileType<<std::endl;

	if(!fileType.compare("rfixo")){
		regFixoVector = parseFixedReg(file);

		for(int i = 0; i < (int)regFixoVector.size(); i++) {
    		success = arvoreB.insert(regFixoVector[i].getChavePrimaria(), regFixoVector[i].getNrr());
    		if(!success) return false;
		}

	}
	else if(!fileType.compare("rvar")){
		std::cout<<"Ready to parse variable..."<<std::endl;
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
	std::string line;
	int posCounter = 0;

	//std::cout<<"Entra no parser"<<std::endl;

	while(!file.eof()){
		RegFixo newRegFixo;

		std::getline(file, line);
		if(line.empty()) break;

		newRegFixo.setChavePrimaria(line.substr(0,4));
		newRegFixo.setCampo1(line.substr(5,68));
		newRegFixo.setCampo2(line.substr(74,21));
		newRegFixo.setCampo3(line.substr(96,25));
		newRegFixo.setNrr(posCounter++);

		//std::cout<<newRegFixo.getNrr()<<"/"<<newRegFixo.getChavePrimaria()<<"/"<<newRegFixo.getCampo1()<<"/"<<newRegFixo.getCampo2()<<"/"<<newRegFixo.getCampo3()<<std::endl;

		regFixoVector.push_back(newRegFixo);
		line.clear();
	}

	return regFixoVector;
}

std::vector<RegVariavel>  CrtArvoreB::parseVariableReg(std::fstream &file){
	std::vector<RegVariavel> regVariavelVector;
	std::string line;
	std::vector<std::string> tokens;
	int posCounter = 0;
	int nextPos = 0;
	int pos = 0;

	while(!file.eof()){
		RegVariavel newRegVariavel;

		std::getline(file, line);
		if(line.empty()) break;

		std::cout<<line<<std::endl;

		pos=0;
		
		nextPos = line.find(";",pos);
		newRegVariavel.setChavePrimaria(line.substr(pos,nextPos-pos));
		pos = nextPos+1;

		nextPos = line.find(";",pos);
		newRegVariavel.setNome(line.substr(pos,nextPos-pos));
		pos = nextPos+1;

		nextPos = line.find(";",pos);
		newRegVariavel.setSobrenome(line.substr(pos,nextPos-pos));
		pos = nextPos+1;

		nextPos = line.find(";",pos);		
		newRegVariavel.setEmpresa(line.substr(pos,nextPos-pos));
		pos = nextPos+1;

		nextPos = line.find(";",pos);
		newRegVariavel.setEndereco(line.substr(pos,nextPos-pos));
		pos = nextPos+1;

		nextPos = line.find(";",pos);
		newRegVariavel.setCidade(line.substr(pos,nextPos-pos));
		pos = nextPos+1;

		nextPos = line.find(";",pos);
		newRegVariavel.setCondado(line.substr(pos,nextPos-pos));
		pos = nextPos+1;

		nextPos = line.find(";",pos);
		newRegVariavel.setEstado(line.substr(pos,nextPos-pos));
		pos = nextPos+1;

		nextPos = line.find(";",pos);
		newRegVariavel.setCEP(line.substr(pos,nextPos-pos));
		pos = nextPos+1;

		nextPos = line.find(";",pos);
		newRegVariavel.setPhone1(line.substr(pos,nextPos-pos));
		pos = nextPos+1;

		nextPos = line.find(";",pos);
		newRegVariavel.setPhone2(line.substr(pos,line.size()-1));

		newRegVariavel.setPrr(posCounter);
		posCounter+=line.size();

		std::cout<<newRegVariavel.getPrr()<<"/"<<newRegVariavel.getChavePrimaria()<<"/"<<newRegVariavel.getNome()<<"/"<<newRegVariavel.getSobrenome()<<"/"<<newRegVariavel.getEmpresa();
		std::cout<<"/"<<newRegVariavel.getEndereco()<<"/"<<newRegVariavel.getCidade()<<"/"<<newRegVariavel.getCondado()<<"/"<<newRegVariavel.getEstado()<<"/"<<newRegVariavel.getCEP()<<"/"<<newRegVariavel.getPhone1()<<"/"<<newRegVariavel.getPhone2()<<std::endl<<std::endl;


		regVariavelVector.push_back(newRegVariavel);
		line.clear();
	}

	return regVariavelVector;
}