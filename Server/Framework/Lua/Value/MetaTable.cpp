#include <Pch.h>

namespace Lua
{
	
	template<class T>
	Int32 MetaTable<T>::lua_new(lua_State* L)
	{
		*reinterpret_cast<T**>(lua_newuserdata(L, sizeof(T*))) = new T();
		luaL_setmetatable(L, GetName());
		return 1;
	}

	template<class T>
	Int32 MetaTable<T>::lua_delete(lua_State * L)
	{
		delete* reinterpret_cast<T**>(lua_touserdata(L, 1));
		return 0;
	}

}