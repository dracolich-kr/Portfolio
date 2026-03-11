#pragma once

class Monster
	: public CombatObject
{
public:
	Monster() {}
	virtual ~Monster() {}

	virtual ErrorResult InitHFSM() override;

	ErrorResult Update(DeltaTime delta) override;

private:

	HFSM::SharedMachine<StateType, TriggerType> mMachine;

};


