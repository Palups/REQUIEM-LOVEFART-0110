#include "GamePlay.h"

GamePlay::GamePlay(GameManager *game)
{
	wall1.loadImage("images/wall1.png"); //carrega imagem que contém a cama, porta e duto de ar
	wall2.loadImage("images/wall2.png"); //carrega imagem que contém vaso sanitário
	m_noteText.loadImage("images/noteText.png"); //carrega imagem do texto do bilhete
	crack1.loadImage("images/Cenario2_desenho1.png"); //carrega imagem da rachadura do lado A
	crack2.loadImage("images/Cenario2_desenho2.png"); //carrega imagem da rachadura do lado B

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
	/*bed = new Button(75 + (465 / 2), 550 + (100 / 2), 465, 100, true, OFF);
	note = new Button(187 + (84 / 2), 331 + (147 / 2), 84, 147, true, OFF, "images/Cenario2_bilhete.png");
	door = new Button(710 + (213 / 2), 292 + (385 / 2), 213, 385, true, OFF);
	toilet = new Button(580 + (135 / 2), 546 + (145 / 2), 135, 145, true, OFF);
	changeSide = new Button(990, 730, 100, 100, true, OFF, "images/btnChangeWall.png");*/

	hud = new HUD();
	m_illuminati = new Button(925, 80, 39, 78, true, OFF, "images/Cenario2_desenho3.png");
	Bed = new Button(75, 550, 500, 100, BED);
	Door = new Button(710, 292, 213, 385, DOOR);
	Toilet = new Button(580, 546, 135, 145, TOILET);
	Note = new Trigger();
	changeSide = new Button(990, 730, 100, 100, true, OFF, "images/btnChangeWall.png");
	objetivo = new Objetivo();
	trans = new Transicao();

	m_fimdodia = false; //set da variave fim do dia

	triggerLock = false;
	dialogueActive = false;
	index = 0;
}

void GamePlay::update(GameManager *game)
{
	LockCheck();
	if (m_fimdodia)//caso fim do dia esteja ativo, adiciona um na variavel dia e vai(é o que deveria) pra transição mylla
	{
		game->gameSide = GAME_SIDE_TRANS;
		game->m_day++;
	}
	/*-- switch case para cada dia de gameplay --*/
	switch (game->m_day) {
	case 1:
		/*-- switch case para cada lado da sala, no primeiro dia --*/
		switch (game->gameSide) {
		case GAME_SIDE_TRANS:
			//incluir tela preta e texto de introdução
			if (m_fimdodia == false)
			{
				if (game->mousePressed)
					game->gameSide = GAME_SIDE_A;
			}
			break;

		case GAME_SIDE_A:
			/*-- Muda o lado do quarto --*/ //objetos lado A: Cama e porta
			if (changeSide->mouseOver())
				if (game->mousePressed)
					game->gameSide = GAME_SIDE_B;
			break;

		case GAME_SIDE_B:
			//cricou no illuminati vc morreu
			if (m_illuminati->mouseOver())
				if (game->mousePressed)
					game->gameSide = GAME_OVER;

			//se clicar no bilhete na parede, aparece a imagem dele maior. se clicar de novo, a imagem some
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
		switch (game->gameSide)
			{
			case GAME_SIDE_TRANS:
				if (m_fimdodia)// teoricamente voltaria para o menu mylla
				{
					if (game->mousePressed)
					{
						game->gameState = GAME_MENU;
					}
				}
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

void GamePlay::draw(GameManager *game)
{
	/*-- switch case para cada dia de gameplay --*/
	switch (game->m_day){
	case 1:
		/*-- switch case para cada lado da sala, no primeiro dia --*/
		switch (game->gameSide){
		case GAME_SIDE_TRANS:
			trans->Draw("images/prologue.png");
			break;
		case GAME_SIDE_A:
			wall1.draw(0, 0);
			crack1.draw(580, 450);
			Bed->draw();
			Door->draw();
			changeSide->drawImage();
			break;
		case GAME_SIDE_B:
			wall2.draw(0, 0);
			crack2.draw(650, 150);
			m_illuminati->drawImage();
			Toilet->draw();
			//Note->Draw();
			Note->DrawImage();
			changeSide->drawImage();
			if (m_showingNote == true)
				m_noteText.draw(0, 0);
			break;
		default:
			break;
		}
		break;
	case 2: // se o dia for igual a 2 ele vem pra cá mylla
		switch (game->gameSide){
		case GAME_SIDE_TRANS:
			trans->Draw("images/fim_dia1.png");
			break;
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
	if(game->gameSide!=GAME_SIDE_TRANS)
		objetivo->Draw();
}

void GamePlay::MousePressed(int x, int y, int button, GameManager *game)
{
	if (!triggerLock)
	{
		if (!dialogueActive) // Dialogo está inativo
		{
			CheckIndex();
			if (Bed->WasClicked(x, y) && game->gameSide == GAME_SIDE_A)
			{
				if (!Bed->IsTrigger(index)) // Dialogo não está trancado por trigger
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
			else if (Door->WasClicked(x, y) && game->gameSide == GAME_SIDE_A) // FOI CLICADO
			{
				if (!Door->IsTrigger(index)) // NÃO ESTÁ TRANCADO POR TRIGGER
				{
					if (Door->GetIndex() < index)
						Door->AddIndex();
					dialogueActive = true;
					hud->Update(Door);
				}
				else // ESTÁ TRANCADO
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
			else if (Toilet->WasClicked(x, y) && game->gameSide == GAME_SIDE_B) // FOI CLICADO
			{
				if (!Toilet->IsTrigger(index)) // NÃO TA TRANCADO POR TRIGGER
				{
					if (Toilet->GetIndex() < index)
						Toilet->AddIndex();
					dialogueActive = true;
					hud->Update(Toilet);
				}
				else // TÁ TRANCADO
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
			if ((Bed->WasClicked(x,y) && game->gameState == GAME_SIDE_A) || (Door->WasClicked(x,y) && game->gameState == GAME_SIDE_A) ||
				(Toilet->WasClicked(x,y) && game->gameState == GAME_SIDE_B))
			{
				dialogueActive = true;
				hud->Update();
			}
			else if (Note->WasClicked(x, y) && game->gameSide == GAME_SIDE_B)
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
			m_fimdodia = true; //ativa o fim do dia para mudar os estados mylla
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


