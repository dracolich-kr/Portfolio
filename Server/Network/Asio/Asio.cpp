#include <Pch.h>

ErrorResult AsioSocket::Open()
{

	return ErrorResult::Success;
}

ErrorResult AsioSocket::Close()
{

	return ErrorResult::Success;
}

ErrorResult AsioSocket::Send(UInt8* buffer, Size size)
{
	//asio::write(mSocketId, );

	return ErrorResult::Success;
}

ErrorResult AsioSocket::Send(Packet* packet)
{

	return ErrorResult::Success;
}

ErrorResult AsioSocket::Read(Size read_bytes)
{
	//asio::read(mSocketId);

	return ErrorResult::Success;
}