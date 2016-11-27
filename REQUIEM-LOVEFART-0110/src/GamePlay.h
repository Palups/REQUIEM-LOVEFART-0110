#pragma once
#include "ofMain.h"
#include "GameManager.h"
#include "Button.h"

class GamePlay
{
public:
	/*-- variáveis --*/
	ofImage wall1;  //imagem que contém a cama, porta e duto de ar
	ofImage wall2;  //imagem que contém vaso sanitário
	ofImage m_noteText; //imagem com texto do bilhete

	Button *bed;  //cama
	Button *note;  //bilhete
	Button *toilet;  //vaso sanitário
	Button *door;  //porta
	Button *changeSide;  //botão que troca as cenas

	bool m_showingNote; //mostrando texto do bilhete

	/*-- métodos --*/
	GamePlay(GameManager *game);
	~GamePlay();

	void reset(GameManager *game);
	void update(GameManager *game);
	void draw(GameManager *game);
};