#pragma once
#include <string>
#include <vector>
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

	//Construtores
	intObject();	
	intObject(int object_x, int object_y);

	//Funcao para checar se foi pressionado o objeto
	void pressed(int x, int y);

	/*Setters*/
	void setPosition(int x, int y);
	void setSize(int w, int h);

	//Funcao que vai ser colocada no draw do ofApp
	void drawZoom();

	//desenha sem a opção de zoom ao clicar
	void draw(int opacity);

	//Funcao que pega a posição X do objeto
	int getX();

	//Funcao que pega a posição Y do objeto
	int getY();

	/*-----Dialogo-----*/

	//Funcao que vai dar o display da caixa de dialogo
	void displayDialog();

	//Adiciona strings no vetor
	void pushDialog(std::string s);

	//Desenha o HUD
	void drawDBox();

	//Index
	int getIndex();
	void addIndex();

private:

	int object_x, object_y; //Coordenadas do objeto	
	int object_w, object_h; //Largura (width) e altura (height) do objeto
	int index; //Indice para navegar nos dialogos
	bool dialogFlag; //Boolean que indica se a caixa de dialogo está aberta

	ofTrueTypeFont myfont; //Fonte
	OBJECT_STATE object_state; //Um boolean para o estado do objeto

	std::vector <std::string> dialogueList; //lista de dialogos
};

