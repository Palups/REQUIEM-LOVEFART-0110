#include "Button.h"
#include "GameManager.h"

/*-- Construtores --*/


Button::Button(int x, int y, int w, int h, bool desenheEle, bool estado, std::string path)
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	m_drawIt = desenheEle;
	m_estado = estado;
	index = 0;
	myfont.loadFont("TravelingTypewriter.ttf", 20);
	dialogFlag = false;
	m_image.loadImage(path);
}
Button::Button(int x, int y, int w, int h, bool desenheEle, bool estado)
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	m_drawIt = desenheEle;
	m_estado = estado;

	index = 0;
	myfont.loadFont("TravelingTypewriter.ttf", 20);
	dialogFlag = false;
}

/* -- Draw e outras funções -- */

void Button::draw()
{
	if (m_drawIt)
	{
		ofSetColor(255, 255, 255, 0);
		ofDrawRectangle(m_x - (getW() / 2), m_y - (getH() / 2), getW(), getH());
		ofSetColor(255, 255, 255, 255);
		/*if (m_estado == ON)
		{
			ofSetColor(255);
			ofDrawRectangle(m_x - (getW() / 2), m_y - (getH() / 2), getW(), getH());
		}
		else
		{
			ofSetColor(255);
			ofDrawRectangle(m_x - (getW() / 2), m_y - (getH() / 2), getW(), getH());
			ofSetColor(0);
			ofDrawRectangle(m_x - (getW() / 2) + 1, m_y - (getH() / 2) + 1, getW() - 2, getH() - 2);
			ofSetColor(255);
		}*/
	}
	//ofSetColor(0, 0, 0, 255);
	//m_image.draw(m_x, m_y); //será usado pro botão com imagem (quando funcionar)
}

void Button::drawImage()
{
	//deixar os retangulos até ter as imagens
		ofSetColor(0);
		ofDrawRectangle(m_x - (getW() / 2) + 1, m_y - (getH() / 2) + 1, getW() - 2, getH() - 2);
		ofSetColor(255);
	
	//aqui vai desenhar a imagem
	//m_image.draw(m_x, m_y);
}

bool Button::mouseOver()
{
	if (
		((ofGetMouseX() > m_x - (getW() / 2)) && (ofGetMouseX() < m_x + (getW() / 2))) &&
		((ofGetMouseY() > m_y - (getH() / 2)) && (ofGetMouseY() < m_y + (getH() / 2)))
		)
	{
		return true;
	}
	else
		return false;
}

/*-- Getters --*/
int Button::getW()
{
	return m_width;
}

int Button::getH()
{
	return m_height;
}

/*-- Dialogo --*/
void Button::pushDialogue(std::string s)
{
	dialogueList.push_back(s);
}

void Button::displayDialogue()
{
	ofSetColor(255, 255, 255);
	myfont.drawString(dialogueList[index], 100, 674);
}

void Button::drawHUD()
{
	//Cor e desenho da caixa de dialogo
	ofSetColor(0, 0, 0);
	ofDrawRectRounded(7, 635, 1010, 100, 5);
}

int Button::getIndex()
{
	return index;
}

void Button::addIndex()
{
	if (index < (dialogueList.size() - 1)) // Condição para que o index não saia do vetor e retorne lixo
		index++;
	else
		return;
}

void Button::disableDialogue()
{
	if (dialogFlag)
		dialogFlag = false;
}
