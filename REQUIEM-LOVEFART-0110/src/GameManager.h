#pragma once
#include "ofMain.h"
#include "Button.h"

#define GAME_MENU 0
#define GAME_PLAY 1
#define GAME_WIN 2
#define GAME_OVER 3
#define GAME_RESET 4
#define GAME_CREDITS 5

#define GAME_SIDE_TRANS 6 //tela de auxílio - introdução, mensagens dei início, etc
#define GAME_SIDE_A 7 
#define GAME_SIDE_B 8

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

#define ON true
#define OFF false

class GameManager
{
public:
	/*-- variáveis --*/
	int gameState; //mostra qual o estado do jogo
	int gameSide; //mostra qual lado da sala
	int m_day; //dia que o gameplay se situa
 
	bool mousePressed; //verificar se mouse está pressionado ou não
	//bool dialogueActive;

	ofImage m_mouse; //skin do mouse

	ofSoundPlayer m_snd_menu; //música do menu
	ofSoundPlayer m_snd_gameplay; //música do gameplay
	ofSoundPlayer m_snd_door; //efeito sonoro ao bater na porta


	/*-- métodos --*/
	GameManager(int gs);
	~GameManager();

	void update();
	void draw();
};

