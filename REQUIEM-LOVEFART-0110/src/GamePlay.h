#pragma once
#include "ofMain.h"
#include "GameManager.h"
#include "Button.h"

class GamePlay
{
public:
	ofImage wall1;
	ofImage wall2;

	Button *bed;
	Button *note;
	Button *toilet;
	Button *door;
	Button *changeSide;

	GamePlay(GameManager *game);
	~GamePlay();

	void update(GameManager *game);
	void draw(GameManager *game);
	void reset(GameManager *game);
};