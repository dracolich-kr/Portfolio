#include "Pch.h"

using namespace std::literals;

using StringList2 = std::list<DefString, Allocator<DefString>>;

class SqlCustomData
{
public:
	SqlCustomData()
		: mAccount(1)
		, mName(2, 256)
		, mLoginAt(3)
	{
	}

	DataBase::ODBC::SqlInt32 mAccount;
	DataBase::ODBC::SqlWString mName;
	DataBase::ODBC::SqlDateTime mLoginAt;
};

class CustomData
{
public:
	Int32 mAccount = 0;
	DefWString mName = L"";
	DateTime mLoginAt = DateTime();
};

class CustomResult : public DataBase::ODBC::Result
{
public:
	CustomResult(DataBase::ODBC::SharedQuery query)
		: Result(query)
	{}

	virtual ~CustomResult()
	{}

	virtual ErrorResult Bind() override
	{
		mSqlData.mAccount.onBindCol(mQuery->GetStmt());
		mSqlData.mName.onBindCol(mQuery->GetStmt());
		mSqlData.mLoginAt.onBindCol(mQuery->GetStmt());

		return ErrorResult::Success;
	}

	virtual ErrorResult Fetch() override
	{
		std::shared_ptr<CustomData> result = MakeShared<CustomData>();
		result->mAccount = mSqlData.mAccount.GetValue();
		result->mName = mSqlData.mName.GetValue().c_str();
		result->mLoginAt = mSqlData.mLoginAt.GetValue();

		mResults.push_back(result);

		return ErrorResult::Success;
	}

private:
	SqlCustomData mSqlData;
	List<std::shared_ptr<CustomData>> mResults;
};

class CustomCommand : public DataBase::ODBC::Command
{
public:
	CustomCommand(DataBase::ODBC::SharedQuery query)
		: Command(query)
	{}

	virtual ~CustomCommand()
	{}

	virtual ErrorResult Prepare() override
	{
		BindParam(SQL_PARAM_INPUT, mAccountNo);
		return ErrorResult::Success;
	}

	void SetAccountNo(Int32 account_no)
	{
		mAccountNo = account_no;
	}

private:
	Int32 mAccountNo = 0;
};


class CustomQuery : public DataBase::ODBC::Query
					, std::enable_shared_from_this<CustomQuery>
{
public:
	virtual ErrorResult Initalize(DataBase::ODBC::SharedSession session)
	{
		ErrorResult result = DataBase::ODBC::Query::Initalize(session);

		mCommand = MakeShared<CustomCommand>(shared_from_this());
		mCommand->Init(L"{CALL dbo.GetAccount(?)}");

		mResults.push_back(MakeShared<CustomResult>(shared_from_this()));

		return result;
	}
	virtual ErrorResult Release()
	{
		ErrorResult result = DataBase::ODBC::Query::Release();

		return result;
	}
};

Int32 main(Int32 argc, Char* argv[])
{
	// 사용할려면 무조건 최초로 호출 하자.
	MemoryPool::GetInstance()->Initalize();
	LogManager::GetInstance()->Initalize();

	auto logger = LogManager::GetInstance()->GetLogger(L"main");

	//std::chrono::milliseconds ms(10);
	//while(1)
	//{
	//	auto elem = LoadManager::GetInstance()->GetItemElem(2);
	//	Player player;
	//	{
	//		//std::shared_ptr<Sector> sector = MakeShared<Sector>();
	//		//sector->Initalize();
	//
	//		SharedSkill skill = MakeShared<Skill>(player);
	//		skill->Initalize();
	//	}
	//
	//	std::this_thread::sleep_for(ms);
	//}

	//Lua::MetaTable temp(nullptr);
	//SectorScript script(nullptr);
	//LOG_DEBUG_FMT(logger, L"Hello %s %d %s", L"ghhhh", 1, script.GetName());
	//
	//DefString cmd = R"(a={}a["CC"] = {["B"]=1,["C"]=20 }
	//	a["bb"] = {["B"]=20,["C"]=1 })";
	//lua_State* L = luaL_newstate();
	//
	//int r = luaL_dostring(L, cmd.c_str());
	//
	//if (r == LUA_OK)
	//{
	//	lua_getglobal(L, "a");
	//
	//	if (lua_isnumber(L, -1))
	//	{
	//		float _result = (float)lua_tonumber(L, -1);
	//		LOG_DEBUG_FMT(logger, L"%d", _result);
	//	}
	//	else if(lua_istable(L, -1))
	//	{
	//		LOG_DEBUG_FMT(logger, L"dd = %d", lua_gettop(L));
	//		lua_pushnil(L);
	//
	//		while (lua_next(L, -2) != 0)
	//		{
	//			auto type = lua_type(L, -1);
	//			auto key = lua_tostring(L, -2);
	//
	//			lua_pushnil(L);
	//			while (lua_next(L, -2) != 0)
	//			{
	//				auto type = lua_type(L, -1);
	//				auto key = lua_tostring(L, -2);
	//				auto value = lua_tointeger(L, -1);
	//
	//				LOG_DEBUG_FMT(logger, L":: {%d}", value);
	//				lua_pop(L, 1);
	//			}
	//
	//			lua_pop(L, 1);
	//		}
	//	}
	//}
	//else
	//{
	//	DefString message = lua_tostring(L, -1);
	//	LOG_DEBUG_FMT(logger, L"%s", message.c_str());
	//}

	//DataBase::ODBC::SharedSession session = MakeShared<DataBase::ODBC::Session>();
	//session->Init();
	//session->Connect(L"Auth", L"127.0.0.1", 1433, L"Test", L"1234");
	//
	//CustomQuery query;
	//query.Initalize(session);
	//query.Execute();

	//DataBase::ODBC::SharedQuery my_query = MakeShared<DataBase::ODBC::Query>();
	//my_query->Initalize(session);

	//std::shared_ptr<Server> server = MakeShared<Server>();
	//
	// 
	
	// 싱글톤 객체는 생성할때 자동으로 초기화 한다.
	//Server::GetInstance()->Initalize();
	Server::GetInstance()->Work();
	Server::GetInstance()->Release();
	return 0;
}