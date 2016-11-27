#pragma once

#include "ofMain.h"
#include "GameManager.h"
#include "Button.h"

class GameMenu
{
public:
	/*-- variáveis --*/
	Button *btnPlay; //botão play
	Button *btnCredits; //botão créditos

	ofImage m_bg; //imagem de background


	/*-- métodos --*/
	GameMenu(GameManager *game);
	~GameMenu();

	void reset();
	void update(GameManager *game);
	void draw(GameManager *game);
};

