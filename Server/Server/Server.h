#pragma once

class Server
	: public Application
	, public Singleton<Server>
{
private:
	friend Singleton<Server>;
	Server() 
		: Application()
		//, mAccept(MakeShared<AsioAccept>(mAsio.GetContext()))
	{
	}

public:
	virtual ~Server()
	{
	}

	virtual ErrorResult Initalize() override;
	virtual ErrorResult Release() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;

	std::shared_ptr<LogicThread> GetLogicThread() { return mLogicThread; }

	//FlatBufferAllocator* GetAllocator() { return &mAllocator; }
private:
	ErrorResult InitalizeNetwork();
	ErrorResult InitalizeDataBase();

private:
	//Asio mAsio;
	//std::shared_ptr<AsioAccept> mAccept;

	std::shared_ptr<Network::ListenSocket> mListendSocket;
	std::shared_ptr<Network::Iocp> mIocp;
	Network::WSAInitializer mWsaInitializer;

	std::shared_ptr<LogicThread> mLogicThread;
	//FlatBufferAllocator mAllocator;
};