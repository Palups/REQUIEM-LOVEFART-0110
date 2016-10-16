#include "Button.h"

Button::Button(float posX, float posY, float height, float width, std::string path)
{
	m_posX = posX;
	m_posY = posY;
	m_height = height;
	m_width = width;
	m_image.loadImage(path);
}

Button::~Button()
{
}

void Button::Desenhar() {
	//ofDrawRectangle(m_posX, m_posY, m_height, m_width);
	m_image.draw(m_posX, m_posY);
}