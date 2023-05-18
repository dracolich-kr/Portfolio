#pragma once

namespace Lua
{
	class Int64
		: public BaseValue
	{
	public:
		Int64(::Int64 value)
			: BaseValue(ValueType::Int64)
			, mValue(value)
		{
		}

		void Push(lua_State* state) override { lua_pushinteger(state, mValue); }
		void Result(lua_State* state) override { mValue = lua_tointeger(state, -1); }

		const ::Int64 GetValue() { return mValue; }

	private:
		::Int64 mValue;
	};
}