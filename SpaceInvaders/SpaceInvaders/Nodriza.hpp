#ifndef _Nodriza_H_
#define _Nodriza_H_
#include "Base.hpp"
class Nodriza :public Base
{

private:

public:
	Nodriza()
	{
		alto = 50;
		ancho = 100;
	}
	~Nodriza(){}
	void Mover(System::Drawing::Graphics^g)
	{
		if (x + ancho + dx > 3000
			|| x + dx < -3000)
		{
			dx = dx * -1;
		}
		x += dx;
	}

};


#endif // !_Nodriza_H_
