#pragma once

namespace Network
{
	class PacketQueue
	{
	public:
		PacketQueue() {}
		virtual ~PacketQueue() {}

		bool IsEmpty();

		void Push(SharedPacket packet);
		SharedPacket Pop();

	private:
		std::mutex mLocker;
		List<SharedPacket> mBuffers;
	};

	__interface PacketProcessor
	{
	public:
		virtual void EnqueuePacket(SharedPacket packet) PURE;

	};

	using SharedPacketQueue = std::shared_ptr<PacketQueue>;
}