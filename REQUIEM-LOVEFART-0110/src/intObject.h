#pragma once
#include "ofMain.h"

class intObject
{
public:
	/*STATE_PRESSED = objeto foi clicado, STATE_NORMAL = objeto nao esta pressionado*/
	enum OBJECT_STATE
	{
		STATE_PRESSED,
		STATE_NORMAL
	};

	//Construtor
	intObject();

	//Funcao para checar se foi pressionado o objeto
	void intObject::pressed(int x, int y);

	//Funcao para alterar a posicao do objeto
	void setPosition(int x, int y);

	// Funcao para alterar o tamanho
	void setSize(int w, int h);

	//Testa se o objeto/botao foi solto
	void released(int x, int y);

	//Funcao que vai ser colocada no draw do ofApp
	void draw();

	//Funcao que vai ser colocada no update do ofApp
	void update();

private:

	int object_x, object_y; //Coordenadas do objeto	
	int object_w, object_h; //Largura (width) e altura (height) do objeto

	OBJECT_STATE object_state; //Um boolean para o estado do objeto
	bool display_dialog;
};

