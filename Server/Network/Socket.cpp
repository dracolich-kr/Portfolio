#include <Pch.h>

ErrorResult BSDSocket::Open()
{
	ErrorResult result = ErrorResult::Success;
	mSocketId = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, nullptr, 0, WSA_FLAG_OVERLAPPED);

	if (mSocketId == INVALID_SOCKET)
	{
		Int32 socket_error = WSAGetLastError();
		return ErrorResult::SocketAllocFailed;
	}

	return result;
}

ErrorResult BSDSocket::Close()
{
	ErrorResult result = ErrorResult::Success;

	shutdown(mSocketId, SD_BOTH);

	Int32 socket_error = closesocket(mSocketId);

	return result;
}

ErrorResult BSDSocket::Send(UInt8* buffer, Size size)
{
	ErrorResult result = ErrorResult::Success;

	return result;
}

ErrorResult BSDSocket::Send(Packet* packet)
{
	return Send(packet->GetBuffer(), packet->GetTotalSize());
}

ErrorResult BSDSocket::Read(Size read_bytes)
{
	ErrorResult result = ErrorResult::Success;

	return result;
}
