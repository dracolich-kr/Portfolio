#include <pch.h>
#include "ReceiveBuffer.h"

void ReceiveBuffer::Clear()
{
	mReadBytes = 0;
}

void ReceiveBuffer::onRead(ISocket* socket, Size bytes_transferred)
{
	IF_RETURN(nullptr == socket, );

	LOG_WARN_FMT(mLogger, L"recevie: %s, % zd", GetBuffer(), bytes_transferred);
	AddReadBytes(bytes_transferred);

	// 최소 해더 사이즈만큼은 받아야 한다.
	if (GetReadBytes() < PacketHeaderSize)
	{
		socket->Read(PacketHeaderSize - (UInt32)GetReadBytes());
		return;
	}

	PacketHeader* header = reinterpret_cast<PacketHeader*>(GetBuffer());

	// 다받았다.
	if (GetReadBytes() >= header->GetPacketSize() + PacketHeaderSize)
	{
		auto packet = MakeShared<Packet>();
		packet->SetPacket(GetBuffer(), header->GetPacketSize());

		/*
		* 로직 쓰레드로 토스하는 기능을 작업해야 함.
		*/
		
		CalcBuffer(header->GetPacketSize() + PacketHeaderSize);

		onRead(socket, 0);
		return;
	}

	// 아직 덜 받았다.
	socket->Read((UInt8)((header->GetPacketSize() + PacketHeaderSize) - GetReadBytes()));

}

void ReceiveBuffer::SetBuffer(const UInt8* buffer, Size size)
{
	memcpy(mBuffer, buffer, size);
}

/// <summary>
///
/// </summary>
/// <param name="read_bytes"></param>
void ReceiveBuffer::CalcBuffer(Size read_bytes)
{
	memmove(mBuffer, mBuffer + read_bytes, GetReadBytes() - read_bytes);
	mReadBytes -= read_bytes;
}