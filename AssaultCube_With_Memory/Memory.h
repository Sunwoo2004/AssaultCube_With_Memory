#pragma once
class CMemory
{
private:
	DWORD m_dwPID;
	HANDLE m_hProcess;
public:
	void Init();
	DWORD GetProcessID(const char* procName);
	BOOL GetProcessData();
	HANDLE GetHandle();
public:
	CMemory();
	~CMemory();
};