#pragma once
#include "ofMain.h"
#include "GameManager.h"
#include "Button.h"

class GameMenu
{
public:
	Button *btnPlay;
	Button *btnExit;

	ofImage m_bg;
	ofImage m_logo;

	ofSoundPlayer m_snd_menu;

	GameMenu();
	~GameMenu();

	void update(GameManager *game);
	void draw(GameManager *game);
	void reset();
};

