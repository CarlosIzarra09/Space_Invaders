#ifndef _Player_H_
#define _Player_H_
#include "Base.hpp"
#include "ArrBala.hpp"
#include "Bala.hpp"
class Player : public Base
{
private:
	ArrBala* arreglo_balas;
public:
	Player() { arreglo_balas = new ArrBala(); }
	~Player() {}

	void Mover_Derecha(System::Drawing::Graphics ^g)
	{
		if (x + dx + ancho < g->VisibleClipBounds.Right)
			x += dx;
	};
	void Mover_Izquierda(System::Drawing::Graphics ^g)
	{
		if (x - dx > g->VisibleClipBounds.Left)
			x -= dx;
	};

	void Disparar()
	{
		if (arreglo_balas->Retornar_cant() == 0)
		{
			Bala*obj = new Bala();
			obj->Cambiar_ANCHO(21);
			obj->Cambiar_ALTO(40);
			obj->Cambiar_DY(-15);
			obj->Cambiar_X(x + (ancho / 2));
			obj->Cambiar_Y(y - obj->Retornar_ALTO());
			arreglo_balas->Add(obj);
		}
	}
	
	void Mostrar(System::Drawing::Graphics ^g, System::Drawing::Image^img)
	{
		g->DrawImage(img, x, y, ancho, alto);
	};

	ArrBala* Retorna_ArrBala() { return arreglo_balas; }
};


#endif // !_Player_H_

