#ifndef _Registro_H_
#define _Registro_H_
#include <string>

class Registro
{
private:
	std::string name;
	int score;
public:
	Registro(std::string name,int score):name(name),score(score){}
	~Registro(){}
	std::string Retornar_Nombre() { return name; }
	int Retornar_Score() { return score; }


};


#endif // !_Registro_H

