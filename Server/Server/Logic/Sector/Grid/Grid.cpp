#include <Pch.h>

ErrorResult Grid::Initaize()
{

	return ErrorResult::Success;
}

ErrorResult Grid::Release()
{
	mCells.clear();
	mNearGrids.clear();

	return ErrorResult::Success;
}

ErrorResult Grid::BroadCast(Network::SharedPacket message)
{
	for (auto cell : mCells)
	{
		//cell->BroadCast(message);
	}

	return ErrorResult::Success;
}

