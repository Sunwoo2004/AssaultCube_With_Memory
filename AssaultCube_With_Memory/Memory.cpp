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
	m_dwPID = 0;
	m_hProcess = 0;
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

HANDLE CMemory::GetHandle()
{
	return m_hProcess;
}

BOOL CMemory::GetProcessData()
{
	while (true)
	{
		cout << "Process Finding.." << endl;
		DWORD PID = GetProcessID("ac_client.exe");
		if (PID > 0)
		{
			//프로세스 아이디를 찾았다면
			m_dwPID = PID;
			cout << "Process Found!!, PID : " << m_dwPID << endl;
			break; //반복문 나옴
		}
		Sleep(100);
	}

	//프로세스를 연다
	m_hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_dwPID);
	
	if (m_hProcess == 0)
	{
		cout << "프로세스를 열지 못했습니다." << endl;
		return FALSE;
	}

	return TRUE;
}