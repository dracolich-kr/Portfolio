#pragma once

static const Size ReceiveBufferSize = 5 * 1024 * 1024;

class ReceiveBuffer
{
public:
	ReceiveBuffer()
		: mReadBytes(0)
		, mBuffer()
		, mStartPos(0)
		, mTailPos(0)
	{
		mLogger = LogManager::GetInstance()->GetLogger("Receive");
	}

	virtual ~ReceiveBuffer() {}

	void Clear();

	void onRead(ISocket* session, Size bytes_transferred);

	void AddReadBytes(Size read_bytes) { mReadBytes += read_bytes; }
	Size GetReadBytes() { return mReadBytes; }

	void SetBuffer(const UInt8* buffer, Size size);
	UInt8* GetBuffer() { return mBuffer; }

	void CalcBuffer(Size read_bytes);

private:
	UInt8 mBuffer[ReceiveBufferSize];
	Size mReadBytes;

	Size mStartPos;
	Size mTailPos;
	SharedLogger mLogger;
};