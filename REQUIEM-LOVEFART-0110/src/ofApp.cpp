#include "ofApp.h"
#include "intObject.h"

bool click = false;  // Booleana para avaliar condi��o no sistema de troca da imagem dos lados.

					 //--------------------------------------------------------------
void ofApp::setup() {
	lado1.sprite.loadImage("images/lado1.png");  // Inicializando imagem do lado 1.
	lado2.sprite.loadImage("images/lado2.png");  // Inicializando imagem do lado 2.
	botao.sprite.loadImage("images/botao.png");  // Inicializando imagem para o bot�o que troca as imagens dos lados.
	logo.sprite.loadImage("images/logo.png"); //logo do menu
	bplay.sprite.loadImage("images/bplay.png"); // bot�o play
	logo.tamX = 924; //largura da logo 
	logo.tamY = 428; // altura da logo
	bplay.tamX = 192; // largura bot�o
	bplay.tamY = 91; // altura bot�o
	logo.x = ofGetWindowWidth() / 2 - logo.tamX / 2; // calculo do centro em x
	logo.y = ofGetWindowHeight() / 2 - logo.tamY / 2; // calculo do centro em y
	bplay.centrox = ofGetWindowWidth() / 2 - bplay.tamX / 2; // centro x bot�o
	bplay.centroy = (ofGetWindowHeight() / 2 - bplay.tamY / 2) + (logo.tamY / 2 + 50); // centro y bot�o
	bplay.x = ofGetWindowWidth() / 2 - bplay.tamX / 2; // rever 
	bplay.y = bplay.centroy;//ofGetWindowHeight() / 2 - bplay.tamY / 2; rever
	light = 255; // setando light para 0 para o fundo ser preto
	opacity = 0;
	bilhete.setPosition(200, 300);
	bilhete.setSize(20, 20);

	//legendas provisorias
	leg.posx = 0;
	leg.posy = 658;
	leg.sprite.loadImage("images/barraleg.png");
	leg.numLeg = 1;
}

//--------------------------------------------------------------
void ofApp::update() {
	if (estadoJogo == MENU)
	{
		if (click) // ao clicar
		{
			light -= 2;
			opacity += 2;// fundo escurece aos poucos
			if (light <=0) // qnd preto muda para o gameplay
			{
				estadoJogo = GAMEPLAY;
			}
		}
	}
	if (estadoJogo == GAMEPLAY)
	{
		
		
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (estadoJogo == MENU) // desenha a logo e define a cor do fundo do menu
	{
		ofBackground(light, light, light);
		ofSetColor(255, 255, 255, opacity);// define a opacidade das imagens
		logo.sprite.draw(logo.x, logo.y);
		ofSetColor(255, 255, 255, 255);
		bplay.sprite.draw(bplay.centrox, bplay.centroy);

	}
	else
		if (estadoJogo == GAMEPLAY) // muda para o gameplay
		{
			// Se click for verdadeiro, desenha a imagem do lado 1. Se for falso, desenha a imagem do lado 2.
			if (click)
			{
				lado1.sprite.draw(0, 0);
				bilhete.draw();
				botao.sprite.draw(487, 700);  // Desenha o bot�o que troca as imagens dos lados.
				if (leg.ativo)
				{
					leg.sprite.draw(leg.posx, leg.posy);
					mudaLeg(leg.numLeg, leg.qualLeg);
				}
				
			}
			else
			{
				lado2.sprite.draw(0, 0);
				botao.sprite.draw(487, 700);  // Desenha o bot�o que troca as imagens dos lados.
			}
			//botao.sprite.draw(487, 700);  // Desenha o bot�o que troca as imagens dos lados.
		}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (estadoJogo == MENU) // ao clicar ative a booleana do menu
	{
		if (x >= bplay.x && x <= (bplay.x + bplay.tamX) && y >= bplay.y &&
			y <= (bplay.y + bplay.tamY) && button == 0) //rever os calculos
			click = true;
	}
	else if (estadoJogo == GAMEPLAY) // mudan�a de tela no gameplay
	{
		// Se as coordenadas X e Y do mouse estiverem entre as descritas abaixo, click � alterado e troca a imagem entre lado 1 e 2.
		if (x > 487 && x < 537 && y > 700 && y < 750 && button == 0)
			click = !click;

		bilhete.pressed(x, y);
		if (bilhete.getDialog())
		{
			leg.ativo = true;
			leg.qualLeg = 1;
			leg.numLeg = 1;
		}
		else
			leg.ativo = false;

		//legendas provisorias
		if (leg.ativo)
		{
			if (x >= 0 && x <= ofGetWindowWidth() && y <= 768 && y >= 658)
			{
				leg.numLeg++;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
