#pragma once

class Item abstract
{
public:
	Item() 
		: mItemId(0)
		, mCount(0)
		, mSkill(nullptr)
	{}

	virtual ~Item() {}

	virtual void Release();

	void SetCount(ItemCount item_count) { mCount = item_count; }
	const ItemCount& GetCount() { return mCount; }
	const ItemId& GetId() { return mItemId; }

	// 인벤 진입
	virtual ErrorResult onEnter(CombatObject& owner) { return ErrorResult::Success; }
	// 인벤 제거
	virtual ErrorResult onLeave(CombatObject& owner) { return ErrorResult::Success; }

	// 장비 장착
	virtual ErrorResult onEquip(CombatObject& owner) { return ErrorResult::Success; }
	// 장비 해제
	virtual ErrorResult onUnEquip(CombatObject& owner) { return ErrorResult::Success; }

	// 아이템 사용
	virtual ErrorResult Use(CombatObject& owner) { return ErrorResult::Success; }

private:
	ItemId mItemId;
	ItemCount mCount;

	SharedSkill mSkill;

	List<SharedItemOption> mOptions;
};

class EquipItem
	: public Item
{
public:
	EquipItem() 
		: Item()
	{}

	virtual ~EquipItem() {}

	virtual ErrorResult onEquip(CombatObject& owner) override;
	virtual ErrorResult onUnEquip(CombatObject& owner) override;

private:
};

class ConsumableItem
	: public Item
{
public:
	ConsumableItem() 
		: Item()
	{}
	virtual ~ConsumableItem() {}

	// 아이템 사용
	virtual ErrorResult Use(CombatObject& owner) override;
private:

};

