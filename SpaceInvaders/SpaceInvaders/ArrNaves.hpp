#ifndef _ArrNaves_H_
#define _ArrNaves_H_
#include "ArrBase.hpp"
#include "Nave.hpp"
class ArrNaves :public ArrBase
{
private:
	int var_aux;
public:
	ArrNaves(){}
	~ArrNaves(){}

	void Mover_Todos(System::Drawing::Graphics ^g)
	{
		for (auto it : arreglo)
		{
			if (it->Retornar_X() + it->Retornar_ANCHO() + it->Retornar_DX() > g->VisibleClipBounds.Right
				|| it->Retornar_X() + it->Retornar_DX() < g->VisibleClipBounds.Left)
			{
				for (auto et : arreglo)
				{
					switch (et->Retornar_ID())
					{
					case 0:
						if (et->Retornar_Y() < 300)
						{
							et->Cambiar_Y(et->Retornar_Y() + et->Retornar_ALTO()/2);
							et->Retornar_DX() > 0 ? et->Cambiar_DX(et->Retornar_DX() + 1) : et->Cambiar_DX(et->Retornar_DX() - 1);
						}
						break;
					case 1:
						if (et->Retornar_Y() < 350)
						{
							et->Cambiar_Y(et->Retornar_Y() + et->Retornar_ALTO()/2);
							et->Retornar_DX() > 0 ? et->Cambiar_DX(et->Retornar_DX() + 1) : et->Cambiar_DX(et->Retornar_DX() - 1);
						}
						break;
					case 2:
						if (et->Retornar_Y() < 400)
						{
							et->Cambiar_Y(et->Retornar_Y() + et->Retornar_ALTO()/2);
							et->Retornar_DX() > 0 ? et->Cambiar_DX(et->Retornar_DX() + 1) : et->Cambiar_DX(et->Retornar_DX() - 1);
						}
						break;
					case 3:
						if (et->Retornar_Y() < 450)
						{
							et->Cambiar_Y(et->Retornar_Y() + et->Retornar_ALTO()/2);
							et->Retornar_DX() > 0 ? et->Cambiar_DX(et->Retornar_DX() + 1) : et->Cambiar_DX(et->Retornar_DX() - 1);
						}
						break;
					}
						
					
					
					et->Cambiar_DX(et->Retornar_DX()*-1);
				}

			}
		}
		
		for (auto it : arreglo)
		{
				it->Cambiar_X(it->Retornar_X() + it->Retornar_DX());
				if(it->Retornar_COLUMNA() == 0)
				it->Cambiar_COLUMNA(1);
				else it->Cambiar_COLUMNA(0);
			
		}
		//_sleep(60);
	}

	void Mostrar_Todos(System::Drawing::Graphics^g, System::Drawing::Image^imgNave1, System::Drawing::Image^imgNave2,
		System::Drawing::Image^imgNave3, System::Drawing::Image^imgNave4)
	{
		for (auto it : arreglo)
		{
			if(it->Retornar_ID()==0)
			it->Mostrar(g, imgNave1);
			else if(it->Retornar_ID() == 1)
			it->Mostrar(g, imgNave4);
			else if(it->Retornar_ID() == 2)
			it->Mostrar(g, imgNave2);
			else it->Mostrar(g, imgNave3);
		}
	}

	void Crear_Naves()
	{
		int posX = 0;
		int posY = 100;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				Nave*nuevo = new Nave();
				nuevo->Cambiar_FILA(0);
				nuevo->Cambiar_COLUMNA(0);
				nuevo->Cambiar_ALTO(50);
				nuevo->Cambiar_ANCHO(50);
				nuevo->Cambiar_Y(posY);
				nuevo->Cambiar_X(posX);
				nuevo->Cambiar_DX(4);
				nuevo->Cambiar_ID(i);
				Add(nuevo);
				posX += 60;
			}
			posY += 50;
			posX = 0;
		}
	}

	void Disparar_Todos(int valor)
	{
		var_aux = 0;
		for (auto it : arreglo)
		{
			if (((Nave*)it)->Retorna_ArrBala()->Retornar_cant() != 0)
			{
				var_aux = 1;
				break;
			}
		}

		if (var_aux == 0)
		{
			((Nave*)arreglo[rand() % arreglo.size()])->Disparar(valor);
		}
	}

	int Cant_naves() { return arreglo.size(); };
};


#endif // !_ArrNaves_H_

