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

	delete memory; //메모리 포인터 동적 해제 (메모리 관리)

	hack->MainProcess();

	delete hack;

	return 0;
}