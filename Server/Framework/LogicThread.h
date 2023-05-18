#pragma once

class LogicThread
	: public Thread
{
public:
	LogicThread() 
		: Thread(ThreadType::Game)
	{}

	virtual ~LogicThread() {}

	void Work() override;

private:
	std::shared_ptr<PacketQueue> mQueue;
};