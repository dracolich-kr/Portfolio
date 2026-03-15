

namespace DataBase::ODBC
{
	class DBThread
		: public Thread
	{
	public:
		DBThread()
			: Thread(ThreadType::Game)
			, mQueue(MakeUnique<Network::PacketQueue>())
			, mSession(MakeShared<Session>())
		{}

		virtual ~DBThread() {}

		void Work() override;

		void Push(Network::SharedPacket&& packet);

	private:
		UniquePtr<Network::PacketQueue> mQueue;
		std::shared_ptr<DataBase::ODBC::Session> mSession;

	};
}