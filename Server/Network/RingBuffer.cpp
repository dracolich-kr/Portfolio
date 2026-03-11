#include <Pch.h>
namespace Network
{
	void RingBuffer::Initalize(size_t size)
	{
		if (mBuffer != nullptr)
		{
			MemoryPool::GetInstance()->Deallocate(mBuffer);
			mBuffer = nullptr;
		}

		IF_RETURN(size <= 0, );

		mBuffer = (BYTE*)MemoryPool::GetInstance()->Allocate(sizeof(UInt8) * size);
		ZeroMemory(mBuffer, sizeof(UInt8) * size);
		mTail = mHead = 0;

		mEnd = size - 1;
	}

	void RingBuffer::Release()
	{
		if (mBuffer != nullptr)
		{
			MemoryPool::GetInstance()->Deallocate(mBuffer);
			mBuffer = nullptr;
		}

		mHead = 0;
		mTail = 0;
		mEnd = 0;
	}

	void RingBuffer::Clear()
	{
		mHead = 0;
		mTail = 0;
		mEnd = 0;
	}

	bool RingBuffer::Push(const UInt8* IN data, size_t size)
	{
		if (GetFreeSize() < size)
			return false;

		if (mTail + size <= mEnd)
		{
			memcpy(mBuffer + mTail, data, size);
			mTail += size;
		}
		else
		{
			Size copy_size = mEnd - mTail;
			memcpy(mBuffer + mTail, data, copy_size);
			mTail = (mTail + size) - mEnd;
			memcpy(mBuffer, data + copy_size, mTail);
		}

		return true;
	}

	bool RingBuffer::Pop(UInt8* OUT data, size_t size)
	{
		if (mHead == mTail)
		{
			return false;
		}

		if (GetUseSize() < size)
		{
			return false;
		}

		if (mHead + size <= mEnd)
		{
			memcpy(data, mBuffer + mHead, size);
			mHead += size;
		}
		else
		{
			Size temp_size = (mEnd - mHead);
			memcpy(data, mBuffer + mHead, temp_size);
			mHead = (mHead + size) - mEnd;
			memcpy(data + temp_size, mBuffer, mHead);
		}

		return true;
	}

	bool RingBuffer::Peek(UInt8* OUT data, Size size) 
	{
		if (mHead == mTail)
		{
			return false;
		}

		if (GetUseSize() < size)
		{
			return false;
		}

		if (mHead + size <= mEnd)
		{
			memcpy(data, mBuffer + mHead, size);
		}
		else
		{
			Size temp_size = (mEnd - mHead);
			memcpy(data, mBuffer + mHead, temp_size);
			memcpy(data + temp_size, mBuffer, (mHead + size) - mEnd);
		}

		return true;
	}

	Size RingBuffer::GetFreeSize() const
	{
		IF_RETURN(mBuffer == nullptr, 0);

		return GetUseSize() - 1;
	}

	Size RingBuffer::GetUseSize() const
	{
		IF_RETURN(mBuffer == nullptr || mHead == mTail, 0);

		return (mTail - mHead + mEnd) % mEnd;
	}

	bool RingBuffer::MoveTail(Size length)
	{
		if (GetUseSize() < length)
			return false;

		if (mTail + length <= mEnd)
			mTail += length;
		else
			mTail = (mTail + length) - mEnd;

		return true;
	}

	bool RingBuffer::MoveHead(Size length)
	{
		if (GetUseSize() < length)
			return false;

		if (mHead + length <= mEnd)
			mHead += length;
		else
			mHead = (mHead + length) - mEnd;

		return true;
	}
}