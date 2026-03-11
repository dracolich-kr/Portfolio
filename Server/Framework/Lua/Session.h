#pragma once

namespace Lua
{

	class Session
	{
	public:
		Session() {}
		virtual ~Session() {}

		ErrorResult Initalize();
		ErrorResult Close();

		ErrorResult LoadFile(DefString file_name);
		ErrorResult LoadBuffer(DefString data);

		// 루아 함수 호출
		ErrorResult CallFunction(std::shared_ptr<Function> func);

		// 루아에 C++ 함수 등록 static 함수 회피에 대해 고민이 된다. ㅁ=
		ErrorResult RegisterFunc(DefString name, lua_CFunction func);
		ErrorResult RegisterTable(DefString name);
		
	private:
		lua_State* mLuaState = nullptr;
	};
}

