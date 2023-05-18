#pragma once

// 패킷 통신시 바이트정렬을 Padding없이 가지고 가기 위함
#pragma pack(push, 1)

class PacketHeader
{
public:
	PacketHeader()
		: mPacketSize(0)
		, mProtocolId(0)
		, mGuid({})
	{}
	virtual ~PacketHeader() {}

	void Clear();

	void SetProtocolId(ProtocolId protocol_id) { mProtocolId = protocol_id; }
	ProtocolId GetProtocolId() { return mProtocolId; }

	void SetPacketSize(Size size) { mPacketSize = size; }
	Size GetPacketSize() { return mPacketSize; }

private:
	Size mPacketSize;
	ProtocolId mProtocolId;
	Bool mCrypt;
	
	// 패킷 고유 아이디 패킷 프로토콜 아이디 말고도 고유성 체크용
	// 그냥 Index로 주고받고 해도 되긴할듯
	GUID mGuid;
};
static const Size PacketHeaderSize = sizeof(PacketHeader);

static const Size PacketSize = 0x10000;

class Packet
{
public:
	Packet()
		: mBuffer()
	{
	}

	virtual ~Packet() {}

	void Clear();

	Size GetTotalSize() { return GetHeader()->GetPacketSize() + PacketHeaderSize; }
	PacketHeader* GetHeader() { return reinterpret_cast<PacketHeader*>(mBuffer); }
	UInt8* GetBody() { return mBuffer + PacketHeaderSize; }
	UInt8* GetBuffer() { return mBuffer; }

	void SetPacket(const void* buffer, Size size);

private:
	UInt8 mBuffer[PacketSize];
};

#pragma pack(pop)