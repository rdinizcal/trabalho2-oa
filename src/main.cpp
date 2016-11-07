#include <iostream>
#include <limits>

#include "../lib/utils.h"
/*#include "../lib/memory.h"
#include "../lib/crtMemory.h"
*/

int main (int argc, char *argv[]){

	int choice=0;
/*	Memory *myMemory = new Memory;
	int files=0;*/
	bool success=false;

	if(argc != 2){
		std::cout<<"Uso incorreto do programa."<<std::endl;
		return 0;
	}

	while(true){

		Utils util;
		/*CrtMemory memoryController;*/
		

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
				//success=memoryController.eraseMemory(files,myMemory);
				//if(success) files--;
				break;
			case 4:
				return 0;
				break;
		}

		std::cout<<"\nPressione ENTER para continuar..."<<std::endl;
		std::getchar();
		std::getchar();
	}

	delete[] myMemory;	/*
	std::cout << "Press enter to continue . . . ";
	std::cin.sync();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	*/
	return 0;
}