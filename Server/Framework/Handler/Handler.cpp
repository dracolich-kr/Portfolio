#include <Pch.h>


ErrorResult C2SReqLoginHandler::Prepare(Network::SharedSession session, Network::SharedPacket packet)
{
	return ErrorResult::Success;
}

ErrorResult C2SReqLoginHandler::Process(Network::SharedSession session, Network::SharedPacket packet)
{
	return ErrorResult::Success;
}

ErrorResult C2SReqLoginHandler::Finish(Network::SharedSession session, Network::SharedPacket packet)
{
	return ErrorResult::Success;
}

ErrorResult C2STestmsgHandler::Prepare(Network::SharedSession session, Network::SharedPacket packet)
{
	auto recvPacket = GetHandle<Protocol::C2S::ReqTestMsg>(packet);

	return ErrorResult::Success;
}

ErrorResult C2STestmsgHandler::Process(Network::SharedSession session, Network::SharedPacket packet)
{
	auto recvPacket = GetHandle<Protocol::C2S::ReqTestMsg>(packet);
	FlatBufferAllocator allocator;
	LOG_ERROR_FMT(LogManager::GetInstance()->GetLogger("Handler"), L"eID_ReqTestMsg : %s %d", toWString(recvPacket->str()->c_str()).c_str(), recvPacket->a());
	flatbuffers::FlatBufferBuilder builder(1024, &allocator);

	Common::Vector3 vec(1, 1, 1);
	auto data = Protocol::S2C::CreateAckLogin(builder, 100, &vec);
	builder.Finish(data);

	auto sendPacket = MakeShared<Network::Packet>();
	sendPacket->GetHeader()->SetPacketSize(builder.GetSize());
	sendPacket->GetHeader()->SetProtocolId(Protocol::S2C::eID_AckLogin);
	sendPacket->SetPacket(builder.GetBufferPointer(), builder.GetSize());

	session->Relay(sendPacket);
	return ErrorResult::Success;
}

ErrorResult C2STestmsgHandler::Finish(Network::SharedSession session, Network::SharedPacket packet)
{
	return ErrorResult::Success;
}

