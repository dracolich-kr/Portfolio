#include <Pch.h>

namespace Network
{
	void NetworkBuffer::Initalize(size_t size)
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

		mSize = size;
	}

	void NetworkBuffer::Release()
	{
		if (mBuffer != nullptr)
		{
			MemoryPool::GetInstance()->Deallocate(mBuffer);
			mBuffer = nullptr;
		}

		mHead = 0;
		mTail = 0;
		mSize = 0;
	}

	void NetworkBuffer::Clear()
	{
		mHead = 0;
		mTail = 0;
		mSize = 0;
	}

	bool NetworkBuffer::Push(const UInt8* IN data, size_t size)
	{
		if (GetFreeSize() < size)
			return false;

		if (mTail + size <= mSize)
		{
			memcpy(mBuffer + mTail, data, size);
			mTail += size;
		}
		else
		{
			Size copy_size = mSize - mTail;
			memcpy(mBuffer + mTail, data, copy_size);
			mTail = (mTail + size) - mSize;
			memcpy(mBuffer, data + copy_size, mTail);
		}

		return true;
	}

	bool NetworkBuffer::Peek(UInt8* OUT data, Size size)
	{
		if (mHead == mTail)
		{
			return false;
		}

		if (GetUseSize() < size)
		{
			return false;
		}

		if (mHead + size <= mSize)
		{
			memcpy(data, mBuffer + mHead, size);
		}
		else
		{
			Size rightSize = (mSize - mHead);
			memcpy(data, mBuffer + mHead, rightSize);
			memcpy(data + rightSize, mBuffer, (mHead + size) - mSize);
		}

		return true;
	}

	bool NetworkBuffer::Pop(UInt8* OUT data, size_t size)
	{
		if (mHead == mTail)
		{
			return false;
		}

		if (GetUseSize() < size)
		{
			return false;
		}

		if (mHead + size <= mSize)
		{
			memcpy(data, mBuffer + mHead, size);
			mHead += size;
		}
		else
		{
			Size rightSize = (mSize - mHead);
			memcpy(data, mBuffer + mHead, rightSize);
			mHead = (mHead + size) - mSize;
			memcpy(data + rightSize, mBuffer, mHead);
		}

		return true;
	}


	Size NetworkBuffer::GetFreeSize()
	{
		IF_RETURN(mBuffer == nullptr, 0);
		IF_RETURN(mHead == mTail, mSize);

		return GetUseSize() - 1;
	}

	Size NetworkBuffer::GetUseSize()
	{
		IF_RETURN(mBuffer == nullptr || mHead == mTail, 0);

		return (mTail - mHead + mSize) % mSize;
	}

	bool NetworkBuffer::MoveTail(Size length)
	{
		if (mTail + length < mSize)
			mTail += length;
		else
			mTail = (mTail + length) - mSize;

		return true;
	}

	bool NetworkBuffer::MoveHead(Size length)
	{
		if (mHead + length < mSize)
			mHead += length;
		else
			mHead = (mHead + length) - mSize;

		return true;
	}
}