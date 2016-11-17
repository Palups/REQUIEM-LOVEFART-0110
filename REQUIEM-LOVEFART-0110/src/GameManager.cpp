#include "GameManager.h"


GameManager::GameManager(int gs)
{
	gameState = gs;
	m_day = 1;
	gameSide = GAME_SIDE_A;
	dialogueActive = OFF;
}

GameManager::~GameManager()
{
}

void GameManager::update()
{
}

void GameManager::draw()
{
	/*Tem que ter a imagem do mouse né*/
	//m_mouse.draw(ofGetMouseX(), ofGetMouseY());
}
