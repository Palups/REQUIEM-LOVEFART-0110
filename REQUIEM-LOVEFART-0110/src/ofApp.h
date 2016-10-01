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
};
