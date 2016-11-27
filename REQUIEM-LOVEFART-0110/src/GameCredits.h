#pragma once

#include "ofMain.h"
#include "GameManager.h"
#include "Button.h"

class GameCredits
{
public:
	/*-- vari�veis --*/
	Button *btnBack; //bot�o back

	ofImage m_background; //imagem de background


	/*-- m�todos --*/
	GameCredits();
	~GameCredits();

	void Reset();
	void Update(GameManager *game);
	void Draw(GameManager *game);
};

