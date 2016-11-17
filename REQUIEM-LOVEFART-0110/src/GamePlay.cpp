#include "GamePlay.h"

GamePlay::GamePlay(GameManager *game)
{
	//load das imagens. sons e etc
	wall1.load("images/wall1.png");
	wall2.load("images/wall2.png");

	reset(game);
}

GamePlay::~GamePlay()
{
}

void GamePlay::update(GameManager * game)
{
	switch (game->m_day)
	{
	case 1:
		switch (game->gameSide)
		{
		case GAME_SIDE_HIS:
			//incluir tela preta e texto de introdução
			break;
		case GAME_SIDE_A:
			//cama e porta
			if (changeSide->mouseOver())
			{
				if (game->mousePressed)
				{
					game->gameSide = GAME_SIDE_B;
				}
			}
			if (door->mouseOver())
			{
				if (game->mousePressed)
				{
					door->m_estado = true;
				}
			}
			if (bed->mouseOver())
			{
				if (door->m_estado && 
					note->m_estado && 
					game->mousePressed)
				{
					bed->m_estado = true;
				}
			}
			if (bed->m_estado)
				game->m_day += 1;
			break;
		case GAME_SIDE_B:
			//bilhete e privada
			if (changeSide->mouseOver())
			{
				if (game->mousePressed)
				{
					game->gameSide = GAME_SIDE_A;
				}
			}
			if (note->mouseOver())
			{
				if (door->m_estado && game->mousePressed)
				{
					note->m_estado = true;
				}
			}
			break;
		default:
			break;
		}
		break;
	case 2:
		std::exit(0);
		switch (game->gameSide)
		{
		case GAME_SIDE_HIS:
			//incluir tela preta e texto de introdução
			break;
		case GAME_SIDE_A:
			break;
		case GAME_SIDE_B:
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void GamePlay::draw(GameManager * game)
{
	switch (game->m_day)
	{
	case 1:
		switch (game->gameSide)
		{
		case GAME_SIDE_A:
			wall1.draw(0, 0);
			bed->draw();
			door->draw();
			changeSide->drawImage();
			break;
		case GAME_SIDE_B:
			wall2.draw(0, 0);
			toilet->draw();
			note->draw();
			changeSide->drawImage();
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (game->gameSide)
		{
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

void GamePlay::reset(GameManager * game)
{
	//aloca e inicializa variaveis
	bed = new Button(75 + (465 / 2), 550 + (100 / 2), 465, 100, true, OFF);
	note = new Button(187 + (49 / 2), 331 + (57 / 2), 49, 57, true, OFF);
	door = new Button(710 + (213 / 2), 292 + (385 / 2), 213, 385, true, OFF);
	toilet = new Button(580 + (135 / 2), 546 + (145 / 2), 135, 145, true, OFF);
	changeSide = new Button(990, 730, 100, 100, true, OFF, "images/btnChangeWall.png");
}


