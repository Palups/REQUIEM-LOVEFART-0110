#pragma once
#include<string>
#include<vector>
#include<iostream>
#include "ofMain.h"
#include "GameManager.h"
#include "Dialogue.h"

#define BED 0
#define DOOR 1
#define TOILET 2

class Button
{
public: 

/*-- Construtores --*/
	Button::Button(int x, int y, int w, int h, bool desenheEle, bool estado, std::string path);
	Button::Button(int x, int y, int w, int h, bool desenheEle, bool estado);
	Button(int x, int y, int w, int h, int object);// cama = 0, porta = 1

/*-- Métodos --*/
	void draw();
	void drawImage();
	bool mouseOver(); // ver se o mouse esta em cima dele
	//int getW();  // retorna largura
	//int getH();  // retorn altura
	void Reset(int object);

/*-- Atributos --*/
	ofImage m_image;
	bool m_estado = true; // Interruptor, PRESSIONADO(ON) ou DESPRESSIONADO(OFF)
	bool m_online = true; // Valido para as cameras, se tiver online funciona
	bool m_drawIt; // Se vai desenhar o botao ou apenas detectar toque

/*-- Métodos do dialogo que funciona --*/
	std::string GetDialogue();
	void AddDialogue(int object); // Instancia os dialogos
	void AddIndex();

	bool IsTrigger(int i);
	void ToggleTrigger(int i);
	bool WasClicked(int x, int y);
	bool GetState(int i);
	int GetIndex();

private:

	ofTrueTypeFont myfont; // Fonte
	//std::vector <std::string> dialogueList; // Vetor de dialogos
	
	//int index; // Indice que percorre o vetor
	//bool dialogFlag; // Boolean para saber se dialogo esta ativo

	int
		m_index,
		m_x,
		m_y,
		m_h,
		m_w;

	vector <Dialogue*> m_dialogueList;
};