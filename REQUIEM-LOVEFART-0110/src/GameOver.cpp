#include "GameOver.h"

GameOver::GameOver()
{
	m_background.loadImage("images/gameover.png");
	m_fimdodia.loadImage("images/fim_dia1.png");
	Reset();
}

GameOver::~GameOver()
{
}

void GameOver::Reset()
{
}

void GameOver::Update(GameManager * game)
{
	if (game->mousePressed)
		game->gameState = GAME_MENU;
}

void GameOver::Draw(GameManager * game)
{
	if (game->m_day > 1)
	{
		m_fimdodia.draw(0, 0);
	}

	else
	{
		m_background.draw(0, 0);
	}
}
