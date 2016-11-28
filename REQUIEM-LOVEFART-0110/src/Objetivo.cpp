#include "Objetivo.h"



Objetivo::Objetivo()
{
	myfont.loadFont("TravelingTypewriter.ttf", 10);
	m_background.loadImage("images/objBackground.png");
	Reset();
}

void Objetivo::Update()
{
}

void Objetivo::Draw()
{
	ofSetColor(0, 0, 0, 190);
	m_background.draw(m_posBackgroundX, m_posBackgroundY);
	ofSetColor(255, 255, 255, 255);
	//ofDrawBitmapString("Objetivo: \n- Sobreviva ao primeiro dia. \n", m_posTextX, m_posTextY);
	myfont.drawString("Objetivo: \n- Sobreviva ao primeiro dia. \n", m_posTextX, m_posTextY);
	ofSetColor(255);
}

void Objetivo::Reset()
{
	m_posBackgroundX = 10;
	m_posBackgroundY = 20;
	m_posTextX = m_posBackgroundX + 15;
	m_posTextY = m_posBackgroundY + 10;
}

Objetivo::~Objetivo()
{
}
