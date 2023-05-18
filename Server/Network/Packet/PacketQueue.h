#pragma once

class PacketQueue
{
public:
	PacketQueue() {}
	virtual ~PacketQueue() {}

	bool IsEmpty();

	void Push(std::shared_ptr<Packet> packet);
	std::shared_ptr<Packet> Pop();

private:
	std::mutex mLocker;
	std::list<std::shared_ptr<Packet>> mBuffers;

};