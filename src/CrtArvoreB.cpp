#include "../lib/CrtArvoreB.h"

/**************************CONSTRUTOR**************************/
CrtArvoreB::CrtArvoreB(){

	std::cout<<"Objeto de CrtArvoreB criado."<<std::endl;
}

/**************************DESTRUTOR**************************/
CrtArvoreB::~CrtArvoreB(){

	//std::cout<<"Objeto de CrtArvoreB destruido."<<std::endl;
}


/**************************METODOS PUBLICOS**************************/
bool CrtArvoreB::setUp(std::string fileType, std::string fileName){

	int success = false;
int lin=0;

std::ifstream txtFile;
std::string linha;

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


txtFile.open("../data2.txt");

while(!txtFile.eof())
{

getline(txtFile,linha);

if(!txtFile.eof())
lin++;
}

txtFile.close();




		//for(int i = 0; i < (int)regFixoVector.size(); i++) {
		for(int i = 1; i <= lin; i++) {			
			std::cout<<"-----"<<std::endl;
			std::cout<<"Inserindo- Chave: "<<regFixoVector[i].getChavePrimaria()<<" Pos: "<<regFixoVector[i].getNrr()<<std::endl;
			
    		success = arvoreB.insert(regFixoVector[i].getChavePrimaria(), regFixoVector[i].getNrr());

    		if(!success) return false;

    	//arvoreB.print();

		}

	}
	else if(!fileType.compare("rvar")){
		regVariavelVector = parseVariableReg(file);

txtFile.open("../data1.txt");

while(!txtFile.eof())
{

getline(txtFile,linha);

if(!txtFile.eof())
lin++;
}

txtFile.close();

		//for(int i = 0; i < (int)regVariavelVector.size(); i++) {
		for(int i = 1; i <= lin; i++) {
			std::cout<<"Inserindo- Chave: "<<regVariavelVector[i].getChavePrimaria()<<" Pos: "<<regVariavelVector[i].getPrr()<<std::endl;

    		success = arvoreB.insert(regVariavelVector[i].getChavePrimaria(), regVariavelVector[i].getPrr());

    		if(!success) return false;

		//arvoreB.print();
		}
	}
	else{
		return false;
	}

	file.close();

	return true;
}

/*void CrtArvoreB::inserir(){
	arvoreB.insert();
}*/

void CrtArvoreB::buscar(){
arvoreB.seek();

}

void CrtArvoreB::mostrar(){
	arvoreB.print();
}

/**************************METODOS PRIVADOS**************************/
std::vector<RegFixo> CrtArvoreB::parseFixedReg(std::fstream &file){
	std::vector<RegFixo> regFixoVector;
	std::string line;
	int posCounter = 1;

	//std::cout<<"Entra no parser"<<std::endl;

	while(!file.eof()){
		RegFixo newRegFixo;

		std::getline(file, line);
		if(line.empty()) break;
		
		newRegFixo.setNrr(posCounter++);
		newRegFixo.setChavePrimaria(line.substr(0,4));
		newRegFixo.setCampo1(line.substr(5,68));
		newRegFixo.setCampo2(line.substr(74,21));
		newRegFixo.setCampo3(line.substr(96,25));
		
		
		if (newRegFixo.getNrr()<=9)
		std::cout<<"0"<<newRegFixo.getNrr()<<"|"<<newRegFixo.getChavePrimaria()<<"|"<<newRegFixo.getCampo1()<<"|"<<newRegFixo.getCampo2()<<"|"<<newRegFixo.getCampo3()<<std::endl;

		else
		std::cout<<newRegFixo.getNrr()<<"|"<<newRegFixo.getChavePrimaria()<<"|"<<newRegFixo.getCampo1()<<"|"<<newRegFixo.getCampo2()<<"|"<<newRegFixo.getCampo3()<<std::endl;

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
