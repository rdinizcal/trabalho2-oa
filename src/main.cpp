#include <iostream>
#include <limits>
#include <fstream>
#include <string.h>
#include <algorithm>

#include "../lib/CrtArvoreB.h"
#include "../lib/utils.h"

int main (int argc, char *argv[]){

	CrtArvoreB crtArvoreB;

	std::string fileName;
	std::string fileType;

	int choice = 0;
	//bool success = false;

	if(argc != 4 || strcmp(argv[2],"-r") != 0 ){
		std::cout<<"Uso incorreto do programa. (main data.txt -r (1|2))"<<std::endl;
		return 0;
	}

	if(!strcmp(argv[3],"1")){
		std::cout<<"Registro de tamanho variavel."<<std::endl;
		fileType = "rvar";
	}else if(!strcmp(argv[3],"2")){
		std::cout<<"Registro de tamanho fixo."<<std::endl;
		fileType = "rfixo";
	} else {
		std::cout<<"Uso incorreto do programa."<<std::endl;
		return 0;
	}

	fileName=argv[1];
	crtArvoreB.setUp(fileType,fileName);

	while(true){

		Utils util;		
		util.clear();

		std::cout<<"**********MENU PRINCIPAL**********"<<std::endl;
		std::cout<<"* 1 - Buscar Registro            *"<<std::endl;
		std::cout<<"* 2 - Inserir Registro           *"<<std::endl;
		std::cout<<"* 3 - Mostrar Arvore-B           *"<<std::endl;
		std::cout<<"* 4 - Sair                       *"<<std::endl;
		std::cout<<"**********************************"<<std::endl;
		std::cout<<std::endl;

		std::cout<<"Escolha um item: ";
		std::cin>>choice;

		if(choice>4 || choice<=0) return 0;

		switch(choice){
			case 1:
				//success=memoryController.writeMemory(files,myMemory);
				//if(success) files++;
				break;
			case 2:
				//success=memoryController.readMemory(files,myMemory);
				break;
			case 3:
				crtArvoreB.mostrar();
				break;
			case 4:
				return 0;
				break;
		}

		std::cout<<"\nPressione ENTER para continuar..."<<std::endl;
		std::getchar();
		std::getchar();
	}

	return 0;
}

