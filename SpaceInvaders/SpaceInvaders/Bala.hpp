#ifndef _Bala_H_
#define _Bala_H_
#include "Base.hpp"
class Bala : public Base
{
private:

public:
	Bala() {}
	~Bala() {}
	void Mostrar(System::Drawing::Graphics ^g, System::Drawing::Image^img) 
	{
		g->DrawImage(img, x, y, ancho, alto);
	};


};


#endif // !_Bala_H_

