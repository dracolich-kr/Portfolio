#include <Pch.h>

namespace Network
{
	void AsioAccept::Listen(Port port)
	{
		asio::ip::tcp::endpoint server_addr(asio::ip::tcp::v6(), port);

		mAcceptor->open(server_addr.protocol());
		mAcceptor->set_option(asio::ip::tcp::acceptor::reuse_address(true));
		mAcceptor->set_option(asio::ip::v6_only(false));
		mAcceptor->bind(server_addr);
		mAcceptor->listen();
	}

	void AsioAccept::Accept(SharedAsioSocket socket)
	{
		socket->Open();
		mAcceptor->async_accept(socket->GetSocket(), std::bind(&AsioAccept::onAccept, this, socket, std::placeholders::_1));
	}

	void AsioAccept::onAccept(SharedAsioSocket socket, const std::error_code& error)
	{
		if (error)
		{
			LOG_ERROR(mLog, L"Accept Fail %d", error.value);
		}
		else
		{
			auto user = SessionManager::GetInstance()->AddUser(socket);
			socket->Read(NetworkBufferSize);
			LOG_ERROR(mLog, "Add User");
		}

		Accept(MakeShared<AsioSocket>(mContext));
	}
}