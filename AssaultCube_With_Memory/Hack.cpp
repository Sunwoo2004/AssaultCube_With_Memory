#include "stdafx.h"
#include "Hack.h"

CHack::CHack()
{
	Init();
}

CHack::CHack(HANDLE hProcess) // Ŭ���� ����� �ڵ��� �̸� ����
{
	Init();
	m_hProcess = hProcess;
}

CHack::~CHack()
{

}

void CHack::Init()
{
	m_hProcess = 0;
}