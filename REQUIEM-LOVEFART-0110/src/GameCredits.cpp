#include "GameCredits.h"

GameCredits::GameCredits()
{
	m_background.loadImage("images/creditsBackground.png");
	Reset();
}

GameCredits::~GameCredits()
{
}

void GameCredits::Reset()
{
	btnBack = new Button(512, 700, 100, 50, true, OFF, "images/btnBack.png"); //definindo posição do botão back
}

void GameCredits::Update(GameManager * game)
{
	if (btnBack->mouseOver())
		if (game->mousePressed)
			game->gameState = GAME_MENU;
}

void GameCredits::Draw(GameManager * game)
{
	m_background.draw(0, 0);
	btnBack->drawImage();
}
