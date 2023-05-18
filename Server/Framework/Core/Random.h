#pragma once

template<typename T>
class Random
{
};

template<>
class Random<Int32>
{
public:
	Random(Int32 max) :
		mRandom(mRandomDevice())
		, mRange(0, max)
	{
	}

	Random(Int32 min, Int32 max) :
		mRandom(mRandomDevice())
		, mRange(min, max)
	{
	}

	virtual ~Random() {}

	Int32 GetRand()
	{
		return mRange(mRandom);
	}

	void SetRange(Int32 max_range) { mRange.param(std::uniform_int_distribution<Int32>::param_type{ 0, max_range }); }
	void SetRange(Int32 min_range, Int32 max_range) { mRange.param(std::uniform_int_distribution<Int32>::param_type{ min_range, max_range }); }

private:
	std::random_device mRandomDevice;
	std::mt19937 mRandom;
	std::uniform_int_distribution<Int32> mRange;
};

template<>
class Random<Double>
{
public:
	Random(Double max) :
		mRandom(mRandomDevice())
		, mRange(0, max)
	{
	}

	Random(Double min, Double max) :
		mRandom(mRandomDevice())
		, mRange(min, max)
	{
	}

	virtual ~Random() {}

	Double GetRand()
	{
		return mRange(mRandom);
	}

	void SetRange(Double max_range) { mRange.param(std::uniform_real_distribution<Double>::param_type{ 0, max_range }); }
	void SetRange(Double min_range, Double max_range) { mRange.param(std::uniform_real_distribution<Double>::param_type{ min_range, max_range }); }

private:
	std::random_device mRandomDevice;
	std::mt19937 mRandom;
	std::uniform_real_distribution<Double> mRange;
};
