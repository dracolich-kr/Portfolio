#pragma once

namespace Lua
{
	class Int32
		: public BaseValue
	{
	public:
		Int32(::Int32 value)
			: BaseValue(ValueType::Int32)
			, mValue(value)
		{
		}

		void Push(lua_State* state) override { lua_pushinteger(state, mValue); }
		void Result(lua_State* state) override { mValue = static_cast<::Int32>(lua_tointeger(state, -1)); }
		
		const ::Int32 GetValue() { return mValue; }

	private:
		::Int32 mValue;
	};
}