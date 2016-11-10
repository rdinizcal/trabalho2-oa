#ifndef ARVOREB_H
#define ARVOREB_H

#include "../lib/No.h"

#include <map>
#include <string>
#include <iostream>

class ArvoreB{
private:
	int height;
	std::map<int, No> mapNo;
	
public:
	ArvoreB();
	~ArvoreB();

	bool insert(std::string, int);

	void setHeight(int height);
	int getHeight();

	void setMapNo(std::map<int,No> mapNo);
	std::map<int,No> getMapNo();
};

#endif