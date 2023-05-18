#include <Pch.h>

void IocpAcceptOverlapped::Reuse()
{
	ZeroMemory(Buffer, ACCEPT_ADDR_LEN);
	Socket = ListenSocket->GetSockets().AcquireObject();

	ListenSocket->Accept(Socket, this);
}

void IocpAcceptOverlapped::OnWork()
{
	if (false == UpdateAcceptSocket())
		return;

	UpdateAddress();

	RegisterIoCompletionPort();

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

void IocpAcceptOverlapped::RegisterIoCompletionPort()
{
	if (nullptr == CreateIoCompletionPort((HANDLE)Socket->GetSocketId(), IocpHandle, 0, 0))
	{
		DWORD dwErr = WSAGetLastError();
		if (dwErr != ERROR_INVALID_PARAMETER)
		{
			Socket->Close();
		}
	}

}

void IocpConnectOverlapped::OnWork()
{
	printf("IocpConnectOverlapped::OnWork()\n");

}

void IocpReadOverlapped::OnWork()
{
	printf("IocpReadOverlapped::OnWork()\n");

}

void IocpSendOverlapped::OnWork()
{
	printf("IocpSendOverlapped::OnWork()\n");

}

void IocpDisconnectOverlapped::OnWork()
{
	printf("IocpDisconnectOverlapped::OnWork()\n");


}