#include <Pch.h>

ErrorResult Client::Initalize()
{
	mSocket = MakeShared<AsioSocket>(mAsio.GetContext());
	mSocket->Open();
	mSocket->Connect("127.0.0.1", 10010);
	mSocket->SetPacketProcessor(this);

	mQueue = MakeShared<PacketQueue>();
	mSession = MakeShared<ClientSession>(0);
	mSession->SetSocket(mSocket);

	mC2SSender = MakeShared<Protocol::C2S::Sender>(mSession);

	mSocket->Read(NetworkBufferSize);

	mReadThread = MakeShared<AsioThread>(mAsio.GetContext());
	mReadThread->SetIndex(ThreadManager::GetInstance()->GenerateIndex());
	mReadThread->Run();

	return ErrorResult::Success;
}

ErrorResult Client::Release()
{
	mSocket->Close();
	return ErrorResult::Success;
}

ErrorResult Client::Update(DeltaTime delta_time)
{
	flatbuffers::FlatBufferBuilder builder(1024, &mAllocator);
	auto rand = MakeShared<Random<Int32>>(100);

	if (rand->GetRand() < 50)
	{
		Common::Vector3 vec(1, 1, 1);
		Common::Vector3 vec2(2, 2, 2);
		Common::Vector3 vec3(3, 3, 3);

		std::vector<Common::Vector3> vecinfo;
		vecinfo.push_back(vec);
		vecinfo.push_back(vec2);
		vecinfo.push_back(vec3);

		std::array<Common::Vector3, 3> info;
		info[0] = vec3;
		info[1] = vec;
		info[2] = vec2;

		flatbuffers::span<Common::Vector3, 3> span(info);
		std::vector<Common::vecPosition> vecPosition;
		vecPosition.push_back(Common::vecPosition(span, 2.0f));

		auto data = Protocol::C2S::CreateReqLoginDirect(builder, 0.005f, &vecinfo, &vecPosition, 0);
		builder.Finish(data);

		auto packet = MakeShared<Packet>();
		packet->GetHeader()->SetPacketSize(builder.GetSize());
		packet->GetHeader()->SetProtocolId(Protocol::C2S::eID_ReqLogin);

		packet->SetPacket(builder.GetBufferPointer(), builder.GetSize());
		mSession->Relay(packet);
	}
	else
	{
		DefString buffer("Hello");
		auto temp = Common::CreateTemp(builder, 2.0f, 3.0f);
		auto test_msg = Protocol::C2S::CreateReqTestMsgDirect(builder, buffer.c_str(), 5, temp);
		builder.Finish(test_msg);

		auto packet = MakeShared<Packet>();
		packet->GetHeader()->SetPacketSize(builder.GetSize());
		packet->GetHeader()->SetProtocolId(Protocol::C2S::eID_ReqTestMsg);

		packet->SetPacket(builder.GetBufferPointer(), builder.GetSize());
		mSocket->Send(packet);
	}

	UpdatePacket();
	return ErrorResult::Success;
}

void Client::UpdatePacket()
{
	while (false == mQueue->IsEmpty())
	{
		auto packet = mQueue->Pop();
		IF_CONTINUE(nullptr == packet);

		switch (packet->GetHeader()->GetProtocolId())
		{
			case Protocol::S2C::eID_AckLogin:
			{
				flatbuffers::Verifier verifier(packet->GetBody(), packet->GetSize());
				auto result = verifier.VerifyBuffer<Protocol::S2C::AckLogin>();
				IF_BREAK(false == result);
				
				auto recvPacket = flatbuffers::GetRoot<Protocol::S2C::AckLogin>(packet->GetBody());
				
				LOG_ERROR_FMT(LogManager::GetInstance()->GetLogger(L"Client"), L"eID_AckLogin : %d %f", recvPacket->a(), recvPacket->vec()->x());
				break;
			}
		default:
			break;
		}

	}
}

ErrorResult Client::Work()
{
	std::chrono::milliseconds ms(1);
	ErrorResult result = ErrorResult::Success;

	DeltaTime delta_time = GetTickCount64();
	DeltaTime end_time = delta_time;

	while (TRUE)
	{
		delta_time = GetTickCount64() - end_time;
		end_time = GetTickCount64();

		result = Update(delta_time);

		std::this_thread::sleep_for(ms);
	}

	return ErrorResult::Success;
}