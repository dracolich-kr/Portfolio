#include <Pch.h>
namespace Network
{
	void IocpAcceptOverlapped::Reuse()
	{
		ZeroMemory(Buffer, ACCEPT_ADDR_LEN);
		Socket = ListenSocket->GetSockets().AcquireObject();
		Socket->Open();

		ListenSocket->Accept(Socket, this);
	}

	void IocpAcceptOverlapped::OnWork(DWORD readBytes)
	{
		if (false == UpdateAcceptSocket())
			return;

		UpdateAddress();
		RegisterClient();

		Reuse();
	}

	BOOL IocpAcceptOverlapped::UpdateAcceptSocket()
	{
		if (setsockopt(Socket->GetSocketId(), SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT,
			(const char*)&ListenSocket->GetSocketId(), sizeof(SOCKET)) == SOCKET_ERROR)
		{
			return false;
		}

		return true;
	}

	void IocpAcceptOverlapped::UpdateAddress()
	{
		PSOCKADDR_IN local_sockaddr = nullptr;
		PSOCKADDR_IN remote_sockaddr = nullptr;

		Int32 local_sockaddr_len = 0;
		Int32 remote_sockaddr_len = 0;

		Int32 addr_length = sizeof(SOCKADDR_IN) + 16;

		SocketUtil::GetAcceptExSockaddrs(Buffer, 0, addr_length, addr_length, (LPSOCKADDR*)&local_sockaddr, &local_sockaddr_len, (LPSOCKADDR*)&remote_sockaddr, &remote_sockaddr_len);
		Socket->SetAddrIn(*remote_sockaddr);
	}

	void IocpAcceptOverlapped::RegisterClient()
	{
		if (nullptr == CreateIoCompletionPort((HANDLE)Socket->GetSocketId(), IocpHandle, 0, 0))
		{
			DWORD dwErr = WSAGetLastError();
			if (dwErr != ERROR_INVALID_PARAMETER)
			{
				Socket->Close();
			}
		}

		SessionManager::GetInstance()->AddUser(Socket);
		Socket->RegisterReceived();

		LOG_DEBUG(LogManager::GetInstance()->GetLogger(L"socket"), "Register Client");
	}

	void IocpConnectOverlapped::OnWork(DWORD readBytes)
	{
		LOG_DEBUG(LogManager::GetInstance()->GetLogger(L"socket"), "IocpConnectOverlapped::OnWork()");

	}

	void IocpReadOverlapped::OnWork(DWORD readBytes)
	{
		auto buffer = Socket->GetReceivedBuffer();
		Socket->GetReceivedBuffer()->MoveTail(readBytes);

		LOG_ERROR_FMT(LogManager::GetInstance()->GetLogger(L"socket"), L"IocpReadOverlapped::OnWork() %d  %d %d", readBytes, buffer->GetHeadPos(), buffer->GetTailPos());

		while (false == buffer->IsEmpty())
		{
			IF_BREAK(buffer->GetUseSize() <= HeaderBufferSize);
			std::shared_ptr<Packet> tempPacket = MakeShared<Packet>();
			buffer->Peek((UInt8*)tempPacket->GetHeader(), HeaderBufferSize);

			IF_BREAK(tempPacket->GetTotalSize() > buffer->GetUseSize());
			buffer->Pop((UInt8*)tempPacket->GetBuffer(), tempPacket->GetTotalSize());

			tempPacket->SetSessionIdx(Socket->GetSessionIndex());
			//flatbuffers::Verifier verifier(tempPacket->GetBody(), tempPacket->GetSize());
			Server::GetInstance()->GetLogicThread()->EnqueuePacket(std::move(tempPacket));
		}

		this->Socket->RegisterReceived();
	}

	void IocpSendOverlapped::OnWork(DWORD readBytes)
	{
		SendBuffer->MoveHead(readBytes);
		LOG_DEBUG_FMT(LogManager::GetInstance()->GetLogger(L"socket"), L"IocpSendOverlapped::OnWork() %d, %d", readBytes, SendBuffer->GetUseSize());

	}

	void IocpDisconnectOverlapped::OnWork(DWORD readBytes)
	{
		LOG_DEBUG_FMT(LogManager::GetInstance()->GetLogger(L"socket"), L"IocpDisconnectOverlapped::OnWork() %d", readBytes);

	}
}