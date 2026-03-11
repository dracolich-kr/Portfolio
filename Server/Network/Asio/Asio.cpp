#include <Pch.h>

namespace Network
{
	ErrorResult AsioSocket::Open()
	{
		mBuffer = MakeShared<NetworkBuffer>();
		mBuffer->Initalize(NetworkBufferSize);

		return ErrorResult::Success;
	}

	ErrorResult AsioSocket::Close()
	{
		std::error_code error;
		mSocket.shutdown(asio::ip::tcp::socket::shutdown_both, error);
		mSocket.close();

		return ErrorResult::Success;
	}

	ErrorResult AsioSocket::Connect(DefString ip_address, Port port)
	{
		std::error_code error;
		asio::ip::tcp::endpoint endpoint(asio::ip::address::from_string(ip_address.c_str()), port);
		mSocket.connect(endpoint, error);

		if (error)
			return ErrorResult::SocketDisconnect;

		return ErrorResult::Success;
	}

	ErrorResult AsioSocket::Send(UInt8* buffer, Size size)
	{
		mSocket.async_write_some(asio::buffer((void*)buffer, size), std::bind(&AsioSocket::onWrite, this, std::placeholders::_1, std::placeholders::_2));

		return ErrorResult::Success;
	}

	ErrorResult AsioSocket::Send(SharedPacket packet)
	{
		return Send(packet->GetBuffer(), packet->GetTotalSize());
	}


	ErrorResult AsioSocket::Read(Size read_bytes)
	{
		if (read_bytes == 0 || read_bytes < NetworkBufferSize)
			read_bytes = NetworkBufferSize;

		mSocket.async_read_some(asio::buffer((void*)mBuffer->GetTail(), read_bytes), std::bind(&AsioSocket::onRead, this, std::placeholders::_1, std::placeholders::_2));

		return ErrorResult::Success;
	}

	void AsioSocket::onWrite(asio::error_code error, std::size_t length)
	{
		auto log = LogManager::GetInstance()->GetLogger("Asio");

		if (error)
		{
			if (error == asio::error::eof)
			{
				LOG_ERROR_FMT(log, L"Disconnect : %d", length);
			}

			LOG_ERROR_FMT(log, L"onWrtie Error : %d", length);
			this->Close();
		}
		else
		{
			//LOG_ERROR_FMT(log, L"onWrtie %d", length);
		}

	}

	void AsioSocket::onRead(asio::error_code error, std::size_t length)
	{
		auto log = LogManager::GetInstance()->GetLogger("Asio");

		if (error)
		{
			LOG_ERROR_FMT(log, L"Error %d", length);
			this->Close();

			return;
		}

		mBuffer->MoveTail(length);
		while (false == mBuffer->IsEmpty())
		{
			IF_RETURN(mBuffer->GetUseSize() <= HeaderBufferSize, );

			auto tempPacket = MakeShared<Packet>();
			mBuffer->Peek((UInt8*)tempPacket->GetHeader(), HeaderBufferSize);

			IF_RETURN(tempPacket->GetTotalSize() > mBuffer->GetUseSize(), );
			mBuffer->Pop((UInt8*)tempPacket->GetBuffer(), tempPacket->GetTotalSize());

			if (mPacketProcessor != nullptr)
			{
				mPacketProcessor->EnqueuePacket(tempPacket);
			}
		}
		Read(mBuffer->GetBufferSize() - mBuffer->GetTailPos());
	}
}