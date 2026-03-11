#include <Pch.h>

namespace Network
{
	ErrorResult BSDSocket::Open()
	{
		ErrorResult result = ErrorResult::Success;
		mSocketId = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, nullptr, 0, 0);

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
		if (socket_error == INVALID_SOCKET)
		{
			Int32 socket_error = WSAGetLastError();
			return ErrorResult::SocketAllocFailed;
		}

		return result;
	}

	ErrorResult BSDSocket::Connect(DefString ip_address, Port port)
	{
		ErrorResult result = ErrorResult::Success;

		return result;
	}


	ErrorResult BSDSocket::Send(UInt8* buffer, Size size)
	{
		ErrorResult result = ErrorResult::Success;
		return result;
	}

	ErrorResult BSDSocket::Send(SharedPacket packet)
	{
		return Send(packet->GetBuffer(), packet->GetTotalSize());
	}

	ErrorResult BSDSocket::Read(Size read_bytes)
	{
		ErrorResult result = ErrorResult::Success;

		return result;
	}
}