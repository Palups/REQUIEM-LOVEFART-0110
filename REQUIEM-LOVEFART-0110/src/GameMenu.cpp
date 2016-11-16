#include "GameMenu.h"



GameMenu::GameMenu()
{
	m_bg.loadImage("images/menuBackground.png");
	/*---tem que ter a musica antes, né---*/
	//m_snd_menu.loadSound("sounds/menu.mp3");
	reset();
}


GameMenu::~GameMenu()
{
}

void GameMenu::update(GameManager *game)
{
	if (btnPlay->mouseOver())
	{
		if (game->mousePressed)
		{
			m_snd_menu.stop();
			game->gameState = GAME_PLAY;
		}
	}
	
	/*if (btnExit->mouseOver())
	{
		if (game->mousePressed)
		{
			std::exit(0);
		}
	}*/
	
}

void GameMenu::draw(GameManager * game)
{
	m_bg.draw(0, 0);
	btnPlay->draw();
	//btnExit->draw();
}

void GameMenu::reset()
{
	//ofSoundStopAll(); 
	/*---definir as posições---*/
	btnPlay = new Button(512, 700, 100, 50, true);
	//btnCredits = new Button(1105, 480, 333, 50, false);
	//btnExit = new Button(1105, 560, 333, 50, false, "images/menuBtnExit.png");

	//m_snd_menu.setLoop(true);
	//m_snd_menu.play();

}
