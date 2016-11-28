#include<iostream>
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofHideCursor();

	gameManager = new GameManager(GAME_MENU); //Define o estado de jogo que começa
	gameMenu = new GameMenu(gameManager);
	gamePlay = new GamePlay(gameManager);
	gameCredits = new GameCredits();
}

//--------------------------------------------------------------
void ofApp::update() {
	switch (gameManager->gameState){
	case GAME_MENU:
		gameMenu->update(gameManager);
		break;
	case GAME_CREDITS:
		gameCredits->Update(gameManager);
		break;
	case GAME_PLAY:
		gamePlay->update(gameManager);
		break;
	/*case GAME_WIN:
		break;
	case GAME_OVER:
		break;*/
	case GAME_RESET:
		gameMenu->reset();
		gamePlay->reset(gameManager);
		gameManager->gameState = GAME_MENU;
		break;
	default:
		break;
	}

	/*Se passou por todos os updates e ninguem usou o clique do mouse, anula o BOOL para simular um clique  ao inves de deixar ligado,
	pois seria um "SEGURANDO BOTAO DO MOUSE"*/
	gameManager->mousePressed = false;
}

//--------------------------------------------------------------
void ofApp::draw() {
	switch (gameManager->gameState){
	case GAME_MENU:
		gameMenu->draw(gameManager);
		break;
	case GAME_CREDITS:
		gameCredits->Draw(gameManager);
		break;
	case GAME_PLAY:
		gamePlay->draw(gameManager);
		break;
	/*case GAME_WIN:
		gameWin->draw();
		break;
	case GAME_OVER:
		gameOver->draw();
		break;*/
	default:
		break;
	}

	gameManager->draw(); //desenha o cursor do mouse
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
	gameManager->mousePressed = true;  //checar se mouse foi pressionado
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	switch (gameManager->gameState)
	{
	case GAME_PLAY:
		gamePlay->MousePressed(x, y, button, gameManager);
	}
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
