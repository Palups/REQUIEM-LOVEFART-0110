#include "ofApp.h"
#include "intObject.h"

bool click = false;  // Booleana para avaliar condição no sistema de troca da imagem dos lados.

					 //--------------------------------------------------------------
void ofApp::setup() {
	lado1.sprite.loadImage("images/lado1.png");  // Inicializando imagem do lado 1.
	lado2.sprite.loadImage("images/lado2.png");  // Inicializando imagem do lado 2.
	botao.sprite.loadImage("images/botao.png");  // Inicializando imagem para o botão que troca as imagens dos lados.
	logo.sprite.loadImage("images/logo.png"); //logo do menu
	bplay.sprite.loadImage("images/bplay.png"); // botão play
	logo.tamX = 924; //largura da logo 
	logo.tamY = 428; // altura da logo
	bplay.tamX = 192; // largura botão
	bplay.tamY = 91; // altura botão
	logo.x = ofGetWindowWidth() / 2 - logo.tamX / 2; // calculo do centro em x
	logo.y = ofGetWindowHeight() / 2 - logo.tamY / 2; // calculo do centro em y
	bplay.centrox = ofGetWindowWidth() / 2 - bplay.tamX / 2; // centro x botão
	bplay.centroy = (ofGetWindowHeight() / 2 - bplay.tamY / 2) + (logo.tamY / 2 + 50); // centro y botão
	bplay.x = ofGetWindowWidth() / 2 - bplay.tamX / 2; // rever 
	bplay.y = bplay.centroy;//ofGetWindowHeight() / 2 - bplay.tamY / 2; rever
	light = 0; // setando light para 0 para o fundo ser preto
}

//--------------------------------------------------------------
void ofApp::update() {
	if (estadoJogo == MENU)
	{
		if (click) // ao clicar
		{
			light += 2; // fundo esbranquece aos poucos
			if (light >= 255) // qnd branco muda para o gameplay
			{
				estadoJogo = GAMEPLAY;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (estadoJogo == MENU) // desenha a logo e define a cor do fundo do menu
	{
		ofBackground(light, light, light);
		logo.sprite.draw(logo.x, logo.y);
		bplay.sprite.draw(bplay.centrox, bplay.centroy);

	}
	else
		if (estadoJogo == GAMEPLAY) // muda para o gameplay
		{
			// Se click for verdadeiro, desenha a imagem do lado 1. Se for falso, desenha a imagem do lado 2.
			if (click)
				lado1.sprite.draw(0, 0);
			else
				lado2.sprite.draw(0, 0);

			botao.sprite.draw(487, 700);  // Desenha o botão que troca as imagens dos lados.
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
	else if (estadoJogo == GAMEPLAY) // mudança de tela no gameplay
	{
		// Se as coordenadas X e Y do mouse estiverem entre as descritas abaixo, click é alterado e troca a imagem entre lado 1 e 2.
		if (x > 487 && x < 537 && y > 700 && y < 750)
			click = !click;
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
