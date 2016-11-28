#pragma once
#include "Button.h"
#include "GameManager.h"
// Classe que vai trancar todos os dialogos. AKA bilhete
class Trigger
{
public:
	Trigger();
	void Reset();
	void Draw();
	void DrawImage();
	void SetState(bool s);

	bool MouseOver();
	bool WasClicked(int x, int y);
	bool GetState();
	~Trigger();

private:
	bool isActive;

	int
		m_x,
		m_y,
		m_w,
		m_h;
	ofImage m_image;
};

