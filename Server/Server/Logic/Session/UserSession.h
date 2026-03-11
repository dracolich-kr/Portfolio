#pragma once

class UserSession 
	: public Network::Session
{
public:
	UserSession(SessionIndex index)
		: Session(index, Network::SessionType::User)
		, mLogicThreadIndex(0)
		, mDataBaseThreadIndex(0)
	{}
	virtual ~UserSession() {}

	void SetLogicThreadIndex(Int32 thread_index) { mLogicThreadIndex = thread_index; }
	Int32 GetLogicThreadIndex() { return mLogicThreadIndex; }

	void SetDataBaseThreadIndex(Int32 thread_index) { mDataBaseThreadIndex = thread_index; }
	Int32 GetDataBaseThreadIndex() { return mDataBaseThreadIndex; }

private:
	Int32 mLogicThreadIndex;
	Int32 mDataBaseThreadIndex;
};

using SharedUserSession = std::shared_ptr<UserSession>;