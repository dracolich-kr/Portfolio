#pragma once

template <typename T>
class ObjectPool
{
public:
	using Object = std::shared_ptr<T>;
	using Trunk = std::unique_ptr<T>;
public:
	ObjectPool() = default;
	virtual ~ObjectPool() = default;

	ObjectPool(const ObjectPool<T>& src) = delete;
	ObjectPool<T>& operator=(const ObjectPool<T>& rhs) = delete;

	Object AcquireObject();

	Bool CheckAllocBlock();

private:
	void AllocBuffer();

private:
	std::queue<Trunk, std::deque<Trunk>> mObjectPool;
	Int32 mAllocSize = 128;
};

#include "ObjectPool.hpp"