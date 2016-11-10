#ifndef NO_H
#define NO_H

#include <vector>
#include <iostream>

class No{
private:
	static int id;
	int nivel;
	int pagina;
	int contador;
	std::vector<int> chave;
	std::vector<int> prr;
	std::vector<int> filho;


public:
	No(): pagina(id++){};
	~No();

	void setNivel(int nivel);
	int getNivel();

	void setPagina(int pagina);
	int getPagina();

	void setContador(int contador);
	int getContador();

	void setChave(std::vector<int> chave);
	std::vector<int> getChave();

	void setPrr(std::vector<int> prr);
	std::vector<int> getPrr();

	void setFilho(std::vector<int> filho);
	std::vector<int> getFilho();
};

#endif