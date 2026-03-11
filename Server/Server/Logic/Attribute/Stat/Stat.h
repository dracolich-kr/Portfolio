#pragma once

enum class StatType : Int32
{
	None = 0
	, Str = 0
	, Dex
	, Int
	, Wis
	, Dameage
	, MaxHealthPoint
	, MaxManaPoint
	, MaxEnergyPoint
	, HealthPointRegen
	, ManaPointRegen
	, EnergyPointRegen
	, Defensive
	, HitPoint
	, Max
};

enum class ValueType
{
	None = 0
	, Int = 1
	, Float = 2
};

class Stat
	: public ICustomMemory
{
public:
	Stat(StatType type)
		: mType(type)
		, mIntValue(0)
		, mFloatValue(0.0F)
		, mValueType(ValueType::None)
	{}

	virtual ~Stat() {}

	void Clear() { mIntValue = 0; mFloatValue = 0; }

	void Set(Int32 value) { mIntValue = value; }
	void Set(Float value) { mFloatValue = value; }

	void Add(Int32 value) { mIntValue += value; }
	void Add(Float value) { mFloatValue += value; }

	void Sub(Int32 value) { mIntValue -= value; }
	void Sub(Float value) { mFloatValue -= value; }

	Int32 GetInt() const { return mIntValue; }
	Float GetFloat() const { return mFloatValue; }

	StatType GetType() const { return mType; }

	void SetValueType(const ValueType type) { mValueType = type; }
	ValueType GetValueType() const { return mValueType; }

private:
	StatType mType;
	ValueType mValueType;
	Int32 mIntValue;
	Float mFloatValue;

};

