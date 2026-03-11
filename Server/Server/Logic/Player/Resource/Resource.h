#pragma once

enum class ResourceType
{
	HP = 0
	// 마나
	, Mana = 1
	// 기력
	, Energy = 2
};

using ResourcePoint = Int32;
class Player;

class Resource abstract
	: public IUpdate
{
public:
	Resource(ResourceType type, Player& player)
		: mType(type)
		, mLoopTick(5000)
		, mPoint(0)
		, mPlayer(player)
	{}
	virtual ~Resource() {}

	virtual ErrorResult Initalize() abstract;

	void SetPoint(ResourcePoint point) { mPoint = point; }
	virtual ResourcePoint GetPoint() abstract;

protected:
	ResourceType mType;
	Player& mPlayer;

	TickTimer mTickTimer;
	Int32 mLoopTick;
	Int32 mPoint;
};

class HealthPointResource
	: public Resource
{
public:
	HealthPointResource(Player& player) :
		Resource(ResourceType::HP, player)
	{}
	virtual ~HealthPointResource() {}

	virtual ErrorResult Initalize() override;
	virtual ErrorResult Update(DeltaTime delta_time) override;
	virtual ResourcePoint GetPoint() override;

private:

};

class ManaResource
	: public Resource
{
public:
	ManaResource(Player& player) :
		Resource(ResourceType::Mana, player)
	{}
	virtual ~ManaResource() {}

	virtual ErrorResult Initalize() override;
	virtual ErrorResult Update(DeltaTime delta_time) override;
	virtual ResourcePoint GetPoint() override;

private:

};

class EnergyResource
	: public Resource
{
public:
	EnergyResource(Player& player) :
		Resource(ResourceType::Energy, player)
	{}
	virtual ~EnergyResource() {}

	virtual ErrorResult Initalize() override;
	virtual ErrorResult Update(DeltaTime delta_time) override;
	virtual ResourcePoint GetPoint() override;

private:

};