#pragma once

#define USE_MEMORY_POOL 1

class ICustomMemory
{
public:
	inline void* operator new (size_t size)
	{
		return MemoryPool::GetInstance()->Allocate(size);
	}

	// 외부에서 할당해서 세팅하는 경우 여기로 호출 된다. 
	inline void* operator new (size_t size, std::align_val_t allgin_val, void* block)
	{
		return block;
	}

	inline void operator delete(void* point)
	{
		MemoryPool::GetInstance()->Deallocate(point);
	}

	inline void* operator new[](size_t size)
	{
		return MemoryPool::GetInstance()->Allocate(size);
	}

	inline void* operator new[](size_t size, std::align_val_t allgin_val, void* block)
	{
		return block;
	}

	inline void operator delete[](void* point)
	{
		MemoryPool::GetInstance()->Deallocate(point);
	}
};

template<class T, typename... Args>
static T* New(Args&&... args)
{
	auto value = reinterpret_cast<T*>(MemoryPool::GetInstance()->Allocate(sizeof(T)));
	new(value) T(std::forward<Args>(args)...);
	return value;
}

template<class T>
void Delete(T* object)
{
	object->~T();
	MemoryPool::GetInstance()->Deallocate(object);
};


template <class T, typename... Args>
std::shared_ptr<T> MakeShared(Args&&... args)
{
	return std::shared_ptr<T>(New<T>(std::forward<Args>(args)...), Delete<T>);
}
