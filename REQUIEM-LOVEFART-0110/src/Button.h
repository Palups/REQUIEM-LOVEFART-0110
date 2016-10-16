#pragma once
#include "ofMain.h"

class Button
{
private:
	float m_posX;
	float m_posY;
	float m_height;
	float m_width;
	ofImage m_image;
public:
	Button(float posX, float posY, float height, float width, std::string path);
	~Button();
	void Desenhar();
};

