#ifndef _Base_H_
#define _Base_H_


class Base
{
protected:
	int x, y, dx, dy, ancho, alto, fil, col, id;


public:
	Base() : x(0), y(0), dx(0), dy(0), ancho(0), alto(0), fil(0), col(0), id(0) {}
	~Base() {}
	void Cambiar_X(int nuevo) { x = nuevo; }
	void Cambiar_Y(int nuevo) { y = nuevo; }
	void Cambiar_DX(int nuevo) { dx = nuevo; }
	void Cambiar_DY(int nuevo) { dy = nuevo; }
	void Cambiar_ANCHO(int nuevo) { ancho = nuevo; }
	void Cambiar_ALTO(int nuevo) { alto = nuevo; }
	void Cambiar_FILA(int nuevo) { fil = nuevo; }
	void Cambiar_COLUMNA(int nuevo) { col = nuevo; }
	void Cambiar_ID(int nuevo) { id = nuevo; }

	int Retornar_X() { return x; }
	int Retornar_Y() { return y; }
	int Retornar_DX() { return dx; }
	int Retornar_DY() { return dy; }
	int Retornar_ANCHO() { return ancho; }
	int Retornar_ALTO() { return alto; }
	int Retornar_FILA() { return fil; }
	int Retornar_COLUMNA() { return col; }
	int Retornar_ID() { return id; }

	virtual void Mover(System::Drawing::Graphics ^g) {};
	virtual void Mostrar(System::Drawing::Graphics ^g, System::Drawing::Image^img) { g->DrawImage(img, x, y, ancho, alto); };
};



#endif // !_Base_H_

