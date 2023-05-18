#include <Pch.h>

ErrorResult ClientSocket::Connect(DefString ip, Port port)
{
	ErrorResult result = ErrorResult::Success;

	mSocketAddr.sin_family = AF_INET;
	mSocketAddr.sin_port = htons(port);
	InetPtonA(AF_INET, ip.c_str(), &mSocketAddr.sin_addr.s_addr);

	Int32 socket_error = WSAConnect(mSocketId, (struct sockaddr*)&mSocketAddr, sizeof(mSocketAddr), nullptr, nullptr ,nullptr, nullptr);
	if (socket_error == -1)
	{
		socket_error = WSAGetLastError();
	}

	return result;	
}

ErrorResult ClientSocket::Disconnect()
{
	ErrorResult result = ErrorResult::Success;

	return result;
}
