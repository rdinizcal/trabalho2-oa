#ifndef ARVOREB_H
#define ARVOREB_H

#include "../lib/No.h"

#include <vector>
#include <string>
#include <iostream>

class ArvoreB {
private:
	int height;
	std::vector<No> noVector;
	
public:
	ArvoreB();
	~ArvoreB();

	bool insert(No*, std::string, int);

	void setHeight(int);
	int getHeight();

	void setNoVector(std::vector<No>);
	std::vector<No> getNoVector();

private:
	No* buscaPosInsercao(No*, std::string);
	bool inserirNo(No* ,std::string ,int ,No* ,No* );

};

#endif