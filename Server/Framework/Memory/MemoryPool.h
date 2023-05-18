#pragma once

class MemoryPool : public Singleton<MemoryPool>
{
private:
	friend Singleton<MemoryPool>;
	MemoryPool() 
		: mMaxAllocSize(0)
	{}

public:
	virtual ~MemoryPool() { Clear(); }
	
	void Initalize();
	void Clear();

	void* Allocate(size_t size);
	void Deallocate(void* object);

private:
	std::map<size_t, MemoryBlockList*> mPools;

	size_t mMaxAllocSize;
};
