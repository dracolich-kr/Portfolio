
class PacketQueue;

namespace DataBase::ODBC
{
	class DBThread
		: public Thread
	{
	public:
		DBThread()
			: Thread(ThreadType::Game)
			, mQueue(MakeShared<PacketQueue>())
			, mSession(MakeShared<Session>())
		{}

		virtual ~DBThread() {}

		void Work() override;

	private:


	private:
		std::shared_ptr<PacketQueue> mQueue;
		std::shared_ptr<DataBase::ODBC::Session> mSession;

	};
}