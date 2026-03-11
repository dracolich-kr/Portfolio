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
	, public IInitalize
	, public IRelease
{
public:
	Entity()
		: mId(0)
		, mType(EntityType::None)
		, mPosition()
		, mLookAt(0.0F)
	{}
	virtual ~Entity() {}

	virtual ErrorResult Initalize() override;
	virtual ErrorResult Release() override;

	const EntityId GetId() { return mId; }
	
	void SetType(EntityType type) { mType = type; }
	const EntityType GetType() { return mType; }

	virtual ErrorResult Update(DeltaTime delta) override;

private:
	EntityId mId;
	EntityType mType;

	Common::Vector3 mPosition;
	Float mLookAt;

};

