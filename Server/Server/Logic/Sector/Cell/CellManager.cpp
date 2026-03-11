#include "pch.h"

ErrorResult CellManager::Initalize()
{

	return ErrorResult::Success;
}

ErrorResult CellManager::Release()
{
	for (auto cell : mCells)
	{
		cell.second->Release();

	}

	return ErrorResult::Success;
}

CellIndex CellManager::Find(Math::Vector3 pos)
{

	return 0;
}
