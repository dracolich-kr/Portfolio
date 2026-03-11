#pragma once

// 메모리 두번 반환 같은 비이상적인 상황 캐치용
enum MemoryState : Int32
{
	Free = 0
	, Alloc
};

DECLSPEC_ALIGN(MEMORY_ALLOCATION_ALIGNMENT)
struct MemoryHeader : public SLIST_ENTRY
{
	MemoryHeader()
		: mSize(0)
		, mThreadIndex(0)
		, mState(MemoryState::Free)
	{}
	virtual ~MemoryHeader() {}

	size_t mSize;
	Int32 mThreadIndex;
	MemoryState mState;
};

static const size_t HeaderBufferSize = sizeof(MemoryHeader);

DECLSPEC_ALIGN(MEMORY_ALLOCATION_ALIGNMENT)
class MemoryBlockList
{
public:

	MemoryBlockList()
		: mBlockSize(0)
		, mPopCount(0)
		, mMaxAllocCount(0)
		, mHeader(nullptr)
	{
	}

	virtual ~MemoryBlockList()
	{
	}

	void Initalize(size_t size, size_t init_alloc_count);

	void Add(UInt8* point);
	UInt8* Pop();

private:
	void capacity(size_t block_range);

private:
	// 생성하는 메모리 블럭 크기
	size_t mBlockSize;

	// 현재까지 생성 요청한 횟수
	size_t mPopCount;

	// 현재 할당한 블럭 개수 생성 방식을 현재 3/2 남아있을 때 3/2 가량 
	size_t mMaxAllocCount;

	// 블럭 리스트 관리 객체 
	PSLIST_HEADER mHeader;

	// 현재 생성해서 보관하고있는 메모리 블럭 갯수
	std::atomic<size_t> mSize;

};