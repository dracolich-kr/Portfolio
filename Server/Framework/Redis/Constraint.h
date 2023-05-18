#pragma once

namespace Redis
{
	enum class RedisType : Int8
	{
		None = 0
		, Master = 1
		, Slave = 2
		, Sentinel = 3
	};

	enum class ReplyType : Int8
	{
		None = 0
		, String = 1
		, Array = 2
		, Integer = 3
		, Nil = 4
		, Status = 5
		, Error = 6
	};

	enum class Type : Int8
	{
		None = 0
		, String
		, List
		, Set
		, ZSet
		, Hash
	};

	using RedisReply = std::shared_ptr<redisReply>;
	using RedisContext = std::shared_ptr<redisContext>;
}