#ifndef _ArrBala_H_
#define _ArrBala_H_
#include "ArrBase.hpp"
#include "Bala.hpp"
class ArrBala :public ArrBase
{
private:

public:
	ArrBala(){}
	~ArrBala(){}

	void Mover_Todos(System::Drawing::Graphics^g)
	{
		for (auto it : arreglo)
		{
			if (it->Retornar_DY() < 0)
			{
				if (it->Retornar_Y() + it->Retornar_DY() > g->VisibleClipBounds.Top)
					it->Cambiar_Y(it->Retornar_Y() + it->Retornar_DY());
				else
					eliminar_pos(0);
			}

			else
			{
				if (it->Retornar_Y() + it->Retornar_ALTO() +it->Retornar_DY() < 610)
					it->Cambiar_Y(it->Retornar_Y() + it->Retornar_DY());
				else
					eliminar_pos(0);
			}

			
		}
	}

};


#endif // !_ArrBala_H_

