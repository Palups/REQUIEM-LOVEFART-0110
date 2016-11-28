#include "HUD.h"


HUD::HUD()
{
	myfont.loadFont("TravelingTypewriter.ttf", 12);
	Reset();
}

void HUD::Reset()
{
	m_x = 20;
	m_y = 660;
	m_w = 910;
	m_h = 90;
}

void HUD::Update(Button *b)
{
	m_dialogue = b->GetDialogue();
}

void HUD::Update()
{
	m_dialogue = "Talvez eu deva explorar mais o quarto..";
}

void HUD::Draw()
{
	ofSetColor(0, 0, 0);
	ofDrawRectRounded(m_x, m_y, m_w, m_h, 5);
	DrawDialogue();
}

void HUD::DrawDialogue()
{
	ofSetColor(255, 255, 255);
	//ofDrawBitmapString(m_dialogue, 40, 690);
	myfont.drawString(m_dialogue, 40, 690);
}


HUD::~HUD()
{
}
