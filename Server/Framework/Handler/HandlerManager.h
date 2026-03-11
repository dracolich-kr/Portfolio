#pragma once

class HandlerManager
{
public:
	HandlerManager() {}
	virtual ~HandlerManager() {}

	ErrorResult Initalize();
	ErrorResult ProcessPacket(Network::SharedSession session, Network::SharedPacket packet);

private:
	Map<ProtocolId, SharedHandler> mHandlers;
};