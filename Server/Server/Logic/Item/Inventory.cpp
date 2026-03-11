#include <Pch.h>


ErrorResult Inventory::LoadFromDB()
{

	return ErrorResult::Success;
}

ErrorResult Inventory::EnterItem(SharedItem item)
{
	IF_RETURN(nullptr == item, ErrorResult::InvalidParameter);
	
	item->onEnter(GetOwner());

	return ErrorResult::Success;
}

ErrorResult Inventory::LeaveItem(SharedItem item)
{
	IF_RETURN(nullptr == item, ErrorResult::InvalidParameter);

	item->onLeave(GetOwner());

	return ErrorResult::Success;
}

ErrorResult Inventory::Find(ItemSlot slot, OUT SharedItem* output)
{
	*output = Find(slot);
	IF_RETURN(output == nullptr, ErrorResult::CantFindItem);

	return ErrorResult::Success;
}

SharedItem Inventory::Find(ItemSlot slot)
{
	auto item = mItems.find(slot);
	IF_RETURN(item == mItems.end(), nullptr);

	return item->second;
}

ErrorResult Inventory::FindbyItemId(ItemId item_id, OUT SharedItem* output)
{
	*output = FindbyItemId(item_id);
	IF_RETURN(output == nullptr, ErrorResult::CantFindItem);

	return ErrorResult::Success;
}

SharedItem Inventory::FindbyItemId(ItemId item_id)
{
	for (auto iter : mItems)
	{
		IF_CONTINUE(iter.second->GetId() != item_id);

		return iter.second;
	}

	return nullptr;
}


ErrorResult Inventory::Update(DeltaTime delta_time)
{

	return ErrorResult::Success;
}
