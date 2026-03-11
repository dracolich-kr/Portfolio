#include <Pch.h>
namespace Network
{
	ErrorResult Iocp::Initalize(std::shared_ptr<ListenSocket> listen_socket)
	{
		mSocket = listen_socket;
		mSocket->SetIocp(this->shared_from_this());

		mHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
		if (mHandle == nullptr)
			return ErrorResult::InitalizeFailed;

		// Accept 연결
		CreateIoCompletionPort((HANDLE)mSocket->GetSocketId(), mHandle, 0, 0);

		return ErrorResult::Success;
	}

	ErrorResult Iocp::Release()
	{
		CloseHandle(mHandle);

		return ErrorResult::Success;
	}

	ErrorResult Iocp::AddAccept(IocpAcceptOverlapped* overlapped)
	{
		if (overlapped == nullptr)
		{
			overlapped = new IocpAcceptOverlapped();
		}

		auto user = mSocket->GetSockets().AcquireObject();
		user->Open();

		overlapped->Socket = user;
		overlapped->ListenSocket = mSocket;
		overlapped->IocpHandle = mHandle;

		mSocket->Accept(user, overlapped);

		return ErrorResult::Success;
	}
}