#pragma once

template <typename Type>
class Singleton
{
public:
	virtual  ~Singleton() {}

	static Type* GetInstance();
	static void Destory();

protected:
	Singleton() {}
private:
	static Type* mInstance;
	static std::mutex mMutex;
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
};

template <typename Type>
Type* Singleton<Type>::GetInstance()
{
	if (nullptr != mInstance)
	{
		return mInstance;
	}

	std::lock_guard<std::mutex> guard(mMutex);
	if (nullptr == mInstance)
	{
		mInstance = new Type;
	}

	return mInstance;
}

template <typename Type>
void Singleton<Type>::Destory()
{
	if (nullptr != mInstance)
	{
		delete mInstance;
		mInstance = nullptr;
	}
}

template <typename Type>
Type* Singleton<Type>::mInstance = nullptr;

template <typename Type>
std::mutex Singleton<Type>::mMutex;