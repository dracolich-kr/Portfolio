#pragma once

class Client : public Application
{
public:
	Client() 
		: Application()
		, mSocket(nullptr)
	{}
	virtual ~Client() {}

	virtual ErrorResult Initalize() override;
	virtual ErrorResult Release() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;

	virtual ErrorResult Work() override;

private:
	WSAInitializer mInit;
	std::shared_ptr<ClientSocket> mSocket;
};