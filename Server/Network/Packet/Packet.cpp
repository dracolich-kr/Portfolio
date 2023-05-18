#include <Pch.h>

void PacketHeader::Clear()
{
	mPacketSize = 0;
}

void Packet::Clear()
{
	ZeroMemory(mBuffer, sizeof(mBuffer));
}

void Packet::SetPacket(const void* buffer, Size size)
{
	memcpy(mBuffer, buffer, size);
}

