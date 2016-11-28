#include "Transicao.h"

Transicao::Transicao()
{
	//m_background.loadImage(path);
	
	/*switch (day)
	{
	case 1:
		m_background.loadImage("images/introDay1.png");
		break;
	case 2:
		m_background.loadImage("images/introDay2.png");
		break;
	case 3:
		m_background.loadImage("images/introDay3.png");
		break;
	default:
		break;
	}*/

	/*m_background.loadImage("images/introBackground.png");
	m_textToShow.loadFont("TravelingTypewriter.ttf", 15);
	m_textDay.loadFont("TravelingTypewriter.ttf", 20);*/
	this->Reset();
}

void Transicao::Update()
{
}

void Transicao::Draw(std::string path)
{
	m_background.loadImage(path);
	m_background.draw(0,0);
		
	/*m_background.draw(0, 0);
	ofSetColor(0);
	m_textDay.drawString("Dia 1", ofGetWindowWidth() / 2, m_textPosY);
	m_textToShow.drawString(m_text, m_textPosX, m_textPosY +50);*/
	
}

void Transicao::Reset()
{
}

Transicao::~Transicao()
{
}
