#include <Pch.h>

UserSocket::UserSocket()
{
	mRecevieBuffer = MakeShared<ReceiveBuffer>();
}

ErrorResult UserSocket::Open()
{
	ErrorResult result = ErrorResult::Success;
	
	mSocketId = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, nullptr, 0, WSA_FLAG_OVERLAPPED);
	if (mSocketId == INVALID_SOCKET)
	{
		SocketResult socket_result = WSAGetLastError();
		return ErrorResult::SocketFailed;
	}

	return ErrorResult::Success;
}

ErrorResult UserSocket::Close()
{
	shutdown(mSocketId, SD_BOTH);
	SocketResult result = closesocket(mSocketId);

	return ErrorResult::Success;
}

ErrorResult UserSocket::Connect(DefString ip, Port port)
{
	ErrorResult result = ErrorResult::Success;

	auto overapped = new IocpConnectOverlapped;
	overapped->Socket = shared_from_this();

	SOCKADDR_IN addr;
	ZeroMemory(&addr, sizeof(addr));

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = 0;

	SocketResult socket_error = bind(GetSocketId(), (SOCKADDR*)&addr, sizeof(addr));
	if (socket_error != 0)
	{
		socket_error = WSAGetLastError();

		printf("bind failed: %d\n", result);
		return ErrorResult::SocketAllocFailed;
	}

	ZeroMemory(&mSocketAddr, sizeof(mSocketAddr));
	mSocketAddr.sin_family = AF_INET;
	InetPtonA(AF_INET, ip.c_str(), &mSocketAddr.sin_addr.s_addr);
	mSocketAddr.sin_port = htons(port);

	if (false == SocketUtil::ConnectEx(GetSocketId(), (SOCKADDR*)&addr, sizeof(addr), nullptr, 0, nullptr, overapped))
	{
		socket_error = WSAGetLastError();
		switch (socket_error)
		{
		case WSA_IO_PENDING:
			break;
		default:
			printf("error : %d\n", result);
			break;
		}
	}

	return ErrorResult::Success;
}

ErrorResult UserSocket::Disconnect()
{
	IocpDisconnectOverlapped* overapped = new IocpDisconnectOverlapped;//New<IocpDisconnectOverlapped>();
	overapped->Socket = shared_from_this();

	if (false == SocketUtil::DisconnectEx(mSocketId, overapped, TF_REUSE_SOCKET, 0))
	{
		SocketResult socket_error = WSAGetLastError();
		if (socket_error != WSA_IO_PENDING)
		{
			return ErrorResult::SocketFailed;
		}
	}

	return ErrorResult::Success;
}


ErrorResult UserSocket::Send(UInt8* buffer, Size size)
{
	return BSDSocket::Send(buffer, size);
}

ErrorResult UserSocket::Send(Packet* packet)
{
	return BSDSocket::Send(packet);
}

ErrorResult UserSocket::Read(Size read_bytes)
{
	return BSDSocket::Read(read_bytes);
}