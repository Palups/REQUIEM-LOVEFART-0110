#include "GamePlay.h"

GamePlay::GamePlay(GameManager *game)
{
	wall1.loadImage("images/wall1.png"); //carrega imagem que cont�m a cama, porta e duto de ar
	wall2.loadImage("images/wall2.png"); //carrega imagem que cont�m vaso sanit�rio
	m_noteText.loadImage("images/noteText.png"); //carrega imagem do texto do bilhete

	reset(game);
}

GamePlay::~GamePlay()
{
}

void GamePlay::reset(GameManager *game)
{
	game->m_snd_gameplay.setLoop(true); //tocar m�sica do gameplay em loop

	m_showingNote = false;

	//aloca��o e inicializa��o das vari�veis
	/*bed = new Button(75 + (465 / 2), 550 + (100 / 2), 465, 100, true, OFF);
	note = new Button(187 + (84 / 2), 331 + (147 / 2), 84, 147, true, OFF, "images/Cenario2_bilhete.png");
	door = new Button(710 + (213 / 2), 292 + (385 / 2), 213, 385, true, OFF);
	toilet = new Button(580 + (135 / 2), 546 + (145 / 2), 135, 145, true, OFF);
	changeSide = new Button(990, 730, 100, 100, true, OFF, "images/btnChangeWall.png");*/

	hud = new HUD();
	Bed = new Button(100, 100, 100, 30, BED);
	Door = new Button(100, 300, 100, 50, DOOR);
	Toilet = new Button(100, 500, 100, 20, TOILET);
	Note = new Trigger();
	changeSide = new Button(990, 730, 100, 100, true, OFF, "images/btnChangeWall.png");

	triggerLock = false;
	dialogueActive = false;
	index = 0;
}

void GamePlay::update(GameManager *game)
{
	LockCheck();
	/*-- switch case para cada dia de gameplay --*/
	switch (game->m_day) {
	case 1:
		/*-- switch case para cada lado da sala, no primeiro dia --*/
		switch (game->gameSide) {
		case GAME_SIDE_HIS:
			//incluir tela preta e texto de introdu��o
			break;

		case GAME_SIDE_A:
			/*-- Muda o lado do quarto --*/ //objetos lado A: Cama e porta
			if (changeSide->mouseOver())
				if (game->mousePressed)
					game->gameSide = GAME_SIDE_B;
			break;

		case GAME_SIDE_B:
			//se clicar no bilhete na parede, aparece a imagem dele maior. se clicar de novo, a imagem some
			//ver depois
			if (!m_showingNote) {
				if (Note->MouseOver()) {
					if(game->mousePressed)
						m_showingNote = true;
				}
			}
			else {
				if (game->mousePressed)
					m_showingNote = false;
			}

			/*-- Muda o lado do quarto --*/
			if (changeSide->mouseOver())
				if (game->mousePressed)
					game->gameSide = GAME_SIDE_A;
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
			//	//incluir tela preta e texto de introdu��o
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
	/*-- switch case para cada dia de gameplay --*/
	switch (game->m_day){
	case 1:
		/*-- switch case para cada lado da sala, no primeiro dia --*/
		switch (game->gameSide){
		case GAME_SIDE_A:
			wall1.draw(0, 0);
			Bed->draw();
			Door->draw();
			changeSide->drawImage();
			break;
		case GAME_SIDE_B:
			wall2.draw(0, 0);
			Toilet->draw();
			Note->DrawImage();
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
	if (dialogueActive)
	{
		hud->Draw();
	}
}

void GamePlay::MousePressed(int x, int y, int button)
{
	if (!triggerLock)
	{
		if (!dialogueActive) // Dialogo est� inativo
		{
			CheckIndex();
			if (Bed->WasClicked(x, y))
			{
				if (!Bed->IsTrigger(index)) // Dialogo n�o est� trancado por trigger
				{
					if (Bed->GetIndex() < index)
						Bed->AddIndex();
					dialogueActive = true;
					hud->Update(Bed);
				}
				else // Dialogo trancado
				{
					if (TriggerCheck(BED))
					{
						if (Bed->GetIndex() < index)
							Bed->AddIndex();
						dialogueActive = true;
						hud->Update(Bed);
					}
					else
					{
						dialogueActive = true;
						hud->Update();
					}
				}
			}
			else if (Door->WasClicked(x, y)) // FOI CLICADO
			{
				if (!Door->IsTrigger(index)) // N�O EST� TRANCADO POR TRIGGER
				{
					if (Door->GetIndex() < index)
						Door->AddIndex();
					dialogueActive = true;
					hud->Update(Door);
				}
				else // EST� TRANCADO
				{
					if (TriggerCheck(DOOR))
					{
						if (Door->GetIndex() < index)
							Door->AddIndex();
						dialogueActive = true;
						hud->Update(Door);
					}
					else
					{
						dialogueActive = true;
						hud->Update();
					}
				}
			}
			else if (Toilet->WasClicked(x, y)) // FOI CLICADO
			{
				if (!Toilet->IsTrigger(index)) // N�O TA TRANCADO POR TRIGGER
				{
					if (Toilet->GetIndex() < index)
						Toilet->AddIndex();
					dialogueActive = true;
					hud->Update(Toilet);
				}
				else // T� TRANCADO
				{
					if (TriggerCheck(TOILET))
					{
						if (Toilet->GetIndex() < index)
							Toilet->AddIndex();
						dialogueActive = true;
						hud->Update(Toilet);
					}
					else
					{
						dialogueActive = true;
						hud->Update();
					}
				}
			}

		}
		else // dialogueActive == true
		{
			dialogueActive = false;
		}
	}
	else
	{
		if (!dialogueActive)
		{
			if (Bed->WasClicked(x, y) || Door->WasClicked(x, y) || Toilet->WasClicked(x, y))
			{
				dialogueActive = true;
				hud->Update();
			}
			else if (Note->WasClicked(x, y))
			{
				std::cout << "TRIGGER POORRRRRRRRAAAAAAAAAAAAA" << std::endl;
				triggerLock = false;
				Bed->ToggleTrigger(index);
				Door->ToggleTrigger(index);
				Toilet->ToggleTrigger(index);
			}
		}
		else
			dialogueActive = false;
	}
}

void GamePlay::CheckIndex()
{
	if ((Bed->GetState(index) && Door->GetState(index) && Toilet->GetState(index)) && index + 1 < DIALOGUES)
	{
		index++;
		std::cout << Bed->GetIndex() << ", " << Door->GetIndex() << ", " << Toilet->GetIndex() << std::endl;
		std::cout << "add index master" << std::endl;
	}
}

bool GamePlay::TriggerCheck(int object)
{
	switch (object)
	{
	case BED:
	{
		if (Door->GetState(index) && Toilet->GetState(index))
		{
			std::cout << "retornou true porra" << std::endl;
			std::cout << Door->GetState(index) << ", " << Toilet->GetState(index) << std::endl;
			return true;
		}
		return false;
		break;
	}
	case DOOR:
	{
		if (Bed->GetState(index) && Toilet->GetState(index))
		{
			std::cout << "retornou true porra" << std::endl;
			std::cout << Bed->GetState(index) << ", " << Toilet->GetState(index) << std::endl;
			return true;
		}
		return false;
		break;
	}
	case TOILET:
	{
		if (Bed->GetState(index) && Door->GetState(index))
		{
			std::cout << "retornou true porra" << std::endl;
			std::cout << Bed->GetState(index) << ", " << Door->GetState(index) << std::endl;
			return true;
		}
		return false;
		break;
	}
	default:
		break;
	}
}

void GamePlay::LockCheck()
{
	if (Bed->IsTrigger(index) && Door->IsTrigger(index) && Toilet->IsTrigger(index))
	{
		triggerLock = true;
	}
}


