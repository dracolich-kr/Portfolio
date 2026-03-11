#pragma once
namespace Network
{
	class SocketUtil
	{
	public:
		static void Initalize();

	public:
		static LPFN_ACCEPTEX AcceptEx;
		static LPFN_GETACCEPTEXSOCKADDRS GetAcceptExSockaddrs;
		static LPFN_DISCONNECTEX DisconnectEx;
		static LPFN_TRANSMITFILE TransmitFile;
		static LPFN_CONNECTEX ConnectEx;
	};
}