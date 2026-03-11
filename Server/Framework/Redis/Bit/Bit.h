#pragma once

namespace Redis::Bit
{
	class Set
		: public BaseCommand
	{
	public:
		Set(DefString key)
			: BaseCommand("SETBIT")
		{
			SetKey(key);
		}

		virtual ~Set() {}

		virtual ErrorResult onResult(RedisReply reply) override;
	private:

	};

	class Get
		: public BaseCommand
	{
	public:
		Get(DefString key)
			: BaseCommand("GETBIT")
		{
			SetKey(key);
		}
		virtual ~Get() {}

		virtual ErrorResult onResult(RedisReply reply) override;
	private:

	};
	
	enum class Operation
	{
		  AND
		, OR
		, XOR
		, NOT
	};

	class Op
		: public BaseCommand
	{
	public:
		Op(DefString key, Operation operation)
			: BaseCommand("BITOP")
		{
			SetKey(key);
			mOperation = operation;
			AddValue(toStringOperation());

		}
		virtual ~Op() {}

		virtual ErrorResult onResult(RedisReply reply) override;
		inline DefString toStringOperation();

	private:
		Operation mOperation;
	};

	class Count
		: public BaseCommand
	{
	public:
		Count(DefString key)
			: BaseCommand("BITCOUNT")
			, mLength(0)
		{
			SetKey(key);
		}
		virtual ~Count() {}

		virtual ErrorResult onResult(RedisReply reply) override;
	private:
		Int32 mLength;
	};
	
	enum class FieldCommand
	{
		Set
		, Get
		, Incrby
	};

	enum class FieldType
	{
		  U4 = 0
		, U8
		, I4
		, I8
	};

	class Field
		: public BaseCommand
	{
	public:
		Field(DefString key, FieldCommand commmand, FieldType type, Int32 value)
			: BaseCommand("BITFIELD")
		{
			SetKey(key);

			mFieldCommand = commmand;
			mFieldType = type;

			AddValue(toStringFieldCommand());
			AddValue(toStringFieldType());
			AddValue(DefString(std::to_string(value)));
		}
		virtual ~Field() {}

		virtual ErrorResult onResult(RedisReply reply) override;

		inline DefString toStringFieldCommand();
		inline DefString toStringFieldType();

	private:
		Int32 mResult;
		FieldCommand mFieldCommand;
		FieldType mFieldType;
	};

	class Pos
		: public BaseCommand
	{
	public:
		Pos(DefString key)
			: BaseCommand("BITPOS")
			, mLength(0)
		{
			SetKey(key);
		}
		virtual ~Pos() {}

		virtual ErrorResult onResult(RedisReply reply) override;

	private:
		Int32 mLength;
	};
}