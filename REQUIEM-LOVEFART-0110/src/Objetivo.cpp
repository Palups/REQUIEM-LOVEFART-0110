#include "Objetivo.h"



Objetivo::Objetivo()
{
	m_background.loadImage("images/objBackground.png");
	this->Reset();
}

void Objetivo::Update()
{
}

void Objetivo::Draw()
{
	ofSetColor(255, 255, 255, 150);
	m_background.draw(m_posBackgroundX, m_posBackgroundY);
	ofSetColor(0, 0, 0, 255);
	ofDrawBitmapString("Objetivo: \n- Sobreviva ao primeiro dia. \n", m_posTextX, m_posTextY);
	ofSetColor(255);
}

void Objetivo::Reset()
{
	m_posBackgroundX = 10;
	m_posBackgroundY = ofGetWindowHeight() / 2;
	m_posTextX = m_posBackgroundX + 15;
	m_posTextY = m_posBackgroundY + 10;
}

Objetivo::~Objetivo()
{
}
