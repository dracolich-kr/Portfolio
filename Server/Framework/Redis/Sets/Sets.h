#pragma once

namespace Redis::Sets
{
	class Add : public BaseCommand
	{
	public:
		Add()
			: BaseCommand("SADD")
		{
		}

		virtual ~Add() {}

		virtual ErrorResult onResult(std::shared_ptr<redisReply> reply) override;

	private:

	};

	class Rem : public BaseCommand
	{
	public:
		Rem()
			: BaseCommand("SREM")
		{
		}

		virtual ~Rem() {}

		virtual ErrorResult onResult(std::shared_ptr<redisReply> reply) override;

	private:

	};
}