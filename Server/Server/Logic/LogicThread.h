#pragma once


class LogicThread
	: public Thread,
	  public Network::PacketProcessor
{
public:
	LogicThread() 
		: Thread(ThreadType::Game)
	{}

	virtual ~LogicThread() {}

	ErrorResult Initalize();

	virtual ErrorResult Update(DeltaTime delta_time);

	void Work() override;

	void EnqueuePacket(Network::SharedPacket&& packet);

private:
	ErrorResult updatePacket(DeltaTime delta_time);
	ErrorResult updateSector(DeltaTime delta_time);

private:
	UniquePtr<Network::PacketQueue> mQueue;
	List<std::shared_ptr<Sector>> mSectors;
	std::shared_ptr<HandlerManager> mHandlerManager;
};
