#pragma once

namespace Network
{
	// RingBuffer 기반 네트워크 버퍼
	class NetworkBuffer : public ICustomMemory
	{
	public:
		NetworkBuffer()
			: mBuffer(nullptr)
			, mHead(0)
			, mTail(0)
			, mSize(0)
		{
		}
		virtual ~NetworkBuffer() {}

		void Initalize(Size size);
		void Release();

		void Clear();

		bool Push(const UInt8* IN data, Size size);	// Tail이 증가 하고 증가한 범위 만큼 데이터를 넣는다.
		bool Pop(UInt8* OUT data, Size size);		// 버퍼에 받은 데이터를 nSize 만큼 가져 온다. 테일 이동
		bool Peek(UInt8* OUT data, Size size);		// 버퍼에 받은 데이터를 nSize 만큼 가져 온다. 테일 이동 없음

		bool IsEmpty() { return mHead == mTail ? true : false; }

		// 버퍼에 Push할 수 있는 사이즈 리턴
		Size GetFreeSize();

		// Pop 할수 있는 사이즈 리턴
		Size GetUseSize();

		bool MoveHead(Size length);
		bool MoveTail(Size length);

		Byte* GetTail() { return mBuffer + mTail; }
		Byte* GetHead() { return mBuffer + mHead; }

		Size GetTailPos() { return mTail; }
		Size GetHeadPos() { return mHead; }
		Size GetBufferSize() { return mSize; }
	private:
		UInt8* mBuffer;

		// 읽어오는 버퍼 위치
		Size mHead;
		// 입력한 버퍼 위치
		Size mTail;

		// 버퍼 사이즈
		Size mSize;
	};
}