#include <Pch.h>

namespace Network
{
	Socket::Socket()
	{
		mReceivedBuffer = MakeShared<NetworkBuffer>();
		mReceivedBuffer->Initalize(PacketMaxBuffer);
		mSendBuffer = MakeShared<NetworkBuffer>();
		mSendBuffer->Initalize(PacketMaxBuffer);
		mPacketProcessor = nullptr;
	}

	Socket::~Socket()
	{
		Close();
	}

	ErrorResult Socket::Open()
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

	ErrorResult Socket::Close()
	{
		IF_RETURN(mSocketId == 0, ErrorResult::Success);

		shutdown(mSocketId, SD_BOTH);
		SocketResult result = closesocket(mSocketId);
		if (result != 0)
		{
			Int32 socketError = WSAGetLastError();
			switch (socketError)
			{
			case WSA_IO_PENDING:
				break;
			default:
				LOG_ERROR_FMT(mLog, L"%d", result);
				break;
			}
		}

		mSocketId = 0;

		return ErrorResult::Success;
	}

	ErrorResult Socket::Connect(DefString ip, Port port)
	{
		ErrorResult result = ErrorResult::Success;

		auto overapped = new IocpConnectOverlapped;
		overapped->Socket = shared_from_this();

		SOCKADDR_IN addr;
		ZeroMemory(&addr, sizeof(addr));

		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = INADDR_ANY;
		addr.sin_port = 0;

		SocketResult socketError = bind(GetSocketId(), (SOCKADDR*)&addr, sizeof(addr));
		if (socketError != 0)
		{
			socketError = WSAGetLastError();

			LOG_ERROR_FMT(mLog, L"%d", result);
			return ErrorResult::SocketAllocFailed;
		}

		ZeroMemory(&mSocketAddr, sizeof(mSocketAddr));
		mSocketAddr.sin_family = AF_INET;
		InetPtonA(AF_INET, ip.c_str(), &mSocketAddr.sin_addr.s_addr);
		mSocketAddr.sin_port = htons(port);

		if (false == SocketUtil::ConnectEx(GetSocketId(), (SOCKADDR*)&addr, sizeof(addr), nullptr, 0, nullptr, overapped))
		{
			socketError = WSAGetLastError();
			switch (socketError)
			{
			case WSA_IO_PENDING:
				break;
			default:
				LOG_ERROR_FMT(mLog, L"%d", result);
				break;
			}
		}

		return ErrorResult::Success;
	}

	ErrorResult Socket::Disconnect()
	{
		IocpDisconnectOverlapped* overapped = new IocpDisconnectOverlapped;
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

	ErrorResult Socket::RegisterReceived()
	{
		DWORD receiveLen;
		DWORD flags = 0;

		IocpReadOverlapped* overapped = new IocpReadOverlapped;
		overapped->Socket = shared_from_this();
		overapped->Buffer.buf = (char*)mReceivedBuffer->GetTail();
		overapped->Buffer.len = mReceivedBuffer->GetBufferSize() - mReceivedBuffer->GetTailPos();

		if (SOCKET_ERROR == WSARecv(GetSocketId(), &overapped->Buffer, 1, &receiveLen, &flags, overapped, nullptr))
		{
			SocketResult socket_error = WSAGetLastError();
			if (socket_error != WSA_IO_PENDING)
			{
				LOG_ERROR_FMT(mLog, L"RegisterReceived Socket Failed : %d", socket_error);
				return ErrorResult::SocketFailed;
			}
		}

		return ErrorResult::Success;
	}

	ErrorResult Socket::Send(UInt8 * buffer, Size size)
	{
		IocpSendOverlapped* overapped = new IocpSendOverlapped;
		overapped->Socket = shared_from_this();
		overapped->SendBuffer = MakeShared<NetworkBuffer>();
		overapped->SendBuffer->Initalize(size);
		overapped->Buffer.len = size;
		overapped->SendBuffer->Push(buffer, size);
		overapped->Buffer.buf = (CHAR*)overapped->SendBuffer->GetTail();

		if (SOCKET_ERROR != WSASend(GetSocketId(), &overapped->Buffer, 1, nullptr, 0, overapped, nullptr))
		{
			SocketResult socket_error = WSAGetLastError();
			if (socket_error != WSA_IO_PENDING)
			{
				LOG_ERROR_FMT(mLog, L"Socket Failed : %d", socket_error);
				return ErrorResult::SocketFailed;
			}
		}

		return ErrorResult::Success;
	}

	ErrorResult Socket::Send(SharedPacket packet)
	{
		IocpSendOverlapped* overapped = new IocpSendOverlapped;
		overapped->Socket = shared_from_this();
		overapped->SendBuffer = MakeShared<NetworkBuffer>();
		overapped->SendBuffer->Initalize(packet->GetTotalSize());
		overapped->Buffer.buf = (CHAR*)overapped->SendBuffer->GetTail();
		overapped->Buffer.len = packet->GetTotalSize();
		overapped->SendBuffer->Push(packet->GetBuffer(), packet->GetTotalSize());

		LOG_ERROR_FMT(mLog, L"SendBuffer : %d", packet->GetTotalSize());

		if (SOCKET_ERROR != WSASend(GetSocketId(), &overapped->Buffer, 1, nullptr, 0, overapped, nullptr))
		{
			SocketResult socket_error = WSAGetLastError();
			if (socket_error != WSA_IO_PENDING)
			{
				LOG_ERROR_FMT(mLog, L"Socket Failed : %d", socket_error);
				return ErrorResult::SocketFailed;
			}
		}

		return BSDSocket::Send(packet);
	}

	ErrorResult Socket::Read(Size read_bytes)
	{

		return BSDSocket::Read(read_bytes);
	}
}