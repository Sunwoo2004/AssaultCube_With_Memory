#include "stdafx.h"
#include "Hack.h"
#include "Offset.h"

using namespace std;

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

void CHack::MainProcess()
{
	int iCase = 0;
	cout << "Service Start.." << endl;
	while (true)
	{
		cout << "�Ѿ˹��� : 1, ü�¹��� : 2" << endl;
		cout << ">>";
		cin >> iCase;
		OnHack(iCase);
		system("cls");
	}
}

void CHack::OnHack(int &iCase) //������ �ּҸ� �޴´�
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
		//cout << "���ǵ��� ���� ����Դϴ�." << endl;
		break;
	}
}

void CHack::OnBulletHack()
{
	static int onoffcheck = false;
	if (onoffcheck == false)
	{
		onoffcheck = true;
		BYTE bArray[] = { 0x90, 0x90 };
		WriteProcessMemory(m_hProcess, (BYTE*)BULLET, &bArray, sizeof bArray / sizeof bArray[0], NULL);
	}
	else
	{
		onoffcheck = false;
		BYTE bArray[] = { 0xFF, 0x08 };
		WriteProcessMemory(m_hProcess, (BYTE*)BULLET, &bArray, sizeof bArray / sizeof bArray[0], NULL);
	}
}

void CHack::OnHealthHack()
{
	static int onoffcheck = false;
	if (onoffcheck == false)
	{
		onoffcheck = true;
		BYTE bArray[] = { 0x90, 0x90, 0x90 };
		WriteProcessMemory(m_hProcess, (BYTE*)HEALTH, &bArray, sizeof bArray / sizeof bArray[0], NULL);
	}
	else
	{
		onoffcheck = false;
		BYTE bArray[] = { 0x29, 0x73, 0x04 };
		WriteProcessMemory(m_hProcess, (BYTE*)HEALTH, &bArray, sizeof bArray / sizeof bArray[0], NULL);
	}
}