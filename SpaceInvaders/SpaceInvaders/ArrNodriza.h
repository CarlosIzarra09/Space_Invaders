#ifndef  _ArrNodriza_H_
#define _ArrNodriza_H_
#include "ArrBase.hpp"
#include "Nodriza.hpp"
class ArrNodriza :public ArrBase
{
private:

public:
	ArrNodriza(){}
	~ArrNodriza(){}
	void Mover_Todos(System::Drawing::Graphics^g)
	{
		for (auto it : arreglo)
			it->Mover(g);
	}


};


#endif // ! _ArrNodriza_H_

