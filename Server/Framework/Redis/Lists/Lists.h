#pragma once

namespace Redis::Lists
{
	template<class T>
	class LPushBase 
		: public BaseCommand
	{
	public:
		LPushBase(DefString key)
			: BaseCommand("LPUSH")
			, mLength(0)
		{
			SetKey(key);
		}

	private:
		Int32 mLength;
	};

	template<typename T>
	class LPush
		: public LPushBase<T>
	{
	public:
		LPush(DefString key)
			: LPushBase(key)
		{
		}

		virtual ErrorResult onResult(std::shared_ptr<redisReply> reply) override;
	};

	template<>
	class LPush<DefString>
		: public LPushBase<DefString>
	{
		LPush(DefString key)
			: LPushBase(key)
		{
		}

		virtual ErrorResult onResult(std::shared_ptr<redisReply> reply) override;
	};

	template<>
	class LPush<DefWString>
		: public LPushBase<DefWString>
	{
		LPush(DefString key)
			: LPushBase(key)
		{
		}

		virtual ErrorResult onResult(std::shared_ptr<redisReply> reply) override;
	};

	template<class T>
	class LPushExBase
		: public BaseCommand
	{
	public:
		LPushExBase(DefString key)
			: BaseCommand("LPUSHEX")
			, mLength(0)
		{
			SetKey(key);
		}

	private:
		Int32 mLength;
	};

	template<typename T>
	class LPushEx
		: public LPushExBase<T>
	{
	public:
		LPushEx(DefString key)
			: LPushExBase(key)
		{
		}

		virtual ErrorResult onResult(std::shared_ptr<redisReply> reply) override;
	};

	template<>
	class LPushEx<DefString>
		: public LPushExBase<DefString>
	{
	public:
		LPushEx(DefString key)
			: LPushExBase(key)
		{
		}

		virtual ErrorResult onResult(std::shared_ptr<redisReply> reply) override;
	};

	template<>
	class LPushEx<DefWString>
		: public LPushExBase<DefWString>
	{
	public:
		LPushEx(DefString key)
			: LPushExBase(key)
		{
		}

		virtual ErrorResult onResult(std::shared_ptr<redisReply> reply) override;
	};
}

#include "Lists.hpp"
#include "ListsPush.hpp"
#include "ListsPushEx.hpp"