#pragma once
#include "ofMain.h"
#include "GameManager.h"
#include "Button.h"

class GameMenu
{
public:
	/*--variáveis--*/
	Button *btnPlay; //botão play

	ofImage m_bg; //imagem de background
	ofImage m_logo; //logo do jogo

	ofSoundPlayer m_snd_menu; //musica do menu


	/*--métodos--*/
	GameMenu();
	~GameMenu();

	void reset();
	void update(GameManager *game);
	void draw(GameManager *game);
};

