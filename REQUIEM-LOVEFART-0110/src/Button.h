#pragma once
#include<string>
#include<vector>
#include "ofMain.h"
#include "GameManager.h"

class Button
{
public: 

/*-- Construtores --*/
	Button::Button(int x, int y, int w, int h, bool desenheEle/*, std::string path*/);
	Button::Button(int x, int y, int w, int h, bool desenheEle, bool estado/*, std::string path*/);

/*-- Métodos --*/
	void draw();
	bool mouseOver(); // ver se o mouse esta em cima dele
	int getW();  // retorna largura
	int getH();  // retorn altura

	int m_x;
	int m_y;
	int m_width; // largura
	int m_height; // altura

/*-- Atributos --*/
	ofImage m_image;
	bool m_estado = true; // Interruptor, LIGADO(ON) ou DESLIGADO(OFF)
	bool m_online = true; // Valido para as cameras, se tiver online funciona
	bool m_drawIt; // Se vai desenhar o botao ou apenas detectar toque

/*-- Metodos associados ao vetor de dialogos --*/

	void pushDialogue(std::string s); // Adiciona dialogo ao vetor
	void displayDialogue(); // Mostra dialogo
	
	void drawHUD(); // Desenha a a caixa do dialogo
	
	int getIndex(); // Retorna o indice onde esta o dialogo
	void addIndex(); // Incrementa o dialogo
	
	void disableDialogue(); // Desativa o dialogo

private:

	ofTrueTypeFont myfont; // Fonte
	std::vector <std::string> dialogueList; // Vetor de dialogos
	
	int index; // Indice que percorre o vetor
	bool dialogFlag; // Boolean para saber se dialogo esta ativo
};