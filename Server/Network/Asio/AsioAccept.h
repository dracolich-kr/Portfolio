#pragma once

class AsioAccept
{
public:
	AsioAccept(std::shared_ptr<asio::io_context> context)
		: mContext(context)
		, mAcceptor(std::make_shared<asio::ip::tcp::acceptor>(*context))
	{
	}

	virtual ~AsioAccept() {}

	void Listen(UINT16 port);
	void Accept(AsioSocket* session);

private:
	void callbackAccept(AsioSocket* session, const std::error_code& error);

private:
	std::shared_ptr<asio::ip::tcp::acceptor> mAcceptor;
	std::shared_ptr<asio::io_context> mContext;
};