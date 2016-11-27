#pragma once
#include "ofMain.h"
#include "GameManager.h"
#include "Button.h"

class GamePlay
{
public:
	/*-- vari�veis --*/
	ofImage wall1;  //imagem que cont�m a cama, porta e duto de ar
	ofImage wall2;  //imagem que cont�m vaso sanit�rio
	ofImage m_noteText; //imagem com texto do bilhete

	Button *bed;  //cama
	Button *note;  //bilhete
	Button *toilet;  //vaso sanit�rio
	Button *door;  //porta
	Button *changeSide;  //bot�o que troca as cenas

	bool m_showingNote; //mostrando texto do bilhete

	/*-- m�todos --*/
	GamePlay(GameManager *game);
	~GamePlay();

	void reset(GameManager *game);
	void update(GameManager *game);
	void draw(GameManager *game);
};