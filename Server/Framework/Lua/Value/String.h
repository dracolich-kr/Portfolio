#pragma once

namespace Lua
{
	class String
		: public BaseValue
	{
	public:
		String(::DefString value)
			: BaseValue(ValueType::String)
			, mValue(value)
		{
		}

		void Push(lua_State* state) override { lua_pushstring(state, mValue.c_str()); }
		void Result(lua_State* state) override { mValue = lua_tostring(state, -1); }

		const ::DefString GetValue() { return mValue; }

	private:
		::DefString mValue;
	};
}