#pragma once
namespace Network
{
	class AsioAccept
	{
	public:
		AsioAccept(std::shared_ptr<asio::io_context> context)
			: mContext(context)
			, mAcceptor(std::make_shared<asio::ip::tcp::acceptor>(*context))
		{
		}

		virtual ~AsioAccept() {}

		void Listen(Port port);
		void Accept(SharedAsioSocket session);

	private:
		void onAccept(SharedAsioSocket session, const std::error_code& error);

	private:
		std::shared_ptr<asio::ip::tcp::acceptor> mAcceptor;
		std::shared_ptr<asio::io_context> mContext;

		log4cplus::Logger mLog = LogManager::GetInstance()->GetLogger("Asio");
	};
}