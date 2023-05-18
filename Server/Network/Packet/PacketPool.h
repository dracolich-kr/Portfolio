#pragma once

class PacketPool
	: Singleton<PacketPool>
{
	PacketPool() {};
	friend Singleton<PacketPool>;

public:
	virtual ~PacketPool() {}

	Packet* Pop();
	void Push(Packet* push);

private:
	//ObjectPool<Packet> m_packet_pool;
};