#include <Pch.h>

UInt8* FlatBufferAllocator::allocate(Size size)
{
	return (UInt8*)MemoryPool::GetInstance()->Allocate(size);
}

void FlatBufferAllocator::deallocate(UInt8* p, Size size)
{
	return MemoryPool::GetInstance()->Deallocate(p);
}