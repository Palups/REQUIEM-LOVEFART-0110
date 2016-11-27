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
	m_snd_menu.play(); //dá play na música do menu
	btnPlay = new Button(512, 700, 113, 50, true, OFF, "images/menuBtnPlay.png"); //definindo posição do botão play
	btnCredits = new Button(800, 700, 182, 50, true, OFF, "images/menuBtnCredits.png"); //definindo posição do botão dos créditos
}

void GameMenu::update(GameManager *game)
{
	if (btnPlay->mouseOver())
		if (game->mousePressed){
			m_snd_menu.stop();
			game->gameState = GAME_PLAY;
		}

	if (btnCredits->mouseOver())
		if (game->mousePressed){
			m_snd_menu.stop();
			game->gameState = GAME_CREDITS;
		}
}

void GameMenu::draw(GameManager *game)
{
	m_bg.draw(0, 0);
	btnPlay->drawImage();
	btnCredits->drawImage();
}
