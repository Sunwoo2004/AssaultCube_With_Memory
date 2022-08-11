#pragma once
class CHack
{
private:
	HANDLE m_hProcess;
public:
	void Init();
	void MainProcess();
	void OnHack(int iCase);

public: //기능리스트
	void OnBulletHack();
	void OnHealthHack();


public:
	CHack(HANDLE hProcess);
	CHack();
	~CHack();
};