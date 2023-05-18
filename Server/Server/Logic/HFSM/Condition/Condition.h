#pragma once

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
		Condition(ConditionType type)
			: mType(type)
		{}
		virtual ~Condition() {}

		virtual Bool Check() PURE;

	private:
		ConditionType mType; 
	};

};