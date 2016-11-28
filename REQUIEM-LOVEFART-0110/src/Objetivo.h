#pragma once
#include "GameManager.h"


class Objetivo
{
private:
	float m_posTextX, m_posTextY;
	float m_posBackgroundX, m_posBackgroundY;
	ofImage m_background;
public:
	Objetivo();

	void Update();
	void Draw();	
	void Reset();
	
	~Objetivo();
};

