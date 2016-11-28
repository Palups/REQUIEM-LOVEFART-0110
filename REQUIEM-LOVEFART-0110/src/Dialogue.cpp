#include "Dialogue.h"



Dialogue::Dialogue()
{
	Reset();
}
void Dialogue::Reset()
{
	m_isActive = false;
	m_isTriggerLock = false;
	m_index = 0;
}

void Dialogue::PushTrigger(int b)
{
	m_triggerList.push_back(b);
}

void Dialogue::PushDialogue(std::string d)
{
	m_dialog = d;
}

void Dialogue::SetTrigger(bool t)
{
	m_isTriggerLock = t;
}

/*-- Metodos de acesso --*/
std::string Dialogue::ShowDialogue()
{
	m_isActive = true;
	return m_dialog;
}

bool Dialogue::IsTrigger()
{
	return m_isTriggerLock;
}

bool Dialogue::GetState()
{
	return m_isActive;
}

Dialogue::~Dialogue()
{
}
