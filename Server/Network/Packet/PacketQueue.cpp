#include <Pch.h>
namespace Network
{
	bool PacketQueue::IsEmpty()
	{
		std::scoped_lock<std::mutex> lock(mLocker);
		return mBuffers.size() == 0;
	}

	void PacketQueue::Push(std::shared_ptr<Packet> packet)
	{
		std::scoped_lock<std::mutex> lock(mLocker);
		mBuffers.push_back(packet);
	}

	std::shared_ptr<Packet> PacketQueue::Pop()
	{
		if (IsEmpty())
			return nullptr;

		std::shared_ptr<Packet> temp = nullptr;

		{
			std::scoped_lock<std::mutex> lock(mLocker);
			temp = mBuffers.front();
			mBuffers.pop_front();
		}

		return temp;
	}
}