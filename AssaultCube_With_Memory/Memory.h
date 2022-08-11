#pragma once
class CMemory
{
private:
	DWORD dwPID;
	HANDLE hProcess;
public:
	void Init();
	DWORD GetProcessID(const char* procName);
	BOOL GetProcessData();
	HANDLE GetHandle();
public:
	CMemory();
	~CMemory();
};