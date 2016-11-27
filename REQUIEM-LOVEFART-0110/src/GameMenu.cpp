#include "GameMenu.h"
#include "GameManager.h"

GameMenu::GameMenu()
{
	m_bg.loadImage("images/menuBackground.png");
	m_snd_menu.loadSound("sounds/soundtrack_menu.mp3");
	reset();
}

GameMenu::~GameMenu()
{
}

void GameMenu::reset()
{
	m_snd_menu.play(); //d� play na m�sica do menu
	btnPlay = new Button(512, 700, 100, 50, true, OFF, "images/menuBtnPlay.png"); //definindo posi��o do bot�o play
}

void GameMenu::update(GameManager *game)
{
	if (btnPlay->mouseOver())
	{
		if (game->mousePressed)
		{
			m_snd_menu.stop();
			game->gameState = GAME_PLAY;
		}
	}	
}

void GameMenu::draw(GameManager * game)
{
	m_bg.draw(0, 0);
	btnPlay->drawImage();
}
