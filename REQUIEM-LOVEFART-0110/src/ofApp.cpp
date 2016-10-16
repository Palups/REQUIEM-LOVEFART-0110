#include "ofApp.h"
#include "intObject.h"
#include "Button.h"

//--------------------------------------------------------------
void ofApp::setup() {
	menuBackground.load("images/menuBackground.png");
	menuLogo.load("images/menuLogo.png");
	wall1.load("images/wall1.jpg");
	wall2.load("images/wall2.jpg");

	/*----------------------------------------------------------------------------*/
	//botão play do menu
	btnPlay = new Button(487, 650, 50, 50, "images/menuBtnPlay.png");

	//botão de trocar de tela
	btnChangeWall = new Button(487, 650, 50, 50, "images/btnChangeWall.png");
	/*----------------------------------------------------------------------------*/

	bilhete.setPosition(200, 300);
	bilhete.setSize(20, 20);
	porta.setPosition(750, 400);
	porta.setSize(83, 250);

	//legendas provisorias
	leg.posx = 0;
	leg.posy = 658;
	leg.sprite.loadImage("images/barraleg.png");
	leg.numLeg = 1;
}

//--------------------------------------------------------------
void ofApp::update() {
	switch (game_state) {
	case GAME_MENU:
		break;

	case GAME_PLAY_SIDE_A:
		break;

	case GAME_PLAY_SIDE_B:
		break;

	case GAME_OVER:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	switch (game_state) {
	case GAME_MENU:
		menuBackground.draw(0, 0);
		menuLogo.draw(262, 165);
		btnPlay->Desenhar();
		break;

	case GAME_PLAY_SIDE_A:
		wall1.draw(0, 0);
		btnChangeWall->Desenhar();

		bilhete.draw();

		if (leg.ativo)
		{
			leg.sprite.draw(leg.posx, leg.posy);
			mudaLeg(leg.numLeg, leg.qualLeg);
		}
		break;

	case GAME_PLAY_SIDE_B:
		wall2.draw(0, 0);
		btnChangeWall->Desenhar();

		porta.draw();
		break;

	case GAME_OVER:
		break;
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
	switch (game_state) {
	case GAME_MENU:
		if (x > 487 && x < 537 && y > 650 && y < 700)
			game_state = GAME_PLAY_SIDE_A;
		break;

	case GAME_PLAY_SIDE_A:
		if (x > 487 && x < 537 && y > 650 && y < 700)
			game_state = GAME_PLAY_SIDE_B;

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
		break;

	case GAME_PLAY_SIDE_B:
		if (x > 487 && x < 537 && y > 650 && y < 700)
			game_state = GAME_PLAY_SIDE_A;

		porta.pressed(x, y);
		if (porta.getDialog())
		{
			leg.ativo = true;
			leg.qualLeg = 2;
			leg.numLeg = 1;
		}
		else
			leg.ativo = false;
		break;

	case GAME_OVER:
		break;
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
