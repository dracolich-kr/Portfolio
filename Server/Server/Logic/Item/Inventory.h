#pragma once

using ItemSlot = Int32;

class Inventory
	: public IUpdate
{
public:
	Inventory(CombatObject& owner)
		: mOwner(owner)
	{}

	virtual ~Inventory() 
	{
	}

	ErrorResult LoadFromDB();

	ErrorResult EnterItem(SharedItem item);
	ErrorResult LeaveItem(SharedItem item);

	ErrorResult Find(ItemSlot slot, OUT SharedItem* output);
	SharedItem Find(ItemSlot slot);

	ErrorResult FindbyItemId(ItemId item_id, OUT SharedItem* output);
	SharedItem FindbyItemId(ItemId item_id);

	CombatObject& GetOwner() { return mOwner; }

	ErrorResult Update(DeltaTime delta_time) override;

private:
	Map<ItemSlot, SharedItem> mItems;
	CombatObject& mOwner;
};

