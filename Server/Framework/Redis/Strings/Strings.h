#pragma once

namespace Redis::Strings
{
	class Set
		: public BaseCommand
	{
	public:
		Set() 
			: BaseCommand("SET")
		{
		}
		virtual ~Set() {}

		virtual ErrorResult onResult(RedisReply reply) override;
	private:

	};
	
	class Get
		: public BaseCommand
	{
	public:
		Get() 
			: BaseCommand("GET")
		{
		}
		virtual ~Get() {}

		virtual ErrorResult onResult(RedisReply reply) override;
	private:

	};


}

#include "Strings.hpp"