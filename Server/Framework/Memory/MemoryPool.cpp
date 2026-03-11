#include <Pch.h>

constexpr std::size_t ce_sqrt(std::size_t x, std::size_t y = 0)
{
	if (x == 0)
		return 0;

	if (x == 1)
		return y;
	++y;

	return ce_sqrt(x >> 1, y);
}

constexpr std::size_t ce_2_square(std::size_t x)
{
	if (x > 0)
		return 2 * ce_2_square(x - 1);
	return 1;
}

// x = sizeof(T)일 때, 64, 128, 256, 512, ... 구하는 메크로.
#define CE_MEMSIZE(x) (ce_2_square( ( (x+7)/64 == 0 ? 0 : ce_sqrt((x+7)/64) + 1) + 6) )

ErrorResult MemoryPool::Initalize()
{
	size_t size = 64;
	for (Int32 index = 0; index < 14; index++)
	{
		MemoryBlockList* list = new MemoryBlockList();
		list->Initalize(size, 128);
		mPools.emplace(size, list);
		size *= 2;
	}

	mMaxAllocSize = size;

	return ErrorResult::Success;
}

void MemoryPool::Clear()
{
	for (auto iter : mPools)
	{
		delete iter.second;
	}

	mPools.clear();
}

void* MemoryPool::Allocate(size_t size)
{
	if (size >= mMaxAllocSize)
	{
		size_t real_size = (size + HeaderBufferSize);
		UInt8* buffer = (UInt8*)_aligned_malloc(sizeof(UInt8) * real_size, MEMORY_ALLOCATION_ALIGNMENT);
		ZeroMemory(buffer, sizeof(UInt8) * real_size);

		MemoryHeader* header = (MemoryHeader*)(buffer);
		new(header) MemoryHeader();

		header->mSize = size;
		header->mThreadIndex = -1;

		return buffer + HeaderBufferSize;
	}

	size_t alloc_size = CE_MEMSIZE(size);
	UInt8* buffer = nullptr;
	auto iter = mPools.find(alloc_size);
	if (iter == mPools.end())
	{
		return nullptr;
	}
	else
	{
		buffer = iter->second->Pop();
	}
	MemoryHeader* header = (MemoryHeader*)(buffer);
	header->mState = MemoryState::Alloc;
	ZeroMemory(buffer + HeaderBufferSize, sizeof(UInt8) * size);

	return buffer + HeaderBufferSize;
}

void MemoryPool::Deallocate(void* object)
{ 
	UInt8* buffer = reinterpret_cast<UInt8*>(object);
	MemoryHeader* header = (MemoryHeader*)(buffer -= HeaderBufferSize);
	header->mState = MemoryState::Free;

	auto iter = mPools.find(header->mSize);

	if (iter == mPools.end())
	{
		_aligned_free(buffer);
		return;
	}

	iter->second->Add(buffer);
}