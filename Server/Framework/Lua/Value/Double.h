#pragma once

namespace Lua
{
	class Double
		: public BaseValue
	{
	public:
		Double(::Double value)
			: BaseValue(ValueType::Double)
			, mValue(value)
		{}

		void Push(lua_State* state) override { lua_pushnumber(state, mValue); }
		void Result(lua_State* state) override { mValue = lua_tonumber(state, -1); }

		const ::Double GetValue() { return mValue; }

	private:
		::Double mValue;
	};
}