#include "GameMenu.h"
#include "GameManager.h"

GameMenu::GameMenu(GameManager *game)
{
	m_bg.loadImage("images/menuBackground.png"); //carrega background do menu

	game->m_snd_menu.loadSound("sounds/soundtrack_menu.mp3"); //carrega m�sica do menu
	game->m_snd_menu.play(); //d� play na m�sica do menu
	game->m_snd_gameplay.loadSound("sounds/soundtrack_gameplay.mp3"); //carrega m�sica do gameplay

	reset();
}

GameMenu::~GameMenu()
{
}

void GameMenu::reset()
{
	btnPlay = new Button(512, 675, 113, 50, true, OFF, "images/menuBtnPlay.png"); //definindo posi��o do bot�o play
	btnCredits = new Button(512, 730, 150, 50, true, OFF, "images/menuBtnCredits.png"); //definindo posi��o do bot�o dos cr�ditos
	ofSoundStopAll();
}

void GameMenu::update(GameManager *game)
{
	//se bot�o play for clicado, som do menu para, som do gameplay come�a, jogo vai para o gameplay
	if (btnPlay->mouseOver()) 
		if (game->mousePressed){
			game->m_snd_menu.stop();
			game->m_snd_gameplay.play();
			game->gameState = GAME_PLAY;
		}

	//se bot�o credits for clicado, o jogo vai para a tela de cr�ditos
	if (btnCredits->mouseOver())
		if (game->mousePressed)
			game->gameState = GAME_CREDITS;
}

void GameMenu::draw(GameManager *game)
{
	m_bg.draw(0, 0);
	btnPlay->drawImage();
	btnCredits->drawImage();
}
