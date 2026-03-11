#pragma once

class ServerSession
	: public Network::Session
{
public:
	ServerSession(SessionIndex idx)
		: Session(idx, Network::SessionType::Server)
	{
	}
	virtual ~ServerSession() {}

private:
	ServerType mServerType;
};
