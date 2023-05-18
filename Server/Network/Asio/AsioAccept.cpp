#include <Pch.h>

void AsioAccept::Listen(UINT16 port)
{
	asio::ip::tcp::endpoint server_addr(asio::ip::tcp::v6(), port);

	mAcceptor->open(server_addr.protocol());
	mAcceptor->set_option(asio::ip::tcp::acceptor::reuse_address(true));
	mAcceptor->set_option(asio::ip::v6_only(false));
	mAcceptor->bind(server_addr);
	mAcceptor->listen();
}

void AsioAccept::Accept(AsioSocket* socket)
{
	mAcceptor->async_accept(socket->GetSocket(), bind(&AsioAccept::callbackAccept, this, socket, std::placeholders::_1));
}

void AsioAccept::callbackAccept(AsioSocket* socket, const std::error_code& error)
{
	if (!error)
	{
		//session->onConnect();
	}
	else
	{
		std::cout << error.message() << std::endl;
		//delete session;
	}

	Accept(new AsioSocket(mContext));
}
