#include <Pch.h>

ErrorResult HandlerManager::Initalize()
{
	mHandlers.emplace(Protocol::C2S::eID_ReqLogin, new C2SReqLoginHandler());
	mHandlers.emplace(Protocol::C2S::eID_ReqTestMsg, new C2STestmsgHandler());

	return ErrorResult::Success;
}

ErrorResult HandlerManager::ProcessPacket(Network::SharedSession session, Network::SharedPacket packet)
{
	auto handler = mHandlers.find(packet->GetHeader()->GetProtocolId());
	IF_RETURN(handler == mHandlers.end(), ErrorResult::Failed);

	try 
	{
		ErrorResult result = handler->second->Prepare(session, packet);

		if (result == ErrorResult::Success)
			result = handler->second->Process(session, packet);

		handler->second->Finish(session, packet);
	}
	catch (...)
	{

	}

	return ErrorResult::Success;
}