#include "Trigger.h"

Trigger::Trigger()
{
	m_image.loadImage("images/Cenario2_bilhete.png");
	Reset();
}

void Trigger::Reset()
{
	isActive = false;
	m_x = 187;
	m_y = 331;
	m_w = 84;
	m_h = 147;
}

void Trigger::Draw()
{
	ofSetColor(180, 0, 50);
	ofDrawRectangle(m_x - (m_w / 2), m_y - (m_h / 2), m_w, m_h);
}

void Trigger::DrawImage()
{
	m_image.draw(m_x - (m_w / 2), m_y - (m_h / 2) , m_w , m_h);
}

void Trigger::SetState(bool s)
{
	isActive = s;
}



bool Trigger::MouseOver()
{
	if (
		((ofGetMouseX() > m_x - (m_w / 2) + 10) && (ofGetMouseX() < m_x + (m_w / 2) - 20)) &&
		((ofGetMouseY() > m_y - (m_h / 2) + 20) && (ofGetMouseY() < m_y + (m_h / 2) - 40))
		)
	{
		return true;
	}
	else
		return false;
}

bool Trigger::WasClicked(int x, int y)
{
	if (x > m_x - (m_w / 2) + 10 && x < (m_x + m_w / 2) -20 && y > m_y - (m_h / 2) +20 && y < (m_y + m_h / 2) -40)
	{
		std::cout << "cricou!!!" << std::endl;
		return true;
	}
	return false;
}

bool Trigger::GetState()
{
	return isActive;
}

Trigger::~Trigger()
{
}
