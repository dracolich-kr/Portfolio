#pragma once

namespace Lua
{
	using ResultCount = Int32;

	// Lua ÀÎÀÚ °ª
	enum class ValueType
	{
		Bool
		, Int8
		, Int16
		, Int32
		, Int64
		, Float
		, Double
		, String
		, Table
	};

	class BaseValue
	{
	public:
		BaseValue(ValueType type) 
			: mType(type)
		{}

		virtual void Push(lua_State* state) PURE;
		virtual void Result(lua_State* state) PURE;

	private:
		ValueType mType;
	};
}