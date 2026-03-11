#pragma once

class EntityManager
	: public IUpdate
{
public:
	EntityManager() {}
	virtual ~EntityManager() {}

	ErrorResult Initalize();
	ErrorResult Update(DeltaTime delta_time) override;

	ErrorResult AddEntity(SharedCombatObject entity);
	ErrorResult EraseEntity(EntityId entity_id);

private:
	Map<EntityId, SharedCombatObject> mCombatObjects;
};

using SharedEntityManager = std::shared_ptr<EntityManager>;