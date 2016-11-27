#include "GameCredits.h"

GameCredits::GameCredits()
{
	m_background.loadImage("images/creditsBackground.png"); //carrega imagem do background
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
	//se botão back for clicado, jogo vai para a tela de menu
	if (btnBack->mouseOver())
		if (game->mousePressed)
			game->gameState = GAME_MENU;
}

void GameCredits::Draw(GameManager * game)
{
	m_background.draw(0, 0);
	btnBack->drawImage();
}
