#include "GameManager.h"

GameManager::GameManager(int gs)
{
	gameState = gs;
	m_day = 1;
	gameSide = GAME_SIDE_TRANS;
	m_mouse.loadImage("images/cursor.png");
	//dialogueActive = OFF;
}

GameManager::~GameManager()
{
}

void GameManager::update()
{
}

void GameManager::draw()
{
	m_mouse.draw(ofGetMouseX(), ofGetMouseY());
}
