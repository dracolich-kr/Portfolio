#pragma once

namespace Lua
{
	class Int8
		: public BaseValue
	{
	public:
		Int8(::Int8 value)
			: BaseValue(ValueType::Int8)
			, mValue(value)
		{
		}

		void Push(lua_State* state) override { lua_pushinteger(state, mValue); }
		void Result(lua_State* state) override { mValue = static_cast<::Int8>(lua_tointeger(state, -1)); }

		const ::Int8 GetValue() { return mValue; }

	private:
		::Int8 mValue;
	};
}