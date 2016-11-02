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


	/*Inicialização dos dialogos*/
	dialogFlag = false;
	myfont.loadFont("TravelingTypewriter.ttf", 20);
	index = 0;
}

intObject::intObject(int object_x, int object_y)
{
	this->object_x = object_x;
	this->object_y = object_y;

	object_state = STATE_NORMAL;

	/*Inicialização dos dialogos*/
	dialogFlag = false;
	myfont.loadFont("TravelingTypewriter.ttf", 20);
	index = 0;
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
	//objeto foi clicado
	if (x >= object_x && x <= (object_x + object_w) && y >= object_y && y <= (object_y + object_h))
	{
		if (object_state == STATE_NORMAL) //objeto nao estava ativo
		{
			object_state = STATE_PRESSED;
			dialogFlag = true;
		}
		else //objeto estava ativo
		{
			object_state = STATE_NORMAL;
			dialogFlag = false;
			addIndex();
		}
	}
}

void intObject::drawZoom()
{
	if (object_state == STATE_NORMAL)
		ofDrawRectangle(object_x, object_y, object_w, object_h);
	else 
		ofDrawRectangle(object_x, object_y, object_w + 100, object_h + 100);
}

void intObject::draw()
{
	/*Desenha o objeto*/
	ofSetColor(255,255,255);
	ofDrawRectangle(object_x, object_y, object_w, object_h);

	/*Condiçoes de dialogo*/
	if (object_state == STATE_PRESSED && dialogFlag == true)
	{
		drawDBox();
		displayDialog();
	}
}

/*---getters---*/
int intObject::getX()
{
	return object_x;
}
int intObject::getY()
{
	return object_y;
}

/*-----------------------------------------*/
/*Dialogo*/

/*Desenha o HUD*/
void intObject::drawDBox()
{
	//Cor e desenho da caixa de dialogo
	ofSetColor(0, 0, 0);
	ofDrawRectRounded(10, 600, 1000, 70, 5);
}

/*Vai dar display do text. i é o indice da lista de dialogos e list eh o vetor de dialogos*/
void intObject::displayDialog()
{
	//Cor e desenho do texto
	ofSetColor(255, 255, 255);
	myfont.drawString(dialogueList[index], 200, 640);
}

void intObject::pushDialog(std::string s)
{
	dialogueList.push_back(s);
}

void intObject::addIndex()
{
	if (index < (dialogueList.size() - 1))
		index++;
	else
		return;
}

int intObject::getIndex()
{
	return index;
}