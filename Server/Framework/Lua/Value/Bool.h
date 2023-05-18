#pragma once

namespace Lua
{
	class Bool
		: public BaseValue
	{
	public:
		Bool(::Bool value)
			: BaseValue(ValueType::Bool)
			, mValue(value)
		{
		}

		void Push(lua_State* state) override { lua_pushboolean(state, mValue); }
		void Result(lua_State* state) override { mValue = lua_toboolean(state, -1); }

		const ::Bool GetValue() { return mValue; }

	private:
		::Bool mValue;
	};
}