#pragma once

class CombatObject;
using ShreadCombatObject = std::shared_ptr<CombatObject>;

enum class EffectLogicType
{
	None = 0
	, Attack
	, AddStat
};

struct EffectParam
{
	ShreadCombatObject Caster = nullptr;
	ShreadCombatObject Target = nullptr;
};

class EffectLogic abstract
{
public:
	EffectLogic(EffectLogicType type) 
		: mType(type)
	{}
	virtual ~EffectLogic() {}

	virtual ErrorResult Initalize();

	virtual ErrorResult onStart(EffectParam param) abstract;
	virtual ErrorResult onEnd(EffectParam param) abstract;

private:
	EffectLogicType mType;
};