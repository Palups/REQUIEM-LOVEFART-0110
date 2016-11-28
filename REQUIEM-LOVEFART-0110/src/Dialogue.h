	#pragma once
#include "ofMain.h"
#include<iostream>
#include<string>

class Dialogue
{
public:
	Dialogue();
	void Reset();
	void PushTrigger(int b);
	void PushDialogue(std::string d);
	void SetTrigger(bool t);

	/*-- Metodos de acesso --*/
	std::string ShowDialogue();
	bool IsTrigger(); // Se tiver trancado por trigger retorna true
	bool GetState();
	~Dialogue();

private:
	std::string m_dialog;
	bool m_isTriggerLock; // está bloqueado por trigger
	bool m_isActive; // É falso até o momento que é ativado o dialogo
	std::vector <int> m_triggerList; // quais são os triggers necessarios pra mostrar esse dialogo
	int m_index; //index pra percorrer o vetor
};

