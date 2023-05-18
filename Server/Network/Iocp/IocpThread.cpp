#include <Pch.h>

void IocpThread::Init(IocpHandle iocp_handle)
{
	mIocpHandle = iocp_handle;
}

void IocpThread::Work()
{
	DWORD read_bytes = 0;
	UInt64 completion_key = 0;
	LPOVERLAPPED overlapped = nullptr;
	ErrorResult error_result = ErrorResult::Success;

	LOG_DEBUG(mLogger, L"Iocp thread start");

	while (TRUE)
	{
		// ½ÇÆÐ : 0
		Int32 result = GetQueuedCompletionStatus(mIocpHandle, &read_bytes, &completion_key, &overlapped, INFINITE);
		if (result == 0)
		{
			error_result = GetWSALastError();
			continue;
		}

		if (overlapped == nullptr)
			continue;

		auto iocp_over = static_cast<IocpOverlapped*>(overlapped);

		if (read_bytes == 0)
		{
			DWORD transfer, flags;
			WSAGetOverlappedResult(iocp_over->Socket->GetSocketId(), overlapped, &transfer, FALSE, &flags);
		}

		iocp_over->OnWork();
	}
}

ErrorResult IocpThread::GetWSALastError()
{
	SocketResult result = WSAGetLastError();

	return ErrorResult::Success;
}
