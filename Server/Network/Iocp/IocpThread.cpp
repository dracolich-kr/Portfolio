#include <Pch.h>
namespace Network
{
	void IocpThread::Init(IocpHandle iocp_handle)
	{
		mIocpHandle = iocp_handle;
	}

	void IocpThread::Work()
	{
		Thread::Work();

		DWORD read_bytes = 0;
		UInt64 completion_key = 0;
		LPOVERLAPPED overlapped = nullptr;
		ErrorResult error_result = ErrorResult::Success;

		LOG_DEBUG(mLogger, L"Iocp thread start");

		while (TRUE)
		{
			// 실패 : 0
			Int32 result = GetQueuedCompletionStatus(mIocpHandle, &read_bytes, &completion_key, &overlapped, INFINITE);
			if (result == 0)
			{
				error_result = GetWSALastError();
				if (overlapped != nullptr)
				{
					IocpOverlapped* iocp_over = static_cast<IocpOverlapped*>(overlapped);
					LOG_DEBUG(mLogger, L"Iocp thread error: %d, %d", static_cast<int>(error_result), iocp_over->Type);

					delete iocp_over;
					iocp_over = nullptr;
				}
				else
				{
					LOG_DEBUG(mLogger, L"Iocp thread error: %d,%d", static_cast<int>(error_result));
				}
				continue;
			}

			if (overlapped == nullptr)
				continue;

			IocpOverlapped* iocp_over = static_cast<IocpOverlapped*>(overlapped);

			if (read_bytes == 0)
			{
				DWORD transfer, flags;
				WSAGetOverlappedResult(iocp_over->Socket->GetSocketId(), overlapped, &transfer, FALSE, &flags);
			}

			iocp_over->OnWork(read_bytes);

			switch (iocp_over->Type)
			{
			case IocpType::Send:
				delete iocp_over;
				break;
			case IocpType::Disconnect:
				break;
			case IocpType::Accept:
				break;
			case IocpType::Read:
				break;
			default:
				break;
			}
		}
	}


	// https://learn.microsoft.com/ko-kr/windows/win32/winsock/windows-sockets-error-codes-2 참고
	ErrorResult IocpThread::GetWSALastError()
	{
		SocketResult result = WSAGetLastError();

		switch (result)
		{
		// 연결이 거부 되었습니다.
		case WSAECONNREFUSED:
			break;
		// 원격 호스트가 강제로 연결이 끊겼습니다.
		case WSAECONNRESET:
			break;
		// 소프트 웨어로 연결이 중단되었습니다.
		case WSAECONNABORTED:
			break;
		// 연결 시도 타임아웃
		case WSAETIMEDOUT:
			break;
		// 네트워크 도달 불가
		case WSAENETUNREACH:
			break;
		// 	호스트 도달 불가
		case WSAEHOSTUNREACH:
			break;

		// 소켓 초기화
		// WSAStartup() 호출 안 됨
		case WSANOTINITIALISED:
			break;
		// 잘못된 인수
		case WSAEINVAL:
			break;
		// 소켓이 아닌 핸들에 작업 시도
		case WSAENOTSOCK:
			break;
		// 주소/포트 이미 사용 중 (bind 실패)
		case WSAEADDRINUSE:
			break;
		// 요청한 주소를 사용할 수 없음
		case WSAEADDRNOTAVAIL:
			break;
		// 소켓 타입이 해당 작업 미지원
		case WSAEOPNOTSUPP:
			break;

		// 전송
		// 논블로킹 소켓에서 즉시 완료 불가
		case WSAEWOULDBLOCK:
			return ErrorResult::Success;
		// 블로킹 작업 진행 중
		case WSAEINPROGRESS:
			break;
		// 메시지가 너무 큼
		case WSAEMSGSIZE:
			break;
		// 버퍼 공간 부족
		case WSAENOBUFS:
			break;
		// 이미 shutdown된 소켓에 전송 시도
		case WSAESHUTDOWN:
			break;
		}

		return ErrorResult::SocketFailed;
	}
}