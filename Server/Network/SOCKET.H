#pragma once
namespace Network
{
	class Socket
		: public BSDSocket
		, public std::enable_shared_from_this<Socket>
	{
	public:
		Socket();

		virtual ~Socket();

		ErrorResult RegisterReceived();

		void SetPacketProcessor(PacketProcessor* packet_processor) { mPacketProcessor = packet_processor; }

	public:
		virtual ErrorResult Open() override;
		virtual ErrorResult Close() override;

		virtual ErrorResult Connect(DefString ip, Port port);
		virtual ErrorResult Disconnect();

		virtual ErrorResult Send(UInt8* buffer, Size size) override;
		virtual ErrorResult Send(SharedPacket packet) override;

		virtual ErrorResult Read(Size read_bytes) override;

		std::shared_ptr<NetworkBuffer> GetReceivedBuffer() { return mReceivedBuffer; }

	private:
		std::shared_ptr<NetworkBuffer> mReceivedBuffer;
		std::shared_ptr<NetworkBuffer> mSendBuffer;
		PacketProcessor* mPacketProcessor;

		log4cplus::Logger mLog = LogManager::GetInstance()->GetLogger("Socket");
	};

	using SharedSocket = std::shared_ptr<Socket>;
}