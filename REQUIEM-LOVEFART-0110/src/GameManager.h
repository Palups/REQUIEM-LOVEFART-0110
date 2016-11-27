#pragma once
#include "ofMain.h"
#include "Button.h"

#define GAME_SIDE_HIS 0 //tela de aux�lio - introdu��o, mensagens dei in�cio, etc
#define GAME_SIDE_A 1 
#define GAME_SIDE_B 2
#define GAME_MENU 0
#define GAME_PLAY 1
#define GAME_WIN 2
#define GAME_OVER 3
#define GAME_RESET 4
#define GAME_CREDITS 5

#define ON true
#define OFF false

class GameManager
{
public:
	/*--vari�veis--*/
	int gameState; //mostra qual o estado do jogo
	int gameSide; //mostra qual lado da sala
	int m_day; //dia

	bool mousePressed; //verificar se mouse est� pressionado ou n�o
	//bool dialogueActive; 

	ofImage m_mouse; //skin do mouse


	/*--m�todos--*/
	GameManager(int gs);
	~GameManager();

	void update();
	void draw();
};

