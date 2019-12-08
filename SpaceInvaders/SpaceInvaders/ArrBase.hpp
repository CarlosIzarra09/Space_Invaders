#ifndef _ArrBase_H_
#define _ArrBase_H_
#include "Base.hpp"
#include <vector>
using namespace std;
class ArrBase
{

protected:
	vector<Base*>aux;
	vector<Base*>arreglo;
public:
	ArrBase(){}
	~ArrBase(){}

	void Add(Base*obj)
	{
		arreglo.push_back(obj);
	}
	int Retornar_cant()
	{
		return arreglo.size();
	}

	void Mostrar_Todos(System::Drawing::Graphics^g,System::Drawing::Image^img)
	{
		for (auto it : arreglo)
		{
			it->Mostrar(g, img);
		}
	}

	virtual void Mover_Todos(System::Drawing::Graphics^g)
	{

	}

	void eliminar_pos(int pos)
	{
		if (pos == 0 && arreglo.size() == 1)
		{
			arreglo.clear();
		}
		else
		{
			for (int i = 0; i < pos; i++)
				aux.push_back(arreglo[i]);
			for (int i = pos + 1; i < arreglo.size(); i++)
				aux.push_back(arreglo[i]);


			arreglo.clear();

			for (auto it : aux)
				arreglo.push_back(it);

			aux.clear();
		}
	}

	vector<Base*> Retornar_arreglo() { return arreglo; }
};


#endif // !_ArrBase_H_

