#include "stdafx.h"
#include "Memory.h"
#include <TlHelp32.h>

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

void CMemory::GetProcessData()
{
	while (true)
	{
		DWORD PID = GetProcessID("ac_client.exe");
		if (PID > 0)
		{
			//프로세스 아이디를 찾았다면
			dwPID = PID;
		}
		Sleep(100);
	}
}