#pragma once
class CMemory
{
private:
	DWORD dwPID;
	HANDLE hProcess;
public:
	void Init();
public:
	CMemory();
	~CMemory();
};