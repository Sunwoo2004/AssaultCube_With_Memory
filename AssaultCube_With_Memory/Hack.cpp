#include "stdafx.h"
#include "Hack.h"

CHack::CHack()
{
	Init();
}

CHack::CHack(HANDLE hProcess) // 클래스 선언시 핸들을 미리 얻어둠
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