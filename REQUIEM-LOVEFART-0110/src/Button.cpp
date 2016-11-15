#include "Button.h"
#include "GameManager.h"

void Button::draw()
{
	/*if (m_drawIt)
	{
		if (m_estado == ON)
		{
			ofSetColor(255);
			ofDrawRectangle(m_x - (getW() / 2), m_y - (getH() / 2), getW(), getH());
		}
		else
		{
			ofSetColor(255);
			ofDrawRectangle(m_x - (getW() / 2), m_y - (getH() / 2), getW(), getH());
			ofSetColor(0);
			ofDrawRectangle(m_x - (getW() / 2)+1, m_y - (getH() / 2)+1, getW()-2, getH()-2);
			ofSetColor(255);
		}
	}*/

	m_image.draw(m_x, m_y);
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

Button::Button(int x, int y, int w, int h, bool desenheEle, std::string path)
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	m_drawIt = desenheEle;
	m_image.loadImage(path);
}
Button::Button(int x, int y, int w, int h, bool desenheEle, bool estado, std::string path)
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	m_drawIt = desenheEle;
	m_estado = estado;
	m_image.loadImage(path);
}

int Button::getW()
{
	return m_width;
}

int Button::getH()
{
	return m_height;
}
