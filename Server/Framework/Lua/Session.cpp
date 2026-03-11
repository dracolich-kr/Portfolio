#include "Pch.h"

namespace Lua
{
	
	ErrorResult Session::Initalize()
	{
		mLuaState = luaL_newstate();

		// 모든 Lua 표준 라이브러리 로드
		luaL_openlibs(mLuaState);
		
		return ErrorResult::Success;
	}

	ErrorResult Session::Close()
	{
		lua_close(mLuaState);

		return ErrorResult::Success;
	}

	ErrorResult Session::RegisterFunc(DefString name, lua_CFunction func)
	{
		lua_register(mLuaState, name.c_str(), func);

		return ErrorResult::Success;
	}

	ErrorResult Session::LoadFile(DefString file_name)
	{

		return ErrorResult::Success;
	}

	ErrorResult Session::LoadBuffer(DefString data)
	{

		return ErrorResult::Success;
	}

	ErrorResult Session::CallFunction(std::shared_ptr<Function> func)
	{
		lua_getglobal(mLuaState, func->GetFuncName().c_str());

		for (auto iter : func->GetParams())
		{
			iter->Push(mLuaState);
		}

		lua_pcall(mLuaState, static_cast<::Int32>(func->GetParamSize()), static_cast<::Int32>(func->GetResultSize()), 0);

		for (auto iter : func->GetParams())
		{
			iter->Result(mLuaState);
			lua_pop(mLuaState, 1);
		}

		return ErrorResult::Success;
	}
}