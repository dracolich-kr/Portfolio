#pragma once

namespace Redis
{
	class ClusterSession
		: public Session
	{
	public:
		ClusterSession(DefString ip, Port port) :
			Session(ip, port)
			, mStartSlot(0)
			, mEndSlot(0)
		{}

		virtual ~ClusterSession() {}

		void SetSlot(UInt32 start_slot, UInt32 end_slot) { mStartSlot = start_slot; mEndSlot = end_slot; }

		const UInt32& GetStartSlot() { return mStartSlot; }
		const UInt32& GetEndSlot() { return mEndSlot; }

	private:
		UInt32 mStartSlot;
		UInt32 mEndSlot;
	};

	class Cluster : public Executor
	{
	public:
		Cluster() {}
		virtual ~Cluster() {}

		virtual ErrorResult Connect() override;
		virtual ErrorResult Work(std::shared_ptr<BaseCommand> command) override;

		uint32_t HashSlot(const DefString& str_key);
		std::shared_ptr<ClusterSession> SelectSession(uint32_t hash_key);

	private:
		UInt16 Crc16(const char* data, size_t len);

	private:
		List<std::shared_ptr<ClusterSession>> mSessions;
	};
}