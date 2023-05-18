#pragma once

class Server
	: public Application
{
public:
	Server() 
		: Application()
		, mIocp(std::make_shared<Iocp>())
		, mListen(std::make_shared<ListenSocket>())
	{
	}

	virtual ~Server()
	{
	}

	virtual ErrorResult Initalize() override;
	virtual ErrorResult Release() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;

private:
	ErrorResult InitalizeNetwork();
	ErrorResult InitalizeDataBase();
private:
	WSAInitializer mInit;

	std::shared_ptr<Iocp> mIocp;
	std::shared_ptr<ListenSocket> mListen;

};