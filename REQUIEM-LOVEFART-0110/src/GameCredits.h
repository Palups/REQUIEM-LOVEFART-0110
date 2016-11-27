#pragma once

#include "ofMain.h"
#include "GameManager.h"
#include "Button.h"

class GameCredits
{
public:
	/*-- variáveis --*/
	Button *btnBack; //botão back

	ofImage m_background; //imagem de background


	/*-- métodos --*/
	GameCredits();
	~GameCredits();

	void Reset();
	void Update(GameManager *game);
	void Draw(GameManager *game);
};

