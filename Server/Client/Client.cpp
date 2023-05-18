#include <Pch.h>

ErrorResult Client::Initalize()
{
	mSocket = std::make_shared<ClientSocket>();
	mSocket->Open();
	mSocket->Connect("127.0.0.1", 10010);

	return ErrorResult::Success;
}

ErrorResult Client::Release()
{
	mSocket->Close();
	return ErrorResult::Success;
}

ErrorResult Client::Update(DeltaTime delta_time)
{

	return ErrorResult::Success;
}

ErrorResult Client::Work()
{

	return ErrorResult::Success;
}