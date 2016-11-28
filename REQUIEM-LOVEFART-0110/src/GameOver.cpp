#include "GameOver.h"

GameOver::GameOver()
{
	m_background.loadImage("images/gameover.png");
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
}

void GameOver::Draw(GameManager * game)
{
	m_background.draw(0, 0);
}
