#ifndef ARVOREB_H
#define ARVOREB_H

#include "../lib/No.h"

#include <map>
#include <string>
#include <iostream>

class ArvoreB{
private:
	std::map<int, No> mapNo;
	
public:
	ArvoreB();
	~ArvoreB();

	void ArvoreB::setMapNo(int mapNo);
	int ArvoreB::getMapNo();
};

#endif