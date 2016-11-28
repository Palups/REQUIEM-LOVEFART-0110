#pragma once
#include "ofMain.h"
#include <string>
#include "Button.h"
class HUD
{
public:
	HUD();
	void Reset();
	void Update(Button *b);
	void Update();
	void Draw();
	void DrawDialogue();
	~HUD();

private:
	ofTrueTypeFont myfont;
	std::string m_dialogue;
	int
		m_x,
		m_y,
		m_w,
		m_h;
};

