#pragma once

#include "ofMain.h"
#include "GameManager.h"
#include "Button.h"

class GameMenu
{
public:
	/*--vari�veis--*/
	Button *btnPlay; //bot�o play
	Button *btnCredits; //bot�o cr�ditos

	ofImage m_bg; //imagem de background

	ofSoundPlayer m_snd_menu; //musica do menu


	/*--m�todos--*/
	GameMenu();
	~GameMenu();

	void reset();
	void update(GameManager *game);
	void draw(GameManager *game);
};

