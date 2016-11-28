#pragma once

#include "ofMain.h"
#include "GameManager.h"

class GameOver
{
private:
	ofImage m_background;
public:
	GameOver();
	~GameOver();

	void Reset();
	void Update(GameManager *game);
	void Draw(GameManager *game);
};

