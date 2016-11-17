#pragma once
#include "ofMain.h"
#include "Button.h"

#define GAME_SIDE_HIS 0 //tela preta de texto
#define GAME_SIDE_A 1
#define GAME_SIDE_B 2
#define GAME_MENU 0
#define GAME_PLAY 1
#define GAME_WIN 2
#define GAME_OVER 3
#define GAME_RESET 4
#define ON true
#define OFF false

class GameManager
{
public:
	int gameState; // Qual cena esta
	int gameSide;
	int m_day;
	bool mousePressed;
	bool dialogueActive;

	ofImage m_mouse;

	GameManager(int gs);
	~GameManager();

	void update();
	void draw();
};

