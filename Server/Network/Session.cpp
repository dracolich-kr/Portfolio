#include <Pch.h>
namespace Network
{
	ErrorResult Session::Relay(std::shared_ptr<Packet> packet)
	{
		IF_RETURN(nullptr == mSocket, ErrorResult::Failed);

		mSocket->Send(packet);

		return ErrorResult::Success;
	}
}