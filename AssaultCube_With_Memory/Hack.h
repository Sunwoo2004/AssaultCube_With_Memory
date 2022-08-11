#pragma once
class CHack
{
private:
	HANDLE m_hProcess;
public:
	void Init();
public:
	CHack(HANDLE hProcess);
	CHack();
	~CHack();
};