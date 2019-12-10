#ifndef _Game_H_
#define _Game_H_
#include "Player.hpp"
#include "ArrBala.hpp"
#include "Bala.hpp"
#include "ArrNaves.hpp"
#include "Button.hpp"
#include "ArrNodriza.h"
class Game
{
private:
	Player* jugador;
	ArrNaves* naves;
	ArrNodriza* nodriza;

	Botton*boton1;
	Botton*boton2;
	int vidas;
	int cont_mover,cont,velocidad_bala,cont_nodrizas;
	int puntaje,nivel;
	bool cambio_nivel, table_score;
public:
	Game() 
	{
		cont_nodrizas = 0;
		velocidad_bala = 20;
		nivel = 0;
		puntaje = 0;
		cont_mover = 0;
		cont = 0;
		vidas = 3;
		cambio_nivel= false;
		table_score = false;
		naves = new ArrNaves();
		nodriza = new ArrNodriza();
		jugador = new Player();
		boton1 = new Botton();
		boton2 = new Botton();
		boton2->Cambiar_ANCHO(35);
		boton2->Cambiar_ALTO(35);
		boton2->Cambiar_X(675);
		boton2->Cambiar_Y(425);
		jugador->Cambiar_ANCHO(93);
		jugador->Cambiar_ALTO(56);
		jugador->Cambiar_X(500);
		jugador->Cambiar_Y(550);
		jugador->Cambiar_DX(10);
		
	}
	~Game() {}

	void Init(int vid)
	{
		
		cont_mover = 0;
		cont = 0;
		nivel += 1;
		if(vidas<3 && vid != 0)
		vidas = vid+1;
		if(vid == 0)
		{
			velocidad_bala = 20;
			vidas = 3;
			nivel = 1;
			puntaje = 0;
		}
		
		naves->Crear_Naves();
	}


	void Play(System::Drawing::Graphics ^g, System::Drawing::Image^imgP, System::Drawing::Image^imgB, System::Drawing::Image^imgNAVE1,
		System::Drawing::Image^imgNAVE2, System::Drawing::Image^imgNAVE3, System::Drawing::Image^imgNAVE4, System::Drawing::Image^imgBenem,
		System::Drawing::Image^imgButton11, System::Drawing::Image^imgButton12,System::Drawing::Image^imgButton2, System::Drawing::Image^imgNodriza,
		System::Drawing::Image^imgf1, System::Drawing::Image^imgf2)
	{
		
		if (table_score == false)
		{
			g->DrawImage(imgf1, 0, 0, 1200, 700);
			System::Drawing::StringFormat^xd;
			System::Drawing::Pen ^pincel = gcnew System::Drawing::Pen(System::Drawing::Color::White, 5);
			System::Drawing::Drawing2D::GraphicsPath^p = gcnew System::Drawing::Drawing2D::GraphicsPath();

			





			if (vidas > 0)
			{
				jugador->Mostrar(g, imgP);
				jugador->Retorna_ArrBala()->Mover_Todos(g);
				jugador->Retorna_ArrBala()->Mostrar_Todos(g, imgB);


				g->DrawImage(imgP, 10, 620, 46, 28);
				if (vidas > 1) g->DrawImage(imgP, 68, 620, 46, 28);
				if (vidas > 2) g->DrawImage(imgP, 126, 620, 46, 28);

			}

			if (nodriza->Retornar_cant() != 0)
			{
				nodriza->Mostrar_Todos(g, imgNodriza);
				nodriza->Mover_Todos(g);
			}

			if (nodriza->Retornar_cant() == 0)
			{
				cont_nodrizas++;
				if (cont_nodrizas == 250)//cada 15 segundos ingresa una nave nodriza
				{
					Nodriza*nuevo = new Nodriza();
					nuevo->Cambiar_X(-200);
					nuevo->Cambiar_Y(60);
					nuevo->Cambiar_DX(15);
					nodriza->Add(nuevo);
					cont_nodrizas = 0;
				}
			}


			System::Drawing::SolidBrush ^brocha = gcnew System::Drawing::SolidBrush(System::Drawing::Color::GreenYellow);
			System::Drawing::SolidBrush ^brocha2 = gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);
			System::Drawing::Font ^fuente = gcnew System::Drawing::Font("Space Invaders", 20, System::Drawing::FontStyle::Bold);
			System::Drawing::Font ^fuente2 = gcnew System::Drawing::Font("Space Invaders", 15, System::Drawing::FontStyle::Bold);
			g->DrawString("Score " + puntaje.ToString(), fuente, brocha2, 10, 10);
			g->DrawString("Level <" + nivel.ToString() + ">", fuente, brocha2, 1010, 10);



			for (auto it : naves->Retornar_arreglo())
			{

				((Nave*)it)->Retorna_ArrBala()->Mover_Todos(g);
				((Nave*)it)->Retorna_ArrBala()->Mostrar_Todos(g, imgBenem);


				for (int i = 0; i < ((Nave*)it)->Retorna_ArrBala()->Retornar_cant(); i++)
				{
					if (colision(jugador, ((Nave*)it)->Retorna_ArrBala()->Retornar_arreglo()[i]))
					{
						if (vidas != 0)
							vidas -= 1;

						((Nave*)it)->Retorna_ArrBala()->eliminar_pos(i);
					}
				}

			}


			



			g->FillRectangle(brocha, 0, 610, 1200, 5);

			if (naves->Retornar_cant() > 0)
			{
				cont_mover++;
				naves->Mostrar_Todos(g, imgNAVE1, imgNAVE2, imgNAVE3, imgNAVE4);
				if (cont_mover == 2)
				{
					naves->Mover_Todos(g);
					cont_mover = 0;
				}
				naves->Disparar_Todos(velocidad_bala);
			}
			else
			{
				cont++;
				p->AddString("YOU WIN", System::Drawing::FontFamily::GenericSansSerif, (int)System::Drawing::FontStyle::Bold, g->DpiY * 70 / 72, System::Drawing::Point(375, 250), xd);
				g->DrawPath(pincel, p);
				if (cont == 20)
					cambio_nivel = true;
			}

			if (cambio_nivel)
			{
				velocidad_bala += 3;
				nodriza->eliminar_pos(0);
				Init(vidas);
				cambio_nivel = false;
			}



			if (jugador->Retorna_ArrBala()->Retornar_arreglo().size() > 0)
			{
				for (int i = 0; i < naves->Retornar_arreglo().size(); i++)
				{

					if (colision(jugador->Retorna_ArrBala()->Retornar_arreglo()[0], naves->Retornar_arreglo()[i]))
					{
						jugador->Retorna_ArrBala()->eliminar_pos(0);
						naves->eliminar_pos(i);
						puntaje += 50;
						break;
					}
				}
			}

			if (jugador->Retorna_ArrBala()->Retornar_arreglo().size() > 0)
			{
				if (nodriza->Retornar_arreglo().size() > 0)
				{
					if (colision(jugador->Retorna_ArrBala()->Retornar_arreglo()[0], nodriza->Retornar_arreglo()[0]))
					{
						jugador->Retorna_ArrBala()->eliminar_pos(0);
						puntaje += 350;
						nodriza->eliminar_pos(0);
					}
				}
			}


			if (vidas == 0)
			{
				jugador->Retorna_ArrBala()->eliminar_pos(0);
				p->AddString("GAME OVER", System::Drawing::FontFamily::GenericSansSerif, (int)System::Drawing::FontStyle::Bold, g->DpiY * 70 / 72, System::Drawing::Point(300, 250), xd);
				g->DrawPath(pincel, p);
				g->DrawString("PRESS R TO RESET", fuente, brocha2, 465, 375);
				g->DrawString("SAVE SCORE", fuente2, brocha2, 510, 430);
				boton2->Mostrar(g, imgButton2);
			}

		}
		else
		{
		g->DrawImage(imgf2, 0, 0, 1200, 700);
		}
		boton1->Dibujar(g, imgButton11, imgButton12);

	}

	Player* Retornar_jugador() { return jugador; }
	ArrNaves*Retornar_ArrNaves() { return naves; }
	ArrNodriza*Retornar_Nodrizas() { return nodriza; }
	Botton*retornar_Boton1() { return boton1; }
	Botton*retornar_Boton2() { return boton2; }
	
	bool colision(Base*ob1, Base*ob2)
	{
		System::Drawing::Rectangle rect1 = System::Drawing::Rectangle(ob1->Retornar_X(), ob1->Retornar_Y(), ob1->Retornar_ANCHO(), ob1->Retornar_ALTO());
		System::Drawing::Rectangle rect2 = System::Drawing::Rectangle(ob2->Retornar_X(), ob2->Retornar_Y(), ob2->Retornar_ANCHO(), ob2->Retornar_ALTO());

		return rect1.IntersectsWith(rect2);
	}

	bool colision_mouse(Base*ob1, int x, int y)
	{
		System::Drawing::Rectangle rect1 = System::Drawing::Rectangle(ob1->Retornar_X(), ob1->Retornar_Y(), ob1->Retornar_ANCHO(), ob1->Retornar_ALTO());
		System::Drawing::Rectangle rect2 = System::Drawing::Rectangle(x, y, 1, 1);

		return rect1.IntersectsWith(rect2);
	}

	int Retornar_vidas()
	{
		return vidas;
	}

	int Retornar_Puntos()
	{
		return puntaje;
	}

	void Cambiar_TableScore(bool nuevo)
	{
		table_score = nuevo;
	}

	bool Retornar_TableScore()
	{
		return table_score;
	}
};


#endif // !_Game_H_


