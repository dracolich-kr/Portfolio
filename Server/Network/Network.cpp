#include <Pch.h>

WSAInitializer::WSAInitializer()
{
	SocketResult result = WSAStartup(MAKEWORD(2, 2), &mWsaData);

	if (result != 0)
		GetError(result);

	SocketUtil::Initalize();
}

WSAInitializer::~WSAInitializer()
{
	WSACleanup();
}