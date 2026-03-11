#pragma once

template <typename Type>
class Singleton
{
public:
	virtual  ~Singleton() {}

	static Type* GetInstance();
	static void Destory();

	virtual ErrorResult Initalize() abstract;

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

	std::scoped_lock<std::mutex> guard(mMutex);
	if (nullptr == mInstance)
	{
		mInstance = new Type;
		mInstance->Initalize();
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