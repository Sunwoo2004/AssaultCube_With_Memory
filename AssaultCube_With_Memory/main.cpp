#include "stdafx.h"
#include "Memory.h"
#include "Hack.h"

int main()
{
	CMemory* memory = new CMemory();
	BOOL bResult = memory->GetProcessData();
	if (bResult == FALSE)
	{
		system("pause");
		return 0;
	}

	CHack* hack = new CHack(memory->GetHandle());

	delete memory; //�޸� ������ ���� ���� (�޸� ����)

	hack->MainProcess();

	delete hack;

	return 0;
}