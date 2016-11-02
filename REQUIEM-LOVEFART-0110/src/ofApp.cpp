#include "ofApp.h"
#include "intObject.h"
#include "Button.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup() {
	menuBackground.load("images/menuBackground.png");
	menuLogo.load("images/menuLogo.png");
	wall1.load("images/wall1.png");
	wall2.load("images/wall2.png");

	/*----------------------------------------------------------------------------*/
	//botão play do menu
	btnPlay = new Button(487, 650, 50, 50, "images/menuBtnPlay.png");

	//botão de trocar de tela
	btnChangeWall = new Button(487, 650, 50, 50, "images/btnChangeWall.png");
	/*----------------------------------------------------------------------------*/
	
	bed = new intObject(75, 550);
	bed->setSize(465, 100);
	door = new intObject(710, 292);
	door->setSize(213, 385);
	duct = new intObject(196, 144);
	duct->setSize(202, 111);
	toilet = new intObject(580, 546);
	toilet->setSize(135, 145);
	note = new intObject(187, 331);
	note->setSize(49, 57);
	calendar = new intObject(726, 152);
	calendar->setSize(125, 220);

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
		//ofSetColor(255, 255, 255, 0); // descomente isso para deixar invisivel
		bed->draw();
		door->draw();
		duct->draw();
		ofSetColor(255, 255, 255, 255);
		btnChangeWall->Desenhar();
		

		if (leg.ativo)
		{
			leg.sprite.draw(leg.posx, leg.posy);
			mudaLeg(leg.numLeg, leg.qualLeg);
		}
		break;

	case GAME_PLAY_SIDE_B:
		wall2.draw(0, 0);
		//ofSetColor(255, 255, 255, 0); //descomente para deixar invisivel
		toilet->draw();
		calendar->draw();
		note->draw();
		ofSetColor(255, 255, 255, 255);
		btnChangeWall->Desenhar();

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
	std::cout << "posicao " << x << " " << y << std::endl;
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

		bed->pressed(x, y);
		if (bed->getDialog())
		{
			leg.ativo = true;
			leg.qualLeg = 1;
			//leg.numLeg = 1;
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

		door->pressed(x, y);
		if (door->getDialog())
		{
			leg.ativo = true;
			leg.qualLeg = 2;
			//leg.numLeg = 1;
		}
		else
			leg.ativo = false;

		if (leg.ativo)
		{
			if (x >= 0 && x <= ofGetWindowWidth() && y <= 768 && y >= 658)
			{
				leg.numLeg++;
			}
		}

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
