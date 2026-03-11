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
			// ½ÇÆÐ : 0
			Int32 result = GetQueuedCompletionStatus(mIocpHandle, &read_bytes, &completion_key, &overlapped, INFINITE);
			if (result == 0)
			{
				error_result = GetWSALastError();
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
			default:
				break;
			}
		}
	}


	ErrorResult IocpThread::GetWSALastError()
	{
		SocketResult result = WSAGetLastError();

		return ErrorResult::Success;
	}
}