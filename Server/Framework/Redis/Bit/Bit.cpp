#include <Pch.h>

namespace Redis::Bit
{
	ErrorResult Set::onResult(std::shared_ptr<redisReply> reply)
	{
		switch ((ReplyType)reply->type)
		{
		case ReplyType::Integer:
			break;
		case ReplyType::Status:
			break;
		case ReplyType::None:
		case ReplyType::String:
		case ReplyType::Array:
		case ReplyType::Nil:
		case ReplyType::Error:
			break;
		default:
			break;
		}

		return ErrorResult::Success;
	}

	ErrorResult Get::onResult(std::shared_ptr<redisReply> reply)
	{
		switch ((ReplyType)reply->type)
		{
		case ReplyType::Integer:
			break;

		case ReplyType::None:
		case ReplyType::String:
		case ReplyType::Array:
		default:
			break;
		case ReplyType::Nil:
		case ReplyType::Status:
		case ReplyType::Error:
			break;
		
		}

		return ErrorResult::Success;
	}

	DefString Op::toStringOperation()
	{
		switch (mOperation)
		{
		default:
		case Operation::AND:
			return DefString("AND");
		case Operation::OR:
			return DefString("OR");
		case Operation::XOR:
			return DefString("XOR");
		case Operation::NOT:
			return DefString("NOT");
		}
	}


	ErrorResult Op::onResult(std::shared_ptr<redisReply> reply)
	{
		switch ((ReplyType)reply->type)
		{
		case ReplyType::None:
			break;
		case ReplyType::String:
			break;
		case ReplyType::Array:
			break;
		case ReplyType::Integer:
			break;
		case ReplyType::Nil:
			break;
		case ReplyType::Status:
			break;
		case ReplyType::Error:
			break;
		default:
			break;
		}

		return ErrorResult::Success;
	}

	ErrorResult Count::onResult(std::shared_ptr<redisReply> reply)
	{
		switch ((ReplyType)reply->type)
		{
		case ReplyType::Integer:
			break;

		case ReplyType::None:
		case ReplyType::String:
		case ReplyType::Array:
		case ReplyType::Nil:
		case ReplyType::Status:
		case ReplyType::Error:
		default:
			break;
		}

		return ErrorResult::Success;
	}

	DefString Field::toStringFieldCommand()
	{
		switch (mFieldCommand)
		{
		default:
		case FieldCommand::Set:
			return DefString("SET");
		case FieldCommand::Get:
			return DefString("GET");
		case FieldCommand::Incrby:
			return DefString("INCRBY");
		}
	}

	DefString Field::toStringFieldType()
	{
		switch (mFieldType)
		{
		default:
		case Redis::Bit::FieldType::U4:
			return DefString("U4");
		case Redis::Bit::FieldType::U8:
			return DefString("U8");
		case Redis::Bit::FieldType::I4:
			return DefString("I4");
		case Redis::Bit::FieldType::I8:
			return DefString("I8");
		}
	}

	ErrorResult Field::onResult(std::shared_ptr<redisReply> reply)
	{
		switch ((ReplyType)reply->type)
		{
		case ReplyType::Integer:
			break;

		case ReplyType::None:
		case ReplyType::String:
		case ReplyType::Array:
		case ReplyType::Nil:
		case ReplyType::Status:
		case ReplyType::Error:
		default:
			break;
		}

		return ErrorResult::Success;
	}

	ErrorResult Pos::onResult(RedisReply reply)
	{
		switch ((ReplyType)reply->type)
		{
		case ReplyType::Integer:
			break;

		case ReplyType::None:
		case ReplyType::String:
		case ReplyType::Array:
		case ReplyType::Nil:
		case ReplyType::Status:
		case ReplyType::Error:
		default:
			break;
		}

		return ErrorResult::Success;
	}

}