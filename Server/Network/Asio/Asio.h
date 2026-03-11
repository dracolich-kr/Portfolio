#pragma once

namespace Network
{
	class NetworkBuffer;
	using AsioContext = std::shared_ptr<asio::io_context>;

	class AsioSocket
		: public ISocket
		, public std::enable_shared_from_this<AsioSocket>
	{
	public:
		AsioSocket(AsioContext sevice)
			: mSocket(*sevice.get())
			, mResolver(*sevice.get())
			, mPacketProcessor(nullptr)
		{

		}

		virtual ~AsioSocket() {}
		asio::ip::tcp::socket& GetSocket() { return mSocket; }

		void SetPacketProcessor(PacketProcessor* processor) { mPacketProcessor = processor; }

	public:
		virtual ErrorResult Open() override;
		virtual ErrorResult Close() override;

		virtual ErrorResult Connect(DefString ip_address, Port port) override;

		virtual ErrorResult Send(UInt8* buffer, Size size) override;
		virtual ErrorResult Send(SharedPacket packet) override;

		virtual ErrorResult Read(Size read_bytes = 0) override;

		void SetSessionIndex(SessionIndex index) override { mSessionIndex = index; }
		const Int32& GetSessionIndex() override { return mSessionIndex; }

	private:
		void onWrite(asio::error_code error, std::size_t length);
		void onRead(asio::error_code error, std::size_t length);

	private:
		asio::ip::tcp::socket mSocket;
		asio::ip::tcp::resolver mResolver;

		std::shared_ptr<NetworkBuffer> mBuffer;

		SharedPacket mTempPacket;
		SessionIndex mSessionIndex;

		PacketProcessor* mPacketProcessor;
	};

	using SharedAsioSocket = std::shared_ptr<AsioSocket>;

	class Asio
	{
	public:
		Asio()
		{
			mContext = MakeShared<asio::io_context>();
		}
		virtual ~Asio() {}

		AsioContext GetContext() { return mContext; }
	private:
		AsioContext mContext;

	};
}