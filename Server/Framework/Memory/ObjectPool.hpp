#pragma once

template<typename T>
Bool ObjectPool<T>::CheckAllocBlock()
{
	IF_RETURN(mObjectPool.empty(), true);

	return false;
}

template<typename T>
typename ObjectPool<T>::Object ObjectPool<T>::AcquireObject()
{
	if(CheckAllocBlock())
		AllocBuffer();

	std::unique_ptr<T> unique_obj(std::move(mObjectPool.front()));
	mObjectPool.pop();

	Object obj(unique_obj.release(), [this](T* t) {
		mObjectPool.emplace(t);
	});

	return obj;
}

template<typename T>
void ObjectPool<T>::AllocBuffer()
{
	for(Int32 count = 0; count < mAllocSize; ++count)
		mObjectPool.emplace(std::make_unique<T>());
}