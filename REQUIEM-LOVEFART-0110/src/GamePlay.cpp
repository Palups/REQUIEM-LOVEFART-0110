#include "GamePlay.h"

GamePlay::GamePlay(GameManager *game)
{
	wall1.loadImage("images/wall1.png"); //carrega imagem que contém a cama, porta e duto de ar
	wall2.loadImage("images/wall2.png"); //carrega imagem que contém vaso sanitário
	m_noteText.loadImage("images/noteText.png"); //carrega imagem do texto do bilhete

	reset(game);
}

GamePlay::~GamePlay()
{
}

void GamePlay::reset(GameManager *game)
{
	game->m_snd_gameplay.setLoop(true); //tocar música do gameplay em loop

	m_showingNote = false;

	//alocação e inicialização das variáveis
	bed = new Button(75 + (465 / 2), 550 + (100 / 2), 465, 100, true, OFF);
	note = new Button(187 + (84 / 2), 331 + (147 / 2), 84, 147, true, OFF, "images/Cenario2_bilhete.png");
	door = new Button(710 + (213 / 2), 292 + (385 / 2), 213, 385, true, OFF);
	toilet = new Button(580 + (135 / 2), 546 + (145 / 2), 135, 145, true, OFF);
	changeSide = new Button(990, 730, 100, 100, true, OFF, "images/btnChangeWall.png");

	/*-- Dialogo --*/
	/*door->pushDialogue("fuck");
	bed->pushDialogue("me");
	note->pushDialogue("in the");
	toilet->pushDialogue("ass");*/
}

void GamePlay::update(GameManager *game)
{
	///*-- Dialogo --*/
	//if (game->mousePressed)
	//{
	//	if (game->dialogueActive == OFF) // Caixa de dialogo está ativa. Desativa ela quando clicar em qualquer lugar
	//	{
	//		game->dialogueActive = ON;
	//		door->disableDialogue();
	//		bed->disableDialogue();
	//		toilet->disableDialogue();
	//		note->disableDialogue();
	//	}
	//}


	/*-- switch case para cada dia de gameplay --*/
	switch (game->m_day) {
	case 1:
		/*-- switch case para cada lado da sala, no primeiro dia --*/
		switch (game->gameSide) {
		case GAME_SIDE_HIS:
			//incluir tela preta e texto de introdução
			break;

		case GAME_SIDE_A:
			//cama e porta
			if (changeSide->mouseOver())
				if (game->mousePressed)
					game->gameSide = GAME_SIDE_B;

			if (door->mouseOver())
				if (game->mousePressed) {
					door->m_estado = true;
					std::cout << "cricou na porta porra" << std::endl;
					//game->dialogueActive = ON;
					//door->enableDialogue();
				}

			if (bed->mouseOver())
				if (door->m_estado && note->m_estado && game->mousePressed) {
					bed->m_estado = true;
					std::cout << "cricou na cama porra" << std::endl;
					//game->dialogueActive = ON;
					//door->enableDialogue();
				}

			if (bed->m_estado)
				game->m_day += 1;

			break;

		case GAME_SIDE_B:
			//se clicar no bilhete na parede, aparece a imagem dele maior. se clicar de novo, a imagem some
			if (!m_showingNote) {
				if (game->mousePressed && note->mouseOver()) {
					m_showingNote = true;
				}
			}
			else {
				if (game->mousePressed)
					m_showingNote = false;
			}

			//bilhete e privada
			if (changeSide->mouseOver())
				if (game->mousePressed)
					game->gameSide = GAME_SIDE_A;

			if (note->mouseOver())
				if (door->m_estado && game->mousePressed) {
					note->m_estado = true;
					std::cout << "cricou no papel porra" << std::endl;
					//game->dialogueActive = ON;
					//door->enableDialogue();
				}
			break;

		default:
			break;
		}
		break;
		
	case 2:
		std::exit(0);
		//switch (game->gameSide)
			//{
			//case GAME_SIDE_HIS:
			//	//incluir tela preta e texto de introdução
			//	break;
			//case GAME_SIDE_A:
			//	break;
			//case GAME_SIDE_B:
			//	break;
			//default:
			//	break;
			//}
		break;

	default:
		break;
	}
}

void GamePlay::draw(GameManager *game)
{
	/*if (game->dialogueActive == ON)
	{
		if (door->dialogActive())
			door->displayDialogue();
		else if (bed->dialogActive())
			bed->displayDialogue();
		else if (note->dialogActive())
			note->displayDialogue();
		else if (toilet->dialogActive())
			toilet->displayDialogue();
	}*/


	/*-- switch case para cada dia de gameplay --*/
	switch (game->m_day){
	case 1:
		/*-- switch case para cada lado da sala, no primeiro dia --*/
		switch (game->gameSide){
		case GAME_SIDE_A:
			wall1.draw(0, 0);
			bed->draw();
			door->draw();
			changeSide->drawImage();
			break;
		case GAME_SIDE_B:
			wall2.draw(0, 0);
			toilet->draw();
			note->drawImage();
			changeSide->drawImage();
			if (m_showingNote == true)
				m_noteText.draw(0, 0);
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (game->gameSide){
		case GAME_SIDE_A:
			wall1.draw(0, 0);
			break;
		case GAME_SIDE_B:
			wall2.draw(0, 0);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}


