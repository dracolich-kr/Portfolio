#pragma once

namespace Lua
{
	static DefString getClassName(const char* fullFuncName)
	{
		DefString fullFuncNameStr(fullFuncName);
		size_t pos = fullFuncNameStr.find_last_of("::");
		if (pos == DefString::npos)
		{
			return "";
		}
		return fullFuncNameStr.substr(0, pos - 1);
	}

	#define __CLASS__ getClassName(__FUNCTION__)

	enum class LuaAllocType
	{
		// 할당으로 처리 [lua에서 할당한거라 Delete 해야함]
		Alloc
		// 공유로 처리 [빌려온거라 프로그램에서 해제]
		, Shared
	};

	template<class T>
	class MetaTable
	{
	public:
		MetaTable(lua_State* state)
			: mState(state)
			, mName(__CLASS__)
			, mType(LuaAllocType::Alloc)
		{}
		virtual ~MetaTable() {}

		virtual void Initalize() PURE;

		const DefString GetName() { return mName; }

	private:
		static Int32 lua_new(lua_State* L);
		static Int32 lua_delete(lua_State* L);

	private:
		lua_State* mState;
		DefString mName;
		LuaAllocType mType;
	};
}