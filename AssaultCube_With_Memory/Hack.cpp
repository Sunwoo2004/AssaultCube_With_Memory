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
	int iCase = 0;
	cout << "Service Start.." << endl;
	while (true)
	{
		cout << "총알무한 : 1, 체력무한 : 2" << endl;
		cout << ">>";
		cin >> iCase;
		OnHack(iCase);
		system("cls");
	}
}

void CHack::OnHack(int iCase)
{
	switch (iCase)
	{
	case 1:
		OnBulletHack();
		break;
	case 2:
		OnHealthHack();
		break;
	default:
		//cout << "정의되지 않은 기능입니다." << endl;
		break;
	}
}

void CHack::OnBulletHack()
{
	static int onoffcheck = false;
	if (onoffcheck == false)
	{
		BYTE bArray[] = { 0x90, 0x90 };
		WriteProcessMemory(m_hProcess, (BYTE*)BULLET, &bArray, sizeof bArray / sizeof bArray[0], NULL);
		//memcpy((BYTE*)BULLET, &bArray, sizeof bArray / sizeof bArray[0]);
	}
	else
	{
		BYTE bArray[] = { 0xFF, 0x08 };
		WriteProcessMemory(m_hProcess, (BYTE*)BULLET, &bArray, sizeof bArray / sizeof bArray[0], NULL);
		//memcpy((BYTE*)BULLET, &bArray, sizeof bArray / sizeof bArray[0]);
	}
}

void CHack::OnHealthHack()
{

}