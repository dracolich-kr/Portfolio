#pragma once

enum class EntityType : Int32
{
	None
	, Player
	, Monster
	, Npc
};

class Entity
	: public IUpdate
{
public:
	Entity()
		: mId(0)
	{}
	virtual ~Entity() {}

	const EntityId GetId() { return mId; }
	
	void SetType(EntityType type) { mType = type; }
	const EntityType GetType() { return mType; }

	ErrorResult Update(DeltaTime delta) override;

private:
	EntityId mId;
	EntityType mType;

	Common::Vector3 mPosition;
	Float mLookAt;

};