#pragma once

class Player
	: public CombatObject
{
public:
	Player()
	{}
	virtual ~Player() {}

	ErrorResult Initalize() override;
	ErrorResult InitHFSM() override;

	ErrorResult Release() override;

	ErrorResult Update(DeltaTime delta) override;

	void SetSession(Network::SharedSession socket) { mSession = socket; }
	const Network::SharedSession& GetSocket() { return mSession; }

private:
	Network::SharedSession mSession;
	SharedInventory mInventory;

	std::shared_ptr<Resource> mHealthPoint;
	std::shared_ptr<Resource> mResource;

};