#ifndef NO_H
#define NO_H

#define ORDEM 5

#include <vector>

class No{
private:
	int contador;
	std::vector<int> chave(ORDEM-2);
	std::vector<int> prr(ORDEM-2);
	std::vector<int> filho(ORDEM-1);


public:
	No();
	~No();

	void insertNode();

	void setContador(int contador);
	int getContador();

	void setChave(vector<int> chave);
	vector<int> getChave();

	void No::setPrr(vector<int> prr);
	vector<int> getPrr();

	void setFilho(vector<int> filho);
	vector<int> getFilho();
};

#endif