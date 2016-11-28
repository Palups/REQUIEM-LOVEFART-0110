#include "Button.h"
#include "GameManager.h"

/*-- Construtores --*/


Button::Button(int x, int y, int w, int h, bool desenheEle, bool estado, std::string path)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
	m_drawIt = desenheEle;
	m_estado = estado;
	
	myfont.loadFont("TravelingTypewriter.ttf", 20);
	
	m_image.loadImage(path);
}

Button::Button(int x, int y, int w, int h, bool desenheEle, bool estado)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
	m_drawIt = desenheEle;
	m_estado = estado;

	
	myfont.loadFont("TravelingTypewriter.ttf", 20);
	
}

Button::Button(int x, int y, int w, int h, int object)
{
	m_index = 0;
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
	m_drawIt = false;
	m_estado = false;
	Reset(object);
}

/* -- Draw e outras funções -- */

void Button::draw()
{
	ofSetColor(0, 0, 0, 0);
	ofDrawRectangle(m_x, m_y, m_w, m_h);
	ofSetColor(255, 255, 255, 255);
}

void Button::drawImage()
{	
	//aqui vai desenhar a imagem
	m_image.draw(m_x - (m_w / 2) + 1, m_y - (m_h / 2) + 1, m_w - 2, m_h - 2);
}

bool Button::mouseOver()
{
	if (
		((ofGetMouseX() > m_x - (m_w / 2)) && (ofGetMouseX() < m_x + (m_h / 2))) &&
		((ofGetMouseY() > m_y - (m_h / 2)) && (ofGetMouseY() < m_y + (m_h / 2)))
		)
	{
		return true;
	}
	else
		return false;
}

void Button::Reset(int object)
{
	switch (object)
	{
	case BED:
		AddDialogue(object);
		break;


	case DOOR:
		AddDialogue(object);
		break;

	case TOILET:
		AddDialogue(object);
		break;
	}
}

std::string Button::GetDialogue()
{
	return m_dialogueList[m_index]->ShowDialogue();
}

void Button::AddDialogue(int object)
{
	switch (object)
	{

	case BED:
	{
		std::cout << "adicionou dialogo" << std::endl;

		Dialogue *a = new Dialogue();
		a->PushDialogue("Preciso sair daqui");
		a->SetTrigger(true); // Olha o bilhete antes de explorar o quarto
		m_dialogueList.push_back(a);

		Dialogue *b = new Dialogue();
		b->PushDialogue("Nao me sinto bem... Vou me deitar");
		b->SetTrigger(false);
		b->PushTrigger(DOOR);
		b->PushTrigger(TOILET);
		m_dialogueList.push_back(b);

		Dialogue *c = new Dialogue();
		c->PushDialogue("Nao me sinto bem... Vou me deitar");
		c->SetTrigger(true); // Ultima interação no quarto
		c->PushTrigger(DOOR);
		c->PushTrigger(TOILET);
		m_dialogueList.push_back(c);

		/*Dialogue *d = new Dialogue();
		d->PushDialogue("fuck me");
		d->SetTrigger(false);
		m_dialogueList.push_back(d);*/

		break;
	}

	case DOOR:
	{

		Dialogue *c = new Dialogue();
		c->PushDialogue("Tem alguem ai?!! ");
		c->SetTrigger(true);
		m_dialogueList.push_back(c);

		Dialogue *d = new Dialogue();
		d->PushDialogue("Esta trancado");
		d->SetTrigger(false);
		m_dialogueList.push_back(d);

		Dialogue *e = new Dialogue();
		e->PushDialogue("Alguem me ajude!!");
		e->SetTrigger(false);
		e->PushTrigger(BED);
		e->PushTrigger(TOILET);
		m_dialogueList.push_back(e);

		/*Dialogue *f = new Dialogue();
		f->PushDialogue("Caralho porra");
		f->SetTrigger(false);
		m_dialogueList.push_back(f);*/

		break;
	}

	case TOILET:
	{
		Dialogue *a = new Dialogue();
		a->PushDialogue("Eca uma privada do lado de uma cama?");
		a->SetTrigger(true);
		m_dialogueList.push_back(a);

		Dialogue *b = new Dialogue();
		b->PushDialogue("Sera que estou numa prisao?");
		b->SetTrigger(false);
		m_dialogueList.push_back(b);

		Dialogue *c = new Dialogue();
		c->PushDialogue("Nao me sinto bem..");
		c->SetTrigger(false);
		c->PushTrigger(BED);
		c->PushTrigger(DOOR);
		m_dialogueList.push_back(c);

		/*Dialogue *d = new Dialogue();
		d->PushDialogue("puta merda pqp");
		d->SetTrigger(false);
		m_dialogueList.push_back(d);*/

		break;
	}
	}
}

void Button::AddIndex()
{
	if (m_index + 1 < m_dialogueList.size())
	{
		std::cout << "Adicionado index " << m_index + 1 << std::endl;
		m_index++;
	}
}

bool Button::IsTrigger(int i)
{
	return m_dialogueList[i]->IsTrigger();
}

void Button::ToggleTrigger(int i)
{
	m_dialogueList[i]->SetTrigger(false);
}

bool Button::WasClicked(int x, int y)
{
	if (x > m_x && x < (m_x + m_w) && y > m_y && y < (m_y + m_h))
	{
		std::cout << "cricou!!!" << std::endl;
		return true;
	}
	return false;
}

bool Button::GetState(int i)
{
	return m_dialogueList[i]->GetState();
}

int Button::GetIndex()
{
	return m_index;
}
