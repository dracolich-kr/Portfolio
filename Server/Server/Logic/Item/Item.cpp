#include <Pch.h>

void Item::Release()
{
	mOptions.clear();
}

ErrorResult EquipItem::onEquip(CombatObject& owner)
{
	Item::onEquip(owner);

	return ErrorResult::Success;
}

ErrorResult EquipItem::onUnEquip(CombatObject& owner)
{
	Item::onUnEquip(owner);

	return ErrorResult::Success;
}