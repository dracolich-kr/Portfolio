#pragma once

class EntityManager
	: public IUpdate
{
public:
	EntityManager() {}
	virtual ~EntityManager() {}
	
	ErrorResult Update(DeltaTime delta) override;

private:
	Map<EntityId, CombatObject> mCombatObjects;
};
