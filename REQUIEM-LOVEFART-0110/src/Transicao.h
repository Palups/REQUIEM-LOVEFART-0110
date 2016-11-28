#pragma once
#include "ofMain.h"
#include <string>
#include "GameManager.h"

class Transicao
{
private:
	//std::string m_text;
	ofImage m_background;
	//float m_textPosX, m_textPosY;
	int m_day; //só pq n tem game manager aqui
	
	//ofTrueTypeFont m_textToShow, m_textDay;
public:
	Transicao();

	void Update();
	void Draw(std::string path);
	void Reset();

	~Transicao();

};