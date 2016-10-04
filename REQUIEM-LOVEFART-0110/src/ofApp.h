#pragma once

#include "ofMain.h"
#include "intObject.h"

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

	//variaveis que controlam o estado do jogo
	const int MENU = 0;
	const int GAMEPLAY = 1;
	const int GAMEOVER = 2;
	int estadoJogo = MENU; //seta o estado inicial pra MENU
	struct image //struct para as imagens
	{
		int centrox, centroy, x, y; //posições
		ofImage sprite; //variavel para carregar as imagens
		int tamX, tamY; //tamanho das imagens(pra pode posicionar de acordo na tela)
	};
	image lado1;  // Variável para a imagem do lado 1.
	image lado2;  // Variável para a imagem do lado 2.
	image botao;  // Variável para a imagem do botão que troca as imagens dos lados.
	image logo;   //variavel para a logo
	image bplay; // variavel para o botão de inicio
	int light; //variavel para cor do background
	int opacity;

	intObject bilhete;
	intObject cama;

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
				ofDrawBitmapString("Abigail: Nossa como o Maycow manja!!!", leg.posx + 10, leg.posy + 10);
				break;
			case 2:
				ofDrawBitmapString("Abigail: Nossa como a Mylla manja!!!", leg.posx + 10, leg.posy + 10);
				break;
			case 3:
				ofDrawBitmapString("Abigail: Nossa como o Palu ta cagando!!!", leg.posx + 10, leg.posy + 10);
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
				leg.qualLeg = 0;
				break;
			}
			break;
		case 3:
			switch (x)
			{
			case 1:
				ofDrawBitmapString("Essa cama parece confortavel", leg.posx + 10, leg.posy + 10);
				break;
			default:
				leg.ativo = false;
				leg.numLeg = 1;
				break;
			}
		default:

			break;
		}

	}
};
