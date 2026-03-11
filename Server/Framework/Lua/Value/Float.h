#pragma once

namespace Lua
{
	class Float
		: public Lua::BaseValue
	{
	public:
		Float(::Float value)
			: BaseValue(ValueType::Float)
			, mValue(value)
		{}

		void Push(lua_State* state) override { lua_pushnumber(state, mValue); }
		void Result(lua_State* state) override { mValue = static_cast<::Float>(lua_tonumber(state, -1)); }

		const ::Float GetValue() { return mValue; }

	private:
		::Float mValue;
	};
}