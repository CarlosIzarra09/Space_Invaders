#ifndef _Button_H_
#define _Button_H_
#include "Base.hpp"

class Botton :public Base
{

private:

public:
	Botton() { id = 1;
	ancho = 30;
	alto = 30;
	x = 1140;
	y = 620;
	}
	~Botton() {}
	void Dibujar(System::Drawing::Graphics^g, System::Drawing::Image ^img, System::Drawing::Image^img2)
	{
		if(id%2!=0)
		g->DrawImage(img, x, y, ancho, alto);
		else g->DrawImage(img2, x, y, ancho, alto);
	}

};


#endif // !_Button_H_

