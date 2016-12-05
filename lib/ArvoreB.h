#ifndef ARVOREB_H
#define ARVOREB_H

#include "../lib/No.h"
#include "../lib/utils.h"

#include <map>
#include <string>
#include <iostream>

class ArvoreB {
private:
	int height;
	std::map<int, No*> noMap;


public:
	ArvoreB();
	~ArvoreB();

	bool insert(std::string, int);
	void print();
	int seek(std::string);
	
	void setHeight(int);
	int getHeight();

	

private:
	No* buscaPosInsercao(No*, std::string);
	bool inserirNo(No*, std::string, int, No*, No* );

};

#endif