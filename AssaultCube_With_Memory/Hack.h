#pragma once
class CHack
{
private:
	HANDLE m_hProcess;
public:
	void Init();
	void MainProcess();
	void OnHack(int iCase);

public: //��ɸ���Ʈ
	void OnBulletHack();
	void OnHealthHack();


public:
	CHack(HANDLE hProcess);
	CHack();
	~CHack();
};