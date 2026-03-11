#include <Pch.h>

ErrorResult Cell::Initalize(CellIndex index)
{
	mIndex = index;

	return ErrorResult::Success;
}

ErrorResult Cell::Release()
{
	mNearCells.clear();
	mEntitys.clear();

	return ErrorResult::Success;
}

void Cell::EnterEntity(EntityId entity_id)
{
	mEntitys.emplace(entity_id);
}

void Cell::LeaveEntity(EntityId entity_id)
{
	mEntitys.erase(entity_id);
}

void Cell::BroadCast(Network::SharedPacket message)
{
	for (auto entity : mEntitys)
	{
			
	}
}
