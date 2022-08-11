#include "stdafx.h"
#include "Hack.h"
#include "Offset.h"

using namespace std;

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

void CHack::MainProcess()
{
	cout << "Service Start.." << endl;
	while (true)
	{
		cout << "총알무한 : 1, 체력무한 : 2" << endl;

	}
}

void CHack::OnHack(int iCase)
{

}

void CHack::OnBulletHack()
{
	static int onoffcheck = false;
	if (onoffcheck == false)
	{
		BYTE bArray[] = { 0x90, 0x90 };
		memcpy((BYTE*)BULLET, &bArray, sizeof bArray / sizeof bArray[0]);
	}
	else
	{
		BYTE bArray[] = { 0xFF, 0x08 };
		memcpy((BYTE*)BULLET, &bArray, sizeof bArray / sizeof bArray[0]);
	}
}