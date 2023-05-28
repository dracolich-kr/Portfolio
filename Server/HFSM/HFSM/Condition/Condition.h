#pragma once

class CombatObject;

namespace HFSM
{
	enum class ConditionType
	{
		None = 0
		, HPMin = 1
		, HPMax = 2
		, WaitTime = 3

	};

	class Condition abstract
	{
	public:
		Condition(ConditionType type, std::shared_ptr<CombatObject> combat_object)
			: mType(type)
			, mCombatObject(combat_object)
		{}
		virtual ~Condition() {}

		// 컨디션 체크 유무
		virtual Bool Check() abstract;
		
		std::shared_ptr<CombatObject> GetCombatObject() { return mCombatObject; }

	private:
		ConditionType mType; 
		std::shared_ptr<CombatObject> mCombatObject;
	};


	class HpMinCondition
		: public Condition
	{
	public:
		HpMinCondition(std::shared_ptr<CombatObject> combat_object)
			: Condition(ConditionType::HPMin, combat_object)
		{} 

		bool Check() override;
	private:
		
	};

	class HpMaxCondition
		: public Condition
	{
	public:
		HpMaxCondition(std::shared_ptr<CombatObject> combat_object)
			: Condition(ConditionType::HPMax, combat_object)
		{}

		bool Check() override;
	private:

	};

	class WaitTimeCondition
		: public Condition
	{
	public:
		WaitTimeCondition(std::shared_ptr<CombatObject> combat_object)
			: Condition(ConditionType::WaitTime, combat_object)
		{}

		bool Check() override;
	private:

	};
};