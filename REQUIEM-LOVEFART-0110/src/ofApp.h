#pragma once

#include "ofMain.h"
#include "intObject.h"
#include "Button.h"

#define GAME_MENU 0 
#define GAME_PLAY_SIDE_A 1
#define GAME_PLAY_SIDE_B 2
#define GAME_OVER 3

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	/*--------------------------------------------------------*/
	int game_state = GAME_MENU;  //controlar estado do jogo
	/*--------------------------------------------------------*/

	/*-------------------------------*/
	//variáveis para imagens normais
	ofImage menuBackground;
	ofImage menuLogo;
	ofImage wall1;
	ofImage wall2;
	/*-------------------------------*/

	/*-------------------------------*/
	//declaração dos ponteiros de botão
	Button *btnPlay;
	Button *btnChangeWall;
	/*-------------------------------*/


	intObject *bed;
	intObject *door;
	intObject *duct;
	intObject *note;
	intObject *calendar;
	intObject *toilet;
	

	//legendas provisorias
	struct legendas
	{
		int posx, posy; //posição das legendas
		ofImage sprite; //imagem da tarja preta
		bool ativo = false; //verifica se a legenda está na tela
		int numLeg; //controla o texto da legenda
		int qualLeg; //controla qual a legenda do objeto
	};

	legendas leg;

	//função que muda as legendas de acordo com os objetos
	void mudaLeg(int x, int obj) 
	{
		switch (obj)
		{
		case 1:
			switch (x)
			{
			case 1:
				ofDrawBitmapString("Abigail: Essa cama me parece confortavel", leg.posx + 10, leg.posy + 10);
				break;
			case 2:
				ofDrawBitmapString("Abigail: Pena que nao esta liberada para dormir, pq nao fiz o que precisa no jogo hehe", leg.posx + 10, leg.posy + 10);
				break;
			case 3:
				ofDrawBitmapString("Abigail: Nossa como o Palu ta bonito!!!", leg.posx + 10, leg.posy + 10);
				break;
			default:
				leg.ativo = false;
				leg.numLeg = 1;
				break;
			}
			break;
		case 2:
			switch (x)
			{
			case 1:
				ofDrawBitmapString("Abigail: M A L A N D R A M E N T E", leg.posx + 10, leg.posy + 10);
				break;
			case 2:
				ofDrawBitmapString("Abigail: DIDIDIDIÊ", leg.posx + 10, leg.posy + 10);
				break;
			case 3:
				ofDrawBitmapString("Abigail: Não era amor, era cilada", leg.posx + 10, leg.posy + 10);
				break;
			default:
				leg.ativo = false;
				leg.numLeg = 1;
				break;
			}
			break;
		default:

			break;
		}

	}
};
