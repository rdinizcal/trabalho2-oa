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
			std::cout<<"-----"<<std::endl;
			std::cout<<"Inserindo- Chave: "<<regFixoVector[i].getChavePrimaria()<<" Pos: "<<regFixoVector[i].getNrr()<<std::endl;
			
    		if(!arvoreB.insert(regFixoVector[i].getChavePrimaria(), regFixoVector[i].getNrr())) return false;
 
		}

	}
	else if(!fileType.compare("rvar")){
		regVariavelVector = parseVariableReg(file);

		for(int i = 0; i < (int)regVariavelVector.size(); i++) {
			std::cout<<"Inserindo- Chave: "<<regVariavelVector[i].getChavePrimaria()<<" Pos: "<<regVariavelVector[i].getPrr()<<std::endl;

    		if(!arvoreB.insert(regVariavelVector[i].getChavePrimaria(), regVariavelVector[i].getPrr())) return false;
		}
	}
	else{
		return false;
	}

	file.close();

	return true;
}

void CrtArvoreB::buscar(std::string fileType, std::string fileName){
	int pos;

	std::string chave;
	std::string filePath;

	std::fstream file;

	std::vector<RegFixo> regFixoVector;
	std::vector<RegVariavel> regVariavelVector;

	filePath = "../";
	filePath.append(fileName);

	file.open(filePath, std::fstream::in);

	if(!file.is_open()){
		std::cout<<fileName<<" nao pode ser aberto."<<std::endl;
		return;
	}

	std::cout<<"Entre com a chave primaria a ser buscada: ";
	std::cin>>chave;


	pos = arvoreB.seek(chave);

	if(pos==-1){
		std::cout<<"Chave nao encontrada."<<std::endl;
	}else{

		if(!fileType.compare("rfixo")){
			regFixoVector = parseFixedReg(file);


			for(int i = 0; i < (int)regFixoVector.size(); i++) {
				
				if(regFixoVector[i].getNrr() == pos){
					std::cout<<regFixoVector[i].getChavePrimaria()<<" "<<regFixoVector[i].getCampo1()<<" "<<regFixoVector[i].getCampo2()<<" "<<regFixoVector[i].getCampo3()<<std::endl;
					break;
				}
				if((i+1) == (int)regFixoVector.size()) std::cout<<"ERROR: O registro foi encontrado na arvore porem nao foi encontrado no arquivo"<<std::endl;

			}

		}
		else if(!fileType.compare("rvar")){
			regVariavelVector = parseVariableReg(file);

			for(int i = 0; i < (int)regVariavelVector.size(); i++) {
				
				if(regVariavelVector[i].getPrr() == pos){
					std::cout<<regVariavelVector[i].getChavePrimaria()<<" "<<regVariavelVector[i].getNome()<<" "<<regVariavelVector[i].getSobrenome()<<" "<<regVariavelVector[i].getEmpresa();
					std::cout<<" "<<regVariavelVector[i].getEndereco()<<" "<<regVariavelVector[i].getCidade()<<" "<<regVariavelVector[i].getCondado()<<" "<<regVariavelVector[i].getEstado();
					std::cout<<" "<<regVariavelVector[i].getCEP()<<" "<<regVariavelVector[i].getPhone1()<<" "<<regVariavelVector[i].getPhone2()<<std::endl;
					break;
				}
				if((i+1) == (int)regVariavelVector.size()) std::cout<<"ERROR: O registro foi encontrado na arvore porem nao foi encontrado no arquivo"<<std::endl;
			}
		}


	}


	file.close();

	return;
}

void CrtArvoreB::mostrar(){
	arvoreB.print();
}

bool CrtArvoreB::inserir(std::string fileType){

	std::string chave;
	int pos;

	if(!fileType.compare("rfixo")){
		
		std::string campo1;
		std::string campo2;
		std::string campo3;

		RegFixo regfix;

		std::cout<<"Chave: ";
		std::cin>>chave;

		std::cout<<"Campo 1: ";
		std::cin>>campo1;

		std::cout<<"Campo 2: ";
		std::cin>>campo2;

		std::cout<<"Campo 3: ";
		std::cin>>campo3;

		pos = regfix.objectCounter;

		regfix.setCampo1(campo1);
		regfix.setCampo2(campo2);
		regfix.setCampo3(campo3);
		regfix.setNrr(pos);
	}
	else if(!fileType.compare("rvar")){
		std::string nome;
		std::string sobrenome;
		std::string empresa;
		std::string endereco;
		std::string cidade;
		std::string condado;
		std::string estado;
		std::string cep;
		std::string phone1;
		std::string phone2;

		RegVariavel regvar;

		std::cout<<"Chave: ";
		std::cin>>chave;

		std::cout<<"Nome: ";
		std::cin>>nome;

		std::cout<<"Sobrenome: ";
		std::cin>>sobrenome;

		std::cout<<"Empresa: ";
		std::cin>>empresa;
		
		std::cout<<"Endereco: ";
		std::cin>>endereco;

		std::cout<<"Cidade: ";
		std::cin>>cidade;

		std::cout<<"Condado: ";
		std::cin>>condado;

		std::cout<<"Estado: ";
		std::cin>>estado;

		std::cout<<"CEP: ";
		std::cin>>cep;

		std::cout<<"Phone1: ";
		std::cin>>phone1;

		std::cout<<"Phone2: ";
		std::cin>>phone2;

		pos = regvar.objectCounter;

		regvar.setChavePrimaria(chave);
		regvar.setNome(nome);
		regvar.setSobrenome(sobrenome);
		regvar.setEmpresa(empresa);
		regvar.setEndereco(endereco);
		regvar.setCidade(cidade);
		regvar.setCondado(condado);
		regvar.setEstado(estado);
		regvar.setCEP(cep);
		regvar.setPhone1(phone1);
		regvar.setPhone2(phone2);
		regvar.setPrr(pos);
	}
	else{
		return false;
	} 

	return arvoreB.insert(chave, pos);
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
		
		newRegFixo.setChavePrimaria(line.substr(0,4));
		newRegFixo.setCampo1(line.substr(5,68));
		newRegFixo.setCampo2(line.substr(74,21));
		newRegFixo.setCampo3(line.substr(96,25));
		newRegFixo.setNrr(posCounter++);
		
		//if (newRegFixo.getNrr()<=9)
		//std::cout<<"0"<<newRegFixo.getNrr()<<"|"<<newRegFixo.getChavePrimaria()<<"|"<<newRegFixo.getCampo1()<<"|"<<newRegFixo.getCampo2()<<"|"<<newRegFixo.getCampo3()<<std::endl;

		//else
		//std::cout<<newRegFixo.getNrr()<<"|"<<newRegFixo.getChavePrimaria()<<"|"<<newRegFixo.getCampo1()<<"|"<<newRegFixo.getCampo2()<<"|"<<newRegFixo.getCampo3()<<std::endl;

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

		//std::cout<<newRegVariavel.getPrr()<<"/"<<newRegVariavel.getChavePrimaria()<<"/"<<newRegVariavel.getNome()<<"/"<<newRegVariavel.getSobrenome()<<"/"<<newRegVariavel.getEmpresa();
		//std::cout<<"/"<<newRegVariavel.getEndereco()<<"/"<<newRegVariavel.getCidade()<<"/"<<newRegVariavel.getCondado()<<"/"<<newRegVariavel.getEstado()<<"/"<<newRegVariavel.getCEP()<<"/"<<newRegVariavel.getPhone1()<<"/"<<newRegVariavel.getPhone2()<<std::endl<<std::endl;


		regVariavelVector.push_back(newRegVariavel);
		line.clear();
	}

	return regVariavelVector;
}
