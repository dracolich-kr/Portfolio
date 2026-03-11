#pragma once

namespace Redis::Sets
{
	// 추가
	class Add : public BaseCommand
	{
	public:
		Add(DefString key)
			: BaseCommand("SADD")
		{
			SetKey(key);
		}

		virtual ~Add() {}

		virtual ErrorResult onResult(std::shared_ptr<redisReply> reply) override;

	private:

	};

	// 집합의 맴버 삭제
	class Rem : public BaseCommand
	{
	public:
		Rem(DefString key)
			: BaseCommand("SREM")
		{
			SetKey(key);
		}

		virtual ~Rem() {}

		virtual ErrorResult onResult(std::shared_ptr<redisReply> reply) override;

	private:

	};

	// 집합 데이터 조회
	class Member : public BaseCommand
	{
	public:
		Member(DefString key)
			: BaseCommand("SREM")
		{
			SetKey(key);
		}

		virtual ~Member() {}

		virtual ErrorResult onResult(std::shared_ptr<redisReply> reply) override;

	private:

	};
}