#pragma once

namespace Lua
{
	class Int16
		: public BaseValue
	{
	public:
		Int16(::Int16 value)
			: BaseValue(ValueType::Int16)
			, mValue(value)
		{
		}

		void Push(lua_State* state) override { lua_pushinteger(state, mValue); }
		void Result(lua_State* state) override { mValue = static_cast<::Int16>(lua_tointeger(state, -1)); }

		const ::Int16 GetValue() { return mValue; }

	private:
		::Int16 mValue;
	};
}