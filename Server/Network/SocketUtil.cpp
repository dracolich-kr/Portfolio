#include <Pch.h>

LPFN_ACCEPTEX SocketUtil::AcceptEx = nullptr;
LPFN_GETACCEPTEXSOCKADDRS SocketUtil::GetAcceptExSockaddrs = nullptr;
LPFN_DISCONNECTEX SocketUtil::DisconnectEx = nullptr;
LPFN_TRANSMITFILE SocketUtil::TransmitFile = nullptr;
LPFN_CONNECTEX SocketUtil::ConnectEx = nullptr;

void SocketUtil::Initalize()
{
	GUID guid = WSAID_ACCEPTEX;
	DWORD bytes = 0;

	std::shared_ptr<UserSocket> socket = MakeShared<UserSocket>();
	socket->Open();
	
	SocketResult result = WSAIoctl(socket->GetSocketId(), SIO_GET_EXTENSION_FUNCTION_POINTER,
		&guid, sizeof(guid),
		&SocketUtil::AcceptEx, sizeof(SocketUtil::AcceptEx),
		&bytes, nullptr, nullptr);

	guid = WSAID_GETACCEPTEXSOCKADDRS;
	result = WSAIoctl(socket->GetSocketId(), SIO_GET_EXTENSION_FUNCTION_POINTER,
		&guid, sizeof(guid),
		&SocketUtil::GetAcceptExSockaddrs, sizeof(SocketUtil::GetAcceptExSockaddrs),
		&bytes, nullptr, nullptr);

	guid = WSAID_DISCONNECTEX;
	result = WSAIoctl(socket->GetSocketId(), SIO_GET_EXTENSION_FUNCTION_POINTER,
		&guid, sizeof(guid),
		&SocketUtil::DisconnectEx, sizeof(SocketUtil::DisconnectEx),
		&bytes, nullptr, nullptr);

	guid = WSAID_TRANSMITFILE;
	result = WSAIoctl(socket->GetSocketId(), SIO_GET_EXTENSION_FUNCTION_POINTER,
		&guid, sizeof(guid),
		&SocketUtil::TransmitFile, sizeof(SocketUtil::TransmitFile),
		&bytes, nullptr, nullptr);

	guid = WSAID_CONNECTEX;
	result = WSAIoctl(socket->GetSocketId(), SIO_GET_EXTENSION_FUNCTION_POINTER,
		&guid, sizeof(guid),
		&SocketUtil::ConnectEx, sizeof(SocketUtil::ConnectEx),
		&bytes, nullptr, nullptr);

	socket->Close();
}
