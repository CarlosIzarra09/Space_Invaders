#ifndef _Nave_H_
#define _Nave_H_
#include "Base.hpp"
#include "ArrBala.hpp"
#include "Bala.hpp"

class Nave :public Base
{
private:
	ArrBala*arreglo;
public:
	Nave() { arreglo = new ArrBala(); }
	~Nave() {}
	void Mostrar(System::Drawing::Graphics^g, System::Drawing::Image^img)
	{
		System::Drawing::Rectangle celda = System::Drawing::Rectangle((col*ancho), (fil*alto), ancho, alto);
		g->DrawImage(img, x, y, celda, System::Drawing::GraphicsUnit::Pixel);
	}

	void Disparar(int valor)
	{
		if (arreglo->Retornar_cant() == 0)
		{
			Bala*obj = new Bala();
			obj->Cambiar_ANCHO(7);
			obj->Cambiar_ALTO(20);
			obj->Cambiar_DY(valor);
			obj->Cambiar_X(x + (ancho / 2));
			obj->Cambiar_Y(y + obj->Retornar_ALTO());
			arreglo->Add(obj);
		}
	}

	ArrBala* Retorna_ArrBala() { return arreglo; }
	
};


#endif // !_Nave_H_

