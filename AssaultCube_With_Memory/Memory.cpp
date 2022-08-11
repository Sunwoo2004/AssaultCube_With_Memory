#include "stdafx.h"
#include "Memory.h"
#include <TlHelp32.h>

using namespace std;

CMemory::CMemory()
{
	Init();
}

CMemory::~CMemory()
{

}

void CMemory::Init()
{
	dwPID = 0;
	hProcess = 0;
}

DWORD CMemory::GetProcessID(const char* procName)
{
	DWORD procID = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);
		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				if (!_stricmp(procEntry.szExeFile, procName))
				{
					procID = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
	CloseHandle(hSnap);
	return procID;
}

BOOL CMemory::GetProcessData()
{
	while (true)
	{
		cout << "Process Finding.." << endl;
		DWORD PID = GetProcessID("ac_client.exe");
		if (PID > 0)
		{
			//���μ��� ���̵� ã�Ҵٸ�
			cout << "Process Found!!" << endl;
			dwPID = PID;
			break; //�ݺ��� ����
		}
		Sleep(100);
	}

	//���μ����� ����
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
	
	if (hProcess == 0)
	{
		cout << "���μ����� ���� ���߽��ϴ�." << endl;
		return FALSE;
	}

	return TRUE;
}