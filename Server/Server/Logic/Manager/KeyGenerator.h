#pragma once

template<typename T>
class KeyGenerator abstract
{
public:
	KeyGenerator()
	{
		static_assert(std::is_arithmetic<T>::value, "T is not arithmetic ");
	}
	virtual ~KeyGenerator() {}

	virtual T Generate() abstract;

protected:
	T mIndex;
};