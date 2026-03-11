#pragma once

class SessionManager
	: public Singleton<SessionManager>
{
	friend Singleton<SessionManager>;

	SessionManager()
		: mIndex(0)
	{}
public:
	virtual ~SessionManager() {}

	virtual ErrorResult Initalize() override;

	ErrorResult AddUser(Network::SharedISocket socket);
	ErrorResult EraseUser(SessionIndex session_index);

	SharedUserSession GetUserSession(SessionIndex session_index);
	
	SessionIndex GenerateIndex() { return mIndex++; }

private:
	SessionIndex mIndex;

	std::mutex mMutex;
	Map<SessionIndex, std::shared_ptr<UserSession>> mUserSession;
	Map<SessionIndex, std::shared_ptr<ServerSession>> mServerSession;
};