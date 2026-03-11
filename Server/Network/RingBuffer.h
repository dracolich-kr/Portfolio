#pragma once
namespace Network
{
	class RingBuffer
	{
	public:
		RingBuffer()
			: mBuffer(nullptr)
			, mHead(0)
			, mTail(0)
			, mEnd(0)
		{
		}
		virtual ~RingBuffer()
		{
		}

		void Initalize(Size size);
		void Release();

		void Clear();

		// Tail이 증가 하고 증가한 범위 만큼 데이터를 넣는다.
		bool Push(const UInt8* IN data, Size size);
		// Head가 증가되고 증가 된만큼 데이터를 data에 복사한다.
		bool Pop(UInt8* OUT data, Size size);
		// Head는 이동하지 않고 데이터를 data에 복사한다.
		bool Peek(UInt8* OUT data, Size size);

		bool IsEmpty() const { return mHead == mTail ? true : false; }

		// 버퍼에 Push할 수 있는 사이즈 리턴
		Size GetFreeSize() const;

		// Pop 할수 있는 사이즈 리턴
		Size GetUseSize() const;

		bool MoveHead(Size length);
		bool MoveTail(Size length);

	private:
		UInt8* mBuffer;
		// 읽어오는 버퍼 위치
		Size mHead;
		// 입력한 버퍼 위치
		Size mTail;

		Size mEnd;
	};
}