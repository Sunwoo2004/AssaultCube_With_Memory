#include "stdafx.h"
#include "Memory.h"

int main()
{
	CMemory* memory = new CMemory();
	BOOL bResult = memory->GetProcessData();
	if (bResult == FALSE)
	{
		system("pause");
	}




	return 0;
}