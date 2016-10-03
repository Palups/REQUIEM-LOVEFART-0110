#include <iostream>
#include "intObject.h"

/*Construtor da classe*/
intObject::intObject()
{
	/*Inicializacao dos parametros*/
	object_x = 0;
	object_y = 0;
	object_w = 0;
	object_h = 0;
	object_state = STATE_NORMAL;
	display_dialog = false;
}

/*Altera a posicao do objeto*/
void intObject::setPosition(int x, int y)
{
	object_x = x;
	object_y = y;
}

/*Altera o tamanho*/
void intObject::setSize(int w, int h)
{
	object_w = w;
	object_h = h;
}

/*Vai testar se o objeto foi pressionado*/
void intObject::pressed(int x, int y)
{
	if (x >= object_x && x <= (object_x + object_w) && y >= object_y && y <= (object_y + object_h))
	{
		if (object_state == STATE_NORMAL)
		{
			object_state = STATE_PRESSED;
			display_dialog = true;
		}
		else
		{
			object_state = STATE_NORMAL;
			display_dialog = false;
		}
	}
}

/*Testa se o objeto/botao foi solto*/
void intObject::released(int x, int y)
{

}

void intObject::draw()
{
	if (object_state == STATE_NORMAL)
		ofDrawRectangle(object_x, object_y, object_w, object_h);
	else 
		ofDrawRectangle(object_x, object_y, object_w + 100, object_h + 100);
}

void intObject::update()
{

}

int intObject::getX()
{
	return object_x;
}
int intObject::getY()
{
	return object_y;
}
bool intObject::getDialog()
{
	return display_dialog;
}