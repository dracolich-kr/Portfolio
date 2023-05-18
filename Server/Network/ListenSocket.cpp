#include <Pch.h>

ErrorResult ListenSocket::Open()
{
	ErrorResult result = BSDSocket::Open();

	if (result != ErrorResult::Success)
	{
		printf(+"WSAIoctl failed with error: %u\n", WSAGetLastError());
	}

	return ErrorResult::Success;
}


ErrorResult ListenSocket::Bind(Port port)
{
	mSocketAddr.sin_family = AF_INET;
	mSocketAddr.sin_port = htons(port);
	mSocketAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	if (bind(mSocketId, (struct sockaddr*)&mSocketAddr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		printf("Error - Fail bind \n");
		Close();
		return ErrorResult::SocketFailed;
	}

	return ErrorResult::Success;
}

ErrorResult ListenSocket::Listen(Int32 back_log)
{
	//SetSoConditionalAccept(true);
	
	if (listen(mSocketId, back_log) == SOCKET_ERROR)
	{
		printf("Error - Fail listen \n");
		// 6. 소켓종료
		Close();
		return ErrorResult::SocketFailed;
	}

	return ErrorResult::Success;
}

ErrorResult ListenSocket::Accept(std::shared_ptr<UserSocket> client, IocpAcceptOverlapped* overlapped)
{
	ErrorResult result = ErrorResult::Success;

	DWORD length = 0;
	DWORD lengthAddr = sizeof(SOCKADDR_IN) + 16;

	Int32 socket_result = SocketUtil::AcceptEx(mSocketId, client->GetSocketId(), overlapped->Buffer, 0, lengthAddr, lengthAddr, &overlapped->Length, overlapped);
	if (socket_result == false)
	{
		socket_result = WSAGetLastError();
		if (socket_result != WSA_IO_PENDING)
		{
			client->Close();
			return result;
		}
	}

	return result;
}

ErrorResult ListenSocket::Accept()
{
	ErrorResult result = ErrorResult::Success;
	sockaddr addr;
	Int32 length = sizeof(sockaddr_in);

	SOCKET socket = accept(mSocketId, &addr, &length);
	if (socket == INVALID_SOCKET)
	{
		Int32 socket_error = GetLastError();
		return result;
	}

	return result;
}

// 애플리케이션에서 수신 대기 소켓에서 들어오는 연결을 관리  
ErrorResult ListenSocket::SetSoConditionalAccept(Bool enable)
{
	Int32 socket_error = setsockopt(mSocketId, SOL_SOCKET, SO_CONDITIONAL_ACCEPT, (CHAR*)&enable, sizeof(enable));

	if (socket_error == -1)
	{
		switch (WSAGetLastError())
		{
		case WSANOTINITIALISED:
			//  함수를 사용하기 전에 성공적인 WSAStartup 호출이 발생해야 합니다.
			break;
		case WSAENETDOWN:
			// 네트워크 하위 시스템이 실패했습니다.
			break;
		case WSAEFAULT:
			// optval 또는 optlen 매개 변수 중 하나는 사용자 주소 공간의 유효한 부분에 없는 메모리를 가리킵니다. optlen 매개 변수가 가리키는 값이 DWORD 값의 크기보다 작은 경우에도 이 오류가 반환됩니다.
			break;
		case WSAEINPROGRESS:
			// 차단 Windows Sockets 1.1 호출이 진행 중이거나 서비스 공급자가 여전히 콜백 함수를 처리하고 있습니다.
			break;
		case WSAEINVAL:
			// 수준 매개 변수를 알 수 없거나 잘못되었습니다. 소켓이 이미 수신 대기 상태인 경우에도 이 오류가 반환됩니다
			break;
		case WSAENOPROTOOPT:
			// 이 옵션은 표시된 프로토콜 패밀리에서 알 수 없거나 지원되지 않습니다.
			break;
		case WSAENOTSOCK:
			// 설명자가 소켓이 아닙니다.
			break;
		}

	}

	return ErrorResult::Success;
}