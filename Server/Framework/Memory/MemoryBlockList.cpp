#include <Pch.h>

void MemoryBlockList::Initalize(size_t size, size_t init_alloc_count)
{
	mBlockSize = size;

	mSize.store(0);

	mHeader = (PSLIST_HEADER)_aligned_malloc(sizeof(SLIST_HEADER), MEMORY_ALLOCATION_ALIGNMENT);
	if (mHeader == nullptr)
		return;

	InitializeSListHead(mHeader);

	capacity(init_alloc_count);
}

void MemoryBlockList::capacity(size_t block_range)
{
	size_t real_size = mBlockSize + HeaderBufferSize;

	for (Int32 index = 0; index < block_range; index++)
	{
		UInt8* buffer = (UInt8*)_aligned_malloc(sizeof(UInt8) * real_size, MEMORY_ALLOCATION_ALIGNMENT);
		ZeroMemory(buffer, sizeof(UInt8) * real_size);

		MemoryHeader* header = (MemoryHeader*)(buffer);
		new(header) MemoryHeader();

		header->mSize = mBlockSize;
		header->mThreadIndex = -1;

		InterlockedPushEntrySList(mHeader, (PSLIST_ENTRY)buffer);
		mSize++;
	}

	mMaxAllocCount += block_range;
}

void MemoryBlockList::Add(UInt8* point)
{
	InterlockedPushEntrySList(mHeader, (PSLIST_ENTRY)(point));
	mSize++;
}

UInt8* MemoryBlockList::Pop()
{
	if( mSize <= 0)
		capacity(mMaxAllocCount);

	mSize--;

	return reinterpret_cast<UInt8*>(InterlockedPopEntrySList(mHeader));
}