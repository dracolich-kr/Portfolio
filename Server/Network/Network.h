#pragma once

// 자동으로 WSA 시작시키는 생성자.
class WSAInitializer
{
public:
	WSAInitializer();
	virtual ~WSAInitializer();

	ErrorResult GetError(Int32 result)
	{
		switch (result)
		{
		case WSASYSNOTREADY:
			// 기본 네트워크 하위 시스템은 네트워크 통신을 수행할 준비가 되지 않았습니다.
			break;
		case WSAVERNOTSUPPORTED:
			// 요청된 Windows 소켓 지원 버전은 이 특정 Windows 소켓 구현에서 제공되지 않습니다
			break;
		case WSAEINPROGRESS:
			// 차단 Windows 소켓 1.1 작업이 진행 중입니다.
			break;
		case WSAEPROCLIM:
			// Windows 소켓 구현에서 지원하는 작업 수에 대한 제한에 도달했습니다.
			break;
		case WSAEFAULT:
			// lpWSAData 매개 변수가 유효한 포인터가 아닙니다
			break;
		default:
			break;
		}

		return ErrorResult::Success;
	}

private:
	WSAData mWsaData;
};

